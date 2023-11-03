package main

import (
	"fmt"
	"sync"
)

var c1 chan int
var c2 chan int

func f1(wg *sync.WaitGroup) {
	defer wg.Done()
	for i := 0; i < 10; i++ {
		<-c1
		fmt.Printf("%d,", 1)
		c2 <- 1
	}
	<-c1
	fmt.Printf("\n")
	close(c2)
	close(c1)
}

func f2(wg *sync.WaitGroup) {
	defer wg.Done()
	for {
		if _, ok := <-c2; ok {
			fmt.Printf("%d,", 2)
			c1 <- 1
		} else {
			break
		}
	}
}

func main() {
	c1 = make(chan int)
	c2 = make(chan int)
	var wg sync.WaitGroup
	wg.Add(2)

	go f1(&wg)
	go f2(&wg)

	go func() {
		c1 <- 1
	}()
	wg.Wait()
}
