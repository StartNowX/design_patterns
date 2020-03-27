#include "strategy.h"

#include <iostream>

using namespace std;

void ConcreteClassA::AlgorithmInterface() { std::cout << "[ConcreteClassA] call algo interface..." << std::endl; }

void ConcreteClassB::AlgorithmInterface() { std::cout << "[ConcreteClassB] call algo interface..." << std::endl; }