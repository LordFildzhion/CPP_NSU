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
  
    //Index access. The methods throw an exception if the index is invalid.
    T &at(size_t index);
    const T &at(size_t index) const;

    T &front(); //Link to the first item.
    T &back();  //Link to the last item.
    const T &front() const;
    const T &back() const;

    //linearization - move the ring buffer so that its first element
    //will move to the beginning of the allocated memory. Returns a pointer 
    //on the first element.
    T *linearize();

    //Checks if the buffer is linearized.
    bool is_linearized() const;

    //Shifts the buffer so that the 
    //with index new_begin.
    void rotate(const size_t new_begin);
    
    //Size of circular buffer
    size_t size() const;

    //True, if size() == 0
    bool empty() const;
    
    //True, if size() == capacity().
    bool full() const;
    
    //The number of free cells in the buffer.
    size_t reserve() const;
    
    //Buffer's capacity
    size_t capacity() const;
    
    //Changes the size of the buffer.
    void set_capacity(const size_t &new_capacity);
    
    //Changes the size of the buffer.
    //In the case of extension, new items are populated with the item element.
    void resize(size_t new_size, const T &item);
    
    //Assignment statement.
    CircularBuffer &operator=(const CircularBuffer &new_buffer);
    
    //It exchanges the contents of the buffer with the cb buffer.
    void swap(CircularBuffer &cb);

    //Adds an item to the end of the buffer. 
    //If the current buffer size is equal to its capacity, then the
    //the first element of the buffer (i.e., the buffer is looped). 
    void push_back(const T &item);

    //Adds a new item before the first buffer item. 
    //Similarly push_back, can overwrite the last element of the buffer.
    void push_front(const T &item);

    //Deletes the last element of the buffer.
    void pop_back();
    
    //Deletes the first element of the buffer.
    void pop_front();

    //Inserts the item element by the pos index. Buffer capacity remains unchanged.
    void insert(const size_t pos, const T &item);

    //Removes elements from the buffer in the interval [first, last).
    void erase(size_t first, size_t last);

    //Clears the buffer.
    void clear();

    bool operator==(const CircularBuffer &b);
    bool operator!=(const CircularBuffer &b);


private:
    size_t cap;
    T *arr;
    size_t current_size;
    size_t first_element;
};
