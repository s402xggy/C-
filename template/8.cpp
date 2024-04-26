#include <iostream>
using namespace std;

template <class T>
class MyArray{
    public:
        MyArray(int capacity):capacity_(capacity), size_(0) {
            arr_ = new T[capacity_];
        }
        MyArray(const MyArray &arr) {
            if (arr_ != nullptr) {
                delete arr_;
                arr_ = nullptr;
            }
            arr_ = new T[arr.capacity_];
            for (int i = 0; i < arr.capacity_; i++) {
                arr_[i] = arr.arr_[i];
            }
            capacity_ = arr.capacity_;
            size_ = arr.size_;
        }

        MyArray& operator=(const MyArray &arr) {
            if (&arr == this)
                return *this;
            if (arr_ != nullptr) {
                delete arr_;
                arr_ = nullptr;
            }

            arr_ = new T[arr.capacity_];
            for (int i = 0; i < arr.capacity_; i++) {
                arr_[i] = arr.arr_[i];
            }
            capacity_ = arr.capacity_;
            size_ = arr.size_;
            return *this;
        }
        ~MyArray() {
            if (arr_ != nullptr) {
                delete []arr_;
                arr_ = nullptr;
            }
        }
        T& operator[](int n) {
            if (n >= size_)
                exit(0);
            else    
                return arr_[n];
        }

        void Push_back(T t) {
            if (size_ == capacity_)
                return ;
            arr_[size_] = t;
            size_++;
        }

        void Pop_back() {
            if (size_ == 0)
                return ;
            size_--;
        }

        int GetCapacity() {
            return capacity_;
        }

        int GetSize() {
            return size_;
        }

    private:
        T *arr_;
        int capacity_;
        int size_;
};



int main() {
    MyArray<int> arr(100);
    arr.Push_back(12);
    arr.Push_back(45);
    arr.Push_back(3);
    arr.Push_back(65);
    arr.Push_back(34);
    arr.Push_back(78);

    cout << arr.GetSize() << endl;
    for (int i = 0; i < arr.GetSize(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.Pop_back();
    arr.Pop_back();
    arr.Pop_back();


    cout << arr.GetSize() << endl;
    for (int i = 0; i < arr.GetSize(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}