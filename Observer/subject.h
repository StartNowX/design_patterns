#pragma

#include <list>
#include <memory>
#include <string>

using State = std::string;

class Observer;

using ObsPtrType = std::shared_ptr<Observer>;

class Subject : public std::enable_shared_from_this<Subject> {
   public:
    virtual ~Subject();
    virtual void Register(ObsPtrType obs);
    virtual void UnRegister(ObsPtrType obs);
    virtual void Notify();

    virtual void SetState(const State& st) = 0;
    virtual State GetState() = 0;

   protected:
    // 不允许用户声明一个Subject类，而只能声明一个具体的子类
    Subject();

   private:
    std::list<ObsPtrType> obs_list_;
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