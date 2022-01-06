#ifndef LIST_H
#define LIST_H
#include "Node.h"
using namespace std;

// link_1: https://gilsonguimaraes.wordpress.com/2011/07/03/codigo-lista-duplamente-encadeada-circular/
// link_2: https://gist.github.com/tuliopaim/1564aa76080d15608971df288bfe8996


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
    // head->next = nullptr;
    // head->ant=nullptr;
     size_list = 0;
};

List::~List(){
       Node* inicio = head;
       while(head->next != inicio){
               Node* temp = head;
               head = head->next;
               delete temp;
        }
        delete inicio;
        size_list = 0;
};

bool List::empty() const{
     return head==nullptr;   
};

int& List::size() const{
        int x = 0 + size_list;
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
//ei, então o back e o front são iguais né
//por enquanto sim,usa o push_back por enquanto.
// e que head anterior vai ser o (next) do nomo_node
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
                //pera mas ele vai apontar pra quem
                //ah lembrei de um negócio do pdf //o que é?//é sobre quando há um nó na lista circular
                //olha lá no pdf do projeto, descobri uma coisa
                Node *aux= new Node(data, aux, aux);
                head=aux;
                // vc tá dizendo para head apontar para ele msm nos dois lados?R:sim, pois é uma lista circular, quando vai pro último vai pro inico//faz sentido
                //assim dá certo ?
                //tipo se igualar head ao aux, head fica igual ao aux né ?
        }else{
                Node *aux= new Node(data, aux, aux);
                Node* ultimo = head->ant;
                head->ant = aux;
                aux->next = head;
                aux->ant = ultimo;
                head = aux;
                //ei podemos economizar linhas se colocarmos Node...aux); na linha 113. assim não seria nessesario a linha 123// o que vc acha?// não crashou :D
                //significa que não há nada na lista R:sim, é nesse caso, por isso coloquei o if e o else
                //ei, mas o que fiz foi naquele caso, no caso onde head==nullptr
        }
        /*
        Node* ultimo = head->ant;
        head->ant = aux;
        aux->next = head;
        aux->ant = ultimo;
        head = aux;
        */
};

void List::push_back(const Item& data) {
    
    Node *newnode = new Node(data, nullptr,nullptr);
    
    if(head == nullptr) {
        head = newnode;
    }
    else {
        Node *pos = head;
        while(pos->next != nullptr) {
            pos = pos->next;
        }
        pos->next = newnode;
    }
    size_list++;
}

// operator<< sobrecarga
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

#endif