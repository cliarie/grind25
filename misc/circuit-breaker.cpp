#include <iostream>

enum CircuitState{
    CLOSED,
    OPEN,
};

class CircuitBreaker{
private:
    int failureThreshold;
    int failureCount;
    CircuitState state;

public:
    CircuitBreaker(int threshold): failureThreshold(threshold), failureCount(0), state(CLOSED){}

    void recordSuccess(){
        failureCount = 0;
        state = CLOSED;
        cout << "Circuit is now closed\n";
    }

    void recordFailure(){
        failureCount++;
        cout << "Failure count: " << failureCount << endl;
        if(failureCount >= failureThreshold){
            state = OPEN;
            cout << "Circuit is now open\n"
        }
    }

    bool isOpen(){
        return state == OPEN;
    }

    void reset(){
        failureCount = 0;
        state = CLOSED;
        cout << "Circuit is now closed and reset\n";
    }
};

bool makeRequest(){
    cout << "Making request\n";
    return rand() % 2 == 0;
}

void handleRequest(CircuitBreaker &cb, CircuitBreaker &cb2){
    if (cb.isOpen()){
        if (makeRequest()){
            cb.recordSuccess();
        } else {
            cb.recordFailure();
        }
    } else{
        cout << "Circuit is open\n";
    }
    // if primary is open or fails, try secondary
    if (makeRequest()){
        cb2.recordSuccess();
    } else {
        cb2.recordFailure();
    }
}
