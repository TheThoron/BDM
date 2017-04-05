#pragma once

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

//!  A node class for the tree structure. 
/*!
add together, Nodes will for the main tree. function will then apply to it to sort it / view variables.
*/

template<class T>
class Node{

private:

	//! a private member variable
	/*!
		a <T> which will be sorted then viewed
	*/
	T _data;

	//! a private member variable
	/*!
	a pointer to his parent in the tree
	*/
	Node<T>* _parent;

	//! a private member variable
	/*!
	a list to this node's children
	*/
	list<Node<T>*> _childs;

public:
	//constructors
	Node() { _parent = nullptr; }
	Node(T d) { _data = d; _parent = nullptr; }

	//accessors
	T& data(){ return _data; }
	list<Node<T>*>& childs(){ return _childs; }

	Node<T>* getParent() { return _parent; }

	//! A public member fonction
	/*!
	when a node implement his father, he instentaly become the father's child
	*/
	void setParent(Node<T>* father) { _parent = father; father->childs().push_back(this); }
};

//! A public fonction
/*!
it compare two strings, with an alphabetical order (upper case are before lower case)
*/
bool alphabeticalOrder(Node<string>* first, Node<string>* second)
{
	if (first->data().compare(second->data()) > 0)
		return false;
	return true;
}

//! A public fonction
/*!
it passes from one node to all his children, and sort them by their value
*/
template<class T>
void sortNode(Node<T>* pt_node)
{
	pt_node->childs().sort(alphabeticalOrder);
	list<Node<T>*>::iterator it;
	for (it = pt_node->childs().begin(); it != pt_node->childs().end(); it++) // this loop pass by all the child
		sortNode(*it); // for each child, we do the same as for the father
}

//! A public fonction
/*!
it passes from one node to all his children, and add them to the string txt.
each time you meet a children, you add one '\t'. (for the children only)
*/
template<class T>
void writeNode(Node<T>* pt_node, string &txt, int nbtab)
{
	list<Node<T>*>::iterator it;
	for (it = pt_node->childs().begin(); it != pt_node->childs().end(); it++) // this loop pass by all the child
	{
		for (int i = 0; i < nbtab; i++) // here we add the '\t'
			txt.push_back('\t');
		txt.append((*it)->data());
		txt.push_back('\n');
		writeNode(*it, txt, nbtab + 1); // for each child, we do the same as for the father
	}
}