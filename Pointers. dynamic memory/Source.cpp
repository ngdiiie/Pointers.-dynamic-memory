/*
//1. Объявить указатели на две переменные указанного типа. Используя указатели
//произвести операции сложения и вычитания над переменными.Вывести адреса
//указателей. double


//2. Написать функцию для обмена значений переменных, указанных выше.Передача по
//указателю.Выполнить программу по шагам и выписать в тетрадь адреса указателей
//и величины переменных. double

#include <iostream>
void swap(double* ptr1, double* ptr2) {
    double temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
int main() {
    setlocale(LC_ALL, "rus");
    double a = 10.5;
    double b = 5.2;
    double* ptrA = &a;
    double* ptrB = &b;
    std::cout << "PtrA: " << ptrA << std::endl;
    std::cout << "PtrB: " << ptrB << std::endl;
    std::cout << "Значение a: " << *ptrA << std::endl;
    std::cout << "Значение b: " << *ptrB << std::endl;
    swap(ptrA, ptrB);
    std::cout << "After swap:" << std::endl;
    std::cout << "Значение a: " << *ptrA << std::endl;
    std::cout << "Значение b: " << *ptrB << std::endl;
    return 0;
}
// Output:
// Address of ptrA: 0x7ffee6e9c918
// Address of ptrB: 0x7ffee6e9c910
// Value of a: 10.5
// Value of b: 5.2
// After swap:
// Value of a: 5.2
// Value of b: 10.5
*/

/*
//3. Объявить динамический массив. Размер массива задаёт пользователь. Заполнить
//массив случайными числами.Вывести на экран адреса и значения элементов
//массива. double
#include <iostream>
#include <cstdlib> 
#include <ctime> 
int main() {
    setlocale(LC_ALL, "rus");
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    double* arr = new double[size];
    srand(time(0)); 
    for (int i = 0; i < size; i++) {
        arr[i] = (double)rand() / RAND_MAX; 
    }
    for (int i = 0; i < size; i++) {
        std::cout << "Адресс" << i << "]: " << &arr[i] << std::endl;
        std::cout << "Значение" << i << "]: " << arr[i] << std::endl;
    }
    delete[] arr; 
    return 0;
}
*/

//Объявить сущность и описать её свойства. Объявить динамический массив
//сущностей.Реализовать функцию, которая изменяет значения элемента(структура)
//массива.Заполнить атрибуты числовыми и текстовыми значениями(диапазон
//значений определить самостоятельно). H.обувь
#include <iostream>
#include <string>
struct Shoe {
    std::string brand;
    int size;
    std::string color;
    std::string material;
    double price;
};
void changeShoe(Shoe* shoe, std::string brand, int size, std::string color, std::string material, double price) {
    shoe->brand = brand;
    shoe->size = size;
    shoe->color = color;
    shoe->material = material;
    shoe->price = price;
}
int main() {
    setlocale(LC_ALL, "rus");
    int size = 5;
    Shoe* shoes = new Shoe[size];
    for (int i = 0; i < size; i++) {
        shoes[i].brand = "Nike";
        shoes[i].size = rand() % 10 + 36;
        shoes[i].color = "Black";
        shoes[i].material = "Leather";
        shoes[i].price = (double)rand() / RAND_MAX * 100 + 50;
    }
    for (int i = 0; i < size; i++) {
        std::cout << "Бренд: " << shoes[i].brand << ", Size: " << shoes[i].size << ", Color: " << shoes[i].color
            << ", Материал: " << shoes[i].material << ", Price: " << shoes[i].price << std::endl;
    }
    changeShoe(&shoes[0], "Adidas", 38, "White", "Textile", 80.0);
    std::cout << "После изменения:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "Бренд: " << shoes[i].brand << ", Size: " << shoes[i].size << ", Color: " << shoes[i].color
            << ", Материал: " << shoes[i].material << ", Price: " << shoes[i].price << std::endl;
    }
    delete[] shoes;
    return 0;
}