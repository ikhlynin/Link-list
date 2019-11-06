#pragma once
#include<iostream>
using namespace std;

template <typename T>
class list
{
public:
	
	list();
	~list();
	void push_back(T data);
	int getSize() { return size; }
	T& operator[](const int index);
	void pop_front();
	void push_front(T data);
	void insert(T data, int index);
	void removeAt(int index);
	void pop_back();
	void clear();

private:
	template <typename T>
	class Node
	{
	public:
		Node* next;
		T data;
		Node(T data = T(), Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	int size;
	Node<T>* head;
};

template <typename T>
list<T>::list()
{

}

template <typename T>
list<T>::~list()
{
	clear();
}

template <typename T>
void list<T>::push_back(T data)
{
	if (head == nullptr)
		head = new Node<T>(data);
	else
	{
		Node<T>* current = this->head;
		while (current->next != nullptr)
			current = current->next;
		current->next = new Node<T>(data);
	}
	size++;
}

template <typename T>
T & list<T>::operator[](const int index)
{
	int counter = 0;
	Node<T> *current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->next;
		counter++;
	}
}

template <typename T>
void list<T>::pop_front()
{
	Node<T>* tmp = head;
	head = head->next;
	delete tmp;
	size--;
}

template <typename T>
void list<T>::clear()
{
	while (size)
		pop_front();
}

template <typename T>
void list<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}

template <typename T>
void list<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->next;
		}
		previous->next = new Node<T>(data, previous->next);
		size++;
	}
}

template <typename T>
void list<T>::removeAt(int index)
{
	if (index == 0)
		pop_front();
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->next;
		Node<T>* el = previous->next;
		previous->next = el->next;
		delete el;
		size--;
	}
}

template<typename T>
void list<T>::pop_back()
{
	removeAt(size - 1);
}
