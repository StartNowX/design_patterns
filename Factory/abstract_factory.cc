/**
 * 抽象工厂模式：提供一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类
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

// 抽象工厂
class AbstractorFactory {
   public:
    virtual Operators* create_add_opt() = 0;
    virtual Operators* create_sub_opt() = 0;
    virtual ~AbstractorFactory() {}
};

// 每一个工厂都对应多个方法，能够实现相互间的交互
class SubFactory : public AbstractorFactory {
   public:
    Operators* create_add_opt() { return new OperatorAdd(); }

    Operators* create_sub_opt() { return new OperatorSub(); }
};

class AddFactory : public AbstractorFactory {
   public:
    Operators* create_add_opt() { return new OperatorAdd(); }

    Operators* create_sub_opt() { return new OperatorSub(); }
};


int main(int argc, char* argv[]) {
    {
        // 一个SubFactory可以创建多个产品Operators
        SubFactory sub_factory;
        Operators* opt_add = sub_factory.create_add_opt();
        Operators* opt_sub = sub_factory.create_sub_opt();
        opt_add->Operator();
        opt_sub->Operator();

        delete opt_add;
        delete opt_sub;
    }

    return 0;
}