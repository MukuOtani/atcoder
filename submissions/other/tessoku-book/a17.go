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
	h := make([]int, n)
	dp[0] = 0
	h[0] = 0
	for i := 1; i < n; i++ {
		dp[i] = dp[i-1] + a[i]
		h[i] = i - 1
		if i > 1 && dp[i] > dp[i-2]+b[i] {
			dp[i] = dp[i-2] + b[i]
			h[i] = i - 2
		}
	}
	ans := []int{}
	last := n - 1
	ans = append(ans, n)
	for last != 0 {
		ans = append(ans, h[last]+1)
		last = h[last]
	}
	fmt.Fprintln(out, len(ans))
	for i := 0; i < len(ans); i++ {
		fmt.Fprint(out, ans[len(ans)-i-1])
		fmt.Fprint(out, " ")
	}
	fmt.Fprintln(out, "")
}
