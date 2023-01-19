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
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	c := make([]int, 100)
	ans := 0
	for i := 0; i < n; i++ {
		ans += c[(100-a[i]%100)%100]
		c[a[i]%100]++
	}

	fmt.Fprintln(out, ans)
}
