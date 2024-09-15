#include <iostream>
#include <mutex>
#include <memory>
#include <pthread.h>

// Abstract base class for Singleton
template <typename T>
class Singleton {

private:
    // Pointer to the Singleton instance
    static std::unique_ptr<T> instance;

    // Mutex for thread safety
    static pthread_mutex_t& getMutex() {
        static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
        return mutex;
    }
public:
    // Deleted methods to prevent copying and assignment
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Static method to get the singleton instance
    static T& getInstance() {
        pthread_mutex_lock(&getMutex());
        if (!instance) {
            instance.reset(new T());
        }
        pthread_mutex_unlock(&getMutex());
        return *instance;
    }

protected:
    // Protected constructor to prevent external instantiation
    Singleton() = default;
    virtual ~Singleton() = default;
};

// Initialize the static member variable
template <typename T>
std::unique_ptr<T> Singleton<T>::instance = nullptr;

// Example derived class
class MySingleton : public Singleton<MySingleton> {
    friend class Singleton<MySingleton>;  // Allow Singleton to access private constructor
private:
    MySingleton() {
        std::cout << "MySingleton constructor called\n";
    }

public:
    void doSomething() {
        std::cout << "Doing something in MySingleton\n";
    }
};

int main() {
    MySingleton& instance1 = MySingleton::getInstance();
    instance1.doSomething();

    MySingleton& instance2 = MySingleton::getInstance();
    instance2.doSomething();

    return 0;
}
