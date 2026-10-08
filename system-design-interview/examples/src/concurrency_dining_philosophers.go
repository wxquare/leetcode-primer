package main

import (
	"fmt"
	"sync"
	"time"
)

var philoCnt int = 5

var thinking = 1
var hungry = 2
var eating = 3

func getLeft(i int) int {
	return (philoCnt + i - 1) % int(philoCnt)
}

func getRight(i int) int {
	return (philoCnt + i + 1) % int(philoCnt)
}

func main() {
	var mutex sync.Mutex
	state := make([]int, philoCnt)
	philoMutexs := make([]sync.Mutex, philoCnt)

	for i := 0; i < int(philoCnt); i++ {
		philoMutexs[i].Lock()
	}

	check := func(x int) {
		if state[x] == hungry && state[getLeft(x)] != eating && state[getRight(x)] != eating {
			state[x] = eating
			philoMutexs[x].Unlock()
		}
	}

	getForks := func(x int) {
		mutex.Lock()
		state[x] = hungry
		check(x)
		mutex.Unlock()
		philoMutexs[x].Lock()
	}

	putForks := func(x int) {
		mutex.Lock()
		state[x] = thinking
		check(getLeft(x))
		check(getRight(x))
		mutex.Unlock()
	}

	for i := 0; i < int(philoCnt); i++ {
		go func(x int) {
			for {
				time.Sleep(1 * time.Second) //thinking
				getForks(x)
				time.Sleep(1 * time.Second)
				putForks(x)
			}
		}(i)
	}
	// print running state
	for {
		mutex.Lock()
		fmt.Println(state)
		mutex.Unlock()
		time.Sleep(2 * time.Second)
	}
}
