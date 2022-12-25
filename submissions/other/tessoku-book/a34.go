package main

import (
	"bufio"
	"fmt"
	"os"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n, x, y int
	fmt.Fscan(in, &n, &x, &y)
	maxNum := 0
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		maxNum = max(maxNum, a[i])
	}

	grundy := make([]int, maxNum+1)
	for i := 0; i <= maxNum; i++ {
		transit := [3]bool{false, false, false}
		if i >= x {
			transit[grundy[i-x]] = true
		}
		if i >= y {
			transit[grundy[i-y]] = true
		}
		if transit[0] == false {
			grundy[i] = 0
		} else if transit[1] == false {
			grundy[i] = 1
		} else {
			grundy[i] = 2
		}
	}
	xorSum := 0
	for i := 0; i < n; i++ {
		xorSum ^= grundy[a[i]]
	}
	if xorSum != 0 {
		fmt.Fprintln(out, "First")
	} else {
		fmt.Fprintln(out, "Second")
	}
}
