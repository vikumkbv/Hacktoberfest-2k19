package main

import (
	"fmt"
)

type node struct {
	value int
	next  *node
}

func push(head *node, value int) *node {
	tmp := head
	head = &node{value, nil}
	head.next = tmp
	return head
}

func pop(head *node) *node {
	if head == nil {
		return head
	}
	return head.next
}

func insert(pos *node, value int) {
	if pos == nil {
		return
	}
	tmp := pos.next
	newNode := &node{value, nil}
	pos.next = newNode
	newNode.next = tmp
}

func erase(head *node, value int) *node {
	if head.value == value {
		return head.next
	}
	prev := head
	for cur := head; cur != nil; cur = cur.next {
		if cur.value == value {
			prev.next = cur.next
			return head
		}
		prev = cur
	}
	return head
}

func printAll(cur *node) {
	if cur == nil {
		fmt.Println("Empty Linked List")
		return
	}
	firstNode := true
	for ; cur != nil; cur = cur.next {
		if firstNode {
			firstNode = false
		} else {
			fmt.Printf("->")
		}
		fmt.Printf("%d", cur.value)
	}
	fmt.Println()
}

func main() {
	linkedList := &node{1, nil}

	linkedList = push(linkedList, 2)
	printAll(linkedList)

	insert(linkedList, 3)
	printAll(linkedList)

	insert(linkedList, 4)
	printAll(linkedList)

	linkedList = pop(linkedList)
	printAll(linkedList)

	linkedList = pop(linkedList)
	printAll(linkedList)

	linkedList = pop(linkedList)
	printAll(linkedList)

	linkedList = pop(linkedList)
	printAll(linkedList)

	linkedList = push(linkedList, 5)
	linkedList = push(linkedList, 6)
	linkedList = push(linkedList, 7)
	printAll(linkedList)

	linkedList = erase(linkedList, 6)
	printAll(linkedList)

	insert(linkedList, 6)
	printAll(linkedList)

	linkedList = erase(linkedList, 7)
	printAll(linkedList)
}
