#include <iostream>

#include "context.h"
#include "strategy.h"

using namespace std;

int main(int argc, char* argv[]) {
    {
        ConcreteClassA cls_a;
        Strategy* stg = &cls_a;
        // stg->AlgorithmInterface();
        Context con(stg);
        con.DoAction();
        }

    {
        ConcreteClassB cls_b;
        Strategy* stg = &cls_b;
        // stg->AlgorithmInterface();
        Context con(stg);
        con.DoAction();
    }

    return 0;
}