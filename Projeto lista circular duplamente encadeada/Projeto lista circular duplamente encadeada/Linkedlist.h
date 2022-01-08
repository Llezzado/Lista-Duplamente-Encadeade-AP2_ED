#ifndef LIST_H
#define LIST_H
#include "Node.h"// vamo trabalhar no remover e inserir
using namespace std;

/*
 link_1: https://gilsonguimaraes.wordpress.com/2011/07/03/codigo-lista-duplamente-encadeada-circular/
 link_2: https://gist.github.com/tuliopaim/1564aa76080d15608971df288bfe8996

 relatório 05/01/22:
  funcções feitas:
        List(),~List(),empty(),size(),clear(),front(),back(),push_back(),push_front(),sobrecarga << 
        em desemvolvimento:

        
        um relatório p/ colocar no final //bora
*/

class List{
private:
        Node *head;
        int size_list;

public:
        List();
        ~List();
        List(const List& lst);
        bool empty() const;
        Item& size() const;
        void clear();
        Item& front();
        Item& back();
        void push_front(const Item& data);
        void push_back(const Item& data);
        void pop_front();
        void pop_back();
        void insertAt(const Item& data, int id);
        Item& removeAt(int index);
        void removeAll(const Item& data);
        void swap(List& lst);
        void concat(List& lst);
        List *copy();
        void append(Item vec[], int n);
        bool equals(const List& lst) const;
        void reverse();
        void merge(List& lst);
        Item& operator[](int index);
        List& operator=(const List& lst);

        friend std::ostream& operator<<(std::ostream& out, const List& l); 

};

List::List(){
     
     head=nullptr;
     size_list = 0;
};

List::~List(){

        if(head == nullptr){return;}
    Node* inicio = head;
	
    while(head->next != inicio) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    size_list = 0;
    
};

bool List::empty() const{
     return head==nullptr;   
};

int& List::size() const{
        Item x = size_list,&temp = x;
        return temp;
};

void List::clear(){

       Node* inicio = head;
       while(head->next != inicio){
               Node* temp = head;
               head = head->next;
               delete temp;
        }
        delete inicio;
        size_list = 0;

};

Item& List::front(){
        if(head==nullptr){
                cout<<"erro: lista vazia";
                Item x = 0;
                return x;
        }
        Item x = head->data,&y = x;
        return y;

}

Item& List::back(){
        if(head==nullptr){
                cout << "erro:lista vazia";
                Item &x = x;
                return x;
        }
       Node *aux=head;
       Node *inicio=head;
       while(aux->next!=inicio){
               aux=aux->next;
       } 
       return aux->data;
}

void List::push_front(const Item& data){
        
        if(head==nullptr){
                
                
                Node *aux= new Node(data, aux, aux);
                head=aux;
                head->next = head; 
                head->ant = head;
                size_list++; 
        
        }else{
                Node *tusk=head;
                Node *aux= new Node(data, nullptr, nullptr);
                Node* ultimo = tusk->ant;
                head = aux;
                aux->next = tusk;
                aux->ant = ultimo;
                tusk->ant = aux;
                ultimo->next = aux;
                size_list++; 
        }

};

void List::push_back(const Item& data) {
    
    Node *newnode = new Node(data, nullptr,nullptr);
    
    if(head == nullptr) {
        head = newnode;
        head->next = head;
        head->ant = head;
        size_list++;
    }
    else {
        
        
        Node *ultimo = head->ant;
        ultimo->next = newnode;
        newnode->ant = ultimo;
        newnode->next = head;
        head->ant = newnode;

    }
    size_list++;
}

std::ostream& operator<<(std::ostream& out, const List& list) {
    Node *atual = list.head;
    out << "[ ";
	
	if(atual != nullptr){
	
		bool x = true;
		while(atual != list.head ||x) {
			
			if(atual == list.head){
				x = false;
			}
			
			out << atual->data << " ";
			atual =atual->next;
		}
	}
    out << "]";
    return out;
}

void List::pop_back(){
        if(head==nullptr){
                cout<< "Essa lista esta vazia.\n";
                return;
        }if(head->next==head){
                head->next=nullptr;
                head->ant=nullptr;
                Node *apagar=head;
                head=head->next;
                delete apagar;
                size_list=0;
                return;
        }
        
       Node *last=head->ant->ant;
       Node *exclui=head->ant;
       Node *first=head;
       Node *josuke=head->ant;
       last->next=first;
       first->ant=last;
       josuke=last;
       
       delete exclui;
       size_list--;

        
        
}

void List::pop_front(){
        if(head == nullptr){
                cout << "Essa lista esta vazia.\n";
                return;
        }
        if(head->next == head){
                Node* temp = head;
                head = nullptr;
                delete temp;
                return;
        }
        Node* temp = head;
        Node* ultimo = head->ant;
        Node* proximo = head->next;
        head = proximo;
        proximo->ant = ultimo;
        ultimo->next = head;
        size_list--;
        delete temp;
        return;
};

/*
codigo feito as pressas(é um insert)

// Inserts data at any position in the range [0..size()]
void List::insertAt(int index, Item data) {
    if(index < 0 || index > tamanho) {
        throw std::out_of_range("index out of range");
    }
    if(index == 0) {
        
		Node *newnode = new Node(data, nullptr, nullptr);
		
		Node* seg = sentinela->proximo; // sentinela é o msm q head
		
		Node* ant = sentinela->anterior;
		
		Node* old = sentinela;
		
		sentinela = newnode;

		sentinela = newnode;
		
		sentinela->proximo = old;
		
		ant->proximo = sentinela;
		
		old->proximo = seg;
		
		sentinela->anterior = ant;
		
		seg->anterior = old;

        tamanho++;
        
		return;
    }
    int counter = 0;
    Node *atual = sentinela;
    while(counter < index-1) {
        counter++;
        atual = atual->proximo;
    }
    Node *newnode = new Node(data, atual->proximo, atual);
    atual->proximo = newnode;
    tamanho++;
}
*/

void List::insertAt(const Item& x,int id){
        Node *aux=head;
        Node *position= new Node (x, nullptr, nullptr);
        if(id<0 || id>size_list){
                throw std::out_of_range("index out of range");
        }
        if(id==0){

             Node *position= new Node (x, nullptr, nullptr);
             Node *anterior=aux->ant;
             Node *proximo=aux->next;
             
             anterior->next=position;
             aux->ant=position;
             
             position->next=aux;
             position->ant =anterior;

             head=position; 

             size_list++;
             return;   
        }
        int k=0;
        while(k<id-1){
                k++;
                aux=aux->next;
               
        }
            Node *tusk= new Node (x, aux->next, aux );
            aux->next=tusk;
             size_list++;

};




Item& List::removeAt(int id){
        
        Item info;
        Node* pos = head;
        size_list--;
        
        if(id < 0 || id > size_list || head == nullptr){
                throw std::out_of_range("index out of range");
        }

        if(head == nullptr){
                throw std::out_of_range("Erro: lista vazia");
        }
        
        if(id == 0){
                
                info = head->data;
                Item& ref = info;
                

                if(head->next == head){
                        head->next=nullptr;
                        head->ant=nullptr;
                        Node *apagar=head;
                        head=head->next;
                        delete apagar;
                        size_list=0;
                        return ref;
                }


                head = pos->next;
                head->ant = pos->ant;
                (pos->ant)->next = head;
                
                
                return ref;
                
        }

        for(int c = 0;c < id;c++){pos = pos->next;};
        info = pos->data;
        Item& ref = info;
        
        (pos->ant)->next = pos->next;
        (pos->next)->ant = pos->ant;

        delete pos;
        
        return ref;
};

void List::removeAll(const Item& data){
        Node* pos = head;
        bool inicio = true;
        int c = 0;
        
        while(pos != head || inicio){

                if(pos == head){inicio = false;}

                if(pos->data == data){
                                               
                        if(pos == head){
                              
                                if(head->next == head){
                                        
                                        head->next=nullptr;
                                        head->ant=nullptr;
                                        Node *apagar=head;
                                        head=head->next;
                                        delete apagar;
                                        size_list=0;
                                }


                                head = pos->next;
                                head->ant = pos->ant;
                                (pos->ant)->next = head;
                                
                        }
                        
                        Node* temp = pos;
                        (pos->ant)->next = pos->next;
                        (pos->next)->ant = pos->ant;
                        delete temp;
                }
                
                c++;
        }
};

void List::swap(List& lst){
        Node* aux;
        int size;
        aux = lst.head;
        size = lst.size_list;
        lst.head = head;
        lst.size_list = size_list;
        head = aux;
        size_list = size;

};

List* List::copy(){
        
        List *copia = new List;
        Node* atual = head;
        
        if(atual != nullptr){
                
                bool x = true;
                while(atual != head ||x) {
                                
                        if(atual == head){
                                x = false;
                        }
                                
                        //copia->push_back(atual->data);

                        Node *newnode = new Node(atual->data, nullptr,nullptr);
                        
                        if(copia->head == nullptr) {
                                copia->head = newnode;
                                copia->head->next = copia->head;
                                copia->head->ant = copia->head;
                                copia->size_list++;
                        }
                        else {
                                
                                
                                Node *ultimo = (copia->head)->ant;
                                ultimo->next = newnode;
                                newnode->ant = ultimo;
                                newnode->next = copia->head;
                                (copia->head)->ant = newnode;

                                /*
                                Node *pos = head;
                                while(pos->next != head) {
                                pos = pos->next;
                                }
                                pos->next = newnode;
                                head->ant = pos->next;
                                pos->next->next = head;
                                /*/
                        }
                        copia->size_list++;

                        atual =atual->next;
                }
        }
        return copia;
};

void List::append(Item vec[], int n){
        for(int x = 0;x<n;x++){
                push_back(vec[x]);
        }
};

void List::concat(List& lst){
        List *tusk=lst;
        tusk->head=head;
        tusk->size_list=size_list;
        Node *aux=head;
        Node *dirty=tusk->head;
        while(aux->next!=nullptr){
                
        }
        
}


#endif