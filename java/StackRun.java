import java.io.*;
import java.util.*;
import java.lang.*;
import java.util.Scanner;

class Node{
	Node next;
	Node prev;
	int data;
	Node(int x){
		data = x;
	}
}


class Stack{
	Node top;
	int size;
	public int pop(){
		int val;

		val = top.data;
		top = top.prev;
		top.next = null;
		size --;
		return  val;
	}

	public int peek(){
		int val;
		val = top.data;
		return val;
	}

	public void push(int value){
		Node newTop = new Node(value);
		newTop.prev = top;
		newTop.next = null;
		top = newTop;
		size ++;

	}
}

class StackRun{

	public static void main(String[] args){
		int n;
		Stack stack = new Stack();
		Scanner s = new Scanner(System.in);
		n = s.nextInt();
		System.out.println(n);
		int arr[] = new int[n];
		for (int i=0; i<n; i++){
			arr[i] = s.nextInt();
		}

		int count = 0;

		while (count<n){
			stack.push(arr[count]);
			count++;
		}
		int count2=0;
		int z;
		while (count2<n-1){
			z = stack.pop();
			System.out.println(z);
		}
		System.out.println(stack.peek());
	}

}