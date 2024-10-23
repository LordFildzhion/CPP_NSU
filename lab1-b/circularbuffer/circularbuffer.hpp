#include <iostream>
#include <algorithm>
#include <concepts>
#include <type_traits>

#pragma once
template <typename T>
class CircularBuffer{
 public:
    CircularBuffer(): cap {0}, arr{{}}, current_size{0}, first_element{0}
    { }
    
    CircularBuffer(const CircularBuffer &a_): cap{a_.capacity()}, arr{new T[cap]}, current_size{a_.size()}, first_element{0} {
        for (size_t it = 0; it < current_size; it++) {
            arr[it] = a_[it];
        }
    }
    
    CircularBuffer(const size_t cap_, T def):  cap{cap_}, arr{new T[cap_] }, current_size{cap_}, first_element{0} {
        for (size_t it = 0; it < cap; it++) {
            arr[it] = def;
        }
    }
    
    ~CircularBuffer() { delete[] arr; }

    T &operator[](size_t index);
    const T &operator[](size_t index) const;
  
    //Доступ по индексу. Методы бросают исключение в случае неверного индекса.
    T &at(size_t index);
    const T &at(size_t index) const;

    T &front(); //Ссылка на первый элемент.
    T &back();  //Ссылка на последний элемент.
    const T &front() const;
    const T &back() const;

    //Линеаризация - сдвинуть кольцевой буфер так, что его первый элемент
    //переместится в начало аллоцированной памяти. Возвращает указатель 
    //на первый элемент.
    T *linearize();
    //Проверяет, является ли буфер линеаризованным.
    bool is_linearized() const;
    //Сдвигает буфер так, что по нулевому индексу окажется элемент 
    //с индексом new_begin.
    void rotate(size_t new_begin);
    //Количество элементов, хранящихся в буфере.
    size_t size() const;
    bool empty() const;
    //true, если size() == capacity().
    bool full() const;
    //Количество свободных ячеек в буфере.
    size_t reserve() const;
    //ёмкость буфера
    size_t capacity() const;

    void set_capacity(const size_t &new_capacity);
    //Изменяет размер буфера.
    //В случае расширения, новые элементы заполняются элементом item.
    void resize(size_t new_size, const T &item);
    //Оператор присваивания.
    CircularBuffer &operator=(const CircularBuffer &new_buffer);
    //Обменивает содержимое буфера с буфером cb.
    void swap(CircularBuffer &cb);

    //Добавляет элемент в конец буфера. 
    //Если текущий размер буфера равен его ёмкости, то переписывается
    //первый элемент буфера (т.е., буфер закольцован). 
    void push_back(const T &item);
    //Добавляет новый элемент перед первым элементом буфера. 
    //Аналогично push_back, может переписать последний элемент буфера.
    void push_front(const T &item);
    //удаляет последний элемент буфера.
    void pop_back();
    //удаляет первый элемент буфера.
    void pop_front();

    //Вставляет элемент item по индексу pos. Ёмкость буфера остается неизменной.
    void insert(const size_t pos, const T &item);
    //Удаляет элементы из буфера в интервале [first, last).
    void erase(size_t first, size_t last);
    //Очищает буфер.
    void clear();

    bool operator==(const CircularBuffer &b);
    bool operator!=(const CircularBuffer &b);


private:
    size_t cap;
    T *arr;
    size_t current_size;
    size_t first_element;
};
