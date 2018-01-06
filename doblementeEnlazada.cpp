#include<iostream>

using namespace std;

class Nodo{

private:
    int dato;
    Nodo *sig;
    Nodo *ant;
public:
    Nodo(void) { sig = ant = NULL; }

    Nodo( int x , Nodo* s = NULL , Nodo* a = NULL )
    {
        dato = x;
        sig = s;
        ant = a;
    }

    // SETTERS
    void setDato(int x) { dato = x; }
    void setAnt(Nodo *a) { ant = a; }
    void setSig(Nodo *s) { sig = s; }

    // GETTERS
    int getDato()  { return dato;}
    Nodo *getAnt() { return ant; }
    Nodo *getSig() { return sig; }

};

class Lista
{
private:
    Nodo *lista; // ancla
public:
    Lista(void) { Inicializar(); } // CONSTRUCTOR

    // METODOS BASICOS

    Nodo *Primero() { return lista; }
    Nodo *Siguiente(Nodo *pos) { return pos->getSig(); }
    Nodo *Anterior(Nodo *pos) { return pos->getAnt(); }

    Nodo *Ultimo() {
        Nodo *aux = lista;

        if ( !Vacia() ) { while ( aux->getSig() ) { aux = aux->getSig(); } }
        return aux;
    }

    // METODOS DE LA LISTA
    void Inicializar() { lista = NULL; }
    bool Vacia() { return lista==NULL; }
    void Mostrar();
    void Pop_back();
    void Pop_front();
    void Push_back();
    void Push_front(int x, Nodo* pos = NULL);
    void Insertar(int x, Nodo* pos = NULL);
};


void Lista::Insertar(int x, Nodo* pos)
{
    Nodo* aux;
        Nodo* temp_n = new Nodo(x);

        if ( Vacia() ){
                lista = temp_n;

        }else{
                if ( pos == Primero() ){
                        aux = Primero();
                        aux->setAnt(temp_n);

                        temp_n->setSig(aux);
                        lista = temp_n;

                }else if ( pos == NULL ){

                        aux = Ultimo();
                        aux->setSig(temp_n);
                        temp_n->setAnt(aux);

                }else{
                        aux = Primero();

                        while ( aux ){
                                if ( aux == pos ){
                                        Anterior(aux)->setSig( temp_n );

                                        temp_n->setAnt( Anterior(aux) );
                                        temp_n->setSig( aux );

                                        aux->setAnt( temp_n );

                                }else {
                                    aux = aux->getSig();
                }
                        }
                }
        }
}

void Lista::Mostrar()
{
    Nodo* aux;

    Primero();
    aux = lista;
        if ( !Vacia() ){
                while ( aux ){
            cout << aux ->getDato();
            cout << "\n";
            aux = aux ->getSig();
                }
        }
}

void Lista::Pop_front(){
/*    if(!Primero)return;
    Nodo* aux;
    Primero;
    Primero=Primero->setSig;
    delete temp;
*/
}

void Lista::Push_front(int x, Nodo* pos){
    Nodo* aux;
    Nodo* temp_n = new Nodo(x);
    aux = Primero();
    if ( pos == Primero() ){
        aux = Primero();
        aux->setAnt(temp_n);

        temp_n->setSig(aux);
        lista = temp_n;
    }
}

int main(void)
{
    Lista numeros; // Mi lista
    int n; // dato a insertar

    numeros.Insertar(2);
    numeros.Mostrar();
    cout<<endl;
    numeros.Insertar(4);
    numeros.Insertar(13);
    numeros.Insertar(20);
    numeros.Mostrar();
    cout<<endl;
    numeros.Push_front(19);
    numeros.Mostrar();
    return 0;
}
