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
	fmt.Fscan(in, &n)
	a := make([]int, n+1)
	a[0] = 0
	for i := 1; i <= n; i++ {
		fmt.Fscan(in, &a[i])
		a[i] += a[i-1]
	}

	fmt.Fscan(in, &q)
	for i := 0; i < q; i++ {
		var l, r int
		fmt.Fscan(in, &l, &r)
		ok := a[r] - a[l-1]
		ng := r - l + 1 - ok
		if ok > ng {
			fmt.Fprintln(out, "win")
		} else if ok == ng {
			fmt.Fprintln(out, "draw")
		} else {
			fmt.Fprintln(out, "lose")
		}
	}
}
