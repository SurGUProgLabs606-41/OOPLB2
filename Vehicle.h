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
    Vehicle(const string& brand, double speed,
            double fuel, double maxFuel, bool engineState);

    // Конструктор копирования
    Vehicle(const Vehicle& other);

    // Деструктор
    ~Vehicle();

    // Статический метод
    static int getObjectCount();
};

#endif