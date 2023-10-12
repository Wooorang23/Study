#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
    private:
        T* data;
        int index;
        int capacity;

        void resize(int newCapacity) {
            T* newData = new T[newCapacity];
            for (int i = 0; i <= index; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        
    public:
        Stack() : capacity(10), data(new T[capacity]), index(-1) {}

        ~Stack() {
            delete [] data;
        }

        void push(const T& item) {
            if (index >= capacity - 1) {
                resize(2 * capacity);
            }
            data[++index] = item;
        }

        T pop() {
            if (index < 0) {
                return T();
            }
            if (index <= capacity / 4 && capacity > 10) {
                resize(capacity / 2);
            }
            return data[index--];
        }

        T top() const {
            if (index < 0) {
                return T();
            }
            return data[index];
        }

        bool empty() const {
            return (index == -1);
        }

        int size() const {
            return index + 1;
        }
        
        bool full() const {
            return (index == capacity - 1);
        }

        friend std::ostream& operator << (std::ostream& os, const Stack& stack) {
            for (int i = 0; i <= stack.index; ++i) {
                os << stack.data[i] << " ";
            }

            return os;
        }
};

#endif
