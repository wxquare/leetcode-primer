package main

import (
	"fmt"
	"sync"
)

func main() {
	chanOdd := make(chan int32)
	chanEven := make(chan int32)
	chanZero := make(chan int32, 1)

	var wg sync.WaitGroup
	wg.Add(3)
	go func() {
		defer wg.Done()
		for i := 1; i <= 2; i++ {
			<-chanZero
			fmt.Println("0")
			if i%2 == 0 {
				chanEven <- 1
			} else {
				chanOdd <- 1
			}
		}
	}()

	go func() {
		defer wg.Done()
		for i := 1; i <= 2; i += 2 {
			<-chanOdd
			fmt.Println(i)
			chanZero <- 1
		}
	}()

	go func() {
		defer wg.Done()
		for i := 2; i <= 2; i += 2 {
			<-chanEven
			fmt.Println(i)
			chanZero <- 1
		}
	}()
	chanZero <- 1
	wg.Wait()
}
