package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Box struct {
	X int
	Y int
}

func (b Box) isBiggerThan(c Box) bool {
	return ((b.X > c.X) && (b.Y > c.Y))
}

func lower_bound(L []Box, target int) int {
	min, max, mid := 0, len(L)-1, 0
	for min <= max {
		mid = (max-min)/2 + min
		if L[mid].Y >= target {
			max = mid - 1
		} else {
			min = mid + 1
		}
	}
	return mid
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	b := make([]Box, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &b[i].X, &b[i].Y)
	}
	sort.Slice(b, func(i, j int) bool {
		if b[i].X == b[j].X {
			return b[i].Y > b[j].Y
		}
		return b[i].X < b[j].X
	})

	var dp []Box
	dp = append(dp, b[0])

	for i := 1; i < n; i++ {
		idx := lower_bound(dp, b[i].Y)
		if b[i].isBiggerThan(dp[idx]) {
			idx++
		}
		if idx >= len(dp) {
			dp = append(dp, b[i])
		} else {
			dp[idx] = b[i]
		}
	}
	fmt.Fprintln(out, len(dp))
}
