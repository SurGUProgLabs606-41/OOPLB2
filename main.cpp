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

    // Начальное состояние
    cout << "\n=== Начальное состояние ===\n";

    cout << "\nАвтомобиль 1:";
    car1.print();

    cout << "\nАвтомобиль 2:";
    car2.print();

    cout << "\nАвтомобиль 3:";
    car3.print();

    // Корректные операции
    cout << "\n=== Корректные операции ===\n";

    car2.startEngine();
    car2.accelerate(50);
    car2.brake(20);
    car2.refuel(10);

    car2.print();

    // Некорректные операции
    cout << "\n=== Некорректные операции ===\n";

    car1.accelerate(30);
    car2.refuel(100);
    car2.brake(-10);
    car2.accelerate(-20);

    // Проверка состояния после ошибок
    cout << "\n=== Состояние после ошибок ===\n";

    car2.print();

    // Проверка независимости объектов
    cout << "\n=== Проверка независимости объектов ===\n";

    cout << "\nИзменяем car1...\n";

    car1.refuel(20);
    car1.startEngine();
    car1.accelerate(30);

    cout << "\nCar1:";
    car1.print();

    cout << "\nCar2:";
    car2.print();

    cout << "\nCar3:";
    car3.print();

    // Количество объектов
    cout << "\nКоличество объектов: "
         << Vehicle::getObjectCount() << "\n";

    return 0;
}