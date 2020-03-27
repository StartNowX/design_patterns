#include "context.h"

#include "strategy.h"

Context::~Context() {
    if (!_stg) {
        delete _stg;
        _stg = nullptr;
    }
}

void Context::DoAction() {
    // 这里根据_stg具体指向的子类调用相应的操作
    _stg->AlgorithmInterface();
}