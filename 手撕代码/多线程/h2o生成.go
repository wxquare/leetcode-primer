package main

import (
	"fmt"
	"sync"
)

func main() {
	hc := make(chan int, 2)
	oc := make(chan int, 2)

	var wg sync.WaitGroup
	wg.Add(2)
	go func() {
		defer wg.Done()
		for {
			select {
			case _, ok := <-hc:
				if !ok {
					return
				}
				fmt.Print("H")
				oc <- 1
			}
		}
	}()

	go func() {
		defer wg.Done()
		for i := 0; i < 10; i++ {
			hc <- 1
			hc <- 1
			<-oc
			fmt.Println("o")
			<-oc
		}
		close(hc)
		close(oc)
	}()

	wg.Wait()
}
