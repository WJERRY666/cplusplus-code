#include <iostream>
#include "vector"
#include <algorithm>
//#include<opencv2\opencv.hpp>
using namespace std;

//c++ template
template<typename AnyType>
//定义一个模板 typename可以用class代替
void Swap(AnyType &a, AnyType &b)
{//交换两个AnyType值
    AnyType temp;
    temp = a;
    a = b;
    b = temp;
}

//插入排序
void charu_sort(vector<int> arr)
{
    int n = arr.size();
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }
    return;
}

//希尔排序
void shell_sort(vector<int> arr)
{
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = 0; i < gap; i++)
        {
            for (int j = i; j < n; j += gap)
            {//控制起始位置（插入排序）
                for (int pos = j; pos > i; pos -= gap)
                {
                    if (arr[pos] < arr[pos - gap])
                    {
                        std::swap(arr[pos], arr[pos - gap]);//交换位置
                    }
                }
            }
        }
    }
    return;
}

//暴力匹配字符串搜索
int strStr(string haystack, string needle)
{
    if (needle.empty())
    {
        return 0;
    }
    int i = 0;
    int j = 0;
    while (i < haystack.size())
    {

        for (j = 0; j < needle.size();)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                i = i - j + 1;
                break;
            }
        }
        if (j == needle.size())
        {
            return i - needle.size();
        }

    }
    if (i == haystack.size())
    {
        return -1;
    }
    return 0;
}

//KMP算法字符串匹配(D数组)
vector<int> get_next(string p)
{
    int i = 1;
    int j = 0;
    vector<int> D;
    D.resize(p.size());     //创建与模式串相同大小的 D（最长公共前后缀）
    D[0] = 0;
    while (i < p.size())
    {
        if (p[i] == p[j])       //相等则 i 和 j 都进行移动，根据对应关系，D[i]=++j
        {
            j++;
            D[i] = j;
            i++;
        }
        else                      //不相等模式串指针 j 进行回溯
        {
            if (j > 0)
            {
                j = D[j - 1];       //j回溯
            }
            else
            {
                D[i] = 0;
                i++;    //此时模式串中 j = 0 了，需要移动 i
            }
        }
    }
    return D;
}

//KMP算法字符串匹配(D数组)       改进版
vector<int> get_nexteval(string p)
{
    int i = 1;
    int j = 0;
    vector<int> D;
    D.resize(p.size());     //创建与模式串相同大小的 D（最长公共前后缀）
    D[0] = 0;
    while (i < p.size()-1)
    {
        if (p[i] == p[j])       //相等则 i 和 j 都进行移动，根据对应关系，D[i]=++j
        {
            ++j;
            if (p[i + 1] == p[j])       //**改进的位置(如果)
            {
                D[i] = D[j - 1];           //字符相同则使用 D[j] 替换 D[i] 的下一个
                i++;
            }
            else                    //如果后续的字符不相等，则按照常规方式 D[i]=++j
            {
                D[i] = j;
                i++;
            }
        }
        else                      //不相等则模式串指针 j 进行回溯
        {
            if (j > 0)
            {
                j = D[j - 1];       //j回溯
            }
            else
            {
                D[i] = 0;
                i++;    //此时模式串中 j = 0 了，需要移动 i
            }
        }
    }
    return D;
}

//KMP字符串查找
int kmp(string T, string P)
{
    if (P.empty())
    {
        return 0;
    }
//    vector<int> next = get_next(P);
    vector<int> next = get_nexteval(P);

    int i, j = 0;
    for (i = 0; i < T.size(); i++)
    {
        while (j < P.size())
        {
            if (i == T.size())      // i 移动到 T 串末尾，说明没有在 T 串中找到 P 串
            {
                return -1;
            }
            if (T[i] == P[j])       //单个字符相等则继续移动串指针
            {
                i++;
                j++;
            }
            else                    //不相等则 j 需要回溯
            {
                if (j > 0)
                {
                    j = next[j - 1];
                }
                else              //如果 j =0 ，需要移动i（ T 和 P 首字母不匹配）
                {
                    i++;
                }
            }
        }
        if (j == P.size())      // j 移动到 P 串末尾，说明在T串中找到了 P 串
        {
            return i - P.size();
        }
    }
    return 0;       // T 中不存在 P 则返回0
}

int main()
{
//    vector<int> arr;
////    生成随机数组
//    for (int i = 0; i < 300; i++) {
////        srand(i);
//        arr.push_back(rand());
//    }
//    shell_sort(arr);
//    sort(arr.begin(), arr.end(), less<int>());//升序排列
    string a = "aabaaabaaac";
    string b = "aaabbbx";//aabaaac
//    int c = strStr(a, b);
//    vector<int> next = get_next(b);
    int flag = kmp(a, b);
    return 0;
}
