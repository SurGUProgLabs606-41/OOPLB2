#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

using namespace std;

class Vehicle
{
private:
    string brand;
    double speed;
    double fuel;
    bool engineState;
    double maxFuel;

    static int objectCount;

public:
    // Конструктор без параметров
    Vehicle();

    // Параметризованный конструктор
    Vehicle(const string& brand, double speed, double fuel, double maxFuel, bool engineState);

    // Конструктор копирования
    Vehicle(const Vehicle& other);

    // Деструктор
    ~Vehicle();

    // Методы получения
    string getBrand() const;
    double getSpeed() const;
    double getFuel() const;
    bool isEngineRunning() const;

    // Статический метод
    static int getObjectCount();

    // Методы изменения состояния
    bool startEngine();
    bool stopEngine();
    bool accelerate(double value);
    bool brake(double value);
    bool refuel(double amount);

    // Вывод информации
    void print() const;
};

#endif