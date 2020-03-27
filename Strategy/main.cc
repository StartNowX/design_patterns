#include <iostream>

#include "context.h"
#include "strategy.h"

using namespace std;

int main(int argc, char* argv[]) {
    {
        ConcreteClassA cls_a;
        Strategy* stg = &cls_a;
        stg->AlgorithmInterface();
    }

    {
        ConcreteClassB cls_b;
        Strategy* stg = &cls_b;
        stg->AlgorithmInterface();
    }

    return 0;
}