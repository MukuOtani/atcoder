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

	num := 0
	for i := 0; i < n; i++ {
		var t string
		var a int
		fmt.Fscan(in, &t, &a)
		if t[0] == '+' {
			num = (num + a) % 10000
		} else if t[0] == '-' {
			num = (num - a) % 10000
		} else {
			num = (num * a) % 10000
		}
		num = (num+10000)%10000
		fmt.Fprintln(out, num)
	}
}
