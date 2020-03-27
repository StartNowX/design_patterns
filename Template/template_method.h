#pragma

/**
 * 模版方法设计模式，定义基类（AbstractClass），在基类中实现一个模版方法接口（TemplateMethod），该接口实现一个通用的不同模块的调用框架，但是不同模块内部的实现细节由子类实现（PrimitiveOperation1，PrimitiveOperation2）
 *
 * 模块内部的实现细节，利用【工厂方法设计模式】，将其实现细节下放到子类中实现
 *
 * 优点：
 *     1. 把能够通用的业务逻辑放到父类中，减少代码的重复
 *     2. 子类可以根据其具体的需求实现算法细节，方便扩展
 *     3. 通过一个父类调用子类实现的操作，子类扩展增加新的行为，符合“开放-封闭原则”
 * 缺点：
 *     1. 同工厂方法模式一样，每增加一个新的算法实现细节，都需要增加一个子类
 *
 * 参考：https://blog.csdn.net/fanyun_01/article/details/51784241
 */

class AbstractClass {
   public:
    ~AbstractClass();

    // 定义统一的模版方法，给出逻辑框架，而逻辑的组成是具体的抽象操作，下放到子类中实现
    // 也就是在该接口中，按照一个通用的框架调用PrimitiveOperation1()和PrimitiveOperation2()，而他们的具体实现算法是不同的，由不同的子类去把控
    // 这样，继承AbstractClass的所有子类都可以只调用TemplateMethod方法就可以完成需求，而不需要单独重写自己的TemplateMethod
    void TemplateMethod();

    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;

   protected:
    // 构造函数下方为protected级别，保证子类能够调用，但是不给用户调用，即用户不能直接构造一个AbstractClass的对象
    AbstractClass();
};

class ConcreteClassA : public AbstractClass {
   public:
    ConcreteClassA();
    ~ConcreteClassA();

    // 按自身特点，实现基类中定义的两个抽象行为
    void PrimitiveOperation1();
    void PrimitiveOperation2();
};

class ConcreteClassB : public AbstractClass {
   public:
    ConcreteClassB();
    ~ConcreteClassB();

    // 按自身特点，实现基类中定义的两个抽象行为
    void PrimitiveOperation1();
    void PrimitiveOperation2();
};