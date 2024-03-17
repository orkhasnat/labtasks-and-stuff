// wrong!!!
package main

import "fmt"

type Node struct {
	val, height, size int
	left, right       *Node
}

func (n *Node) Height() int {
	if n == nil {
		return 0
	}
	return n.height
}

func (n *Node) Size() int {
	if n == nil {
		return 0
	}
	return n.size
}

func (n *Node) Update() {
	n.height = max(n.left.Height(), n.right.Height()) + 1
	n.size = n.left.Size() + n.right.Size() + 1
}

func (n *Node) balanceFactor() int {
	if n == nil {
		return 0
	}
	return n.left.Height() - n.right.Height()
}

func (x *Node) rotateLeft() *Node {
	y := x.right
	x.right = y.left
	y.left = x
	x.Update()
	y.Update()
	return y
}

func (y *Node) rotateRight() *Node {
	x := y.left
	y.left = x.right
	x.right = y
	y.Update()
	x.Update()
	return x
}

func (n *Node) insert(val int) *Node {
	if n == nil {
		return &Node{val: val, height: 1, size: 0}
	}
	if val < n.val {
		n.left = n.left.insert(val)
	} else if val > n.val {
		n.right = n.right.insert(val)
	} else {
		return n // no duplicate allowed
	}
	n.Update()

	bf := n.balanceFactor()

	// LL case
	if bf > 1 && val < n.left.val {
		return n.rotateRight()
	}
	// RR case
	if bf < -1 && val > n.right.val {
		return n.rotateLeft()
	}
	// LR case
	if bf > 1 && val > n.left.val {
		n.left = n.left.rotateLeft()
		return n.rotateRight()
	}
	// RL case
	if bf < -1 && val < n.right.val {
		n.right = n.right.rotateRight()
		return n.rotateLeft()
	}
	return n
}

func (n *Node) sumSmallerOrEqualKthElem(k int) int {
	if n == nil {
		return 0
	}
	if k == n.Size() {
		return n.val + n.left.sumSmallerOrEqualKthElem(k)
	} else if k < n.Size() {
		return n.left.sumSmallerOrEqualKthElem(k)
	} else {
		return n.val + n.left.Size() + n.right.sumSmallerOrEqualKthElem(k-1-n.left.Size())
	}
}

func (root *Node) inorderTraversal() {
	if root == nil {
		return
	}
	root.left.inorderTraversal()
	fmt.Print(root.val, " ")
	root.right.inorderTraversal()
}

func main() {
	var root *Node
	tree := []int{7, 2, 13, 9, 10, 8}
	// build
	for _, i := range tree {
		root = root.insert(i)
	}
	root.inorderTraversal()
	var k int
	fmt.Print("\nEnter K = ?\b")
	fmt.Scanf("%d", &k)
	fmt.Print(root.sumSmallerOrEqualKthElem(k))
}
