#ifndef LIST_H
#define LIST_H
#include "Node.h"
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
        void insertAt(const Item& data, int index);
        Item removeAt(int index);
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
        int x = size_list;
        return x;
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
        return head->data;

}

Item& List::back(){
        if(head==nullptr){
                cout << "erro:lista vazia";
                Item x = 0;
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
        delete temp;// eu acho q já tá bom essa func()
        return;
};

#endif
