package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var s string
	fmt.Fscan(r, &s)
	ans := 0
	base := 1
	for i := 0; i < len(s); i++ {
		keta, _ := strconv.Atoi(s[len(s)-i-1 : len(s)-i])
		if i != 0 {
			base *= 2
		}
		// fmt.Println(i, base, keta)
		ans += keta * base
	}
	fmt.Fprintln(w, ans)
}
