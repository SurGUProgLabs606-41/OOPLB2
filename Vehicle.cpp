#include "Vehicle.h"
#include <iostream>

using namespace std;

/**
 * @brief [21] Инициализация статического счётчика объектов.
 */
int Vehicle::objectCount = 0;

/**
 * @brief [5] Конструктор без параметров.
 *
 * [13] Объект создаётся сразу с корректным состоянием.
 */
Vehicle::Vehicle()
    : brand("Unknown"),
      speed(0),
      fuel(0),
      engineState(false),
      maxFuel(50)
{
    objectCount++;
}

/**
 * @brief [6] Параметризованный конструктор.
 *
 * [8] Используется список инициализации.
 *
 * [13] Проверяется корректность переданных значений.
 *
 * @param brand Марка автомобиля.
 * @param speed Начальная скорость.
 * @param fuel Начальное количество топлива.
 * @param maxFuel Максимальный объём бака.
 * @param engineState Состояние двигателя.
 */
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

    if (this->fuel <= 0)
        this->engineState = false;

    objectCount++;
}

/**
 * @brief [7] Конструктор копирования.
 *
 * Создаёт независимую копию другого объекта.
 *
 * @param other Объект для копирования.
 */
Vehicle::Vehicle(const Vehicle& other)
    : brand(other.brand),
      speed(other.speed),
      fuel(other.fuel),
      engineState(other.engineState),
      maxFuel(other.maxFuel)
{
    objectCount++;
}

/**
 * @brief [16] Деструктор.
 *
 * [21] При уничтожении объекта счётчик уменьшается.
 */
Vehicle::~Vehicle()
{
    objectCount--;
}

/**
 * @brief [9] Возвращает марку автомобиля.
 *
 * @return Марка автомобиля.
 */
string Vehicle::getBrand() const
{
    return brand;
}

/**
 * @brief [9] Возвращает скорость автомобиля.
 *
 * @return Скорость автомобиля.
 */
double Vehicle::getSpeed() const
{
    return speed;
}

/**
 * @brief [9] Возвращает количество топлива.
 *
 * @return Количество топлива.
 */
double Vehicle::getFuel() const
{
    return fuel;
}

/**
 * @brief [9][10] Проверяет состояние двигателя.
 *
 * @return true, если двигатель включен, иначе false.
 */
bool Vehicle::isEngineRunning() const
{
    return engineState;
}

/**
 * @brief [21] Возвращает количество существующих объектов.
 *
 * @return Количество объектов Vehicle.
 */
int Vehicle::getObjectCount()
{
    return objectCount;
}

/**
 * @brief [11][13] Запускает двигатель автомобиля.
 *
 * Двигатель нельзя запустить, если он уже работает
 * или отсутствует топливо.
 *
 * @return true при успешном запуске, иначе false.
 */
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

/**
 * @brief [11][13] Останавливает двигатель автомобиля.
 *
 * @return true при успешной остановке, иначе false.
 */
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

/**
 * @brief [11][13] Увеличивает скорость автомобиля.
 *
 * [13] Проверяется корректность операции и наличие топлива.
 *
 * @param value Величина увеличения скорости.
 * @return true при успешной операции, иначе false.
 */
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

/**
 * @brief [11][13] Уменьшает скорость автомобиля.
 *
 * @param value Величина уменьшения скорости.
 * @return true при успешной операции, иначе false.
 */
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

/**
 * @brief [11][13] Заправляет автомобиль.
 *
 * [13] Проверяется максимальный объём топливного бака.
 *
 * @param amount Количество топлива.
 * @return true при успешной заправке, иначе false.
 */
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

/**
 * @brief [15] Выводит информацию об автомобиле.
 *
 * [10] Метод объявлен const, так как не изменяет состояние объекта.
 */
void Vehicle::print() const
{
    cout << "\n--- Автомобиль ---\n";
    cout << "Марка: " << brand << '\n';
    cout << "Скорость: " << speed << " км/ч\n";
    cout << "Топливо: " << fuel << " л\n";
    cout << "Максимальный объём бака: " << maxFuel << " л\n";

    if (engineState == true)
        cout << "Двигатель: включен\n";
    else
        cout << "Двигатель: выключен\n";
}