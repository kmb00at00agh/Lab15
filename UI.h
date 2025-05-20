#include "Observer.h"
#include <iostream>

class UI : public Observer {
public:
    void update() override {
        std::cout << "[UI] Character's state has changed!" << std::endl;
    }
};