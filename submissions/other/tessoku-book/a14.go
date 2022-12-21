package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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

	var n, k int
	fmt.Fscan(in, &n, &k)
	a := make([]int, n)
	b := make([]int, n)
	c := make([]int, n)
	d := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &b[i])
	}
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &c[i])
	}
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &d[i])
	}
	p := make([]int, n*n)
	q := make([]int, n*n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			p[i*n+j] = a[i] + b[j]
			q[i*n+j] = c[i] + d[j]
		}
	}
	sort.Ints(q)
	for i := 0; i < len(p); i++ {
		target := k - p[i]
		judge, _ := binarySearch(q, target)
		if judge {
			fmt.Fprintln(out, "Yes")
			return
		}
	}
	fmt.Fprintln(out, "No")
	return
}
