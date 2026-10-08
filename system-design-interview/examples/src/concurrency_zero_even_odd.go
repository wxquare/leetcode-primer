package main

import (
	"fmt"
	"sync"
)

func main() {
	chanOdd := make(chan int)
	chanEven := make(chan int)
	chanZero := make(chan int, 1)

	var wg sync.WaitGroup
	wg.Add(3)

	go func() {
		defer wg.Done()
		for {
			if a, ok := <-chanOdd; !ok {
				break
			} else {
				fmt.Print(a)
			}
			chanZero <- 1
		}
	}()

	go func() {
		defer wg.Done()
		for {
			if a, ok := <-chanEven; !ok {
				break
			} else {
				fmt.Print(a)
			}
			chanZero <- 1
		}
	}()

	go func() {
		defer wg.Done()
		for i := 1; i <= 10; i++ {
			<-chanZero
			fmt.Print(0)
			if i%2 == 0 {
				chanEven <- i
			} else {
				chanOdd <- i
			}
		}
		<-chanZero
		close(chanEven)
		close(chanOdd)
	}()
	chanZero <- 1
	wg.Wait()
}
