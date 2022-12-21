package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

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
	l := make([]int, n+5)
	dp[0] = 0
	for i := 1; i < n; i++ {
		dp[i] = dp[i-1]+int(math.Abs(float64(h[i]-h[i-1])))
		l[i] = i-1
		if i > 1 &&  dp[i] > dp[i-2]+int(math.Abs(float64(h[i]-h[i-2]))){
			dp[i] = dp[i-2]+int(math.Abs(float64(h[i]-h[i-2])))
			l[i] = i-2
		}
	}
	ans := []int{}
	last := n - 1
	ans = append(ans, n)
	for last != 0 {
		ans = append(ans, l[last]+1)
		last = l[last]
	}
	fmt.Fprintln(out, len(ans))
	for i := 0; i < len(ans); i++ {
		fmt.Fprint(out, ans[len(ans)-i-1])
		fmt.Fprint(out, " ")
	}
	fmt.Fprintln(out, "")
}
