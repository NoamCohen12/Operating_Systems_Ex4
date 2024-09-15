#include <pthread.h>
#include <iostream>

template <typename MutexType>
class Guard {
public:
    explicit Guard(MutexType& mutex) : mutex_(mutex) {
        pthread_mutex_lock(&mutex_);
    }

    ~Guard() {
        pthread_mutex_unlock(&mutex_);
    }

    Guard(const Guard&) = delete;
    Guard& operator=(const Guard&) = delete;

private:
    MutexType& mutex_;
};

int main() {
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, nullptr);

    {
        Guard<pthread_mutex_t> guard(mutex);
        // Critical section: Mutex is locked
        std::cout << "Mutex is locked\n";
    } // Mutex is automatically unlocked here when `guard` goes out of scope

    pthread_mutex_destroy(&mutex);
    return 0;
}
