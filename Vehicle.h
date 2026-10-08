#ifndef VEHICLE_H
#define VEHICLE_H
// Файл объявления класса Vehicle.
#include <string>

using namespace std;
// Обращаться к Private можно только через публичные методы класса. 
/**
 * @brief Класс для представления автомобиля.
 *
 * [1] Класс содержит несколько полей разных типов.
 * Требование о поле пользовательского типа требует отдельного класса.
 * [2] Используются типы string, double и bool.
 * [3] Все поля класса объявлены private.
 * [4] Для получения состояния автомобиля предусмотрены
 * публичные методы.
 */
class Vehicle
{
private:
    /** @brief [1] Марка автомобиля. */
    string brand;

    /** @brief [1] Текущая скорость автомобиля. */
    double speed;

    /** @brief [1] Количество топлива. */
    double fuel;

    /** @brief [1] Состояние двигателя. */
    bool engineState;

    /** @brief [1] Максимальный объём топливного бака. */
    double maxFuel;

    /** @brief [21] Количество существующих объектов класса. */
    static int objectCount;

public:
    /**
     * @brief [5] Конструктор без параметров.
     *
     * Создаёт автомобиль с корректным начальным состоянием.
     */
    Vehicle();

    /**
     * @brief [6] Параметризованный конструктор.
     *
     * @param brand Марка автомобиля.
     * @param speed Начальная скорость.
     * @param fuel Начальное количество топлива.
     * @param maxFuel Максимальный объём бака.
     * @param engineState Начальное состояние двигателя.
     *
     * [8] Реализация конструктора использует список инициализации.
     */
    Vehicle(const string& brand, double speed, double fuel, double maxFuel, bool engineState);

    /**
     * @brief [7] Конструктор копирования.
     *
     * Используется как третий способ создания объекта.
     *
     * @param other Объект для копирования.
     */
    Vehicle(const Vehicle& other);

    /**
     * @brief [16] Явно объявленный деструктор.
     */
    ~Vehicle();

    /**
     * @brief [9] Возвращает марку автомобиля.
     *
     * @return Марка автомобиля.
     */
    string getBrand() const;

    /**
     * @brief [9] Возвращает скорость автомобиля.
     *
     * @return Скорость автомобиля.
     */
    double getSpeed() const;

    /**
     * @brief [9] Возвращает количество топлива.
     *
     * @return Количество топлива.
     */
    double getFuel() const;

    /**
     * @brief [9] Проверяет состояние двигателя.
     *
     * @return true, если двигатель включен, иначе false.
     *
     * [10] Метод не изменяет объект и объявлен const.
     */
    bool isEngineRunning() const;

    /**
     * @brief [21] Возвращает количество существующих объектов.
     *
     * @return Количество объектов Vehicle.
     */
    static int getObjectCount();

    /**
     * @brief [11] Запускает двигатель автомобиля.
     *
     * @return true при успешном запуске, иначе false.
     */
    bool startEngine();

    /**
     * @brief [11] Останавливает двигатель автомобиля.
     *
     * @return true при успешной остановке, иначе false.
     */
    bool stopEngine();

    /**
     * @brief [11] Увеличивает скорость автомобиля.
     *
     * @param value Величина увеличения скорости.
     * @return true при успешной операции, иначе false.
     */
    bool accelerate(double value);

    /**
     * @brief [11] Уменьшает скорость автомобиля.
     *
     * @param value Величина уменьшения скорости.
     * @return true при успешной операции, иначе false.
     */
    bool brake(double value);

    /**
     * @brief [11] Заправляет автомобиль.
     *
     * @param amount Количество топлива.
     * @return true при успешной заправке, иначе false.
     */
    bool refuel(double amount);

    /**
     * @brief [15] Выводит информацию об автомобиле.
     *
     * [10] Метод не изменяет объект и объявлен const.
     */
    void print() const;
};

#endif