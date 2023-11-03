package main

import (
	"fmt"
	"math/rand"
	"sync"
)

// 10000 个数累计和
const count int32 = 10000

const producerCount int32 = 3
const consumerCount int32 = 4

var dataChan chan int32

var resChan chan int32

func init() {
	dataChan = make(chan int32, 10)
	resChan = make(chan int32, 2)
}

func produce() {
	var wg sync.WaitGroup
	a := count / producerCount
	b := count % producerCount
	for i := 0; i < int(producerCount); i++ {
		batch := a
		if i < int(b) {
			batch += 1
		}
		wg.Add(1)
		go func(x int32) {
			defer wg.Done()
			for j := 0; j < int(x); j++ {
				v := rand.Intn(10)
				dataChan <- int32(v)
			}
		}(batch)
	}
	wg.Wait()
	close(dataChan)
}

func consumer() {
	var wg sync.WaitGroup
	for i := 0; i < int(consumerCount); i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			var sum int32 = 0
			for {
				if d, ok := <-dataChan; ok {
					sum = sum + d
				} else {
					break
				}
			}
			resChan <- sum
		}()
	}
	wg.Wait()
	close(resChan)
}

func main() {
	go produce()
	go consumer()
	var ans int32 = 0
	for s := range resChan {
		ans = ans + s
	}
	fmt.Println(ans)
}
