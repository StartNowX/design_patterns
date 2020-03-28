#include <iostream>

#include "observer.h"
#include "subject.h"

int main(int argc, char* argv[]) {
    ConcreteSubjectA con_sub_a;
    Subject* sub = &con_sub_a;
    {
        // 观察者A订阅sub，这里sub绑定到con_sub_a这个对象
        ConcreteObserverA con_obs_a(sub);
        con_obs_a.Update(sub);

        sub->SetState("con_sub_a test");
        con_obs_a.Update(sub);
    }

    {
        std::cout << "=================" << std::endl;
        ConcreteObserverA con_obs_a(sub);
        ConcreteObserverB con_obs_b(sub);
        con_obs_a.Update(sub);
        con_obs_b.Update(sub);

        sub->SetState("NewSub");
        con_obs_b.Update(sub);
        con_obs_a.Update(sub);
    }
    return 0;
}