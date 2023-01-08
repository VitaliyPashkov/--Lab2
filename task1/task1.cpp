#include <iostream>
#include "vector.h" // подключение хэдеров - наших классов
#include "matrix.h"
int main()
{
    setlocale(LC_ALL, "Rus");
    Matrix* matrix = new Matrix(5, 5); // создание матрицы 5х5
    Vector* vector = new Vector(10); // создание вектора длиной 10

    matrix->print();
    vector->makeArray1D(matrix);
    vector->print();

    delete matrix; // очистка памяти посредством удаления объектов
    delete vector;

}