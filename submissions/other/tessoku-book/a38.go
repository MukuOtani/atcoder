package main

import (
	"bufio"
	"fmt"
	"os"
)

func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var d, n int
	fmt.Fscan(in, &d, &n)
	w := make([]int, d)
	for i := 0; i < d; i++ {
		w[i] = 24
	}
	for i := 0; i < n; i++ {
		var l, r, h int
		fmt.Fscan(in, &l, &r, &h)
		for j := l - 1; j < r; j++ {
			w[j] = Min(w[j], h)
		}
	}
	ans := 0
	for i := 0; i < d; i++ {
		ans += w[i]
	}
	fmt.Fprintln(out, ans)
}
