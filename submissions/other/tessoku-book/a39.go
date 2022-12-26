package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Movie struct {
	Start int
	End   int
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	movies := make([]Movie, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &movies[i].Start, &movies[i].End)
	}
	sort.Slice(movies, func(i, j int) bool {
		return movies[i].End <= movies[j].End
	})

	current, ans := 0, 0
	for i := 0; i < n; i++ {
		if current <= movies[i].Start {
			current = movies[i].End
			ans++
		}
	}
	fmt.Fprintln(out, ans)
}
