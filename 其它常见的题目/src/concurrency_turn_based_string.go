package main

import (
	"fmt"
	"sync"
)

func main() {
	c3 := make(chan int)
	c5 := make(chan int)
	c35 := make(chan int)
	c := make(chan int)
	ready := make(chan int, 1)

	var wg sync.WaitGroup

	wg.Add(5)
	go func() {
		defer wg.Done()
		for {
			if _, ok := <-c3; !ok {
				return
			} else {
				fmt.Print("bzz")
				ready <- 1
			}
		}
	}()

	go func() {
		defer wg.Done()
		for {
			if _, ok := <-c5; !ok {
				return
			} else {
				fmt.Print("foo")
				ready <- 1
			}
		}
	}()

	go func() {
		defer wg.Done()
		for {
			if _, ok := <-c35; !ok {
				return
			} else {
				fmt.Print("foobzz")
				ready <- 1
			}
		}
	}()

	go func() {
		defer wg.Done()
		for {
			if i, ok := <-c; !ok {
				return
			} else {
				fmt.Print(i)
				ready <- 1
			}
		}
	}()

	go func() {
		defer wg.Done()
		for i := 0; i < 10; i++ {
			<-ready
			if i%3 == 0 && i%5 == 0 {
				c35 <- i
			} else if i%3 == 0 {
				c3 <- i
			} else if i%5 == 0 {
				c5 <- i
			} else {
				c <- i
			}
		}
		<-ready
		close(c3)
		close(c5)
		close(c35)
		close(c)
		close(ready)
	}()
	ready <- 1
	wg.Wait()
}
