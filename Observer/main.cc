#include <iostream>

#include "observer.h"
#include "subject.h"

class A {
   public:
    A(int a) : a_(a) {}
    ~A() { std::cout << "~A()" << std::endl; }

    void Show() { std::cout << "a_ = " << a_ << std::endl; }

   private:
    int a_;
};

void Test() {
    std::shared_ptr<A> a_ptr = std::shared_ptr<A>(new A(3), [](A* p) {
        std::cout << "delete a" << std::endl;
        delete p;
    });

    a_ptr->Show();
}

void Test111() {
    {
        ConcreteSubjectA* sub_a = new ConcreteSubjectA;
        auto sub_a_ptr = std::shared_ptr<ConcreteSubjectA>(sub_a, [](ConcreteSubjectA* a) {
            std::cout << "delete ConcreteSubjectA ptr" << std::endl;
            delete a;
        });

        {
            // 观察者A订阅sub_a_ptr，这里sub_a_ptr绑定到con_sub_a这个对象
            // auto con_obs_a = std::shared_ptr<ConcreteObserverA>(new ConcreteObserverA); // 裸指针构造会double free
            ConcreteObserverA* obs_a = new ConcreteObserverA;
            auto con_obs_a = std::shared_ptr<ConcreteObserverA>(obs_a, [](ConcreteObserverA* p) {
                std::cout << "delete ConcreteObserverA ptr" << std::endl;
                delete p;
            });
            con_obs_a->Bind(sub_a_ptr);
            con_obs_a->Update(sub_a_ptr);

            sub_a_ptr->SetState("con_sub_a test");
            con_obs_a->Update(sub_a_ptr);

            con_obs_a->UnBind(sub_a_ptr);
        }
        std::cout << "000 sub_a_ptr.count = " << sub_a_ptr.use_count() << std::endl;  // 1, sub_a

        std::cout << "=================" << std::endl;

        {
            auto con_obs_a = std::make_shared<ConcreteObserverA>();
            auto con_obs_b = std::make_shared<ConcreteObserverB>();

            con_obs_a->Bind(sub_a_ptr);
            con_obs_a->Update(sub_a_ptr);

            con_obs_b->Bind(sub_a_ptr);
            con_obs_b->Update(sub_a_ptr);

            sub_a_ptr->SetState("NewSub");
            con_obs_b->Update(sub_a_ptr);
            con_obs_a->Update(sub_a_ptr);
            std::cout << "111 sub_a_ptr.count = " << sub_a_ptr.use_count() << std::endl;  // 3个，sub_a, con_obs_a/b

            con_obs_a->UnBind(sub_a_ptr);
            con_obs_b->UnBind(sub_a_ptr);
        }
        std::cout << "sub_a_ptr.count = " << sub_a_ptr.use_count() << std::endl;  // 1, sub_a
    }
    std::cout << "Finish Test111, delete sub_a_ptr..." << std::endl;
}

int main(int argc, char* argv[]) {
    // 会double free，con_sub_a声明周期结束后，会析构掉，而sub指向了con_sub_a，又析构了一遍
    // ConcreteSubjectA con_sub_a;
    // Subject* sub1 = &con_sub_a;
    // auto sub = SubPtrType(sub1);

    Test111();

    std::cout << "========finish=========" << std::endl;

    Test();
    return 0;
}