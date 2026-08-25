package main

import (
	"fmt"
	"math/rand"
	"sync"
	"sync/atomic"
)

var total int32

func producer(Q chan<- int32, count int32, producerAmount int32) {
	var wg sync.WaitGroup
	for i := 0; i < int(producerAmount); i++ {
		batch := count / producerAmount
		if i < int(count%producerAmount) {
			batch++
		}
		wg.Add(1)
		go func(batch int32) {
			fmt.Printf("batch=%d\n", batch)
			defer wg.Done()
			for j := 0; j < int(batch); j++ {
				t := rand.Intn(100)
				atomic.AddInt32(&total, int32(t))
				Q <- int32(t)
			}
		}(batch)
	}
	wg.Wait()
	close(Q)
}

func consumer(Q <-chan int32, sumChan chan<- int32, consumerAmount int32) {
	var wg sync.WaitGroup
	for i := 0; i < int(consumerAmount); i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			var sum int32 = 0
			for v := range Q {
				sum += int32(v)
			}
			sumChan <- sum
		}()
	}
	wg.Wait()
}
func main() {
	Q := make(chan int32, 100)
	sumChan := make(chan int32)
	count := 1000000
	producerAmount := 3
	consumerAmount := 4

	var wg sync.WaitGroup
	wg.Add(2)
	go func() {
		defer wg.Done()
		producer(Q, int32(count), int32(producerAmount))
	}()

	go func() {
		defer wg.Done()
		consumer(Q, sumChan, int32(consumerAmount))
	}()

	go func() {
		wg.Wait()
		close(sumChan)
	}()

	var sumAll int32
	for sum := range sumChan {
		sumAll += sum
	}
	fmt.Printf("%+v,%+v\n", sumAll, total)
}
