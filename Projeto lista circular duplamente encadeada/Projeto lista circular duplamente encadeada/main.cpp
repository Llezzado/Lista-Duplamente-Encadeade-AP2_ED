#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Linkedlist.h"
#include "Node.h"
#include <stack>

using namespace std;

/*
Dupla:
Nome: Juan Pablo Rufino Mesquita	Matrícula: 509982
Nome: Álisson Rodrigues Fernandes	Matrícula: 510357

Obs: leia o relatório para ver os comandos.
*/
int main() {

	vector<List*> listas;

	while(true) {
		string comando;
		getline(cin, comando);
		std::stringstream ss{ comando };
		vector<string> tokens;
		string buffer;

        cout << "->" << ss.str() << endl;

		while(ss >> buffer){
            tokens.push_back(buffer);
        };

        // exit
		if(tokens[0] == "sair") {
			for(unsigned i = 0; i < listas.size(); i++)
				delete listas[i];
			listas.clear();
			break;
		}
		
		//create
		else if(tokens[0] == "criar") {
			List *novo = new List;
			listas.push_back(novo);
		}

		//front
		else if(tokens[0] == "front") {
			int l = std::stoi(tokens[1]);
			if(listas[l]->size() > 0){cout << listas[l]->front() << endl;}else{
				cout << "esta lista esta vazia.\n";
			}
			
		}

		//back
		else if(tokens[0] == "back") {
			int l = std::stoi(tokens[1]);
			if(!listas[l]->empty()){
				cout << listas[l]->back() << endl;
			}else{
				cout << "esta lista esta vazia.\n";
			}
			
		}

		//empty
		else if(tokens[0] == "empty") {
			int l = std::stoi(tokens[1]);
			cout << listas[l]->empty() << endl;		
		}

		else if(tokens[0] == "concat") {
			int x = std::stoi(tokens[1]);
			int y = std::stoi(tokens[2]);
			listas[y]->concat(*listas[x]);
		}

		//size
		else if(tokens[0] == "size") {
			int l = std::stoi(tokens[1]);
			cout << listas[l]->size() << endl;
		}

		//clean
		else if(tokens[0] == "clear") {
			int l = std::stoi(tokens[1]);
			listas[l]->clear();
			cout << "A lista " << l << " foi esvasiada." << endl;
		}

		// push back x l
		else if(tokens[0] == "push_back") {
			int x = std::stoi(tokens[1]);
			int l = std::stoi(tokens[2]);
			listas[l]->push_back(x);
		}

		// push front x l
		else if(tokens[0] == "push_front") {
			int x = std::stoi(tokens[1]);
			int l = std::stoi(tokens[2]);
			listas[l]->push_front(x);
		}

		// pop back x 1
		else if(tokens[0] == "pop_back") {
			int x = std::stoi(tokens[1]);
			listas[x]->pop_back();
		}

		// pop front x 1
		else if(tokens[0] == "pop_front") { 
			int x = std::stoi(tokens[1]);
			listas[x]->pop_front();
		}

		//insetrAt x l
		else if(tokens[0] == "insertAt") {
			int x = std::stoi(tokens[1]);
			int y = std::stoi(tokens[2]);
			int z = std::stoi(tokens[3]);
			listas[z]->insertAt(y,x);
		}

		// removeAt x l
		else if(tokens[0] == "removeAt") {
			int x = std::stoi(tokens[1]);
			int z = std::stoi(tokens[2]);
			cout << (listas[z]->removeAt(x)) << " foi removido\n";
		}

		// remove All
		else if(tokens[0] == "removeAll") {
			int x = std::stoi(tokens[1]);
			int z = std::stoi(tokens[2]);
			listas[z]->removeAll(x);
		}

		// swap
		else if(tokens[0] == "trocar") {
			int x = std::stoi(tokens[1]);
			int y = std::stoi(tokens[2]);
			listas[y]->swap(*(listas[x]));
		}

		// merge
		else if(tokens[0] == "mesclar") {
			int x = std::stoi(tokens[1]);
			int y = std::stoi(tokens[2]);
			listas[y]->merge(*(listas[x]));
		}

		// copy l
		else if(tokens[0] == "copy") {
			int l = std::stoi(tokens[1]);
			List *lcp = listas[l]->copy();
			listas.push_back(lcp);
		}

		// append l a1 ... an 
		else if(tokens[0] == "append") {
			int l = std::stoi(tokens[1]);
			int n = tokens.size()-2;
			int *v = new int[n];
			for(int i = 0; i < n; i++)
				v[i] = std::stoi(tokens[i+2]);
			listas[l]->append(v, n);
		}


		// equals l1 l2 
		else if(tokens[0] == "equals") {
			int l1 = std::stoi(tokens[1]);
			int l2 = std::stoi(tokens[2]);
			if(listas[l1]->equals(*listas[l2])) cout << "listas iguais" << endl;
			else cout << "listas diferentes" << endl;
		}

		// reverse l
		else if(tokens[0] == "reverse") {
			int l = std::stoi(tokens[1]);
			listas[l]->reverse();
		}

		//back
		else if(tokens[0] == "get") {
			int x = std::stoi(tokens[1]);
			int y = std::stoi(tokens[2]);
			List &z = *(listas[y]);
			cout << z[x] << endl;
		}

		//sobrecarga de =
		else if(tokens[0] == "igual") {
			int x = std::stoi(tokens[1]);
			int y = std::stoi(tokens[2]);
			*(listas[y]) = *(listas[x]);
		}

		// show 
		else if(tokens[0] == "ver") {
            for(unsigned i = 0; i < listas.size(); ++i) {
                cout << "lista " << i << ": " << *listas[i] << endl;
            }	
		}

		else {
			cout << "comando inexistente" << endl;
		}
	}
	return 0;
}