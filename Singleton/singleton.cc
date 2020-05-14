/*
 * @Descripttion:
 * @version:
 * @Author: sunxiang
 * @Date: 2019-08-11 23:42:12
 * @LastEditors: sunxiang
 * @LastEditTime: 2019-08-12 00:58:19
 */
#include "singleton.h"

#include <atomic>
#include <iostream>
#include <mutex>

// version 1 线程不安全版本
// Singleton* Singleton::GetInstance() {
//     if (nullptr == instance) {
//         instance = new Singleton();
//         return instance;
//     }
// }

// // verson 2 线程安全版本, 锁的代价大
// std::mutex g_mutex;
// Singleton* Singleton::GetInstance() {
//     g_mutex.lock();
//     if (nullptr == instance) {
//         instance = new Singleton();
//     }
//     g_mutex.unlock();
//     return instance;
// }

// // verson 3 双锁检查(DCL, double check lock)，由于内存问题会出现re-order的情况
// // 主要在于instance = new
// Singleton();这句话在编译器指令里面分为三步骤（分配内存、调用构造器、指针赋值），可能出现这三个顺序re-order的情况//
// std::mutex g_mutex;
// Singleton* Singleton::GetInstance() {
/***
 * 如果没有按照分配内存、调用构造器、指针赋值这个顺序，可以某个线程在第一个if判断时就认为instance不是nullptr的了，就返回一个不完整的instance
 */
//     if (nullptr == instance) {
//         g_mutex.lock();
//         if (nullptr == instance) {
//             instance = new Singleton();
//         }
//     }
//     g_mutex.unlock();
//     return instance;
// }

// verson 4 C++跨平台
// C++11 跨平台
// std::atomic<Singleton*> m_instance;
// std::mutex m_mutex;
// Singleton* Singleton::GetInstance() {
//     Singleton* tmp = m_instance.load(std::memory_order_relaxed);
//     std::atomic_thread_fence(std::memory_order_acquire);
//     if(nullptr == tmp){
//         std::lock_guard<std::mutex> lock(m_mutex);
//         tmp = m_instance.load(std::memory_order_relaxed);
//         if(nullptr == tmp){
//             tmp = new Singleton;
//             std::atomic_thread_fence(std::memory_order_release);
//             m_instance.store(tmp, std::memory_order_relaxed);
//         }
//     }
//     return tmp;
// }

// 最简易版本, Meyers' Singleton
// ensure creating objective when first call this method
Singleton& Singleton::GetInstance() {
    static Singleton instance;
    return instance;
}

void Singleton::ShowSingleOperation() { std::cout << "U are operating single pattern." << std::endl; }

Singleton* Singleton::instance = nullptr;

Singleton::Singleton() {}

Singleton::~Singleton() {
    std::cout << "deconstructor" << std::endl;
    delete instance;
}