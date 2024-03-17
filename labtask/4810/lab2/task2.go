// Gemini Code. Also doesnt work lol.
package main

import (
	"fmt"
)

type item struct {
	price  int
	weight int
}

type segmentTree struct {
	tree []int
	size int
}

func buildSegmentTree(arr []item, start, end int, st *segmentTree) {
	if start == end {
		st.tree[st.size*start+1] = arr[start].weight
		return
	}
	mid := (start + end) / 2
	buildSegmentTree(arr, start, mid, st)
	buildSegmentTree(arr, mid+1, end, st)
	st.tree[st.size*start+1] = max(st.tree[st.size*2*start+2], st.tree[st.size*2*start+3])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func query(st *segmentTree, qs, qe int, start, end int) int {
	if qs <= start && qe >= end {
		return st.tree[st.size*start+1]
	}

	if qs > end || qe < start {
		return 0
	}

	mid := (start + end) / 2
	return max(query(st, qs, qe, start, mid), query(st, qs, qe, mid+1, end))
}

func processQueries(arr []item, queries [][]int) []int {
	n := len(arr)
	st := &segmentTree{
		tree: make([]int, 4*n), // 4*n to accommodate worst-case tree size
		size: n,
	}
	buildSegmentTree(arr, 0, n-1, st)

	results := make([]int, len(queries))
	for i, _query := range queries {
		low, high := _query[0], _query[1]
		results[i] = query(st, low, high, 0, n-1)
	}
	return results
}

func main() {
	arr := []item{
		{price: 24, weight: 6},
		{price: 30, weight: 8},
		{price: 21, weight: 7},
	}
	queries := [][]int{
		{10, 24},
		{20, 30},
	}
	results := processQueries(arr, queries)
	fmt.Println(results)
}
