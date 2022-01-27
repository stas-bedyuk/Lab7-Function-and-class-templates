// 3 sem lab 7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>

using namespace std;

template <typename T1, typename T2>
T1 sort(T1 a, T2 b) {
    cout << "default" << endl;
    float m;
    for (int i = 0; i < b ; i++) 
    {
        m = a[i];
        a[i] = a[b -1];
        a[b -1] = m;
        b--;
    }
    return a;
}
//qwerty123ty54
template <> char* sort(char* a, int b) {
    char m;
    int y=0;
    cout << "specialized" << endl;
    for (int i = 0; i < b; i++)
    {
        for (int j = b - 1; j > i; j--)
        {
            if (a[j] > 47 && a[j] < 58)
            {
                m = a[j-1];
                a[j -1] = a[j];
                a[j] = m;
            }
        }
    }
    int j = 0;
    while (a[j] > 47 && a[j] < 58) j++;
    for (int i = j; i < b; i++)
    {
       m = a[i];
        a[i] = a[b - 1];
        a[b - 1] = m;
        b--;
    }
    return a;
}

int main() {
    cout << "___ CHAR ___" << endl;
    char* str = new char[50];
    cout << "Enter string: ";
    cin.getline(str, 50);
    int len = strlen(str);
    cout << "Sort: " << sort(str, len) << endl;

    cout << "___ INT ___" << endl;
    int size;
    cout << "Enter number of elements: ";
    cin >> size;
    int* massiv = new int[size];
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> massiv[i];
    }
    massiv = sort(massiv, size);
    cout << "Sort: ";
    for (int i = 0; i < size; i++)
        cout << " " << massiv[i];

    cout << "\n___ FLOAT ___" << endl;
    int size1;
    cout << "Enter number of elements: ";
    cin >> size1;
    float* massiv2 = new float[size1];
    cout << "Enter " << size1 << " elements:" << endl;
    for (int i = 0; i < size1; i++) {
        cin >> massiv2[i];
    }
    massiv2 = sort(massiv2, size1);
    cout << "Sort: "; 
    for (int i = 0; i < size1; i++)
        cout << "  " << massiv2[i];
    delete[]str;
    delete[]massiv;
    delete[]massiv2;
    return 0;
}