package main

import (
	"bufio"
	"fmt"
	"os"
)

func max(a,b int) int {
	if a>b {
		return a
	}
	return b
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n, w int
	fmt.Fscan(in, &n, &w)
	a := make([]int, n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i], &b[i])
	}

	dp := make([][]int, n+5)
	for i := 0; i < n+5; i++ {
		dp[i] = make([]int, w+5)
	}
	for i := 1; i <= n; i++ {
		for j := 0; j <= w; j++ {
			dp[i][j] = dp[i-1][j]
			if(j-a[i-1]>=0){
				dp[i][j] = max(dp[i][j], dp[i-1][j-a[i-1]]+b[i-1])
			}
		}
	}
	ans := 0
	for i := 0; i <= w; i++ {
		ans = max(ans, dp[n][i])
	}
	fmt.Fprintln(out, ans)
}
