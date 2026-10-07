#include <iostream>
#include "Vehicle.h"

using namespace std;

int main()
{
    // Создание автомобиля с конструктором без параметров
    Vehicle car1;

    // Создание автомобиля с параметризованным конструктором
    Vehicle car2("Toyota", 0, 30, 60, false);

    // Создание автомобиля с помощью конструктора копирования
    Vehicle car3(car2);

    return 0;
}