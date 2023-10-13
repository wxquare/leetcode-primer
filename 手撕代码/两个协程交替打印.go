package main

import (
	"fmt"
	"sync"
)

func main() {
	wg := sync.WaitGroup{}
	c1 := make(chan int, 1)
	c2 := make(chan int)
	wg.Add(1)
	go func() {
		defer wg.Done()
		for i := 0; i < 10; i++ {
			<-c1
			fmt.Println(i, "A")
			c2 <- 1
		}
	}()

	wg.Add(1)
	go func() {
		defer wg.Done()
		for i := 0; i < 10; i++ {
			<-c2
			fmt.Println(i, "B")
			c1 <- 1
		}
	}()

	c1 <- 1
	wg.Wait()
	close(c1)
	close(c2)
}
