package main

import (
	"bufio"
	"fmt"
	"os"
)

func Gcd(x, y int) int {
	a, b := x, y
	if x > y {
		a, b = y, x
	}
	residual := b % a
	if residual == 0 {
		return a
	}
	return Gcd(a, residual)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var a, b int
	fmt.Fscan(in, &a, &b)
	fmt.Fprintln(out, Gcd(a, b))
}
