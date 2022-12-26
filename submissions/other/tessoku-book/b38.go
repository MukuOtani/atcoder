package main

import (
	"bufio"
	"fmt"
	"os"
)

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int
	var s string
	fmt.Fscan(in, &n, &s)

	h := make([]int, n)
	for i := 0; i < n; i++ {
		h[i] = 1
	}
	for i := 0; i < n-1; i++ {
		if s[i] == 'A' {
			h[i+1] = h[i] + 1
		}
	}
	for i := n - 2; i >= 0; i-- {
		if s[i] == 'B' {
			h[i] = Max(h[i+1]+1, h[i])
		}
	}
	ans := 0
	for i := 0; i < n; i++ {
		ans += h[i]
	}
	fmt.Fprintln(out, ans)
}
