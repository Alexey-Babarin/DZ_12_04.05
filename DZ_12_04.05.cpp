#include <iostream>
#include <locale.h> // Для подключения русской локали

using namespace std;

class Array 
{
public:
    int arr[5]; // Массив из 5 элементов

    Array() 
    {
        for (int i = 0; i < 5; i++) 
        {
            arr[i] = 0; // Инициализация массива нулями
        }
    }

    friend Array operator+(int num, Array& a) // Перегрузка оператора сложения для суммирования числа с объектом класса
    {
        Array temp;
        for (int i = 0; i < 5; i++) 
        {
            temp.arr[i] = num + a.arr[i]; // Суммирование числа с каждым элементом массива
        }
        return temp;
    }

    friend ostream& operator<<(ostream& os, const Array& a) // Перегрузка оператора вывода для объекта класса
    {
        for (int i = 0; i < 5; i++) 
        {
            os << a.arr[i] << " "; // Вывод элементов массива через пробел
        }
        return os;
    }
};

int main() 
{
    setlocale(LC_ALL, "Russian"); // Установка русской локали

    Array arr1;
    Array arr2;

    cout << "Введите 5 целых чисел для заполнения первого массива: ";
    for (int i = 0; i < 5; i++) 
    {
        cin >> arr1.arr[i];
    }

    arr2 = 10 + arr1; // Пример использования оператора сложения

    cout << "Первый массив: " << arr1 << endl;
    cout << "Сумма второго массива: " << arr2 << endl;

    return 0;
}