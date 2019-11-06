#include "list.h"

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
	if (head = nullptr)
		head = new Node<T>(data);
	else
	{
		Node<T>* current = this->head;
		while (current->next!=nullptr)
		{
			current = current->next;
		}
		current->next = new Node<T>(data);
	}
	size++;
}

template <typename T>
T& list<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current->next!=nullptr)
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
	{
		pop_front();
	}
}