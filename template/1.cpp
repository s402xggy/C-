#include <iostream>
using namespace std;

/*
    1、普通函数可以发生隐式类型转换。
    2、模版自动类型推导不可以发生隐式类型转换。
    3、模板显示指定类型推导不可以发生隐式类型转换。



*/
template <class T>
void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
// 选择排序模版
template <class T>
void SelectSort(T arr[], int len) {
    for (int i = 0; i < len; i++) {
        int max = i;
        for (int j = i+1; j < len; j++) {
            if (arr[j] < arr[max]) {
                max = j;
            }
        }
        if (max != i) {
            Swap(arr[max], arr[i]);
        }
    }
}

template <class T>
void ShowArray(T arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int a = 10, b = 80;
    // 1、自动类型推导
    Swap(a, b);
    cout << "a = " << a << " b = " << b << endl;
    // 2、显示指定类型
    Swap<int>(a, b);
    cout << "a = " << a << " b = " << b << endl;

    char ch[] = "yqwoaini";
    cout << sizeof(ch) << endl;
    SelectSort<char>(ch, sizeof(ch) / sizeof(char) - 1);
    ShowArray<char>(ch, sizeof(ch) / sizeof(char) - 1);

    int arr[] = {3, 56, 1, 88, 23, 45, 1, 62, 11, 77, 58};
    SelectSort<int>(arr, sizeof(arr) / sizeof(int));
    ShowArray<int>(arr, sizeof(arr) / sizeof(int));

    return 0;
}