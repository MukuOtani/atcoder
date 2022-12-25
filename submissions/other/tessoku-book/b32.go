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

	var n, k int
	fmt.Fscan(in, &n, &k)

	a := make([]int, k)
	for i := 0; i < k; i++ {
		fmt.Fscan(in, &a[i])
	}

	dp := make([]bool, n+5)
	for i := 0; i <= n; i++ {
		dp[i] = false
		for j := 0; j < k; j++ {
			if i >= a[j] && dp[i-a[j]] == false {
				dp[i] = true
			}
		}
	}
	if dp[n] {
		fmt.Fprintln(out, "First")
	} else {
		fmt.Fprintln(out, "Second")
	}

}
