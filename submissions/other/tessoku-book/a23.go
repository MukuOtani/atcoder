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

	var n, m int
	fmt.Fscan(in, &n, &m)
	a := make([][]int, m)
	for i := 0; i < m; i++ {
		a[i] = make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Fscan(in, &a[i][j])
		}
	}
	b := make([]int, m)
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			b[i] += a[i][j] << j
		}
	}

	dp := make([]int, (1<<n)+5)
	for i := 0; i < (1<<n)+5; i++ {
		dp[i] = 1000
	}
	dp[0] = 0

	for i := 0; i < m; i++ {
		for j := 0; j < (1 << n); j++ {
			dp[j|b[i]] = min(dp[j|b[i]], dp[j]+1)
		}
	}
	if dp[(1<<n)-1] == 1000 {
		fmt.Fprintln(out, -1)
	} else {
		fmt.Fprintln(out, dp[(1<<n)-1])
	}
}
