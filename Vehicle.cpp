#include "Vehicle.h"
#include <iostream>

using namespace std;

int Vehicle::objectCount = 0;

// Конструктор без параметров
Vehicle::Vehicle()
    : brand("Unknown"),
      speed(0),
      fuel(0),
      engineState(false),
      maxFuel(50)
{
    objectCount++;
}

// Параметризованный конструктор
Vehicle::Vehicle(const string& brand, double speed, double fuel, double maxFuel, bool engineState)
    : brand(brand),
      speed(speed),
      fuel(fuel),
      engineState(engineState),
      maxFuel(maxFuel)
{
    if (speed < 0)
        this->speed = 0;

    if (maxFuel <= 0)
        this->maxFuel = 50;

    if (fuel < 0)
        this->fuel = 0;

    if (fuel > this->maxFuel)
        this->fuel = this->maxFuel;

    objectCount++;
}

// Конструктор копирования
Vehicle::Vehicle(const Vehicle& other)
    : brand(other.brand),
      speed(other.speed),
      fuel(other.fuel),
      engineState(other.engineState),
      maxFuel(other.maxFuel)
{
    objectCount++;
}

// Деструктор
Vehicle::~Vehicle()
{
    objectCount--;
}

int Vehicle::getObjectCount()
{
    return objectCount;
}

// Запуск двигателя
bool Vehicle::startEngine()
{
    if (engineState == true)
    {
        cout << "Двигатель уже запущен.\n";
        return false;
    }

    if (fuel <= 0)
    {
        cout << "Нельзя запустить двигатель: нет топлива.\n";
        return false;
    }

    engineState = true;

    cout << "Двигатель запущен.\n";

    return true;
}

// Остановка двигателя
bool Vehicle::stopEngine()
{
    if (engineState == false)
    {
        cout << "Двигатель уже выключен.\n";
        return false;
    }

    engineState = false;

    cout << "Двигатель остановлен.\n";

    return true;
}

// Ускорение
bool Vehicle::accelerate(double value)
{
    if (engineState == false)
    {
        cout << "Нельзя ускориться: двигатель выключен.\n";
        return false;
    }

    if (value <= 0)
    {
        cout << "Ускорение должно быть больше нуля.\n";
        return false;
    }

    if (fuel <= 0)
    {
        cout << "Нельзя ускориться: нет топлива.\n";
        return false;
    }

    speed += value;

    // Расход топлива
    fuel -= value * 0.1;

    if (fuel < 0)
        fuel = 0;

    return true;
}

// Торможение
bool Vehicle::brake(double value)
{
    if (value <= 0)
    {
        cout << "Торможение должно быть больше нуля.\n";
        return false;
    }

    if (speed == 0)
    {
        cout << "Автомобиль уже стоит.\n";
        return false;
    }

    speed -= value;

    // Скорость не может быть отрицательной
    if (speed < 0)
        speed = 0;

    return true;
}

// Заправка
bool Vehicle::refuel(double amount)
{
    if (amount <= 0)
    {
        cout << "Количество топлива должно быть больше нуля.\n";
        return false;
    }

    if (fuel + amount > maxFuel)
    {
        cout << "Нельзя заправить автомобиль: превышен объём бака.\n";
        return false;
    }

    fuel += amount;

    return true;
}