package main

import "fmt"

type Grid struct {
	data [][]byte
	rows int
	cols int
}

func NewGrid(grid [][]byte) *Grid {
	return &Grid{
		data: grid,
		rows: len(grid),
		cols: len(grid[0]),
	}
}

func (g *Grid) NumOfIslands() int {
	if g.rows == 0 {
		return 0
	}

	var count int

	for i := 0; i < g.rows; i++ {
		for j := 0; j < g.cols; j++ {
			if g.data[i][j] == 1 {
				g.dfs(i, j)
				count++
			}
		}
	}

	return count
}

func (g *Grid) dfs(i, j int) {
	if i < 0 || j < 0 || i >= g.rows || j >= g.cols || g.data[i][j] != 1 {
		return
	}
	g.data[i][j] = 0

	g.dfs(i+1, j)
	g.dfs(i-1, j)
	g.dfs(i, j+1)
	g.dfs(i, j-1)
}

func main() {
	mat := [][]byte{
		{1, 1, 0, 0, 0},
		{0, 1, 0, 0, 1},
		{1, 0, 0, 1, 1},
		{0, 0, 0, 0, 0},
		{1, 0, 1, 0, 0},
	}
	g := NewGrid(mat)
	fmt.Println(g.NumOfIslands())
	// N.B the output given in the slide is wrong unless the matrix is a torus only in the x axis
	// i.e the matrix wraps around on the x axis.
}
