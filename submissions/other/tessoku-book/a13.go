package main

import (
	"bufio"
	"fmt"
	"os"
)

func shakutoriSearch(array []int, target int) int {
	ans := 0
	lowIdx, highIdx := 0, 0
	for lowIdx < len(array) && highIdx < len(array) {
		if array[highIdx]-array[lowIdx] <= target {
			ans += highIdx - lowIdx
			highIdx++
		} else {
			lowIdx++
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
