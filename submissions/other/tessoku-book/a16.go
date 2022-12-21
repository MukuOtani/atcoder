package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func chmin(a, b int) int {
	if a <= b {
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

	for i := 0; i < n; i++ {
		if i == 0 {
			continue
		}
		fmt.Fscan(in, &a[i])
	}
	for i := 0; i < n; i++ {
		if i < 2 {
			continue
		}
		fmt.Fscan(in, &b[i])
	}

	dp := make([]int, n)
	dp[0] = 0
	for i := 1; i < n; i++ {
		dp[i] = math.MaxInt32
		dp[i] = chmin(dp[i], dp[i-1]+a[i])
		if i > 1 {
			dp[i] = chmin(dp[i], dp[i-2]+b[i])
		}
	}
	fmt.Fprintln(out, dp[n-1])
}
