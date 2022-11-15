package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var n, x int
	fmt.Fscan(r, &n, &x)
	found := false
	var a int
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &a)
		if a == x {
			found = true
		}
	}
	if found {
		fmt.Fprintln(w, "Yes")
	} else {
		fmt.Fprintln(w, "No")
	}
}
