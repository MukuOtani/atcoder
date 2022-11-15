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

	var n, q int
	c := 1500
	fmt.Fscan(in, &n)
	p := make([][]int, c+1)
	for i := 0; i <= c; i++ {
		p[i] = make([]int, c+1)
	}
	for i := 0; i < n; i++ {
		var x, y int
		fmt.Fscan(in, &x, &y)
		p[x][y]++
	}

	for i := 1; i <= c; i++ {
		for j := 1; j <= c; j++ {
			p[i][j] += p[i][j-1]
		}
		for j := 1; j <= c; j++ {
			p[i][j] += p[i-1][j]
		}
	}

	fmt.Fscan(in, &q)
	for i := 0; i < q; i++ {
		var a, b, c, d int
		fmt.Fscan(in, &a, &b, &c, &d)
		fmt.Fprintln(out, p[c][d]+p[a-1][b-1]-p[a-1][d]-p[c][b-1])
	}
}
