package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n, w, v int
	fmt.Fscan(in, &n, &w)
	v = n * 1000
	a := make([]int, n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i], &b[i])
	}

	dp := make([][]int, n+5)
	for i := 0; i < n+5; i++ {
		dp[i] = make([]int, v+5)
	}
	for i := 0; i < n+5; i++ {
		for j := 0; j < v+5; j++ {
			dp[i][j] = int(math.Pow(10, 11))
		}
	}
	dp[0][0] = 0

	for i := 1; i <= n; i++ {
		for j := 0; j <= v; j++ {
			if j-b[i-1] >= 0 {
				dp[i][j] = min(dp[i-1][j], dp[i-1][j-b[i-1]]+a[i-1])
			} else {
				dp[i][j] = dp[i-1][j]
			}
		}
	}
	ans := 0
	for i := 0; i <= v; i++ {
		if dp[n][i] <= w {
			ans = i
		}
	}
	fmt.Fprintln(out, ans)
}
