#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T>
class ListNode {
public:
	T val;
	ListNode* next;

	// Инициализация конструктора без параметров
	ListNode() : val(0), next(nullptr) {}

	// Конструктор с параметром данных
	ListNode(T x) : val(x), next(nullptr) {}

	// Конструктор с параметром данных и указателем на следующий элемент списка
	ListNode(T x, ListNode* next) : val(x), next(next) {}
};

#endif // LISTNODE_H