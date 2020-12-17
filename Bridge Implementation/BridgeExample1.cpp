/**
 * La implementaci�n define la interfaz para todas las clases de implementaci�n.
 * No tiene que coincidir con la interfaz de Abstraction. De hecho, las dos
 * interfaces pueden ser completamente diferentes. Normalmente, la interfaz
 * de implementaci�n proporciona solo operaciones primitivas, mientras que la
 * abstracci�n define operaciones de nivel superior basadas en esas primitivas.
**/

#include <string>
#include <iostream>
using namespace std;

class Implementation {
    public:
        virtual ~Implementation() {}
        virtual string OperationImplementation() const = 0;
};

/**
* Cada Implementaci�n Concreta corresponde a una plataforma espec�fica e
* implementa la interfaz de Implementaci�n utilizando la API de esa plataforma.
**/

class ConcreteImplementationA : public Implementation {
    public:
        string OperationImplementation() const override {
            return "Implementaci�n concreta A: aqu� est� el resultado en la plataforma A.\n";
        }
};

class ConcreteImplementationB : public Implementation {
    public:
        string OperationImplementation() const override {
            return "Implementaci�n concreta B: aqu� est� el resultado en la plataforma B.\n";
        }
};

/**
 * La abstracci�n define la interfaz para la parte de "control" de las dos clases
 * jerarqu�as. Mantiene una referencia a un objeto de la Implementaci�n
 * jerarqu�a y delega todo el trabajo real a este objeto.
**/

class Abstraction {
    protected:
        Implementation* implementation_;

    public:
        Abstraction(Implementation* implementation) : implementation_(implementation) {}

    virtual ~Abstraction() {}

    virtual string Operation() const {
        return "Abstracci�n: Operaci�n base con:\n" + this->implementation_->OperationImplementation();
    }
};

/**
 * Puede extender la abstracci�n sin cambiar las clases de implementaci�n.
**/

class ExtendedAbstraction : public Abstraction {
    public:
        ExtendedAbstraction(Implementation* implementation) : Abstraction(implementation) {}
        string Operation() const override {
            return "Abstracci�n extendida: operaci�n extendida con:\n" + this->implementation_->OperationImplementation();
        }
};

/**
 * Excepto por la fase de inicializaci�n, donde se vincula un objeto de abstracci�n
 * con un objeto de implementaci�n espec�fico, el c�digo de cliente solo debe depender de
 * la clase Abstracci�n. De esta forma, el c�digo del cliente puede admitir cualquier abstracci�n.
 * combinaci�n de implementaci�n.
**/

void ClientCode(const Abstraction& abstraction) {
    cout << abstraction.Operation();
}

/**
 * El c�digo del cliente deber�a poder funcionar con cualquier combinaci�n
 * de implementaci�n de abstracci�n preconfigurada.
**/

int main() {
    Implementation* implementation = new ConcreteImplementationA;
    Abstraction* abstraction = new Abstraction(implementation);
    ClientCode(*abstraction);
    cout << endl;
    delete implementation;
    delete abstraction;

    implementation = new ConcreteImplementationB;
    abstraction = new ExtendedAbstraction(implementation);
    ClientCode(*abstraction);

    delete implementation;
    delete abstraction;

    return 0;
}
