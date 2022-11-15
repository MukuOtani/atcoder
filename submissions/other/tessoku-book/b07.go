package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var t, n int
	fmt.Fscan(in, &t, &n)
	a := make([]int, t+1)
	for i := 0; i < n; i++ {
		var l, r int
		fmt.Fscan(in, &l, &r)
		a[l]++
		a[r]--
	}
	for i := 1; i < t; i++ {
		a[i] += a[i-1]
	}
	for i := 0; i < t; i++ {
		fmt.Fprintln(out, a[i])
	}
}
