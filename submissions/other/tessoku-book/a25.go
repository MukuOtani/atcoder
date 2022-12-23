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
	c := make([]string, h)
	for i := 0; i < h; i++ {
		fmt.Fscan(in, &c[i])
	}

	r := make([][]int, h)
	for i := 0; i < h; i++ {
		r[i] = make([]int, w)
	}
	r[0][0] = 1
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if c[i][j] == '#' {
				continue
			}
			if i != 0 && c[i-1][j] == '.' {
				r[i][j] += r[i-1][j]
			}
			if j != 0 && c[i][j-1] == '.' {
				r[i][j] += r[i][j-1]
			}
		}
	}
	fmt.Fprintln(out, r[h-1][w-1])
}
