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

	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		dp[n-1][i] = a[i]
	}

	for i := n - 2; i >= 0; i-- {
		for j := 0; j <= i; j++ {
			if i%2 == 0 {
				dp[i][j] = Max(dp[i+1][j], dp[i+1][j+1])
			} else {
				dp[i][j] = Min(dp[i+1][j], dp[i+1][j+1])
			}
		}
	}
	fmt.Fprintln(out, dp[0][0])
}
