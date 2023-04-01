#include <pthread.h>
#include <iostream>
#include <algorithm>
using namespace std;

class SingleInstance {
private:
    //涉及到创建对象的函数都设置为private
    SingleInstance()
    {
        cout << "SingleInstance Lazy" << endl;
    }

    SingleInstance(const SingleInstance& other){};

    SingleInstance& operator = (const SingleInstance& other)
    {
        return *this;
    }
    //静态成员
    static SingleInstance* ins;

public:
    static SingleInstance* GetInstance()
    {
        if(ins == nullptr)
        {
            pthread_mutex_lock(&mutex);
            if(ins == nullptr)
            {
                ins = new SingleInstance();
            }
            pthread_mutex_unlock(&mutex);
        }
        return ins;
    }
    ~SingleInstance();
    //互斥锁
    static pthread_mutex_t mutex;
};

//懒汉式，静态变量需要定义
SingleInstance* SingleInstance::ins = nullptr;
pthread_mutex_t SingleInstance::mutex;


int main(){
    //因为不能创建变量，所以通过静态函数的方法返回静态成员变量
    SingleInstance* ins = SingleInstance::GetInstance();
    delete ins;
    return 0;
}
