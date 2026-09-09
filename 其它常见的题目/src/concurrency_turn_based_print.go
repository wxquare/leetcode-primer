package main

import (
	"fmt"
	"sync"
)

func main() {
	c1 := make(chan int)
	c2 := make(chan int)
	var wg sync.WaitGroup
	wg.Add(1)
	go func() {
		defer wg.Done()
		for i := 0; i < 10; i++ {
			<-c1
			fmt.Printf("%s", "A")
			c2 <- 1
		}
		<-c1
		close(c2)
		close(c1)
	}()

	wg.Add(1)
	go func() {
		defer wg.Done()
		for {
			if _, ok := <-c2; ok {
				fmt.Printf("%s", "B")
				c1 <- 1
			} else {
				break
			}
		}
	}()
	c1 <- 1
	wg.Wait()
}
