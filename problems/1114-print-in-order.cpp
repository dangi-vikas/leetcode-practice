#include<semaphore.h>

class Foo {
    sem_t sem1;
    sem_t sem2;
    
public:
    Foo() {
        sem_init(&sem1, 0, 0);
        sem_init(&sem2, 0, 0);
    }

    void first(function<void()> printFirst) {
        printFirst();
        sem_post(&sem1);
    }

    void second(function<void()> printSecond) {
        sem_wait(&sem1);
        printSecond();
        sem_post(&sem2);
    }

    void third(function<void()> printThird) {
        sem_wait(&sem2);
        printThird();
    }
};