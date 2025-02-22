#ifndef CIRCULARBUFFER_HPP
#define CIRCULARBUFFER_HPP

#include <iostream>
#include <algorithm>
#include <type_traits>
#include <exception>
#include <string>
#include <utility>

class CircularBufferException : public std::exception {
 private:
    std::string error_message;

 public:
    explicit CircularBufferException(const std::string &message) : error_message(message) {}
    const char* what() const noexcept;
};

template <typename T>
class CircularBuffer {
 public:
    CircularBuffer();
    explicit CircularBuffer(const CircularBuffer &a_);
    explicit CircularBuffer(const size_t new_capacity);
    explicit CircularBuffer(const size_t new_capacity, T def);
    ~CircularBuffer();

    T &operator[](const size_t &index);
    const T &operator[](const size_t &index) const;

    // Index access. The methods throw an exception if the index is invalid.
    T &at(size_t index);
    const T &at(size_t index) const;

    T &front();  // Link to the first item.
    T &back();   // Link to the last item.
    const T &front() const;
    const T &back() const;

    // Linearization - move the ring buffer so that its first element
    // will move to the beginning of the allocated memory. Returns a pointer
    // on the first element.
    T *linearize();

    // Checks if the buffer is linearized.
    bool isLinearized() const;

    // Shifts the buffer so that the
    // with index new_begin.
    void rotate(const size_t &new_begin);

    // Size of circular buffer
    size_t size() const;

    // True, if size() == 0
    bool empty() const;

    // True, if size() == capacity().
    bool full() const;

    // The number of free cells in the buffer.
    size_t reserve() const;

    // Buffer's capacity
    size_t capacity() const;

    // Changes the size of the buffer.
    void setCapacity(const size_t &new_capacity);

    // Changes the size of the buffer.
    // In the case of extension, new items are populated with the item element.
    void resize(const size_t &new_size, const T &item);

    // Assignment statement.
    CircularBuffer &operator=(const CircularBuffer &new_buffer);

    // It exchanges the contents of the buffer with the cb buffer.
    void swap(CircularBuffer &cb);

    // Adds an item to the end of the buffer.
    // If the current buffer size is equal to its capacity, then the
    // the first element of the buffer (i.e., the buffer is looped).
    void pushBack(const T &item);

    // Adds a new item before the first buffer item.
    // Similarly pushBack, can overwrite the last element of the buffer.
    void pushFront(const T &item);

    // Deletes the last element of the buffer.
    void popBack();

    // Deletes the first element of the buffer.
    void popFront();

    // Inserts the item element by the pos index. Buffer capacity remains unchanged.
    void insert(const size_t &pos, const T &item);

    // Removes elements from the buffer in the interval [first, last).
    void erase(const size_t &first, const size_t &last);

    // Clears the buffer.
    void clear();

    bool operator==(const CircularBuffer &b);
    bool operator!=(const CircularBuffer &b);

 private:
    size_t capacity_;
    T *arr;
    size_t current_size;
    size_t first_element;
    size_t last_element;
};

const char* CircularBufferException::what() const noexcept {
    return error_message.c_str();
}

template <typename T>
CircularBuffer<T>::CircularBuffer() {
    capacity_ = 0;
    arr = nullptr;
    current_size = 0;
    first_element = 0;
    last_element = 0;
}

template <typename T>
CircularBuffer<T>::CircularBuffer(const size_t new_capacity) {
    capacity_ = new_capacity;
    arr = new T[new_capacity];
    current_size = 0;
    first_element = 0;
    last_element = 0;
}

template <typename T>
CircularBuffer<T>::CircularBuffer(const CircularBuffer<T> &a_) {
    capacity_ = a_.capacity();
    arr = new T[capacity_];
    current_size = a_.size();
    first_element = a_.first_element;
    last_element = a_.last_element;

    for (size_t it = 0; it < current_size; it++) {
        arr[it] = a_[it];
    }
}

template <typename T>
CircularBuffer<T>::CircularBuffer(const size_t new_capacity, T def) {
    capacity_ = new_capacity;
    arr = new T[capacity_];
    current_size = capacity_;
    first_element = 0;
    last_element = current_size - 1;

    for (size_t it = first_element; it < current_size; it++) {
        arr[it] = def;
    }
}

template <typename T>
CircularBuffer<T>::~CircularBuffer() {
    delete[] arr;
}

template <typename T>
T& CircularBuffer<T>::at(size_t index) {
    if (index >= current_size || index < first_element) {
        throw CircularBufferException("ERROR:: CIRCULAR_BUFFER::AT::INVALID BUFFER INDEX");
    }

    return arr[index];
}

template <typename T>
const T& CircularBuffer<T>::at(size_t index) const {
    if (index >= current_size || index < first_element) {
        throw CircularBufferException("ERROR:: CIRCULAR_BUFFER::AT::INVALID BUFFER INDEX");
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
    if (*this == new_buffer) {
        return *this;
    }

    capacity_ = new_buffer.capacity();
    current_size = new_buffer.size();

    delete[] arr;
    arr = new T[capacity_];

    for (size_t i = 0; i < capacity_; i++) {
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
    return !(*this == b);
}

template <typename T>
T& CircularBuffer<T>::front() {
    if (empty()) {
        throw CircularBufferException("ERROR:: CIRCULAR_BUFFER::FRONT::BUFFER IS EMPTY");
    }

    return arr[first_element];
}

template <typename T>
const T& CircularBuffer<T>::front() const {
    if (empty()) {
        throw CircularBufferException("ERROR:: CIRCULAR_BUFFER::FRONT::BUFFER IS EMPTY");
    }

    return arr[first_element];
}

template <typename T>
T& CircularBuffer<T>::back() {
    if (empty()) {
        throw CircularBufferException("ERROR:: CIRCULAR_BUFFER::BACK::BUFFER IS EMPTY");
    }

    size_t last_index = (last_element == 0) ? capacity_ - 1 : last_element - 1;
    return arr[last_index];
}

template <typename T>
const T& CircularBuffer<T>::back() const {
    if (empty()) {
        throw CircularBufferException("ERROR:: CIRCULAR_BUFFER::BACK::BUFFER IS EMPTY");
    }

    size_t last_index = (last_element == 0) ? capacity_ - 1 : last_element - 1;
    return arr[last_index];
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
bool CircularBuffer<T>::isLinearized() const {
    return (first_element == 0);
}

template <typename T>
void CircularBuffer<T>::rotate(const size_t &new_begin) {
    for (size_t i = new_begin; i < first_element; i++) {
        std::swap(arr[i], arr[i - new_begin]);
    }
}

template <typename T>
void CircularBuffer<T>::swap(CircularBuffer &other) {
    std::swap(arr, other.arr);
    std::swap(capacity_, other.capacity_);
    std::swap(current_size, other.current_size);
    std::swap(first_element, other.first_element);
    std::swap(last_element, other.last_element);
}

template <typename T>
bool CircularBuffer<T>::full() const {
    return current_size == capacity_;
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
    return capacity_;
}

template <typename T>
size_t CircularBuffer<T>::reserve() const {
    return capacity_ - current_size;
}

template <typename T>
void CircularBuffer<T>::setCapacity(const size_t &new_capacity) {
    T *newarr = new T[new_capacity];
    current_size = std::min(current_size, new_capacity);
    for (size_t i = 0; i < current_size; i++) {
        newarr[i] = arr[i];
    }

    delete[] arr;
    arr = newarr;
    capacity_ = new_capacity;
}

template <typename T>
void CircularBuffer<T>::resize(const size_t &new_size, const T& item) {
    setCapacity(new_size);

    for (size_t i = current_size; i < new_size; i++) {
        arr[i] = item;
    }

    current_size = new_size;
}

template <typename T>
void CircularBuffer<T>::pushBack(const T& new_element) {
    if (current_size < capacity_) {
        current_size++;
    } else {
        first_element = (first_element + 1) % capacity_;
    }

    arr[last_element] = new_element;
    last_element = (last_element + 1) % capacity_;
}

template <typename T>
void CircularBuffer<T>::pushFront(const T& new_element) {
    current_size = std::min(current_size + 1, capacity_);

    if (first_element == 0) {
        first_element = capacity_;
    }

    arr[--first_element] = new_element;

    last_element = first_element + current_size - 1;
    if (last_element >= capacity_) {
        last_element -= capacity_;
    }
}

template <typename T>
void CircularBuffer<T>::popBack() {
    if (current_size == 0) {
        throw CircularBufferException("ERROR:: CIRCULAR_BUFFER::POP_BACK::BUFFER IS EMPTY");
    }

    last_element--;
    last_element = (last_element + capacity_) % capacity_;

    if (first_element != 0) {
        for (size_t i = last_element; i < current_size - 1; i++) {
            std::swap(arr[i], arr[i + 1]);
        }
    }

    --current_size;
}

template <typename T>
void CircularBuffer<T>::popFront() {
    if (current_size == 0) {
        throw CircularBufferException("ERROR:: CIRCULAR_BUFFER::POP_FRONT::BUFFER IS EMPTY");
    }

    first_element = (first_element + capacity_ + 1) % capacity_;

    --current_size;
}

template <typename T>
void CircularBuffer<T>::insert(const size_t &pos, const T &item) {
    if (pos > current_size) {
        throw CircularBufferException("ERROR:: CIRCULAR_BUFFER::INSERT::BAD POSITION FOR INSERT (POSITION > BUFFER'S SIZE)");
    }

    if (current_size == capacity_) {
        if (first_element + 1 < current_size) {
            arr[first_element++] = item;
            return;
        }

        first_element = 0;
        arr[first_element] = item;

        return;
    }

    for (size_t i = current_size; i > pos; i--) {
        std::swap(arr[i], arr[i - 1]);
    }

    arr[pos] = item;
}

template <typename T>
void CircularBuffer<T>::erase(const size_t &first, const size_t &last) {
    if (current_size < first) {
        throw CircularBufferException("ERROR:: CIRCULAR_BUFFER::ERASE::UNCORRECT VALUE FOR ERASE (FIRST > BUFFER SIZE)");
    }

    if (current_size < last) {
        throw CircularBufferException("ERROR:: CIRCULAR_BUFFER::ERASE::UNCORRECT VALUE FOR ERASE (LAST > BUFFER SIZE)");
    }

    if (first > last) {
        throw CircularBufferException("ERROR:: CIRCULAR_BUFFER::ERASE::UNCORRECT VALUE FOR ERASE (FIRST > LAST)");
    }

    size_t size_difference = last - first;
    if (current_size < capacity_) {
        for (size_t i = first, j = last; j < current_size && i < last; i++, j++) {
            std::swap(arr[i], arr[j]);
        }
        current_size -= size_difference;

        return;
    }

    size_t i = first, j = last;
    while (j != last_element) {
        arr[i] = arr[j];
        i = (i + 1) % capacity_;
        j = (j + 1) % capacity_;
    }
    current_size -= size_difference;
    last_element = (last_element + capacity_ - size_difference) % capacity_;
}

template <typename T>
void CircularBuffer<T>::clear() {
    delete[] arr;
    arr = nullptr;
    capacity_ = 0;
    current_size = 0;
}

#endif  // CIRCULARBUFFER_HPP
