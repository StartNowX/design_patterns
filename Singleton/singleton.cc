/*
 * @Descripttion:
 * @version:
 * @Author: sunxiang
 * @Date: 2019-08-11 23:42:12
 * @LastEditors: sunxiang
 * @LastEditTime: 2019-08-12 00:58:19
 */
#include "singleton.h"

#include <iostream>

// version 1
// Singleton* Singleton::GetInstance() {
//     if (nullptr == instance) {
//         instance = new Singleton();
//         return instance;
//     }
// }

// ensure creating objective when first call this method
Singleton& Singleton::GetInstance(){
    if (nullptr == instance) {
        static Singleton instance;
        return instance;
    }
}

void Singleton::ShowSingleOperation() { std::cout << "U are operating single pattern." << std::endl; }

Singleton* Singleton::instance = nullptr;

Singleton::Singleton() {}

Singleton::~Singleton() {
    std::cout << "deconstructor" << std::endl;
    delete instance;
}