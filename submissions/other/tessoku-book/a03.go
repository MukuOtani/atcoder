package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var n, k int
	fmt.Fscan(r, &n, &k)
	p,q := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &p[i])
		
	}
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &q[i])
		
	}
	for _, a := range p {
		for _, b := range q {
			// fmt.Println(a, b)
			if a+b==k{
				fmt.Fprintln(w, "Yes")
				return
			}
		}
	}
	fmt.Fprintln(w, "No")
}
