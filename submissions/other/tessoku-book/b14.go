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
	a := make([]int, n/2)
	for i := 0; i < n/2; i++ {
		fmt.Fscan(in, &a[i])
	}
	b := make([]int, n-n/2)
	for i := 0; i < n-n/2; i++ {
		fmt.Fscan(in, &b[i])
	}

	p := make([]int, 1<<len(a))
	q := make([]int, 1<<len(b))
	for i := 0; i < (1 << len(a)); i++ {
		sum := 0
		for j := 0; j < len(a); j++ {
			keta := 1 << j
			if (i/keta)%2 == 1 {
				sum += a[j]
			}
		}
		p[i] = sum
	}
	for i := 0; i < (1 << len(b)); i++ {
		sum := 0
		for j := 0; j < len(b); j++ {
			keta := 1 << j
			if (i/keta)%2 == 1 {
				sum += b[j]
			}
		}
		q[i] = sum
	}

	sort.Ints(p)
	for i := 0; i < len(q); i++ {
		target := k - q[i]
		judge, _ := binarySearch(p, target)
		if judge {
			fmt.Fprintln(out, "Yes")
			return
		}
	}
	fmt.Fprintln(out, "No")
	return
}
