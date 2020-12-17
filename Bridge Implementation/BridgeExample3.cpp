#include<iostream>
#include<string>

using namespace std;

class IColor{
public:
    virtual string Color() = 0;
};

class RedColor : public IColor{
public:
    string Color(){
        return "de Color Rojo";
    }
};

class BlueColor : public IColor{
public:
    string Color(){
        return "de Color Azul";
    }
};

class ICarModel {
public:
    virtual string WhatIsMyType() = 0;
};

class Model_A : public ICarModel {
    IColor* _myColor;
    public:
        Model_A(IColor *obj) :_myColor(obj){}
        string WhatIsMyType() {
            return "Soy el modelo A " + _myColor->Color();
        }
};

class Model_B : public ICarModel {
    IColor* _myColor;
    public:
        Model_B(IColor *obj) :_myColor(obj){}
        string WhatIsMyType() {
            return "Soy el modelo B " + _myColor->Color();;
        }
};

int main() {
    IColor* red = new RedColor();
    IColor* blue = new BlueColor();

    ICarModel* modelA = new Model_B(red);
    ICarModel* modelB = new Model_A(blue);

    cout << "\n" << modelA->WhatIsMyType();
    cout << "\n" << modelB->WhatIsMyType() << "\n\n";

    return 0;
}
