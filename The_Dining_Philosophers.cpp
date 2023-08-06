#include <mutex>
#include <condition_variable>
using namespace std;

class DiningPhilosophers {
private:
    mutex mtx;
    condition_variable cv[5];
    enum State { THINKING, HUNGRY, EATING };
    State state[5];

    void test(int i) {
        if (state[i] == HUNGRY && state[(i + 4) % 5] != EATING && state[(i + 1) % 5] != EATING) {
            state[i] = EATING;
            cv[i].notify_one();
        }
    }

public:
    DiningPhilosophers() {
        for (int i = 0; i < 5; ++i) {
            state[i] = THINKING;
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        unique_lock<mutex> lock(mtx);

        state[philosopher] = HUNGRY;
        test(philosopher);

        while (state[philosopher] != EATING) {
            cv[philosopher].wait(lock);
        }

        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        putRightFork();

        state[philosopher] = THINKING;

        test((philosopher + 4) % 5);
        test((philosopher + 1) % 5);

        cv[(philosopher + 4) % 5].notify_one();
        cv[(philosopher + 1) % 5].notify_one();
    }
};
