#ifndef QUEUE_H
#define QUEUE_H

#include "ListNode.h"

template <typename T>
class Queue {
    private:
        ListNode<T>* frontNode;
        ListNode<T>* rearNode;

    public:
        Queue() : frontNode(nullptr), rearNode(nullptr) {}
        ~Queue() {
            while (!empty()) {
                dequeue();
            }
        }

        void enqueue(T val) {
            ListNode<T>* newNode = new ListNode<T>(val);
            if (empty()) {
                frontNode = rearNode = newNode;
            } else {
                rearNode->next = newNode;
                rearNode = newNode;
            }
        }

        void dequeue() {
            if (empty()) {
                return;
            }
            ListNode<T>* temp = frontNode;
            frontNode = frontNode->next;
            delete temp;
            if (frontNode == nullptr) {
                rearNode = nullptr;
            }
        }

        T front() const {
            if (empty()) {
                throw std::runtime_error("Queue is empty");
            }
            return frontNode->val;
        }

        bool empty() const {
            return frontNode == nullptr;
        }

         friend std::ostream& operator << (std::ostream& os, const Queue<T>& queue) {
            ListNode<T>* current = queue.frontNode;
            while (current) {
                os << current->val << " ";
                current = current->next;
            }
            return os;
        }
};

#endif