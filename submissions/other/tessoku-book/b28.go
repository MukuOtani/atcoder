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
	fmt.Fscan(in, &n)
	a := make([]int, n+5)

	a[1] = 1
	a[2] = 1

	for i := 3; i <= n; i++ {
		a[i] = (a[i-1] + a[i-2]) % (1e9 + 7)
	}

	fmt.Fprintln(out, a[n])
}
