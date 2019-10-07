package main

import (
	"fmt"
	"math"
)

// Shape Interface with definition of Area and Perimeter
type Shape interface {
	Area() float64
	Perimeter() float64
}

// Rectangle Definition of a Rectangle
type Rectangle struct {
	Length, Width float64
}

// Area return the area of the rectangle
func (r Rectangle) Area() float64 {
	return r.Length * r.Width
}

// Perimeter return the perimeter of the rectangle
func (r Rectangle) Perimeter() float64 {
	return 2 * (r.Length + r.Width)
}

// Circle Definition of a Circle
type Circle struct {
	Radius float64
}

// Area return the area of the circle
func (c Circle) Area() float64 {
	return math.Pi * c.Radius * c.Radius
}

// Perimeter return the perimeter of the circle
func (c Circle) Perimeter() float64 {
	return 2 * math.Pi * c.Radius
}

// printShape function to print the area and perimeter of a shape, recive the interface as argument
func printShape(s Shape) {
	fmt.Printf("Shape Type = %T, Shape Value = %v\n", s, s)
	fmt.Printf("Area = %f, Perimeter = %f\n\n", s.Area(), s.Perimeter())
}

func main() {
	s := Circle{5.0}
	printShape(s)

	s1 := Rectangle{4.0, 6.0}
	printShape(s1)
}
