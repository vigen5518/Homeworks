#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
public:
    T* data_;
    size_t size_;
    size_t capacity_;

    void reallocate(size_t new_capacity);

    Vector();
    Vector(size_t count, const T& value = T());
    Vector(size_t count);
    Vector(const Vector& other);
    ~Vector();

    Vector& operator=(const Vector& other);

    T& at(size_t pos);
    const T& at(size_t pos) const;

    T& operator[](size_t pos);
    const T& operator[](size_t pos) const;

    T& front();
    const T& front() const;

    T& back();
    const T& back() const;

    T* data();
    const T* data() const;

    T* begin();
    const T* begin() const;
    T* end();
    const T* end() const;

    bool empty() const;
    size_t size() const;
    size_t capacity() const;

    void reserve(size_t new_capacity);
    void resize(size_t count, const T& value = T());

    void push_back(const T& value);
    void pop_back();
    void clear();
};

template <typename T>
void Vector<T>::reallocate(size_t new_capacity) {
    if (new_capacity <= size_) {
        return;
    }
    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}

template <typename T>
Vector<T>::Vector() {
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

template <typename T>
Vector<T>::Vector(size_t count, const T& value) {
    size_ = count;
    capacity_ = count;
    data_ = new T[count];
    for (size_t i = 0; i < count; ++i) {
        data_[i] = value;
    }
}

template <typename T>
Vector<T>::Vector(size_t count) {
    size_ = count;
    capacity_ = count;
    data_ = new T[count]();
}

template <typename T>
Vector<T>::Vector(const Vector& other) {
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new T[capacity_];
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data_;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this == &other) {
        return *this;
    }
    delete[] data_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new T[capacity_];
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
    return *this;
}

template <typename T>
T& Vector<T>::at(size_t pos) {
    if (pos >= size_) {
        std::cout << "Error: Vector access out of bounds!" << std::endl;
        exit(1);
    }
    return data_[pos];
}

template <typename T>
const T& Vector<T>::at(size_t pos) const {
    if (pos >= size_) {
        std::cout << "Error: Vector access out of bounds!" << std::endl;
        exit(1);
    }
    return data_[pos];
}

template <typename T>
T& Vector<T>::operator[](size_t pos) {
    return data_[pos];
}

template <typename T>
const T& Vector<T>::operator[](size_t pos) const {
    return data_[pos];
}

template <typename T>
T& Vector<T>::front() {
    return data_[0];
}

template <typename T>
const T& Vector<T>::front() const {
    return data_[0];
}

template <typename T>
T& Vector<T>::back() {
    return data_[size_ - 1];
}

template <typename T>
const T& Vector<T>::back() const {
    return data_[size_ - 1];
}

template <typename T>
T* Vector<T>::data() {
    return data_;
}

template <typename T>
const T* Vector<T>::data() const {
    return data_;
}

template <typename T>
T* Vector<T>::begin() {
    return data_;
}

template <typename T>
const T* Vector<T>::begin() const {
    return data_;
}

template <typename T>
T* Vector<T>::end() {
    return data_ + size_;
}

template <typename T>
const T* Vector<T>::end() const {
    return data_ + size_;
}

template <typename T>
bool Vector<T>::empty() const {
    return size_ == 0;
}

template <typename T>
size_t Vector<T>::size() const {
    return size_;
}

template <typename T>
size_t Vector<T>::capacity() const {
    return capacity_;
}

template <typename T>
void Vector<T>::reserve(size_t new_capacity) {
    if (new_capacity > capacity_) {
        reallocate(new_capacity);
    }
}

template <typename T>
void Vector<T>::resize(size_t count, const T& value) {
    if (count > capacity_) {
        reallocate(count);
    }
    if (count > size_) {
        for (size_t i = size_; i < count; ++i) {
            data_[i] = value;
        }
    }
    size_ = count;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size_ >= capacity_) {
        reallocate(capacity_ == 0 ? 1 : capacity_ + 5);
    }
    data_[size_] = value;
    size_++;
}

template <typename T>
void Vector<T>::pop_back() {
    if (size_ > 0) {
        size_--;
    }
}

template <typename T>
void Vector<T>::clear() {
    size_ = 0;
}

#endif
