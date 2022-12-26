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

	var n, m, b int
	fmt.Fscan(in, &n, &m, &b)
	a := make([]int, n)
	c := make([]int, m)
	aSum, cSum := 0, 0
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		aSum += a[i]
	}
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &c[i])
		cSum += c[i]
	}

	ans := aSum*m + cSum*n + b*m*n
	fmt.Fprintln(out, ans)
}
