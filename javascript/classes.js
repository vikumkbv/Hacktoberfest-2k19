class Rectangle {
	constructor(width, height) {
		this.width = width || 0;
		this.height = height || 0;
	}
	
	computeArea() {
		return this.width * this.height;
	}
}
	
class Square extends Rectangle {
	constructor(sideLength) {
		super(sideLength, sideLength);
	}
}

const square = new Square(2);

console.log(square.width); // 2
console.log(square.height); // 2
console.log(square.computeArea()); // 4

console.log(square instanceof Square); // true
console.log(square instanceof Rectangle); // true
