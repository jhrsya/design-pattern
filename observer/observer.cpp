#include <iostream>
#include <list>
using namespace std;

class Subject;
//观察者 基类（内部实例化了被观察者的对象sub)
class Observer {
protected:
    string name;
    Subject *sub;
public:
    //构造函数
    Observer(string name, Subject* sub){
        this->name = name;
        this->sub = sub;
    }
    virtual void update() = 0;
};

class StockObserver: public Observer {
public:
    StockObserver(string name, Subject* sub): Observer(name, sub){};
    void update();
};

class NBAObserver: public Observer {
public:
    NBAObserver(string name, Subject* sub): Observer(name, sub) {};
    void update();
};

//被观察者 基类 （内部存放了所有的观察者对象，以便状态发生变化时，给观察者发通知）
class Subject {
protected:
    list<Observer *> observers;
public:
    string action;  //被观察者对象的状态
    virtual void attach(Observer*) = 0;
    virtual void detach(Observer*) = 0;
    virtual void notify() = 0;
};

class Secretary: public Subject {
    void attach(Observer *observer){
        observers.push_back(observer);
    }
    void detach(Observer *observer){
        list<Observer *>::iterator iter = observers.begin();
        while(iter != observers.end()){
            if((*iter) != observer){
                observers.erase(iter);
                return;
            }
            ++iter;
        }
    }
    void notify(){
        list<Observer*>::iterator iter = observers.begin();
        while(iter != observers.end()){
            (*iter)->update();  //每一个观察者都更新状态
            ++iter;
        }
    }
};

void StockObserver::update(){
    cout << name << " get message: " << sub->action << endl;
    if(sub->action == "boss is coming!"){
        cout << "stop stock, working." << endl;
    }
}

void NBAObserver::update(){
    cout << name << " get message: " << sub->action << endl;
    if(sub->action == "boss is coming!"){
        cout << "stop stock, working." << endl;
    }
}

int main(){
    Subject* BOSS = new Secretary();
    Observer* xa = new NBAObserver("xa", BOSS);
    Observer* xb = new NBAObserver("xb", BOSS);
    Observer* xc = new NBAObserver("xc", BOSS);

    BOSS->attach(xa);
    BOSS->attach(xb);
    BOSS->attach(xc);

    BOSS->action = "having lunch";
    BOSS->notify();
    cout << endl;
    BOSS->action = "boss is coming!";
    BOSS->notify();
    return 0;
}