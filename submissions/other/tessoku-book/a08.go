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

	var h, w int
	fmt.Fscan(in, &h, &w)
	x := make([][]int, h+1)
	for i := 0; i <= h; i++ {
		x[i] = make([]int, w+1)
	}
	for i := 1; i <= h; i++ {
		for j := 1; j <= w; j++ {
			fmt.Fscan(in, &x[i][j])
		}
	}

	for i := 1; i <= h; i++ {
		for j := 1; j <= w; j++ {
			x[i][j] += x[i][j-1]
		}
		for j := 1; j <= w; j++ {
			x[i][j] += x[i-1][j]
		}
	}

	var q int
	fmt.Fscan(in, &q)
	for i := 0; i < q; i++ {
		var a, b, c, d int
		fmt.Fscan(in, &a, &b, &c, &d)
		fmt.Fprintln(out, x[c][d]+x[a-1][b-1]-x[a-1][d]-x[c][b-1])
	}
}
