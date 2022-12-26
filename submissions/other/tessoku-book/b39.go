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

	var n, d int
	fmt.Fscan(in, &n, &d)
	x := make([]int, n)
	y := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &x[i], &y[i])
	}
	done := make([]bool, n)
	ans := 0
	for i := 1; i <= d; i++ {
		idx := -1
		deal := 0
		for j := 0; j < n; j++ {
			if x[j] <= i && !done[j] {
				if deal < y[j] {
					idx, deal = j, y[j]
				}
			}
		}
		if idx >= 0 {
			ans += deal
			done[idx] = true
		}
	}
	fmt.Fprintln(out, ans)
}
