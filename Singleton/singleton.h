/*
 * @Descripttion: Implementation of Class Singleton
 * @version:
 * @Author: sunxiang
 * @Date: 2019-08-11 11:45:43
 * @LastEditors: sunxiang
 * @LastEditTime: 2019-08-12 01:06:12
 */


#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <iostream>


class Singleton {
   public:
    // version 1
    // static Singleton* GetInstance();

    // version 2
    static Singleton& GetInstance();

    void ShowSingleOperation();

   private:
    static Singleton* instance;
    
    // TODO: check why version 1 do not print the infos
    class Deletor {
       public:
        ~Deletor(){
            if(nullptr != Singleton::instance){
                std::cout << "Use nested class to delete" << std::endl;
                delete Singleton::instance;
            }
        }
    };

    // class Deletor;
    static Deletor deletor;

    Singleton();
    ~Singleton();
    // disable copy constructor
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};


#endif  // SINGLETON_H_
