#include<iostream>

using namespace std;

template<class T>
class Nodo
{
     public:
        Nodo<T>  * m_pSig;
             T     m_Dato;
     public:
       Nodo(T d)
       { 
          m_pSig=0;
          m_Dato=d;
       }  
};

template<class T>
class List
{   
    typedef Nodo<T>  * pNodo;
    private:
       pNodo m_pHead;
       pNodo m_pLast;
    public:
       List()
       { 
         m_pHead = 0;
         m_pLast =0;
       } 
      
      void push_front(T d)
      {
           pNodo pNuevo   =  new Nodo<T>(d);
           if ( !m_pHead )
				m_pHead = m_pLast = pNuevo;
           else
			{
                pNuevo->m_pSig = m_pHead;
				m_pHead = pNuevo;
            } 
      }


	void push_back(T d){
		pNodo pNuevo   =  new Nodo<T>(d);
           if ( !m_pHead )
				m_pHead = m_pLast = pNuevo;
           else
			{
				m_pLast->m_pSig = pNuevo;
				m_pLast=nuevo;	
            } 
	}

    void pop_front(){
	  if(!m_pHead) return;	
      pNodo temp = m_pHead;
      m_pHead = m_pHead->m_pSig;
      delete temp;
    }
	void pop_back()
   {
		if(!m_pHead) return;
		if(m_pHead == m_pLast) 
		{ 
		  delete m_pHead; 
		  m_pHead = m_pLast =0;
		} 
		pNodo tmp = m_pHead;
		for(  ; tmp->m_pSig!=m_pLast; tmp = tmp->m_pSig);
		delete m_pLast;
		m_pLast = tmp;
   }
    
   void Add(T d, Nodo<T> * & p)
   {
        if(!p) {p = new Nodo<T>(d); return;}
        Add(d, p->m_pSig);
   }    
}; 

int main()
{
    List<int>  A;
    A.push_front(5);
    A.push_front(15);
    A.push_front(25);
    A.push_front(35);
 
    int s=8;
    return 1;
}

