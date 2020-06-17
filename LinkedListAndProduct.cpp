// LinkedListAndProduct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "LinkedList.h"
#include "Product.h"

template<typename T>
void OutputList(const LinkedList<T>& l) {
	int sz = l.size();
	for (int i = 0; i < sz; i++)
		std::cout << l.getAtPos(i) << ' ';
	std::cout << std::endl;
}

void TestIntegerList() {
	LinkedList<int> l;

	l.insertAtPos(4, 0);
	OutputList(l);
	l.insertFirst(2);
	OutputList(l);
	l.insertLast(6);
	OutputList(l);
	l.insertAtPos(3, 1);
	OutputList(l);
	l.insertAtPos(5, 3);
	OutputList(l);
	std::cout << "Size: " << l.size() << std::endl;
	std::cout << "Contains(5): " << (l.isContains(5) ? "YES" : "NO") << std::endl;
	std::cout << "Contains(7): " << (l.isContains(7) ? "YES" : "NO") << std::endl;
	l.deleteAtPos(2);
	OutputList(l);
	l.deleteByValue(2);
	OutputList(l);
	l.deleteByValue(6);
	OutputList(l);
	l.deleteFirst();
	OutputList(l);
	l.deleteLast();
	std::cout << "Empty? " << (l.isEmpty() ? "YES" : "NO") << std::endl;
	l.insertLast(9);
	OutputList(l);
}

void TestProductList()
{
	LinkedList<Product> l;
	l.insertFirst(Product("A", 10, 70));
	OutputList(l);
	l.insertLast(Product("C", 30, 50));
	OutputList(l);
	l.insertAtPos(Product("B", 20, 60), 1);
	OutputList(l);
	std::cout << "Count: " << l.size() << std::endl;
	
	Product p1("B", 20, 60);
	std::cout << "Contains " << p1 << "? " << (l.isContains(p1) ? "YES" : "NO") << std::endl;
	Product p2("B", 25, 60);
	std::cout << "Contains " << p2 << "? " << (l.isContains(p2) ? "YES" : "NO") << std::endl;

	l.deleteByValue(Product("C", 30, 50));
	OutputList(l);
	l.deleteLast();
	OutputList(l);
	l.deleteFirst();
	OutputList(l);
}

int main()
{
	TestIntegerList();
	TestProductList();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
