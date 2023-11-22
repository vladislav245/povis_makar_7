#pragma once

#include "Header.h"

class binary_tree {

private:

	class class_ptr {

	public:

		void find_path(int ind, string* path);

		Interface* obj; //указатель на объект
		class_ptr* left;   //указатель на левый элемент
		class_ptr* right;  //указатель на правый элемент

		class_ptr();
		class_ptr(Interface* obj, int index);
		~class_ptr();
	};

	class_ptr* cl_ptr;
	void display_tree(class_ptr* tree, string direction);

public:

	binary_tree() { cl_ptr = nullptr; };

	void InsertAt(Interface* ptr, int index);
	void RemoveAt(int index);
	void display();

	~binary_tree();
};