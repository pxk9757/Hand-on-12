#include <iostream>

class DynamicArray {
private:
    int* array;
    int size;
    int capacity;

public:
    DynamicArray() {
        capacity = 1;
        size = 0;
        array = new int[capacity];
    }

    ~DynamicArray() {
        delete[] array;
    }

    void push_back(int value) {
        if (size == capacity) {
            capacity *= 2;
            int* newArray = new int[capacity];
            for (int i = 0; i < size; ++i) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
        array[size++] = value;
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return array[index];
    }

    int getSize() const {
        return size;
    }
};

int main() {
    DynamicArray arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    for (int i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
