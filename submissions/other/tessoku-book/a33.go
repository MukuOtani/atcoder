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

	ans := 0
	for i := 0; i < n; i++ {
		var a int
		fmt.Fscan(in, &a)
		if i == 0 {
			ans = a
		} else {
			ans ^= a
		}
	}
	if ans != 0 {
		fmt.Fprintln(out, "First")
	} else {
		fmt.Fprintln(out, "Second")
	}

}
