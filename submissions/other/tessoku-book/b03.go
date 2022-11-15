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
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &a[i])
		
	}
	for i:=0; i<n; i++{
		for j:=i+1; j<n; j++{
			for k:=j+1; k<n; k++{
				if a[i]+a[j]+a[k]==1000{
					fmt.Fprintln(w, "Yes")
					return
				}
			}
		}
	}
	fmt.Fprintln(w, "No")
}
