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
Vehicle::Vehicle(const string& brand, double speed,
                 double fuel, double maxFuel, bool engineState)
    : brand(brand),
      speed(speed),
      fuel(fuel),
      engineState(engineState),
      maxFuel(maxFuel)
{
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