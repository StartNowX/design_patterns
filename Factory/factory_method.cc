/**
 * 工厂方法模式：定义一个用于创建对象的接口，让子类决定实例化哪一个类
 *
 * 但是，如果需要新增加需求，则需要从父类（AbstractorFactory）新继承一个对应需求的类
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

class AbstractorFactory {
   public:
    // 将具体实例化某一类的对象交给子类来做
    virtual Operators* create_factory() = 0;
    virtual ~AbstractorFactory() {}
};

class AddFactory : public AbstractorFactory {
   public:
    Operators* create_factory() { return new OperatorAdd(); }
};

class SubFactory : public AbstractorFactory {
   public:
    Operators* create_factory() { return new OperatorSub(); }
};

int main(int argc, char* argv[]) {
    {
        AddFactory add_factory;
        Operators* opt_add = add_factory.create_factory();
        opt_add->Operator();
        delete opt_add;
    }

    {
        SubFactory sub_factory;
        Operators* opt_sub = sub_factory.create_factory();
        opt_sub->Operator();
        delete opt_sub;
    }

    return 0;
}