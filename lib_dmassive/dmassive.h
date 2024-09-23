#ifndef DMASSIVE_H
#define DMASSIVE_H

#include <stdexcept>
#include <iostream>

template <typename T>
class TDMassive {
public:
    // Конструктор
    TDMassive() : m_data(nullptr), m_size(0), m_capacity(0) {}

    // Деструктор
    ~TDMassive() { delete[] m_data; }

    // Вставка элемента на заданную позицию
    void insert(size_t index, const T& value) {
        if (index > m_size) {
            throw std::out_of_range("Index out of range");
        }

        if (m_size == m_capacity) {
            resize();
        }

        // Сдвигаем элементы после index
        for (size_t i = m_size; i > index; --i) {
            m_data[i] = m_data[i - 1];
        }

        // Вставляем значение
        m_data[index] = value;
        m_size++;
    }

    // Поиск элемента по значению
    int find(const T& value) const noexcept {
        for (size_t i = 0; i < m_size; ++i) {
            if (m_data[i] == value) {
                return i; // Возвращаем индекс найденного элемента
            }
        }
        return -1; // Возвращаем -1, если элемент не найден
    }

    // Удаление элемента по индексу
    void erase(size_t index) {
        if (index < m_size) {
            for (size_t i = index; i < m_size - 1; ++i) {
                m_data[i] = m_data[i + 1];
            }
            m_size--;
        }
        else {
            throw std::out_of_range("Index out of range");
        }
    }

    // Замена элемента по индексу
    void replace(size_t index, const T& value) {
        if (index < m_size) {
            m_data[index] = value;
        }
        else {
            throw std::out_of_range("Index out of range");
        }
    }

    // Очистка массива
    void clear() noexcept {
        m_size = 0;
        delete[] m_data;
        m_data = nullptr;
    }

    // Вывод массива на экран
    friend std::ostream& operator<<(std::ostream& os, const TDMassive& massive) {
        os << "Массив: ";
        for (size_t i = 0; i < massive.m_size; ++i) {
            os << massive.m_data[i] << " ";
        }
        return os;
    }

    // Оператор доступа к элементу
    T& operator[](size_t index) {
        if (index >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];
    }

    // Оператор доступа к элементу (const версия)
    const T& operator[](size_t index) const {
        if (index >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];
    }

    // Метод для получения размера массива
    size_t size() const {
        return m_size;
    }

private:
    T* m_data; // Указатель на динамический массив
    size_t m_size; // Количество элементов в массиве
    size_t m_capacity; // Текущая вместимость массива

    // Вспомогательная функция для расширения массива
    void resize() {
        m_capacity = m_capacity == 0 ? 1 : m_capacity * 2; // Увеличиваем вместимость в 2 раза
        T* new_data = new T[m_capacity];

        // Копируем данные в новый массив
        for (size_t i = 0; i < m_size; ++i) {
            new_data[i] = m_data[i];
        }

        delete[] m_data; // Освобождаем память старого массива
        m_data = new_data; // Присваиваем указатель на новый массив
    }
};

#endif // DMASSIVE_H
