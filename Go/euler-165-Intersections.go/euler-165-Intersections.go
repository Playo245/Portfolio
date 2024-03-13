package main

import (
	"fmt"
	"os"
	"strconv"
)

type Point struct {
	X, Y float64
}

func cross(a, b, c Point) float64 {
	return (b.X-a.X)*(c.Y-b.Y) - (b.Y-a.Y)*(c.X-b.X)
}

func solve(p1, p2, p3, p4 Point) Point {
	if cross(p1, p2, p3)*cross(p1, p2, p4) < 0 && cross(p3, p4, p1)*cross(p3, p4, p2) < 0 {
		pa, pb, pc := p1.Y-p2.Y, p2.X-p1.X, p1.X*p2.Y-p2.X*p1.Y
		qa, qb, qc := p3.Y-p4.Y, p4.X-p3.X, p3.X*p4.Y-p4.X*p3.Y
		xa, xb, xc := pb*qc-qb*pc, pc*qa-qc*pa, pa*qb-qa*pb

		if xc != 0.0 {
			return Point{xa / xc, xb / xc}
		}
	}
	return Point{-1, -1}
}

func main() {
	if len(os.Args) != 2 {
		fmt.Println("Usage: go run euler-165-Intersections.go <value_of_n>")
		return
	}

	nStr := os.Args[1]
	n, err := strconv.Atoi(nStr)
	if err != nil {
		fmt.Println("Invalid input: Please enter a valid number.")
		fmt.Println("Error message:", err)
		return
	}

	s := make([]int, n*4+10)
	p := make([]Point, n*2+10)

	s[0] = 290797
	for i := 0; i < n*4; i++ {
		s[i+1] = s[i] * s[i] % 50515093
	}
	for i := 1; i <= n*2; i++ {
		p[i] = Point{float64(s[2*i-1] % 500), float64(s[2*i-0] % 500)}
	}

	var S = make(map[Point]struct{})
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			x := solve(p[i*2+1], p[i*2+2], p[j*2+1], p[j*2+2])
			S[x] = struct{}{}
		}
	}
	fmt.Println(len(S) - 1)
}
