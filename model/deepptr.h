#ifndef DEEPPTR
#define DEEPPTR

template<class T>
class DeepPtr {
    public:
        T* pointer;
        DeepPtr(T* = nullptr);
        DeepPtr(const DeepPtr&);
        DeepPtr<T>& operator=(const DeepPtr&);
        T& operator*() const;
        T* operator->() const;
        bool operator==(const DeepPtr&) const;
        bool operator!=(const DeepPtr&) const;
        ~DeepPtr();
};

template<class T>
DeepPtr<T>::DeepPtr(T* toPointer): pointer(toPointer != nullptr? toPointer->clone() : nullptr) {}

template<class T>
DeepPtr<T>::DeepPtr(const DeepPtr& toDeepPtr): pointer(toDeepPtr.pointer != nullptr? (toDeepPtr.pointer)->clone() : nullptr) {}

template<class T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr& toDeepPtr) {
    if(this != &toDeepPtr) {
        if(pointer) {
            delete pointer;
        }
        pointer = toDeepPtr.pointer != nullptr? (toDeepPtr.pointer)->clone() : nullptr;
    }
    return *this;
}

template<class T>
T& DeepPtr<T>::operator*() const {
    return *pointer;
}

template<class T>
T* DeepPtr<T>::operator->() const {
    return pointer;
}

template<class T>
bool DeepPtr<T>::operator==(const DeepPtr& toDeepPtr) const {
    return *pointer == *toDeepPtr;
}

template<class T>
bool DeepPtr<T>::operator!=(const DeepPtr& toDeepPtr) const {
    return *pointer != *toDeepPtr;
}

template<class T>
DeepPtr<T>::~DeepPtr() {
    if(pointer) {
        delete pointer;
    }
}

#endif // DEEPPTR

