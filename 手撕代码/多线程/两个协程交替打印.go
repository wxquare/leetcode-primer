package main

import (
	"fmt"
	"sync"
)

func main() {
	wg := sync.WaitGroup{}
	c1 := make(chan int)
	c2 := make(chan int)
	wg.Add(1)
	go func() {
		defer wg.Done()
		for {
			if _, ok := <-c2; !ok {
				break
			}
			fmt.Print("B")
			c1 <- 1
		}

	}()

	wg.Add(1)
	go func() {
		defer wg.Done()
		for i := 0; i < 10; i++ {
			<-c1
			fmt.Print("A")
			c2 <- 1
		}
		<-c1
		close(c2)
		close(c1)
	}()
	go func() {
		c1 <- 1
	}()
	wg.Wait()
	fmt.Println()
}
