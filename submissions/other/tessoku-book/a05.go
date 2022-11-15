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

	var n, k int
	fmt.Fscan(r, &n, &k)
	ans := 0
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			if 0 < k-i-j && k-i-j <= n {
				ans++
			}
		}
	}
	fmt.Fprint(w, ans)
}
