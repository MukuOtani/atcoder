package main

import (
	"bufio"
	"fmt"
	"os"
)

func modPow(a, b, mod int) int {
	p, num := a, 1
	for i := 0; i < 30; i++ {
		if (b>>i)&1 == 1 {
			num = (num * p) % mod
		}
		p = (p * p) % mod
	}
	return num
}

func modDiv(a, b, mod int) int {
	return (a * modPow(b, mod-2, mod) % mod)
}

func modNcr(n, r, mod int) int {
	a := 1
	for i := 1; i <= n; i++ {
		a = (a * i) % mod
	}
	b := 1
	for i := 1; i <= r; i++ {
		b = (b * i) % mod
	}
	for i := 1; i <= n-r; i++ {
		b = (b * i) % mod
	}
	return modDiv(a, b, mod)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	const mod int = 1e9 + 7
	var h, w int
	fmt.Fscan(in, &h, &w)

	fmt.Fprintln(out, modNcr(h+w-2, h-1, mod))
}
