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

	var a, b int
	fmt.Fscan(r, &a, &b)
	found := false
	for i := a; i <= b; i++ {
		if 100%i == 0 {
			found = true
		}
	}
	if found {
		fmt.Fprintln(w, "Yes")
	} else {
		fmt.Fprintln(w, "No")
	}
}
