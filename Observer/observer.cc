#include "observer.h"

#include <iostream>

#include "subject.h"

Observer::Observer() { st_ = '\0'; }
Observer::~Observer() {}

// 每一个观察者在构造时向Subject订阅
ConcreteObserverA::ConcreteObserverA(Subject* sub) {
    sub_ = sub;
    sub_->Register(this);
}
// 每一个观察者在析构时向Subject取消注册信息
ConcreteObserverA::~ConcreteObserverA() {
    sub_->UnRegister(this);
    if (!sub_) {
        delete sub_;
    }
}
// 获取观察者订阅的类
Subject* ConcreteObserverA::GetSubject() { return sub_; }

// 观察者获取订阅的Subject的信息，该Update接口，将在Subject类Notify的时候调用
void ConcreteObserverA::Update(Subject* sub) {
    st_ = sub->GetState();
    PrintInfo();
}

void ConcreteObserverA::PrintInfo() { std::cout << "ConcreteObserverA st_ " << st_ << " ......" << std::endl; }


ConcreteObserverB::ConcreteObserverB(Subject* sub) {
    sub_ = sub;
    sub->Register(this);
}

ConcreteObserverB::~ConcreteObserverB() {
    sub_->UnRegister(this);
    if (!sub_) {
        delete sub_;
    }
}

Subject* ConcreteObserverB::GetSubject() { return sub_; }

void ConcreteObserverB::Update(Subject* sub) {
    st_ = sub->GetState();
    PrintInfo();
}

void ConcreteObserverB::PrintInfo() { std::cout << "ConcreteObserverB st_ " << st_ << " ......" << std::endl; }