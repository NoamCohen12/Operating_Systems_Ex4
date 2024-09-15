#include <iostream>
#include <pthread.h>
#include "Singleton.hpp"

int main() {
    Singleton* singleton = Singleton::getInstance();
    singleton->doSomething();

    // Example using Guard (Scope Mutex)
    pthread_mutex_t exampleMutex = PTHREAD_MUTEX_INITIALIZER;

    {
        MutexGuard guard(exampleMutex); // Automatically locks exampleMutex
        // Critical section protected by exampleMutex
        std::cout << "Inside critical section" << std::endl;
    }
    // exampleMutex is automatically unlocked when guard goes out of scope

    return 0;
}
