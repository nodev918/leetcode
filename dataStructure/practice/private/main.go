package main

type Node struct {
	Val interface{}
	Next *Node
}

type LinkedList interface {
	Prepend(*Node)
	Append(*Node)
	Pop() *Node
	PopFirst() *Node
	Head() *Node
	Tail()
	Remove(*Node)
}