#include <iostream>
#include <stack>

using namespace std;

template <class T>
class Nodo{
	public:
		T m_Dato;
		Nodo<T> * m_pIzq;
		Nodo<T> * m_pDer;
	public:
	Nodo(){
		m_pIzq = m_pDer = 0;
	}
	Nodo(T d){
		m_Dato = d;
		m_pIzq = m_pDer = 0;
	}
};


template<class T>
class SBT{
	public:
		Nodo <T> * m_pRoot;
	public:
		SBT():m_pRoot(0){
		}
		bool find(T,Nodo<T>**&);
		void Add(T,Nodo<T>*&);
		void mostrar(Nodo<T>*,int);
		void Inorden(Nodo<T>*r);
		void Preorden(Nodo<T>*r);
		void Preorden2(Nodo<T>*r);
		void Postorden(Nodo<T>*r);
		int NroNodos(Nodo<T>*nodo);
		void hermano(T d);
        int hoja(Nodo<T>*);
		int contarHojas(Nodo<T>*);
		Nodo<T>* get_hermano_rec(Nodo<T>* raiz,T value);
		Nodo<T>* padrerecursivo(Nodo<T>* pRoot, T value);
		Nodo<T>* getpapa(T d);
		int padre(T d);
};
template<class T>
bool SBT<T> :: find(T d , Nodo<T> **&p){
	p=&m_pRoot;
	while(*p){
		if((*p)->m_Dato == d)return true;
		if ((*p)->m_Dato > d){
			p=&((*p)->m_pIzq);
		}
		else{
			p=&((*p)->m_pDer);
		}
	}
	return false;
}

template<class T>
void SBT<T> :: Add (T d , Nodo<T>*&p){
	if (!p){p=new Nodo<T>(d);return;}
	if (p->m_Dato==d)return;
	if(p->m_Dato > d ) Add(d,p->m_pIzq);
	else
		Add(d,p->m_pDer);
}

template<class T>
void SBT <T> :: mostrar(Nodo<T>*arbol,int cont){
	if(arbol == NULL){return;
	}
	else{
		mostrar(arbol->m_pDer,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->m_Dato<<endl;
		mostrar(arbol->m_pIzq,cont+1);
	}
}

template<class T>
void SBT<T>::Inorden(Nodo<T>*r){
    if(!r) return;
    Inorden(r->m_pIzq);
    cout<<r->m_Dato;
    Inorden(r->m_pDer);
}
template<class T>
void SBT<T>::Preorden(Nodo<T>*r){
    if(!r) return;
    cout<<r->m_Dato;
    Preorden(r->m_pIzq);
    Preorden(r->m_pDer);
}
template<class T>
void SBT<T>::Postorden(Nodo<T>*r){
    if(!r) return;
    Postorden(r->m_pIzq);
    Postorden(r->m_pDer);
    cout<<r->m_Dato;
}


template <class T>
void SBT<T>::Preorden2(Nodo<T>*r){
    if(r==0)return;
    stack<Nodo<T>*>s;
    s.push(r);
    while(s.empty()==false){
        Nodo<T>*p = s.top();
        cout<<p->m_Dato<<"-";
        s.pop();
        if(p->m_pDer){
            s.push(p->m_pDer);
        }
        if(p->m_pIzq){
            s.push(p->m_pIzq);
        }
    }
}

template <class T>
int SBT <T> :: NroNodos(Nodo<T>*nodo){
	if (nodo == NULL){return 0;
	}
	return 1 + NroNodos(nodo->m_pIzq) + NroNodos(nodo->m_pDer);
}

template<class T>
void SBT<T>::hermano(T d){
    if(m_pRoot==NULL){return;}
    else{
        Nodo<T>*tmp1=m_pRoot;
        Nodo<T>*tmp2=m_pRoot;
        if(tmp1->m_Dato==d){return;}
        while(tmp2->m_Dato!=d){
            tmp1=tmp2;
            if(d>tmp2->m_Dato){
                    tmp2=tmp2->m_pDer;
            }
            else{
                    tmp2=tmp2->m_pIzq;
            }
        }
        if(d>tmp1->m_Dato){
            tmp1=tmp1->m_pIzq;
            cout<<"HERMANO: "<<tmp1->m_Dato<<endl;
        }
        else{
            tmp1=tmp1->m_pDer;
            cout<<"HERMANO: "<<tmp1->m_Dato<<endl;
        }

    }
}
template<class T>
Nodo<T>* SBT<T>::get_hermano_rec(Nodo<T>* raiz,T value){
    if(!raiz){return 0;}
    if(raiz->m_pDer->m_Dato==value){
        if(raiz->m_pIzq){return raiz->m_pIzq;}
        return 0;
    }
    if(raiz->m_pIzq->m_Dato==value){
        if(raiz->m_pDer){return raiz->m_pDer;}
        return 0;
    }
    if(value>raiz->m_Dato){return get_hermano_rec(raiz->m_pDer,value);}
    if(value<raiz->m_Dato){return get_hermano_rec(raiz->m_pIzq,value);}
    return 0;
}



template<class T>
int SBT<T> :: hoja(Nodo<T>*r){
	if(!r->m_pDer && !r->m_pIzq)
		return 1;
	else
		return 0;
}

template<class T>
int SBT<T> :: contarHojas(Nodo<T>*r)
{
	if (!r)return 0;
	return hoja(r) + contarHojas(r->m_pDer)+contarHojas(r->m_pIzq);
 }

template<class T>
Nodo<T>* SBT<T>::getpapa(T d){
    Nodo<T>*tmp1;
    Nodo<T>*tmp2;
    tmp1=tmp2=m_pRoot;
    if(!m_pRoot){return 0;}
    if(d==m_pRoot->m_Dato){return 0;}
    while(tmp2){
        if(tmp2->m_Dato==d)return 0;
        tmp1=tmp2;
        if(tmp2->m_Dato>d){
            tmp2=tmp2->m_pIzq;
        }
        else{
            tmp2=tmp1->m_pDer;
        }
    }
    return 0;

}

template<class T>
Nodo<T>* SBT<T>::padrerecursivo(Nodo<T>* pRoot, T value)
{
    if (pRoot == NULL)
       return NULL;

    if(pRoot->m_pIzq == NULL && pRoot->m_pDer == NULL)
       return NULL;

    if( (pRoot->m_pIzq != NULL && pRoot->m_pIzq->m_Dato== value)
        || (pRoot->m_pDer != NULL && pRoot->m_pDer->m_Dato == value))
       return pRoot;

    if(pRoot->m_Dato > value)
       return padrerecursivo(pRoot->m_pIzq,value);

    if(pRoot->m_Dato < value)
       return padrerecursivo(pRoot->m_pDer,value);
}



template<class T>
int SBT <T> :: padre(T d){
	Nodo<T>*temp1=m_pRoot;
	Nodo<T>*temp2=m_pRoot;
	if (!m_pRoot ) return 0;
	if(d == m_pRoot -> m_Dato )return 0;
	while (temp2){
		if  ( temp2 -> m_Dato == d)return temp1->m_Dato;
		temp1 = temp2;
		if(temp2->m_Dato > d)
			temp2 = temp2->m_pIzq;
		else
			temp2 = temp2->m_pDer;
	}
	return 0;
}


main(){
	SBT<int> B;
	int contador = 0;
	int nodos = 0;
	B.Add(8,B.m_pRoot);
	B.Add(3,B.m_pRoot);
	B.Add(1,B.m_pRoot);
	B.Add(6,B.m_pRoot);
	B.Add(4,B.m_pRoot);
	B.Add(7,B.m_pRoot);
	B.Add(10,B.m_pRoot);
	B.Add(14,B.m_pRoot);


	B.mostrar(B.m_pRoot,contador);
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"INORDEN: ";
	B.Inorden(B.m_pRoot);
	cout<<endl;
    cout<<"PREORDEN: ";
    B.Preorden(B.m_pRoot);
    cout<<endl;
    cout<<"POSTORDEN: ";
    B.Postorden(B.m_pRoot);
    cout<<endl;
	B.hermano(4);
	cout<<"PAPA:"<<B.padre(14)<<endl;
	cout<<"Nodos: "<<B.NroNodos(B.m_pRoot)<<endl;
	cout<<"Hojas: "<<B.contarHojas(B.m_pRoot)<<endl;
	cout<<endl;
	cout<<endl;
	B.Preorden2(B.m_pRoot);

	return 0;
}

