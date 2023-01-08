#pragma once
#include <iostream>
#include "matrix.h"
class Vector { //создание класса Vector 
public:
    int* arr;
    Vector(size_t N) { // конструктор с параметром
        arr = new int[N];
        this->N = N;
    }
    ~Vector() { // деструктор
        delete[] arr;
    }
    int operator [] (int i) { // перегрузка оператора []
        return arr[i];
    }
    void operator ++ () { // прегрузка оператора ++
        for (size_t i = 0; i < N; i++)
        {
            arr[i]++;
        }
    }
    void operator ++ (int d) {
        this->operator++();
    }
    void operator -- () { // прегрузка оператора --
        for (size_t i = 0; i < N; i++)
        {
            arr[i]--;
        }
    }
    void operator -- (int d) {
        this->operator--();
    }
    void print() { // функция вывода в консоль
        std::cout << "[";
        for (size_t i = 0; i < N; ++i)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\b]" << std::endl;
    }
    void makeArray1D(Matrix* matrix)
    {
        for (size_t i = 1; i < N / 2; i += 2) // N/2 здесь - количество нечетных строк в матрице
        {
            for (size_t j = 0; j < N / 2; ++j)
            {
                arr[j + 5 * (i - 1) / 2] = (*matrix).at(i, j); // заполняем массив
            }
        }
    }
private:
    size_t N;
};