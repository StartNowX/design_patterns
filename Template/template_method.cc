#include "template_method.h"

#include <iostream>

using namespace std;

AbstractClass::AbstractClass() { std::cout << "constructor in AbstractClass" << std::endl; }
AbstractClass::~AbstractClass() { std::cout << "deconstructor in AbstractClass" << std::endl; }

void AbstractClass::TemplateMethod() {
    std::cout << "[TemplateMethod] call primitiveOperation1 ..." << std::endl;
    PrimitiveOperation1();
    std::cout << "[TemplateMethod] call primitiveOperation2 ..." << std::endl;
    PrimitiveOperation2();
    std::cout << "[TemplateMethod] call primitiveOperation2 ..." << std::endl;
    PrimitiveOperation2();
}

ConcreteClassA::ConcreteClassA() { std::cout << "constructor in ConcreteClassA" << std::endl; }
ConcreteClassA::~ConcreteClassA() { std::cout << "deconstructor in ConcreteClassA" << std::endl; }

void ConcreteClassA::PrimitiveOperation1() {
    std::cout << "[****ConcreteClassA] class A call PrimitiveOperation1!" << std::endl;
}
void ConcreteClassA::PrimitiveOperation2() {
    std::cout << "[****ConcreteClassA] class A call PrimitiveOperation2!" << std::endl;
}

ConcreteClassB::ConcreteClassB() { std::cout << "constructor in ConcreteClassB" << std::endl; }
ConcreteClassB::~ConcreteClassB() { std::cout << "deconstructor in ConcreteClassB" << std::endl; }

void ConcreteClassB::PrimitiveOperation1() {
    std::cout << "[====ConcreteClassB] class B call PrimitiveOperation1!" << std::endl;
}
void ConcreteClassB::PrimitiveOperation2() {
    std::cout << "[====ConcreteClassB] class B call PrimitiveOperation2!" << std::endl;
}
