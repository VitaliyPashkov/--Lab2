#pragma once
#include <iostream>
#include "vector.h"
#include <iomanip>
using namespace std; 

class Matrix {
public:
    int** arr;
    Matrix(size_t N, size_t M) { //конструктор с параметрами
        this->N = N;
        this->M = M;
        arr = new int* [N];
        for (size_t i = 0; i < N; i++)
        {
            arr[i] = new int[M];
        }
        initializeArray();
    }
    ~Matrix() {
        for (size_t i = 0; i < N; i++)
        {
            delete[] arr[i];
        }
        delete[] arr; // деструктор
    }
    int at(size_t i, size_t j) {
        return arr[i][j];
    }
    int setAt(size_t i, size_t j, int val) {
        arr[i][j] = val;
    }
    void operator ++ () { //перегрузка оператора ++ без параметров
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                arr[N][M]++;
            }
        }
    }
    void operator ++ (int d) { //перегрузка оператора ++ с параметром 
        this->operator++();
    }
    void operator -- () {
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                arr[N][M]--;
            }
        }
    }
    void operator -- (int d) { //перегрузка оператора -- без параметров
        this->operator--();
    }
    void print() { 
        cout << "[";

        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < N; ++j)
                cout << setw(8) << arr[i][j];

            if (i + 1 != N)
                cout << endl << " ";
            else
                cout << setw(8) << "]\n\n" << setw(30) << "=>\n\n";

        }


    }
    void initializeArray()
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < N; ++j) {
                arr[i][j] = fact(i) + fact(j);
            }
            // эквивалентно: arr[i][j] = i! + j!
        }
    }
private:
    int fact(int n) //вспомогательная функция для вычисления факториала
    {
        int result = 1;
        for (int i = 2; i <= n; i++)
            result *= i;
        return result;
    }
    size_t N;
    size_t M;

};
