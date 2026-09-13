#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H
#include <utility>

// Your implementation here
template <typename T>
class UniquePtr {
    template <typename U>
    friend class UniquePtr;
public: 
	UniquePtr(T* p = nullptr) : mPtr{p} {}
    ~UniquePtr() {
        if (mPtr != nullptr) {
            delete mPtr;
        }
	}
    UniquePtr(UniquePtr&& other) { 
        mPtr = other.mPtr;
        other.mPtr = nullptr;
    }
    UniquePtr& operator=(UniquePtr&& other) { 
        if (this != &other) {
            delete mPtr;
            mPtr = other.mPtr;
            other.mPtr = nullptr;
        }
        return *this;
    }
    template <typename U>
    UniquePtr(UniquePtr<U>&& other) {
        mPtr = other.mPtr;
        other.mPtr = nullptr;
    }
    T& operator*() { 
        return *mPtr;
    }
    T* operator->() { 
        return mPtr;
    }
    T* get() { 
        return mPtr;
    }
    bool operator==(const UniquePtr<T>& other) {
        if (mPtr == other.mPtr) {
            return true;
        } else {
            return false;
        }
    }
    T* release() { 
        T* res = mPtr;
        delete mPtr;
        return res;
    }
    void reset(T* newPtr = nullptr) {
        T* prevptr = mPtr;
        mPtr = newPtr;
        if (prevptr != nullptr) {
            delete prevptr;
        }
    }
    void swap(UniquePtr<T>& other) { 
        std::swap(*this, other);
    }
    operator bool() {
        if (mPtr != nullptr) {
            return true;
        } else {
            return false;
        }
    }

private: 
    T* mPtr;
};

template <typename T, typename... Args>
UniquePtr<T> makeUnique(Args&&... args) {
    return UniquePtr<T>(new T(std::forward<Args>(args)...));
}


#endif
