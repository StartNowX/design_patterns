#pragma

/**
 * Strategy中定义一个抽象接口，由子类去分别实现各自的该接口，然后由另一个类Context根据传入的strategy子类去统一调用AlgorigthmInterface接口，
 */

class Strategy {
   public:
    Strategy() {}
    virtual ~Strategy() {}

    // 子类分别实现这些接口
    virtual void AlgorithmInterface() = 0;
};

class ConcreteClassA : public Strategy {
   public:
    ConcreteClassA() {}
    virtual ~ConcreteClassA() {}

    void AlgorithmInterface();
};


class ConcreteClassB : public Strategy {
   public:
    ConcreteClassB() {}
    virtual ~ConcreteClassB() {}

    void AlgorithmInterface();
};