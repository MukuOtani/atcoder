package main

import (
	"bufio"
	"fmt"
	"os"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func binarySearch(array []int, target int) int {
	low, high, mid := 0, len(array)-1, 0
	for low < high {
		mid = (low + high) / 2
		switch {
		case target <= array[mid]:
			high = mid
		case target > array[mid]:
			low = mid + 1
		}
	}
	return low
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	var dp []int

	for i := 0; i < n; i++ {
		if len(dp) == 0 || dp[len(dp)-1] < a[i] {
			dp = append(dp, a[i])
		} else {
			idx := binarySearch(dp, a[i])
			dp[idx] = min(dp[idx], a[i])
		}
	}
	fmt.Fprintln(out, len(dp))
}
