#include "observer.h"

#include <iostream>

#include "subject.h"

Observer::Observer() { st_ = '\0'; }
Observer::~Observer() { std::cout << "~Observer()" << std::endl; }

// 每一个观察者在构造时向Subject订阅，
// ConcreteObserverA::ConcreteObserverA(ObsPtrType sub) {
//     sub_ = sub;
//     sub_->Register(share_from_this()); // 不能再构造函数中直接调用share_from_this，这时候对象还没有初始化完成
// }

// 每一个观察者在析构时向Subject取消注册信息
ConcreteObserverA::~ConcreteObserverA() { std::cout << "~ConcreteObserverA()" << std::endl; }

void ConcreteObserverA::Bind(SubPtrType sub) {
    sub_ = sub;
    sub_->Register(shared_from_this());
}

void ConcreteObserverA::UnBind(SubPtrType sub) { sub_->UnRegister(shared_from_this()); }

// 获取观察者订阅的类
SubPtrType ConcreteObserverA::GetSubject() { return sub_; }

// 观察者获取订阅的Subject的信息，该Update接口，将在Subject类Notify的时候调用
void ConcreteObserverA::Update(SubPtrType sub) {
    st_ = sub->GetState();
    PrintInfo();
}

void ConcreteObserverA::PrintInfo() { std::cout << "ConcreteObserverA st_ " << st_ << " ......" << std::endl; }


ConcreteObserverB::~ConcreteObserverB() { std::cout << "~ConcreteObserverB()" << std::endl; }

void ConcreteObserverB::Bind(SubPtrType sub) {
    sub_ = sub;
    sub_->Register(shared_from_this());
}

void ConcreteObserverB::UnBind(SubPtrType sub) { sub_->UnRegister(shared_from_this()); }

SubPtrType ConcreteObserverB::GetSubject() { return sub_; }

void ConcreteObserverB::Update(SubPtrType sub) {
    st_ = sub->GetState();
    PrintInfo();
}

void ConcreteObserverB::PrintInfo() { std::cout << "ConcreteObserverB st_ " << st_ << " ......" << std::endl; }