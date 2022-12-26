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

	var n, k int
	var s string
	fmt.Fscan(in, &n, &k)
	fmt.Fscan(in, &s)

	m := 0
	for i := 0; i < n; i++ {
		if s[i] == '1' {
			m++
		}
	}

	if (m-k)%2 == 0 {
		fmt.Fprintln(out, "Yes")
	} else {
		fmt.Fprintln(out, "No")
	}

}
