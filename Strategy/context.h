/**
 * Strategy和Template的区别就在于，template模式利用继承的方式实现抽象接口，而strategy模式则是通过组合的方式
 */

class Strategy;

class Context {
   public:
    Context(Strategy *stg) : _stg(stg) {}
    ~Context();

    void DoAction();

   private:
    Strategy *_stg;
};