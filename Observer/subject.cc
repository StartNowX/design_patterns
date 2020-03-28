#include "subject.h"

#include <iostream>

#include "observer.h"

Subject::Subject(){};
Subject::~Subject() { std::cout << "~Subject()" << std::endl; };

// 观察者注册
void Subject::Register(ObsPtrType obs) { obs_list_.push_back(obs); }

void Subject::UnRegister(ObsPtrType obs) {
    if (!obs_list_.empty()) {
        obs_list_.remove(obs);
    }
}

void Subject::Notify() {
    for (auto obs : obs_list_) {
        obs->Update(shared_from_this());
    }
}

ConcreteSubjectA::ConcreteSubjectA() { st_ = '\0'; }
ConcreteSubjectA::~ConcreteSubjectA() {}
void ConcreteSubjectA::SetState(const State& st) { st_ = st; }
State ConcreteSubjectA::GetState() { return st_; }