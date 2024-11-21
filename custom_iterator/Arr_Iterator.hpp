#include <iostream>


#ifndef ARR_ITERATOR_HPP
#define ARR_ITERATOR_HPP

template <typename T>
class Arr{
 public:
    Arr (const size_t size= 0);

    Arr (const Arr &arr);

    Arr (const std::initializer_list <T> &init_list);

    ~Arr();

    T &operator[] (const size_t &i);

    const T &operator[] (const size_t &i) const;

    Arr &operator= (const Arr &arr);

    const size_t size() const;

    class Arr_Iterator
    {
     public:
        Arr_Iterator() = delete;

        Arr_Iterator(T* ptr);

		T& operator*();

		T* operator->();

		Arr_Iterator& operator++ ();

		Arr_Iterator& operator+= (const size_t &n);

		Arr_Iterator& operator-- ();

		Arr_Iterator& operator-= (const size_t &n);

		const bool operator== (const Arr_Iterator& other) const;

		const bool operator!= (const Arr_Iterator& other) const;

		Arr_Iterator& operator= (const Arr_Iterator& other);

        const Arr_Iterator& operator= (const Arr_Iterator& other) const;
        
     private:
        T *val_;

    };
    
    const Arr_Iterator begin() const;

    const Arr_Iterator end() const;

    void print();

    void swap(Arr &other);

 private:
    size_t capacity_;
    size_t size_;
    T *arr_;

};

//Functions from Arr<T>

template <typename T>
Arr<T>::Arr (const size_t size) {
    capacity_ = size;
    size_ = size;
    arr_ = new T[capacity_];
}

template <typename T>
Arr<T>::Arr (const Arr &arr): size_(arr.size_), capacity_(arr.capacity_) {
    arr_ = new T[capacity_];

    for (size_t i = 0; i < size_; i++) {
        arr_[i] = arr[i];
    }
}

template <typename T>
Arr<T>::Arr (const std::initializer_list <T> &init_list): size_(init_list.size()), capacity_(init_list.size()) {
    arr_ = new T[size_];

    for (auto init_list_iterator = init_list.begin(); init_list_iterator < init_list.end(); init_list_iterator++) {
        arr_[init_list_iterator - init_list.begin()] = *init_list_iterator;
    }
}

template <typename T>
Arr<T>::~Arr() {
    delete[] arr_;
}

template <typename T>
T& Arr<T>::operator[] (const size_t &i) {
    return arr_[i];
}

template <typename T>
const T& Arr<T>::operator[] (const size_t &i) const {
    return arr_[i];
}

template <typename T>
Arr<T>& Arr<T>::operator= (const Arr &arr) {
    capacity_ = arr.capacity_;
    size_ = arr.size_;

    delete[] arr_;
    arr_ = new T[capacity_];

    for (size_t i = 0; i < size_; i++) {
        arr_[i] = arr[i];
    }

    return *this;
}

template <typename T>
const size_t Arr<T>::size() const{
    return size_;
}

template <typename T>
const typename Arr<T>::Arr_Iterator Arr<T>::begin() const {
    return Arr_Iterator(&arr_[0]);
}

template <typename T>
const typename Arr<T>::Arr_Iterator Arr<T>::end() const{
    return Arr_Iterator(&arr_[size_]);
}

template <typename T>
void Arr<T>::print() {
    for (size_t i = 0; i < size_; i++) {
        std::cout << arr_[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Arr<T>::swap(Arr &other) {
    Arr c = *this;
    *this = other;
    other = c;
}


//Functions from Arr<T>::Arr_Iterator

template <typename T>
Arr<T>::Arr_Iterator::Arr_Iterator(T* ptr) {
    val_ = ptr;
}

template <typename T>
T& Arr<T>::Arr_Iterator::operator*() {
    return *val_;
}

template <typename T>
T* Arr<T>::Arr_Iterator::operator->() {
    return val_;
}

template <typename T>
typename Arr<T>::Arr_Iterator& Arr<T>::Arr_Iterator::operator++ () {
    val_++;
    return *this;
}

template <typename T>
typename Arr<T>::Arr_Iterator& Arr<T>::Arr_Iterator::operator+= (const size_t &n) {
    val_ += n;
    return *this;
}

template <typename T>
typename Arr<T>::Arr_Iterator& Arr<T>::Arr_Iterator::operator-- () {
    val_--;
    return *this;
}

template <typename T>
typename Arr<T>::Arr_Iterator& Arr<T>::Arr_Iterator::operator-= (const size_t &n) {
    val_ -= n;
    return *this;
}

template <typename T>
const bool Arr<T>::Arr_Iterator::operator== (const Arr_Iterator& other) const {
    return val_ == other.val_;
}

template <typename T>
const bool Arr<T>::Arr_Iterator::operator!= (const Arr_Iterator& other) const {
    return val_ != other.val_;
}

template <typename T>
typename Arr<T>::Arr_Iterator& Arr<T>::Arr_Iterator::operator= (const Arr_Iterator& other) {
    val_ = other.val_;
    return *this;
}

template <typename T>
const typename Arr<T>::Arr_Iterator& Arr<T>::Arr_Iterator::operator= (const Arr_Iterator& other) const {
    val_ = other.val_;
    return *this;
}

#endif
