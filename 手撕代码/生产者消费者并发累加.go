package main

import (
	"fmt"
	"math/rand"
	"sync"
	"sync/atomic"
)

var producerLimit int32 = 3
var consumerLimit int32 = 4

var count int32 = 1000000
var QSize int32 = 10

var sum int32

func producer(Q chan int32) {
	var wg sync.WaitGroup
	a := count / producerLimit
	b := count % producerLimit
	for i := 0; i < int(producerLimit); i++ {
		batch := a
		if int32(i) < b {
			batch += 1
		}

		wg.Add(1)
		go func(size int32) {
			defer wg.Done()
			for j := 0; j < int(batch); j++ {
				t := rand.Int31n(2)
				atomic.AddInt32(&sum, t)
				Q <- t
			}
		}(batch)
	}
	wg.Wait()
	close(Q)
}

func consumer(Q chan int32, sumChan chan int32) {
	var wg sync.WaitGroup
	for i := 0; i < int(consumerLimit); i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			var sum int32
			for a := range Q {
				sum += a
			}
			sumChan <- sum
		}()
	}
	wg.Wait()
	close(sumChan)
}

func main() {
	Q := make(chan int32, QSize)
	sumChan := make(chan int32)

	go producer(Q)
	go consumer(Q, sumChan)

	var res int32
	for sum := range sumChan {
		res += sum
	}
	fmt.Println(res, sum)
}
