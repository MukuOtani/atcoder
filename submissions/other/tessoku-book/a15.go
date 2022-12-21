package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	b := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	copy(b, a)
	sort.Ints(b)

	unique := []int{b[0]}
	for i := 1; i < n; i++ {
		if b[i] != b[i-1] {
			unique = append(unique, b[i])
		}
	}
	m := make(map[int]int)
	for i, v := range unique {
		m[v] = i + 1
	}
	for i := 0; i < n; i++ {
		fmt.Fprint(out, m[a[i]])
		fmt.Fprint(out, " ")
	}
	fmt.Fprintln(out, "")
}
