package main

import "fmt"

// byte --> uint8

func rightViewRec(tree []byte, index, curLevel byte, maxLevel *byte) {
	if index >= byte(len(tree)) {
		return
	}
	if *maxLevel < curLevel {
		fmt.Print(tree[index], " ")
		*maxLevel = curLevel
	}
	rightViewRec(tree, 2*index+2, curLevel+1, maxLevel) // right
	rightViewRec(tree, 2*index+1, curLevel+1, maxLevel) //left
}
func rightView(tree []byte) {
	maxLevel := byte(0)
	rightViewRec(tree, 0, 1, &maxLevel)
}
func main() {
	var n byte
	fmt.Scanln(&n)
	// var tree [n]byte // go doesnt let you use variable sized array in compile type
	// better to use slices
	tree := make([]byte, n)
	for i := byte(0); i < n; i++ {
		fmt.Scanf("%v", &tree[i])
	}
	rightView(tree)
}
