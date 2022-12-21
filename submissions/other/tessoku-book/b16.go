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
	h := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Fscan(in, &h[i])
	}

	dp := make([]int, n+5)
	dp[0] = 0
	for i := 1; i < n; i++ {
		dp[i] = math.MaxInt32
		dp[i] = chmin(dp[i], dp[i-1]+int(math.Abs(float64(h[i]-h[i-1]))))
		if i > 1 {
			dp[i] = chmin(dp[i], dp[i-2]+int(math.Abs(float64(h[i]-h[i-2]))))
		}
	}
	fmt.Fprintln(out, dp[n-1])
}
