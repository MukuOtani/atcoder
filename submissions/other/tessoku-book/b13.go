package main

import (
	"bufio"
	"fmt"
	"os"
)

func shakutoriSearch(array []int, target int) int {
	ans, sum := 0, 0
	lowIdx, highIdx := 0, 0
	sum += array[lowIdx]
	for lowIdx < len(array) && highIdx < len(array) {
		if sum <= target {
			ans += highIdx - lowIdx + 1
			highIdx++
			if highIdx < len(array) {
				sum += array[highIdx]
			}
		} else {
			lowIdx++
			if lowIdx < len(array) {
				sum -= array[lowIdx-1]
			}
		}
	}
	return ans
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n, k int
	fmt.Fscan(in, &n, &k)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	ans := shakutoriSearch(a, k)
	fmt.Fprintln(out, ans)
}
