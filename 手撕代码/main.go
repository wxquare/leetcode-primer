package main

import "fmt"

func main() {
	s := "abc"
	for i, c := range s {
		fmt.Printf("%d,%c\n", i, c)
	}

	for i := range s {
		fmt.Printf("%d\n", i)
	}
}
