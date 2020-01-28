#ifndef CONTAINER
#define CONTAINER

template <class T>
class Container {
    private:
        T* buffer;
        unsigned int capacity;
        unsigned int size;
    public:
        typedef T* iterator;

        Container();
        void add(const T&);
        T& at(const unsigned int&) const;
        void clear();
        bool erase(const unsigned int&);
        unsigned int getCapacity() const;
        unsigned int getSize() const;
        bool isEmpty() const;

        iterator begin() const;
        iterator end() const;

        T& operator[](const unsigned int&) const;
        Container<T>& operator=(const Container<T>&);
        bool operator==(const Container<T>&) const;
        bool operator!=(const Container<T>&) const;
        bool operator<(const Container<T>&) const;

        int search(const T&) const;
        ~Container();
};

template<class T>
Container<T>::Container(): buffer(nullptr), capacity(0), size(0){}

template<class T>
void Container<T>::add(const T& toAdd) {
    if(size >= capacity) {
        capacity = 1+size;
        T* newBuffer = new T[capacity];
        for(unsigned int i = 0; i < size; ++i) {
            newBuffer[i] = buffer[i];
        }
        delete[] buffer;
        buffer = newBuffer;
    }
    buffer[size] = toAdd;
    ++size;
}

template<class T>
T& Container<T>::at(const unsigned int& toPos) const {
    if(toPos <= size) {
        return buffer[toPos];
    }
}

template<class T>
void Container<T>::clear() {
    if(size > 0) {
        T* newBuffer = nullptr;
        delete[] buffer;
        buffer = newBuffer;
        capacity = 0;
        size = 0;
    }
}

template<class T>
bool Container<T>::erase(const unsigned int &toPos) {
    if(toPos < size) {
        unsigned int truePos = 0;
        T* newBuffer = new T[capacity];
        for(unsigned int i = 0; i < size; ++i) {
            if(i != toPos) {
                newBuffer[truePos] = buffer[i];
                ++truePos;
            }
        }
        size--;
        delete[] buffer;
        buffer = newBuffer;
        return true;
    }
    return false;
}

template<class T>
unsigned int Container<T>::getCapacity() const {
    return capacity;
}

template<class T>
unsigned int Container<T>::getSize() const {
    return size;
}

template<class T>
bool Container<T>::isEmpty() const {
    return size == 0;
}

template<class T>
typename Container<T>::iterator Container<T>::begin() const {
    return buffer;
}

template<class T>
typename Container<T>::iterator Container<T>::end() const {
    return buffer+size;
}

template<class T>
T& Container<T>::operator[](const unsigned int& toPos) const {
    return buffer[toPos];
}

template<class T>
Container<T>& Container<T>::operator=(const Container<T>& toContainer) {
    if(toContainer.isEmpty()) {
        clear();
    }
    else if(this != &toContainer) {
        T* newBuffer = new T[toContainer.capacity];

        for(unsigned int i = 0; i < toContainer.size; ++i) {
            newBuffer[i] = toContainer[i];
        }
        delete[] buffer;
        size = toContainer.size;
        capacity = toContainer.capacity;

        buffer = newBuffer;
    }
    return *this;
}

template<class T>
bool Container<T>::operator==(const Container<T>& toCheck) const {
    if(buffer && toCheck) {
        if(size == toCheck.getSize()) {
            for(unsigned int i = 0; i < size; ++i) {
                if(buffer[i] != toCheck[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

template<class T>
bool Container<T>::operator!=(const Container<T>& toCheck) const {
    if(buffer && toCheck) {
        if(size == toCheck.getSize()) {
            for(unsigned int i = 0; i < size; ++i) {
                if(buffer[i] == toCheck[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

template<class T>
bool Container<T>::operator<(const Container<T>& toCheck) const {
    return buffer < toCheck.buffer;
}

template<class T>
int Container<T>::search(const T& toSearch) const {
    for(unsigned int i = 0; i < size; ++i) {
        if(buffer[i] == toSearch) {
            return i;
        }
    }
    return -1;
}

template<class T>
Container<T>::~Container() {
    if(buffer) {
        delete[] buffer;
    }
}


#endif // CONTAINER
