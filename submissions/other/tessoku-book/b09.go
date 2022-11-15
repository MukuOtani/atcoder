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

	var n int
	c := 1500
	fmt.Fscan(in, &n)
	x := make([][]int, c+2)
	for i := 0; i <= c+1; i++ {
		x[i] = make([]int, c+2)
	}
	for i := 0; i < n; i++ {
		var a, b, c, d int
		fmt.Fscan(in, &a, &b, &c, &d)
		x[a][b]++
		x[c][d]++
		x[a][d]--
		x[c][b]--
	}

	for i := 0; i < c; i++ {
		for j := 0; j < c; j++ {
			x[i][j+1] += x[i][j]
		}
	}

	for i := 0; i < c; i++ {
		for j := 0; j < c; j++ {
			x[i+1][j] += x[i][j]
		}
	}

	ans := 0
	for i := 0; i < c; i++ {
		for j := 0; j < c; j++ {
			if x[i][j] > 0 {
				ans++
			}
		}
	}
	fmt.Fprintln(out, ans)
}
