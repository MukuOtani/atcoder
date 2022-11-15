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

	var h, w, n int
	fmt.Fscan(in, &h, &w, &n)
	x := make([][]int, h+2)
	for i := 0; i <= h+1; i++ {
		x[i] = make([]int, w+2)
	}
	for i := 0; i < n; i++ {
		var a, b, c, d int
		fmt.Fscan(in, &a, &b, &c, &d)
		x[a][b]++
		x[c+1][d+1]++
		x[a][d+1]--
		x[c+1][b]--
	}

	for i := 1; i <= h; i++ {
		for j := 1; j <= w; j++ {
			x[i][j] += x[i][j-1]
		}
		for j := 1; j <= w; j++ {
			x[i][j] += x[i-1][j]
		}
	}

	for i := 1; i <= h; i++ {
		for j := 1; j <= w; j++ {
			fmt.Print(x[i][j])
			if j == w {
				fmt.Print("\n")
			} else {
				fmt.Print(" ")
			}
		}
	}
}
