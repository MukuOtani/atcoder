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
	fmt.Fscan(in, &n)
	p := make([]int, n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &p[i], &a[i])
	}
	for i := 0; i < n; i++ {
		p[i]--
	}

	dp := make([][]int, n+5)
	for i := 0; i < n+5; i++ {
		dp[i] = make([]int, n+5)
	}

	for len := n - 2; len >= 0; len-- {
		for l := 0; l < n-len; l++ {
			r := l + len

			scoreL, scoreR := 0, 0
			if l >= 1 && l <= p[l-1] && p[l-1] <= r {
				scoreL = a[l-1]
			}
			if r < n-1 && l <= p[r+1] && p[r+1] <= r {
				scoreR = a[r+1]
			}

			if l >= 1 && r < n-1 {
				dp[l][r] = max(dp[l-1][r]+scoreL, dp[l][r+1]+scoreR)
			} else if l >= 1 {
				dp[l][r] = dp[l-1][r] + scoreL
			} else if r < n-1 {
				dp[l][r] = dp[l][r+1] + scoreR
			}
		}
	}
	ans := 0
	for i := 0; i < n; i++ {
		ans = max(ans, dp[i][i])
	}
	fmt.Fprintln(out, ans)
}
