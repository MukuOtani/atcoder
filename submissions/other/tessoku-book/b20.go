package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func maxInt(a []int) int {
	sort.Sort(sort.IntSlice(a))
	return a[len(a)-1]
}

func minInt(a []int) int {
	sort.Sort(sort.IntSlice(a))
	return a[0]
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var s, t string
	fmt.Fscan(in, &s, &t)
	ls, lt := len(s), len(t)

	dp := make([][]int, ls+5)
	for i := 0; i < ls+5; i++ {
		dp[i] = make([]int, lt+5)
	}
	for i := 0; i <= ls; i++ {
		for j := 0; j <= lt; j++ {
			if i >= 1 && j >= 1 && s[i-1] == t[j-1] {
				dp[i][j] = minInt([]int{dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1]})
			} else if i >= 1 && j >= 1 {
				dp[i][j] = minInt([]int{dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1})
			} else if i >= 1 {
				dp[i][j] = dp[i-1][j] + 1
			} else if j >= 1 {
				dp[i][j] = dp[i][j-1] + 1
			}
		}
	}
	fmt.Fprintln(out, dp[ls][lt])
}
