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
	a := make([]int, n-1)
	b := make([]int, n-1)
	for i := 0; i < n-1; i++ {
		fmt.Fscan(in, &a[i])
		a[i]--
	}
	for i := 0; i < n-1; i++ {
		fmt.Fscan(in, &b[i])
		b[i]--
	}

	dp := make([]int, n+5)
	for i := 0; i < n+5; i++ {
		dp[i] = -1000000000
	}
	dp[0] = 0

	for i := 0; i < n-1; i++ {
		dp[a[i]] = max(dp[a[i]], dp[i]+100)
		dp[b[i]] = max(dp[b[i]], dp[i]+150)
	}
	fmt.Fprintln(out, dp[n-1])
}
