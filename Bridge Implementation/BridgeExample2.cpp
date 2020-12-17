#include <iostream>
#include <string>

using namespace std;

/* Interfaz implementada.*/
class AbstractInterface{
    public:
        virtual void someFunctionality() = 0;
};

/* Interfaz para implementación interna que usa Bridge. */
class ImplementationInterface{
    public:
        virtual void anotherFunctionality() = 0;
};

/* Bridge */
class Bridge : public AbstractInterface{
    protected:
        ImplementationInterface* implementation;

    public:
        Bridge(ImplementationInterface* backend)
        {
            implementation = backend;
        }
};

/* Diferentes casos especiales de la interfaz. */

class UseCase1 : public Bridge{
    public:
        UseCase1(ImplementationInterface* backend) : Bridge(backend) {}

        void someFunctionality(){
            std::cout << "UseCase1 on ";
            implementation->anotherFunctionality();
        }
};

class UseCase2 : public Bridge{
    public:
        UseCase2(ImplementationInterface* backend) : Bridge(backend) {}

        void someFunctionality(){
            cout << "UseCase2 on ";
            implementation->anotherFunctionality();
        }
};

/* Diferentes implementaciones de fondo. */

class Windows : public ImplementationInterface{
    public:
        void anotherFunctionality(){
            std::cout << "°° Windows °° " << std::endl;
        }
};

class Linux : public ImplementationInterface{
    public:
        void anotherFunctionality(){
            std::cout << "!! Linux !! " << std::endl;
        }
};

int main(){
    AbstractInterface *useCase = 0;
    ImplementationInterface *osWindows = new Windows;
    ImplementationInterface *osLinux = new Linux;

    /* Primer caso */
    useCase = new UseCase1(osWindows);
    useCase->someFunctionality();

    useCase = new UseCase1(osLinux);
    useCase->someFunctionality();

    /* Segundo caso */
    useCase = new UseCase2(osWindows);
    useCase->someFunctionality();

    useCase = new UseCase2(osLinux);
    useCase->someFunctionality();

    return 0;
}
