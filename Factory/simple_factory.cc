/**
 * 简单工厂模式
 * 统一由一个类管理所有的对象的实例化，但是如果有新的需求增加的话，就需要修改这个类了
 */

#include <iostream>
using namespace std;

enum OPERATOR { ADD, SUBSTRACTION, MULTI, DIVID };

class Operators {
   public:
    virtual void Operator() = 0;
    ~Operators(){};
};

class OperatorAdd : public Operators {
   public:
    void Operator() { std::cout << "this is add operator" << std::endl; }
};

class OperatorSub : public Operators {
   public:
    void Operator() { std::cout << "this is substraction operator" << std::endl; }
};

// 如果新增加运算符的话，就需要更改这个AbstractFactory
class AbstractFactory {
   public:
    // 统一由这一个类实现不同类型的对象的创建
    Operators* creat_operator(OPERATOR opt) {
        Operators* opt_factory = nullptr;
        switch (opt) {
            case ADD:
                opt_factory = new OperatorAdd();
                break;
            case SUBSTRACTION:
                opt_factory = new OperatorSub();
                break;
            default:
                break;
        }
        return opt_factory;
    }
};

int main(int argc, char* argv[]) {
    AbstractFactory abs_factory;
    {
        Operators* opt_factory = abs_factory.creat_operator(ADD);
        opt_factory->Operator();
        delete opt_factory;
    }

    {
        OperatorFactory* opt_factory = abs_factory.creat_operator(SUBSTRACTION);
        opt_factory->Operator();
        delete opt_factory;
    }


    return 0;
}