package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func LowerBound(array []int, target int) int {
	low, high, mid := 0, len(array)-1, 0
	for low <= high {
		mid = (low + high) / 2
		if array[mid] >= target {
			high = mid - 1
		} else {
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
	sort.Ints(a)

	var q int
	fmt.Fscan(in, &q)
	for i := 0; i < q; i++ {
		var x int
		fmt.Fscan(in, &x)
		fmt.Fprintln(out, LowerBound(a, x))
	}
}
