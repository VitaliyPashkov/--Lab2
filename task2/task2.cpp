#include <iostream>
#include <math.h>
#include <string>
using namespace std;
class Fraction {
public:
    double dividend;
    double divisor;
    static int countOfFractions;
    Fraction(int dividend, int divisor) {
        this->dividend = dividend / gcd(dividend, divisor);
        this->divisor = divisor / gcd(dividend, divisor);
        countOfFractions++;
    }
    static int gcd(int n, int m) {
        while (m)
        {
            int temp = m;
            m = n % m;
            n = temp;
        }
        return n;
    }
    // ======================перегрузка операторов=======================

    Fraction* operator + (Fraction n) { // перегрузка операторов
        return this->doubleAsFraction(this->toDouble() + n.toDouble());
    }
    Fraction* operator - (Fraction n) {
        return this->doubleAsFraction(this->toDouble() - n.toDouble());
    }
    Fraction* operator * (Fraction n) {
        return this->doubleAsFraction(this->toDouble() * n.toDouble());
    }
    Fraction* operator / (Fraction n) {
        return this->doubleAsFraction(this->toDouble() / n.toDouble());
    }
    static void printAsFraction(double decimal_fraction) { // функия печати десятичной дроби (типа double) в обыкновенную
        Fraction* fraction = doubleAsFraction(decimal_fraction);
        cout << fraction->dividend << "/" << fraction->divisor << endl;
    }
    static void printAsFraction(char* decimal_fraction) { // функия печати десятичной дроби (типа char*) в обыкновенную
        double n = stod(decimal_fraction);
        printAsFraction(n);
    }
    void print() { // функция печати дроби на консоль
        cout << dividend << "/" << divisor << endl;
    }
private:
    double toDouble() {
        return dividend / divisor;
    }
    static Fraction* doubleAsFraction(double number) { // функция преобразования десятичной дроби в обыкновенную
        double intVal = floor(number);
        double fVal = number - intVal;
        const long pVal = pow(10, 9);
        long long gcdVal
            = gcd(round(fVal * pVal), pVal);
        long long num
            = round(fVal * pVal) / gcdVal;
        long long deno = pVal / gcdVal;
        return new Fraction((intVal * deno) + num, deno);
    }
};
int Fraction::countOfFractions = 0; // переменная для подсчета количества созданных дробей
int main()
{
    //setlocale(LC_ALL, "Rus");

    Fraction* fraction1 = new Fraction(1, 4); // создание экземпляра класса - первой дроби
    Fraction* fraction2 = new Fraction(5, 25); // второй
    string str = "3.66"; // случайно взятое десятичное число для демонстрации
    char fraction3[10];
    strcpy_s(fraction3, str.c_str());
    Fraction* sum = *fraction1 + *fraction2; // вычисления для демонстрации работы перегруженных операторов
    Fraction* multiplication = *fraction1 * *fraction2;
    Fraction* substraction = *fraction1 - *fraction2;
    Fraction* division = *fraction1 / *fraction2;
    cout << "Первая дробь: ";
    fraction1->print();
    cout << "Вторая дробь: ";
    fraction2->print();
    cout << "Сложение: ";
    sum->print();
    cout << "Умножение: ";
    multiplication->print();
    cout << "Вычитание: ";
    substraction->print();
    cout << "Деление: ";
    division->print();
    cout << str << " в виде дроби: ";
    Fraction::printAsFraction(fraction3);
    cout << "НОД(63, 774): " << Fraction::gcd(63, 774) << endl;
    cout << "Количество дробей: " << Fraction::countOfFractions << endl;
}