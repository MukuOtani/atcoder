package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func min(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}

type Point struct {
	x float64
	y float64
}

func calcTime(p1, p2 Point) float64 {
	return math.Pow(math.Pow(p1.x-p2.x, 2)+math.Pow(p1.y-p2.y, 2), 0.5)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	p := make([]Point, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &p[i].x, &p[i].y)
	}

	dp := make([][]float64, (1<<n)+5)
	for i := 0; i < (1<<n)+5; i++ {
		dp[i] = make([]float64, n+5)
		for j := 0; j < n+5; j++ {
			dp[i][j] = 100000000000
		}
	}
	dp[0][0] = 0

	for i := 0; i < (1 << n); i++ {
		for j := 0; j < n; j++ {
			if dp[i][j] == 100000000000 {
				continue
			}
			for k := 0; k < n; k++ {
				dp[i|(1<<k)][k] = min(dp[i|(1<<k)][k], dp[i][j]+calcTime(p[j], p[k]))
			}
		}
	}
	fmt.Fprintln(out, dp[(1<<n)-1][0])
}
