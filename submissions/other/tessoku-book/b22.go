package main

import (
	"bufio"
	"fmt"
	"os"
)

func min(a, b int) int {
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
	b := make([]int, n)
	for i := 0; i < n-1; i++ {
		fmt.Fscan(in, &a[i])
	}
	for i := 0; i < n-2; i++ {
		fmt.Fscan(in, &b[i])
	}

	dp := make([]int, n+5)
	for i := 0; i < n+5; i++ {
		dp[i] = 1000000000
	}
	dp[0] = 0

	for i := 0; i < n-1; i++ {
		dp[i+1] = min(dp[i+1], dp[i]+a[i])
		if i < n-2 {
			dp[i+2] = min(dp[i+2], dp[i]+b[i])
		}
	}
	fmt.Fprintln(out, dp[n-1])
}
