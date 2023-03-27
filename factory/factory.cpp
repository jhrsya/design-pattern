#include <iostream>
using namespace std;

//抽象产品类，不能实例化
class Product {
public:
    Product(){};
    virtual void show() = 0;    //纯虚函数
};

//抽象工厂类，不能实例化
class Factory {
public:
    Factory(){};
    virtual Product* CreateProduct() = 0;   //纯虚函数
};

//产品A
class ProductA: public Product {
public:
    ProductA(){};
    void show(){
        cout << "product A create!" << endl;
    }
};

//产品B
class ProductB: public Product {
public:
    ProductB(){};
    void show(){
        cout << "product B create!" << endl;
    }
};

//工厂A
class FactoryA: public Factory {
public:
    FactoryA(){};
    Product* CreateProduct(){
        Product* product_ = nullptr;
        product_ = new ProductA();
        return product_;
    }
};

//工厂B
class FactoryB: public Factory {
public:
    FactoryB(){};
    Product* CreateProduct(){
        Product* product_ = nullptr;
        product_ = new ProductB();
        return product_;
    }
};

int main(){
    Product* product_ = nullptr;
    auto MyFactoryA = new FactoryA();
    product_ = MyFactoryA->CreateProduct(); //调用产品A的工厂来生产产品A
    product_->show();
    delete product_;

    auto MyFactoryB = new FactoryB();
    product_ = MyFactoryB->CreateProduct(); //调用产品B的工厂来生产产品B
    product_->show();
    delete product_;
    return 0;
}