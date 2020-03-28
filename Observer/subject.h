#pragma

#include <list>
#include <string>

using State = std::string;

class Observer;

class Subject {
   public:
    virtual ~Subject();
    virtual void Register(Observer* obs);
    virtual void UnRegister(Observer* obs);
    virtual void Notify();

    virtual void SetState(const State& st) = 0;
    virtual State GetState() = 0;

   protected:
    // 不允许用户声明一个Subject类，而只能声明一个具体的子类
    Subject();

   private:
    std::list<Observer*> obs_list_;
};

class ConcreteSubjectA : public Subject {
   public:
    ConcreteSubjectA();
    ~ConcreteSubjectA();

    void SetState(const State& st);
    State GetState();

   private:
    State st_;
};