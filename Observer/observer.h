#pragma

#include <string>

using State = std::string;

class Subject;

// 观察者抽象类，不同的观察者子类去实现自己的Update操作
class Observer {
   public:
    virtual ~Observer();
    virtual void Update(Subject* sub) = 0;
    virtual void PrintInfo() = 0;

   protected:
    Observer();
    State st_;
};

class ConcreteObserverA : public Observer {
   public:
    virtual Subject* GetSubject();
    // 每个观察者的构造时，都需要有Subject参数，相当于必须指定其订阅的对象
    // 这里通过Subject基类指针，实现了不同Subject子类的动态绑定
    ConcreteObserverA(Subject* sub);
    ~ConcreteObserverA();

    void Update(Subject* sub);
    void PrintInfo();

   private:
    Subject* sub_;
};


class ConcreteObserverB : public Observer {
   public:
    virtual Subject* GetSubject();
    // 每个观察者的构造时，都需要有Subject参数，相当于必须指定其订阅的对象
    // 这里通过Subject基类指针，实现了不同Subject子类的动态绑定
    ConcreteObserverB(Subject* sub);
    ~ConcreteObserverB();

    void Update(Subject* sub);
    void PrintInfo();

   private:
    Subject* sub_;
};
