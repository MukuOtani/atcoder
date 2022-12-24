package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func isPrime(target int) bool {
	for i := 2; i <= int(math.Pow(float64(target), 0.5)); i++ {
		if target%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var q int
	fmt.Fscan(in, &q)
	for i := 0; i < q; i++ {
		var num int
		fmt.Fscan(in, &num)
		if isPrime(num) {
			fmt.Fprintln(out, "Yes")
		} else {
			fmt.Fprintln(out, "No")
		}
	}
}
