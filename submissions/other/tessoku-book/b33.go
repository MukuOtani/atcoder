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

	var n, h, w int
	fmt.Fscan(in, &n, &h, &w)

	ans := 0
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Fscan(in, &a, &b)
		ans ^= a - 1
		ans ^= b - 1
	}
	if ans != 0 {
		fmt.Fprintln(out, "First")
	} else {
		fmt.Fprintln(out, "Second")
	}

}
