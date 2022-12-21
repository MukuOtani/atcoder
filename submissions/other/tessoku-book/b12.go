package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func binarySearch(n int) (bool, float64) {
	low, high, mid := 0.0, 100.0, 50.0
	for i := 0; i < 30; i++ {
		mid = (low + high) / 2
		val := f(mid, n)
		switch {
		case val < 0:
			low = mid
		case val > 0:
			high = mid
		}
	}
	return true, mid
}

func f(x float64, n int) float64 {
	return math.Pow(x, 3.0) + x - float64(n)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)

	_, ans := binarySearch(n)
	fmt.Fprintln(out, ans)
}
