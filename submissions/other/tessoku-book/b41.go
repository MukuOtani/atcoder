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

	var x, y int
	fmt.Fscan(in, &x, &y)
	ans := [][2]int{[2]int{x, y}}
	if x == 1 && y == 1 {
		fmt.Fprintln(out, 0)
		return
	}

	for x > 0 && y > 0 {
		if x > y {
			x -= y
		} else {
			y -= x
		}
		if x == 1 && y == 1 {
			break
		}
		ans = append(ans, [2]int{x, y})
	}

	fmt.Fprintln(out, len(ans))

	for i := len(ans) - 1; i >= 0; i-- {
		fmt.Fprintln(out, ans[i][0], ans[i][1])
	}
}
