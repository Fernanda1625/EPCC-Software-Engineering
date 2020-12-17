/**
 * La implementación define la interfaz para todas las clases de implementación.
 * No tiene que coincidir con la interfaz de Abstraction. De hecho, las dos
 * interfaces pueden ser completamente diferentes. Normalmente, la interfaz
 * de implementación proporciona solo operaciones primitivas, mientras que la
 * abstracción define operaciones de nivel superior basadas en esas primitivas.
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
* Cada Implementación Concreta corresponde a una plataforma específica e
* implementa la interfaz de Implementación utilizando la API de esa plataforma.
**/

class ConcreteImplementationA : public Implementation {
    public:
        string OperationImplementation() const override {
            return "Implementación concreta A: aquí está el resultado en la plataforma A.\n";
        }
};

class ConcreteImplementationB : public Implementation {
    public:
        string OperationImplementation() const override {
            return "Implementación concreta B: aquí está el resultado en la plataforma B.\n";
        }
};

/**
 * La abstracción define la interfaz para la parte de "control" de las dos clases
 * jerarquías. Mantiene una referencia a un objeto de la Implementación
 * jerarquía y delega todo el trabajo real a este objeto.
**/

class Abstraction {
    protected:
        Implementation* implementation_;

    public:
        Abstraction(Implementation* implementation) : implementation_(implementation) {}

    virtual ~Abstraction() {}

    virtual string Operation() const {
        return "Abstracción: Operación base con:\n" + this->implementation_->OperationImplementation();
    }
};

/**
 * Puede extender la abstracción sin cambiar las clases de implementación.
**/

class ExtendedAbstraction : public Abstraction {
    public:
        ExtendedAbstraction(Implementation* implementation) : Abstraction(implementation) {}
        string Operation() const override {
            return "Abstracción extendida: operación extendida con:\n" + this->implementation_->OperationImplementation();
        }
};

/**
 * Excepto por la fase de inicialización, donde se vincula un objeto de abstracción
 * con un objeto de implementación específico, el código de cliente solo debe depender de
 * la clase Abstracción. De esta forma, el código del cliente puede admitir cualquier abstracción.
 * combinación de implementación.
**/

void ClientCode(const Abstraction& abstraction) {
    cout << abstraction.Operation();
}

/**
 * El código del cliente debería poder funcionar con cualquier combinación
 * de implementación de abstracción preconfigurada.
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
