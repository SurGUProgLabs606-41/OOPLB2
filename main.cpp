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

    cout << "Количество объектов: "
         << Vehicle::getObjectCount() << "\n";

    // Корректные операции
    cout << "\n=== Корректные операции ===\n";

    car2.startEngine();
    car2.accelerate(50);
    car2.brake(20);
    car2.refuel(10);

    return 0;
}