/*
Programmname: Vector
Version: 1.0
Date: 28.10.2018
Name: Groﬂ Philipp, Pfleghaar Patrick
*/

#pragma once
# include <stdexcept>

template <typename T>
/*!
Generate class MyNode
*/
class MyNode													
/*!
Define pointer to p_next 
*/																
{
public:
	T obj;														

	MyNode<T>* p_next;

	/*!
	Default consturktor,
	set p_next as nullpointer 
	*/
	MyNode() : p_next(nullptr) {}

	/*!
	Copy-construktor,
	transfer a reference of the object
		*/
	MyNode(const T&ref) : obj(ref), p_next(nullptr) {}
};

template <typename T>
/*!
Generate class MyVector
*/
class MyVector												
{
private:														
	MyNode<T>* p_first;
	size_t m_size;


public:
	MyVector() : p_first(nullptr), m_size(0) {}
	~MyVector();
	/*!
	Define functions of the Vector
	*/
	void push_back(const T &ref);								
	void pop_back();
	void resize(size_t size);
	void clear();
	size_t size() { return m_size; } // = unsigned int size
	T at(size_t pos);	//int at(unsigned int pos)
	
};

template <typename T>
/*!
Destructor ( new p_first get defined and the delete the old one)
*/
MyVector<T>::~MyVector()										
{
	while (p_first != nullptr) {
		MyNode<T>* p_temp = p_first;
		p_first = p_first->p_next;
		delete p_temp;
	}

}


template <typename T>
/*!
New Element get push back o the end
*/
void MyVector<T>::push_back(const T &ref)						
{
	if (p_first == nullptr) {
		p_first = new MyNode<T>(ref);
	}
	else {
		MyNode<T>* p_node = p_first;
		while (p_node->p_next != nullptr) {
			p_node = p_node->p_next;
		}
		p_node->p_next = new MyNode<T>(ref);
	}
	m_size++;														
}


template <typename T>
/*!
Delete the last element of the Vector
*/
void MyVector<T>::pop_back()
{
	if (p_first == nullptr);
	if (p_first->p_next != nullptr) {
		MyNode<T>* p_help = p_first; //phelp to first element
		while (p_help->p_next->p_next != nullptr) {
			p_help = p_help->p_next; //next element
		}
		delete p_help->p_next; //delete last element
		p_help->p_next = nullptr; //pointer p_next to nullptr
				
		m_size--;
	}
	else {
		delete p_first;
		p_first = nullptr;
		m_size = 0;
	}
}


template <typename T>
/*!
Gives out an chooseable Value
*/
T MyVector<T>::at(size_t pos)									
{
	if (pos < m_size) {
		size_t i(0);
		MyNode<T>* p_node = p_first;
		while (p_node != nullptr /*always true*/) {
			if (i == pos) return p_node->obj;
			p_node = p_node->p_next;
			i++;
		}
	}
	/*!
	exception, you need an catch in the cpp, if you don¥t do that the programm will break down
	*/
	throw std::out_of_range("Value out of range"); 
}


template <typename T>
/*!
Deletes the whole vector
*/
void MyVector<T>::clear()
{
	while (size() > 0) {
		pop_back();
	}
}

template <typename T>
/*!
Reduce the vector to a choosable lenght
*/
void MyVector<T>::resize(size_t pos)
{
	if (pos < m_size) {
		while (size() > pos) {
			pop_back();
		}
	}
	/*!
	exception, you need an catch in the cpp, if you don¥t do that the programm will break down
	*/
	throw std::out_of_range("Wrong Value"); 
}

