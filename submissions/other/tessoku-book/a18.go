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

	dp := make([]bool, s+5)
	dp[0] = true

	for i := 0; i < n; i++ {
		for j := s - a[i]; j >= 0; j-- {
			if dp[j] {
				dp[j+a[i]] = true
			}
		}
	}
	if dp[s] {
		fmt.Fprintln(out, "Yes")
		return
	}
	fmt.Fprintln(out, "No")
}
