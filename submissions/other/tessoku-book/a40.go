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

	c := map[int]int{}
	for i := 0; i < n; i++ {
		if _, ok := c[a[i]]; !ok {
			c[a[i]] = 1
		} else {
			c[a[i]]++
		}
	}

	ans := 0
	for _, v := range c {
		ans += v * (v - 1) * (v - 2) / 6
	}

	fmt.Fprintln(out, ans)
}
