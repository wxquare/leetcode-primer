package main

import (
	"fmt"
	"sync"
)
var c1 chan int 
var c2 chan int

func foo(wg *sync.WaitGroup) {
	wg.Add(1)
	defer wg.Done()
	for i := 0; i < 5; i++ {
		<-c1
		fmt.Println("foo()")
		if i == 4{
			close(c2)
		} else {
			c2 <- 1
		}
	}
}
func bar(wg *sync.WaitGroup) {
	wg.Add(1)
	defer wg.Done()
	for i := 0; i < 5; i++ {
		<-c2
		fmt.Println("bar()")
		if i == 4{
			close(c1)
		} else {
			c1 <- 1
		}
	}
}

func main() {
	var wg sync.WaitGroup
	c1 = make(chan int)
	c2 = make(chan int)
	go foo(&wg)
	c1<-1
	go bar(&wg)
	wg.Wait()
}
