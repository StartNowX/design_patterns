### 观察者模式

1. 定义对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并被自动更新。它还有两个别名，依赖(Dependents)，发布-订阅(Publish-Subsrcibe)

2. 下面案例中的Subject即一，Observer则是多，每个Observer向Subject去订阅消息（注册），当Subject发生变化时，通知多个Observer，每个Observer通过Update获取最新的消息

2. 实例结构解读
    * Subject类，维护一个Observer类的list，定义Register/Unregister/Notify三个成员函数
        * Register/Unregister：维护list列表，以Observer对象指针作为入参，实时更新list
        * Notify：负责发布到list中所有的observer对象，即遍历list，并对每个对象调用其update成员函数
    * Observer类，定义一个update接口，并下放到具体的子类去实现
        * Update以Subject作为入参，可以实现同步更新多个Subject
        * Update接口下放到子类实现，这样Subject类的Notify接口，能够自动绑定对应的子类