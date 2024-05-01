package main

import "fmt"

// Object interface
type Object interface {
	display()
}

// Shape struct
type Shape struct {
	colour string
}

func (s Shape) display() {
	// Default display function for shapes
	fmt.Printf("A %s shape.\n", s.colour)
}

// Circle struct
type Circle struct {
	Shape
}

func (c Circle) display() {
	fmt.Printf("A %s circle.\n", c.colour)
}

// Triangle struct
type Triangle struct {
	Shape
}

func (t Triangle) display() {
	fmt.Printf("A %s triangle.\n", t.colour)
}

// Square struct
type Square struct {
	Shape
}

func (s Square) display() {
	fmt.Printf("A %s square.\n", s.colour)
}

// Rectangle struct
type Rectangle struct {
	Shape
}

func (r Rectangle) display() {
	fmt.Printf("A %s rectangle.\n", r.colour)
}

// Village struct
type Village struct {
	objects []Object
}

func (v *Village) addObject(obj Object) {
	v.objects = append(v.objects, obj)
}

func (v Village) display() {
	for _, obj := range v.objects {
		obj.display()
	}
}

// House struct
type House struct {
	Village
}

func NewHouse() *House {
	house := &House{}
	house.addObject(Triangle{Shape{"red"}})
	house.addObject(Square{Shape{"white"}})
	return house
}

func (h House) display() {
	fmt.Println("House:")
	h.Village.display()
}

// Tree struct
type Tree struct {
	Village
}

func NewTree() *Tree {
	tree := &Tree{}
	tree.addObject(Circle{Shape{"green"}})
	tree.addObject(Rectangle{Shape{"brown"}})
	return tree
}

func (t Tree) display() {
	fmt.Println("Tree:")
	t.Village.display()
}

// Water struct
type Water struct {
	Village
}

func NewWater() *Water {
	water := &Water{}
	water.addObject(Rectangle{Shape{"blue"}})
	return water
}

func (w Water) display() {
	fmt.Println("Water:")
	w.Village.display()
}

func main() {
	village := Village{}
	village.addObject(NewHouse())
	village.addObject(NewTree())
	village.addObject(NewWater())

	village.display()
}

// Object and Shape structs are used for abstraction.
// Composite pattern starts from Village. It contains other objects such as House, Tree, and Water.
// House contains Triangle and Square.
// Tree contains Circle and Rectangle.
// Water contains Rectangle.
