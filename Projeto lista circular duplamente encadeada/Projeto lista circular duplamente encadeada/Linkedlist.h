#ifndef LIST_H
#define LIST_H
#include "Node.h"// vamo trabalhar no remover e inserir
using namespace std;

/*
 link_1: https://gilsonguimaraes.wordpress.com/2011/07/03/codigo-lista-duplamente-encadeada-circular/
 link_2: https://gist.github.com/tuliopaim/1564aa76080d15608971df288bfe8996

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
        /*if(head==nullptr){
                cout<<"erro: lista vazia";
                Item x = 0;
                return x;
        }*/
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
        //size_list++;
    }
    else {

        (head->ant)->next = newnode;
        newnode->ant = (head->ant);
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
        Node *pos = head,*temp;
        bool inicio = true;
        
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
                                        break;
                                }else{
                                        temp = head;
                                        head = head->next;
                                        head->ant = pos->ant;
                                        (pos->ant)->next = head;
                                        pos = (pos->next)->next;
                                        delete temp;

                                }

                        }else{
                                temp = pos;
                                (pos->ant)->next = pos->next;
                                (pos->next)->ant = pos->ant;
                                pos = pos->next;
                        }
                        size_list--;
                }else{
                        pos = pos->next;
                }

                
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

                        Node *newnode = new Node(atual->data, nullptr,nullptr);
                        
                        if(copia->head == nullptr) {
                                copia->head = newnode;
                                copia->head->next = copia->head;
                                copia->head->ant = copia->head;
                                
                        }
                        else {
                                
                                
                                Node *ultimo = (copia->head)->ant;
                                ultimo->next = newnode;
                                newnode->ant = ultimo;
                                newnode->next = copia->head;
                                (copia->head)->ant = newnode;
                        }
                        copia->size_list++;

                        atual =atual->next;
                }
        }
        return copia;
};

void List::append(Item vec[], int n){
        for(int x = 0;x<n;x++){
                
                Node *newnode = new Node(vec[x], nullptr,nullptr);
                
                if(head == nullptr) {
                        head = newnode;
                        head->next = head;
                        head->ant = head;
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
};

void List::concat(List& lst){

        Node *ultimo=head->ant;
        Node *dirty=lst.head;
        int n[lst.size_list];

        for (int i = 0; i < lst.size_list-1; i++)
        {
                
                Node *newnode = new Node(dirty->data, nullptr,nullptr);
                        
                if(head == nullptr) {
                        head = newnode;
                        head->next = head;
                        head->ant = head;
                        size_list++;
                }
                else {

                        (head->ant)->next = newnode;
                        newnode->ant = (head->ant);
                        newnode->next = head;
                        head->ant = newnode;

                }
                size_list++;
                
                dirty = dirty->next;

        }
        lst.head = nullptr;
        lst.size_list = 0;
        
}

bool List::equals(const List& lst)const{
        
        if(size_list  == lst.size_list){
                
                Node* pos = head;
                Node* aux = lst.head;
                bool inicio = true;

                while(pos != head ||inicio){

                        if(pos == head){inicio = false;}
                        
                        if(pos->data != aux->data){
                                return false;
                        }

                        pos = pos->next;
                        aux = aux->next;

                }
                return true;
        }

        return false;
};


void List::reverse(){

        Node *aux,*posicao,*novo = (head->ant);
        aux = novo;
        posicao = aux->ant;
        while(posicao != novo){
                aux->ant = aux->next;
                aux->next = posicao;
                posicao = posicao -> ant;
                aux = aux->next;
        }



        aux->ant = aux->next;
        aux->next = posicao;
        head = posicao;

};

/*
void merge(List& lst);
L1 = [ 1 2 3 4 ] e L2 = [ 7 8 9 0 5 6 ].
o resultado L1 = [ 1 7 2 8 3 9 4 0 5 6 ] e L2 = []

*/
void List::merge(List& lst){
     Node *aux=head;
     Node *valentine=lst.head;
     int cont=0;
     int contadorfull=lst.size_list + size_list;
     Node *ultimo=lst.head->ant;
     while(cont<contadorfull){
             if(valentine!=nullptr){

                     Node *seguinte=aux->next->next;
                     Node *proximo=valentine->next;
                     valentine->next=aux->next;
                     aux->next->ant=valentine;
                     valentine->ant=aux;
                     aux->next->next=aux->next;
                     aux->next=valentine;
                     valentine=proximo;
                     delete valentine->ant;
                     aux=aux->next->next;
                     aux->next=seguinte;
                     size_list++;
                     lst.size_list--;

                }else{
                     Node *ficar=aux;
                     aux=aux->next;
                     aux->ant=ficar;
                }
                cont++;

        }

        head=aux->next;
};
/*arrumei a sobrecarga de [ ]//testa aí meu codigo
Node *x = head->next,*y = lst.head->next,*h = head;//não foi dnv..
bool vez = true;
int c = 0;
h->next = lst.head;
h->ant = (lst.head)->ant;
(h->next)->ant = h;
(h->ant)->next = h;
for (c = 0; c < size_list && c < lst.size_list ; c++)
{
        if(vez){
                h->next = x;
                x->next;
                (h->next)->ant = h;
                h = h->next;
                vez = false;
        }else{
                h->next = y;
                y = y->next;
                (h->next)->ant = h;
                vez = true
        }
}

*/
Item& List::operator[](int index){
        Node* pos = head;
        
        for ( int i = 0; i < index; i++){
                pos = pos->next;
        }
        return pos->data;
};


List& List::operator=(const List& lst){
        
        clear();
        List *x;
        Node * pos = lst.head;
        bool y = true;
        while ( pos!= lst.head||y)
        {
                y = false;
                push_back(pos->data);
                pos = pos->next;
        }
        
        x->size_list = lst.size_list;
        List &z = *x;
        return z;
};

#endif