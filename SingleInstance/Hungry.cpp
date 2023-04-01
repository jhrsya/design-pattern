#include <iostream>
#include <algorithm>

class SingleInstance {
public:
    static SingleInstance* GetInstance()
    {
        static SingleInstance ins;
        return &ins;
    }
    ~SingleInstance(){};
private:
    //设计创建对象的函数设置为私有的
    SingleInstance()
    {
        std::cout << "SingelInstance()" << std::endl;
    }
    SingleInstance(const SingleInstance& other){};
    SingleInstance& operator = (const SingleInstance& other)
    {
        return *this;
    }
};

int main(){
    //因为不能创建对象所以通过静态成员函数的方法返回静态成员遍历
    SingleInstance* ins = SingleInstance::GetInstance();
    return 0;
}