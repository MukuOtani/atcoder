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

	var d, n int
	fmt.Fscan(in, &d, &n)
	a := make([]int, d+1)
	for i := 0; i < n; i++ {
		var l, r int
		fmt.Fscan(in, &l, &r)
		a[l-1]++
		a[r]--
	}
	for i := 1; i < d; i++ {
		a[i] += a[i-1]
	}
	for i := 0; i < d; i++ {
		fmt.Fprintln(out, a[i])
	}
}
