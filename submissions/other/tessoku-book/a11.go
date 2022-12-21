package main

import (
	"bufio"
	"fmt"
	"os"
)

func binarySearch(array []int, target int) (bool, int) {
	low, high, mid := 0, len(array)-1, 0
	for low <= high {
		mid = (low + high) / 2
		switch {
		case target < array[mid]:
			high = mid - 1
		case target == array[mid]:
			return true, mid
		case target > array[mid]:
			low = mid + 1
		}
	}
	return false, -1
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n, x int
	fmt.Fscan(in, &n, &x)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	_, idx := binarySearch(a,x)
	fmt.Fprintln(out, idx+1)
}
