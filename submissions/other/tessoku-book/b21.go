package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxInt(a []int) int {
	sort.Sort(sort.IntSlice(a))
	return a[len(a)-1]
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int
	var s string
	fmt.Fscan(in, &n, &s)

	dp := make([][]int, n+5)
	for i := 0; i < n+5; i++ {
		dp[i] = make([]int, n+5)
	}

	for i := 0; i < n; i++ {
		dp[i][i] = 1
	}
	for i := 0; i < n-1; i++ {
		if s[i] == s[i+1] {
			dp[i][i+1] = 2
		} else {
			dp[i][i+1] = 1
		}
	}

	for len := 2; len <= n-1; len++ {
		for l := 0; l < n-len; l++ {
			r := l + len

			if s[l] == s[r] {
				dp[l][r] = maxInt([]int{dp[l][r-1], dp[l+1][r], dp[l+1][r-1] + 2})
			} else {
				dp[l][r] = maxInt([]int{dp[l][r-1], dp[l+1][r]})
			}
		}
	}

	fmt.Fprintln(out, dp[0][n-1])
}
