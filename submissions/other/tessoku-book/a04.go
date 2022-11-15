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

	var n int
	fmt.Fscan(r, &n)
	for i := 0; i < 10; i++ {
		fmt.Fprint(w, n/(1<<(9-i))%2)
	}
}
