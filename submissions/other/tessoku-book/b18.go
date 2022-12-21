package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n, s int
	fmt.Fscan(in, &n, &s)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	dp := make([][]bool, n+5)
	for i := 0; i < n+5; i++ {
		dp[i] = make([]bool, s+5)
	}
	dp[0][0] = true
	for i := 1; i <= n; i++ {
		for j := 0; j <= s; j++ {
			dp[i][j] = dp[i][j] || dp[i-1][j]
			if dp[i-1][j] && j+a[i-1] <= s {
				dp[i][j+a[i-1]] = true
			}
		}
	}
	if !dp[n][s] {
		fmt.Fprintln(out, -1)
		return
	}

	sum := s
	cards := []int{}
	for i := n - 1; i >= 0; i-- {
		if sum-a[i] >= 0 && dp[i][sum-a[i]] {
			sum -= a[i]
			cards = append(cards, i+1)
		}
	}

	fmt.Fprintln(out, len(cards))
	for i := len(cards) - 1; i >= 0; i-- {
		fmt.Fprint(out, cards[i])
		fmt.Fprint(out, " ")
	}
	fmt.Fprintln(out, "")
}
