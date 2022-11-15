package main

import (
	"bufio"
	"fmt"
	"os"
)

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n, d int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	l, r := make([]int, n+1), make([]int, n+1)
	l[0] = a[0]
	r[n-1] = a[n-1]
	for i := 0; i < n-1; i++ {
		l[i+1] = max(a[i+1], l[i])
	}
	for i := n - 1; i > 0; i-- {
		r[i-1] = max(a[i-1], r[i])
	}
	fmt.Fscan(in, &d)
	for i := 0; i < d; i++ {
		var a, b int
		fmt.Fscan(in, &a, &b)
		// fmt.Fprintln(out, l[a-2], r[b])
		fmt.Fprintln(out, max(l[a-2], r[b]))
	}
}
