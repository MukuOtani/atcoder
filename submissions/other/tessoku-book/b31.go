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

	a := n / 3
	b := n / 5
	c := n / 7
	d := n / 15
	e := n / 35
	f := n / 21
	g := n / 105

	fmt.Fprintln(out, a+b+c-d-e-f+g)
}
