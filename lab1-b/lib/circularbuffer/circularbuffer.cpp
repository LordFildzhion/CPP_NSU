#include "circularbuffer.hpp"


const char* cb_error::what() const noexcept{
    return error_message.c_str();
}

template <typename T>
CircularBuffer<T>::CircularBuffer() {
    cap = 0;
    arr = nullptr;
    current_size = 0;
    first_element = 0;
}

template <typename T>
CircularBuffer<T>::CircularBuffer(const CircularBuffer<T> &a_) {

    cap = a_.capacity();
    arr = new T[cap];
    current_size = a_.size();
    first_element = 0;

    for (size_t it = 0; it < current_size; it++) {
        arr[it] = a_[it];
    }
}

template <typename T>
CircularBuffer<T>::CircularBuffer(const size_t cap_, T def){
    
    cap = cap_;
    arr = new T[cap_];
    current_size = cap_;
    first_element = 0;

    for (size_t it = 0; it < cap; it++) {
        arr[it] = def;
    }
}

template <typename T>
CircularBuffer<T>::~CircularBuffer() {
    delete[] arr;
}

template <typename T>
T& CircularBuffer<T>::at(size_t index) {
    if (index >= current_size) {
        throw std::string("ERROR:: CIRCULAR_BUFFER::AT::INVALID BUFFER INDEX");
    }

    return arr[index];
}

template <typename T>
const T& CircularBuffer<T>::at(size_t index) const {
    if (index >= current_size) {
        throw std::string("ERROR:: CIRCULAR_BUFFER::AT::INVALID BUFFER INDEX");
    }

    return arr[index];
}

template <typename T>
T& CircularBuffer<T>::operator[](const size_t &index) {
    return arr[index];
}

template <typename T>
const T& CircularBuffer<T>::operator[](const size_t &index) const {
    return arr[index];
}

template <typename T>
CircularBuffer<T>& CircularBuffer<T>::operator=(const CircularBuffer<T> &new_buffer) {
    if (*this == &new_buffer) {
        return *this;
    }

    cap = new_buffer.capacity();
    current_size = new_buffer.size();

    delete[] arr;
    arr = new T[cap];

    for (size_t i = 0; i < cap; i++) {
        arr[i] = new_buffer[i];
    }

    return *this;
}

template <typename T>
bool CircularBuffer<T>::operator==(const CircularBuffer<T> &b) {
    if (current_size != b.size()) {
        return false;
    }

    for (size_t i = 0; i < b.size(); i++) {
        if (b[i] != arr[i]) {
            return false;
        }
    }

    return true;
}

template <typename T>
bool CircularBuffer<T>::operator!=(const CircularBuffer &b) {
    return !(this == b);
}

template <typename T>
T& CircularBuffer<T>::front() {
    return arr[first_element];
}

template <typename T>
const T& CircularBuffer<T>::front() const {
    return arr[first_element];
}

template <typename T>
T& CircularBuffer<T>::back() {
    if (first_element == 0) {
        return arr[current_size - 1];
    } else {
        return arr[first_element - 1];
    }
}

template <typename T>
const T& CircularBuffer<T>::back() const {
    if (first_element == 0) {
        return arr[current_size - 1];
    } else {
        return arr[first_element - 1];
    }
}

template <typename T>
T* CircularBuffer<T>::linearize() {
    for (size_t i = first_element; i < current_size; i++) {
        std::swap(arr[i], arr[i - first_element]);
    }
    first_element = 0;

    return &arr[first_element];
}

template <typename T>
bool CircularBuffer<T>::is_linearized() const {
    return (first_element == 0);
}

template <typename T>
void CircularBuffer<T>::rotate(const size_t &new_begin) {
    for (size_t i = new_begin; i < first_element; i++) {
        std::swap(arr[i], arr[i - new_begin]);
    }
}

template <typename T>
void CircularBuffer<T>::swap(CircularBuffer &b) {
    CircularBuffer<T> c = b;
    b = *this;
    *this = c;
}

template <typename T>
bool CircularBuffer<T>::full() const {
    return current_size == cap;
}

template <typename T>
bool CircularBuffer<T>::empty() const {
    return current_size == 0;
}

template <typename T>
size_t CircularBuffer<T>::size() const {
    return current_size;
}

template <typename T>
size_t CircularBuffer<T>::capacity() const {
    return cap;
}

template <typename T>
size_t CircularBuffer<T>::reserve() const {
    return cap - current_size;
}

template <typename T>
void CircularBuffer<T>::set_capacity(const size_t &new_capacity) {
    T *newarr = new T[new_capacity];
    current_size = std::min(current_size, new_capacity);
    for (size_t i = 0; i < current_size; i++) {
        newarr[i] = arr[i];
    }
    
    delete[] arr;
    arr = newarr;
    cap = new_capacity;
}

template <typename T>
void CircularBuffer<T>::resize(const size_t &new_size, const T& item) {
    set_capacity(new_size);

    for (size_t i = current_size; i < new_size; i++) {
        arr[i] = item;
    }

    current_size = new_size;
}

template <typename T>
void CircularBuffer<T>::push_back(const T& new_element) {
    if (current_size < cap) {
        arr[current_size++] = new_element;
    }
    else {
        arr[first_element++] = new_element;
        if (first_element == current_size) {
            first_element = 0;
        }
    }
}

template <typename T>
void CircularBuffer<T>::push_front(const T& new_element) {
    if (first_element == 0) {
        first_element = cap;
    }
    arr[--first_element] = new_element;

    if (current_size < cap) {
        current_size++;
    }
}

template <typename T>
void CircularBuffer<T>::pop_back() {
    if (current_size == 0) {
        return;
    }

    if (first_element != 0) {
        std::swap(arr[current_size - 1], arr[first_element - 1]);
        for (size_t i = first_element - 1; i > 0; i--) {
            std::swap(arr[i], arr[i - 1]);
        }
    }

    --current_size;
}

template <typename T>
void CircularBuffer<T>::pop_front() {
    if (current_size == 0) {
        return;
    }

    if (first_element != 0) {
        for (size_t i = first_element; i < current_size - 1; i++) {
            std::swap(arr[i], arr[i + 1]);
        }
    }

    --current_size;
}

template <typename T>
void CircularBuffer<T>::insert(const size_t &pos, const T &item) {

    if (pos > current_size) {
        throw std::string("ERROR:: CIRCULAR_BUFFER::INSERT::BAD POSITION FOR INSERT (POSITION > BUFFER'S SIZE)");
    }

    if (current_size == cap) {
        if (first_element + 1 < current_size) {
            arr[first_element++] = item;
        } else {
            first_element = 0;
            arr[first_element] = item;
        }
    } else {
        for (size_t i = current_size; i > pos; i--) {
            std::swap(arr[i], arr[i - 1]);
        }
        arr[pos] = item;
    }
}

template <typename T>
void CircularBuffer<T>::erase(const size_t &first, const size_t &last) {

    if (current_size < first) {
        throw std::string("ERROR:: CIRCULAR_BUFFER::ERASE::UNCORRECT VALUE FOR ERASE (FIRST > BUFFER SIZE)");
    }

    if (current_size < last) {
        throw std::string("ERROR:: CIRCULAR_BUFFER::ERASE::UNCORRECT VALUE FOR ERASE (LAST > BUFFER SIZE)");
    }
    if (first > last) {
        throw std::string("ERROR:: CIRCULAR_BUFFER::ERASE::UNCORRECT VALUE FOR ERASE (FIRST > LAST)");
    }
    
    if (current_size < cap) {

        for (size_t i = first, j = last; j < current_size && i < last; i++, j++) {
            std::swap(arr[i], arr[j]);
        }
        current_size -= last - first;
    
    }
    else {

        size_t size_difference = last - first;

        if (size_difference == cap) {
            current_size = 0;
            return;
        }

        for (size_t i = 0; i < size_difference; i++) {
            std::swap(arr[first_element + first + i], arr[(first_element + last + i) % cap]);
        }

        if (first_element >= first && first_element <= last) {
            first_element = 0;
        }
    }
}

template <typename T>
void CircularBuffer<T>::clear() {
    delete[] arr;
    arr = nullptr;
    cap = 0;
    current_size = 0;
}
