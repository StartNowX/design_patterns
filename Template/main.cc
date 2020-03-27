#include <iostream>

#include "template_method.h"

int main(int argc, char* argv[]) {
    {
        ConcreteClassA cls_a;

        // AbstractClass base;  // object of abstract class is not allowed
        AbstractClass* base = &cls_a;
        // 这里TemplateMethod里面调用将是ConcreteClassA实现的PrimitiveOperation1和PrimitiveOperation2
        base->TemplateMethod();
        // cls_a.TemplateMethod();
    }

    {
        // 抽象类绑定到子类b上
        ConcreteClassB cls_b;
        AbstractClass* base = &cls_b;
        // 这里TemplateMethod里面调用将是ConcreteClassB实现的PrimitiveOperation1和PrimitiveOperation2
        base->TemplateMethod();
    }


    return 0;
}