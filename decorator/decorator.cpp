#include <iostream>
#include <list>
#include <memory>
using namespace std;

//抽象构件类 Transform (变形金刚)
class Transform {
public:
    virtual void move() = 0;
};

//具体构件类Car
class Car: public Transform {
public:
    Car(){
        cout << "Transform is a car." << endl;
    }
    void move(){
        cout << "moving in the road." << endl;
    }
};

//抽象装饰类
class Changer: public Transform {
public:
    Changer(shared_ptr<Transform> transform){
        this->transform = transform;
    }
    void move(){
        transform->move();
    }
private:
    shared_ptr<Transform> transform;
};

//具体装饰类Robot
class Robot : public Changer{
public:
    Robot(shared_ptr<Transform> transform) : Changer(transform){
        cout << "become a robot." << endl;
    }
    void say(){
        cout << "say" << endl;
    }
};

//具体装饰类
class Airplane : public Changer{
public:
    Airplane(shared_ptr<Transform> transform) : Changer(transform){
        cout << "become airplane." << endl;
    }
    void say(){
        cout << "fly in the sky." << endl;
    }
};


int main(){
    shared_ptr<Transform> camaro = make_shared<Car>();
    camaro->move();
    cout << "------------------------" << endl;
    shared_ptr<Robot> bumblebee = make_shared<Robot>(camaro);
    bumblebee->move();
    bumblebee->say();

    cout << "------------------------" << endl;
    shared_ptr<Airplane> air = make_shared<Airplane>(camaro);
    air->move();
    air->say();
    return 0;
}