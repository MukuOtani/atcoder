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

	var a, b int
	fmt.Fscan(in, &a, &b)

	p, num := a, 1
	for i := 0; i < 30; i++ {
		if (b>>i)&1 == 1 {
			num = (num * p) % (1e9 + 7)
		}
		p = (p * p) % (1e9 + 7)
	}
	fmt.Fprintln(out, num)
}
