/*
 * @Descripttion:
 * @version:
 * @Author: sunxiang
 * @Date: 2019-08-11 23:40:44
 * @LastEditors: sunxiang
 * @LastEditTime: 2019-08-12 00:59:37
 */
#include "singleton.h"

#include <iostream>

void test_single() {
    // version 1, not call deconstructor, memory leak
    // Singleton* test_singleton = Singleton::GetInstance();
    // test_singleton->ShowSingleOperation();

    Singleton& test_singleton = Singleton::GetInstance();
    test_singleton.ShowSingleOperation();
}

int main(int argc, char* argv[]) {
    test_single();

    std::cout << "test over" << std::endl;


    return 0;
}
