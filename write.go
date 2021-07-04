package main

import "fmt"

func main() {
	var n, m, a, b, index int
	fmt.Scan(&n, &m)
	node := make([]int, n+1)
	for i := 0; i < m; i++ {
		fmt.Scan(&a, &b)
		if a > b {
			index = a
		} else {
			index = b
		}
		node[index]++
	}
	ans := 0
	for i := 1; i <= n; i++ {
		if node[i] == 1 {
			ans++
		}
	}
	fmt.Println(ans)
}
