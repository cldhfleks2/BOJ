#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
//제네릭타입으로 구현
template <typename T>
class Node {
public:
	T data = NULL;
	Node<T>* prev = nullptr, * next = nullptr;
	//생성자에는 제네릭X
	Node(T data,
		Node<T>* prev = nullptr,
		Node<T>* next = nullptr)
		: data(data), prev(prev), next(next) {}
};

template <typename T>
class Deque {
private:
	int dataSize = 0;
	Node<T>* tail = nullptr, * head = nullptr;
public:
	//생성자에는 제네릭X
	Deque() {}
	~Deque() {}
	void push_front(const T data);
	void push_back(const T data);
	T pop_front();
	T pop_back();
	T front() const;
	T back() const;
	bool empty() const;
	int size() const;
};

template <class T>
void Deque<T>::push_front(const T data) {
	if (empty()) {
		head = new Node<T>(data);
		tail = head;
	}
	else {
		Node<T>* newNode = new Node<T>(data, head, nullptr);
		head->next = newNode;
		head = newNode;
	}
	dataSize++;
}

template <class T>
void Deque<T>::push_back(const T data) {
	if (empty()) {
		head = new Node<T>(data);
		tail = head;
	}
	else {
		Node<T>* newNode = new Node<T>(data, nullptr, tail);
		tail->prev = newNode;
		tail = newNode;
	}
	dataSize++;
}

template <class T>
T Deque<T>::pop_front() {
	if (empty())
		return -1;
	T data = front();

	Node<T>* delNode = head;
	head = head->prev;
	delete delNode;
	dataSize--;

	if (dataSize == 0)
		head = nullptr;
	return data;
}

template <class T>
T Deque<T>::pop_back() {
	if (empty())
		return -1;
	T data = back();

	Node<T>* delNode = tail;
	tail = tail->next;
	delete delNode;
	dataSize--;

	if (dataSize == 0)
		tail = nullptr;
	return data;
}

template <class T>
bool Deque<T>::empty() const {
	return dataSize == 0;
}

template <class T>
int Deque<T>::size() const {
	return dataSize;
}
template <class T>
T Deque<T>::front() const {
	if (empty())
		return -1;
	return head->data;
}

template <class T>
T Deque<T>::back() const {
	if (empty())
		return -1;
	return tail->data;
}

int main(int n, int num) {
	scanf("%d", &n);
	Deque<int> d;
	for (int i = 0; i < n; i++) {
		char c[12]; //정수앞 공백까지 11자 + \0 = 12
		scanf("%s", c);
		if (!strcmp(c, "push_front")) {
			scanf("%d", &num);
			d.push_front(num);
		}
		else if (!strcmp(c, "push_back")) {
			scanf("%d", &num);
			d.push_back(num);
		}
		else if (!strcmp(c, "pop_front")) {
			printf("%d\n", d.pop_front());
		}
		else if (!strcmp(c, "pop_back")) {
			printf("%d\n", d.pop_back());
		}
		else if (!strcmp(c, "size")) {
			printf("%d\n", d.size());
		}
		else if (!strcmp(c, "empty")) {
			printf("%d\n", d.empty() ? 1 : 0);
		}
		else if (!strcmp(c, "front")) {
			printf("%d\n", d.front());
		}
		else if (!strcmp(c, "back")) {
			printf("%d\n", d.back());
		}
	}
	return 0;
}