#include <iostream>
#include <string>


template <typename T>
class List {
private:


	template <typename T>
	class Node {
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T>* head;


public:
	List();
	~List();

	void push_back(T data);
	int get_size() { return Size; }
	T& operator[](const int index);
	void pop_front();
	void clear();

	void push_front(T data);
	void insert(T data, int index);
	void remove_at(int index);
	void pop_back();
};

template <typename T>
List<T>::List() {
	Size = 0;
	head = nullptr;
}

template <typename T>
List<T>::~List() {
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr) { head = new Node<T>(data); }
	else {
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}

	Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;

	while (current != nullptr) {
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;

	}
	// TODO: вставьте здесь оператор return
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;

	delete temp;

	Size--;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front();
	}
	else {

		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;

		Size++;

	}
}

template<typename T>
void List<T>::remove_at(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else {
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;

		delete toDelete;
		Size--;

	}
}

template<typename T>
void List<T>::pop_back()
{
	remove_at(Size - 1);
}



int main() {
	setlocale(LC_ALL, "ru");

	List<int> lst;
	int arr_size;
	std::cin >> arr_size;

	for (int i = 0; i < arr_size; i++)
	{
		lst.push_back(rand() % 10);
	}

	for (int i = 0; i < lst.get_size(); i++) {
		std::cout << lst[i] << std::endl;
	}

	return 0;
}
