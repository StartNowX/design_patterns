/*
 * @Descripttion:
 * @version:
 * @Author: sunxiang
 * @Date: 2019-08-11 23:40:44
 * @LastEditors: sunxiang
 * @LastEditTime: 2019-08-12 00:59:37
 */
#include <iostream>

#include "singleton.h"

void test_single() {
    // version 1, not call deconstructor, memory leak
    // Singleton* test_singleton = Singleton::GetInstance();
    // test_singleton->ShowSingleOperation();
    // test_singleton = nullptr;

    // 由于返回的是Singleton类的static成员的引用，所以不管顶层有多少地方调用下面这句话，其始终是同一个Singleton的instance的引用（static）
    Singleton& test_singleton = Singleton::GetInstance();
    test_singleton.ShowSingleOperation();
}

int main(int argc, char* argv[]) {
    test_single();

    std::cout << "test over" << std::endl;


    return 0;
}
