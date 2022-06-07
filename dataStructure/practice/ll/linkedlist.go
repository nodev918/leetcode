package ll

import "fmt"

type Node struct {
	Val interface{}
	Next *Node
}

type LinkedList struct {
	head *Node
	tail *Node
}

func New() *LinkedList{
	return new(LinkedList)
}

func NewNode(val interface{}) *Node{
	n := new(Node)
	v.Val = val
	return n
}

func (l *LinkedList) isEmpty() bool {
	return l.head == nil
}

func (l *LinkedList) Prepend(n *Node){
	if l.isEmpty(){
		l.head = n
		l.tail = n
		return
	}
	n.Next = l.head
	l.head = n
}

func (l *LinkedList) Append(n *Node) {
	if l.isEmpty(){
		l.head = n
		l.tail = n
		return
	}
	l.tail.Next = n
	l.tail = n
}

func (l *LinkedList) Pop() (*Node, error) {
	if l.isEmpty(){
		return nil, fmt.Errorf("Linked-List is empty")
	}
	
	var previous *Node

	if l.head == l.tail{
		previous = l.head
		l.head = nil
		l.tail = nil
		return previous, nil
	}

	for current := l.head;current != l.tail; current = current.Next{
		previous = current
	}

	tmp := previous.Next
	previous.Next = nil
	l.tail = previous
	return tmp, nil
}

func (l *LinkedList) PopFirst()(*Node, error){
	
}