#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
template <typename T>
class Node {
public:
	T data= NULL;
	Node<T> *next = nullptr, *prev = nullptr;
	Node(T data
		, Node<T> *prev = nullptr
		, Node<T>* next = nullptr)
		: data(data), prev(prev), next(next) {}
};

template <typename T>
class Stack {
private:
	Node<T> *head = nullptr;
	int dataSize = 0;
public:
	Stack() {}
	~Stack() {}
	void push(const T data);
	T pop();
	int size() const;
	bool empty() const;
	T top() const;
};

template <typename T>
void Stack<T>::push(const T data) {
	if (empty()) {
		head = new Node<T>(data); //새로만든노드를 헤드로 지정
	}
	else {
		Node<T> *prevNode = head;
		head = new Node<T>(data, prevNode, nullptr);//새로만든노드를 헤드로 재지정
		prevNode->next = head; //이전노드와 새로만든노드 연결
	}
	dataSize++;
}

template <typename T>
T Stack<T>::pop() {
	if (empty()) {
		return -1;
	}
	T data = top();
	Node<T> *delNode = head;
	head = head->prev;
	delete delNode;
	dataSize--;
	return data;
}

template <typename T>
int Stack<T>::size() const {
	return dataSize;
}

template <typename T>
bool Stack<T>::empty() const{
	return dataSize == 0;
}

template <typename T>
T Stack<T>::top() const {
	if (empty())
		return -1;
	return head->data;
}

int main(int n) {
	scanf("%d", &n);
	Stack<int> s;
	while (n--) {
		char c[6];
		int num;
		scanf("%s", c);
		if (!strcmp(c, "push")) {
			scanf("%d", &num);
			s.push(num);
		}
		else if (!strcmp(c, "pop")) {
			printf("%d\n", s.pop());
		}
		else if (!strcmp(c, "size")) {
			printf("%d\n", s.size());
		}
		else if (!strcmp(c, "empty")) {
			printf("%d\n", s.empty() ? 1 : 0);
		}
		else if (!strcmp(c, "top")) {
			printf("%d\n", s.top());
		}
	}

	return 0;
}
