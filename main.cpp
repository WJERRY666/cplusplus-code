#include <iostream>
#include "vector"
#include <algorithm>
//#include<opencv2\opencv.hpp>
using namespace std;

//c++ template
template<typename AnyType>
//定义一个模板 typename可以用class代替
void Swap(AnyType &a, AnyType &b) {//交换两个AnyType值
    AnyType temp;
    temp = a;
    a = b;
    b = temp;
}

//插入排序
void charu_sort(vector<int> arr) {
    int n = arr.size();
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 0; i < n; i++) {
        for (j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            } else {
                break;
            }
        }
    }
    return;
}

//希尔排序
void shell_sort(vector<int> arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = 0; i < gap; i++) {
            for (int j = i; j < n; j += gap) {//控制起始位置（插入排序）
                for (int pos = j; pos > i; pos -= gap) {
                    if (arr[pos] < arr[pos - gap]) {
                        std::swap(arr[pos], arr[pos - gap]);//交换位置
                    }
                }
            }
        }
    }
    return;
}

int main() {
    vector<int> arr;
//    生成随机数组
    for (int i = 0; i < 300; i++) {
//        srand(i);
        arr.push_back(rand());
    }
    shell_sort(arr);
    sort(arr.begin(), arr.end(), less<int>());//升序排列
    return 0;
}
