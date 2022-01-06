#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Linkedlist.h"
#include "Node.h"
//#include <cstddef>
using namespace std;

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
		if(tokens[0] == "exit") {
			for(unsigned i = 0; i < listas.size(); i++)
				delete listas[i];
			listas.clear();
			break;
		}

		//create
		else if(tokens[0] == "create") {
			List *novo = new List;
			listas.push_back(novo);
		}

		// push back x l
		else if(tokens[0] == "push_back") {
			int x = std::stoi(tokens[1]);
			int l = std::stoi(tokens[2]);
			listas[l]->push_back(x);
		}

		/*/ push front x l
		else if(tokens[0] == "push_front") {
			int x = std::stoi(tokens[1]);
			int l = std::stoi(tokens[2]);
			listas[l]->push_front(x);
		}
		// insetrAt x l
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
			listas[z]->removeAt(x);
		}
		// copy l
		else if(tokens[0] == "copy") {
			int l = std::stoi(tokens[1]);
			List *lcp = listas[l]->copy();
			listas.push_back(lcp);
		}
		// front
		else if(tokens[0] == "front") {
			int l = std::stoi(tokens[1]);
			cout << listas[l]->front() << endl;
		}
		// back
		else if(tokens[0] == "back") {
			int l = std::stoi(tokens[1]);
			cout << listas[l]->back() << endl;
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
		// removeAll x l
		else if(tokens[0] == "removeAll") {
			int x = std::stoi(tokens[1]);
			int l = std::stoi(tokens[2]);
			listas[l]->removeAll(x);
		}
        // concat l1 l2
		else if(tokens[0] == "concat") {
			int l1 = std::stoi(tokens[1]);
			int l2 = std::stoi(tokens[2]);
			listas[l1]->concat(*listas[l2]);
		}
        /*/// show 
		else if(tokens[0] == "show") {
            for(unsigned i = 0; i < listas.size(); ++i) {
                cout << "lista " << i << ": " << *listas[i] << endl;
            }	
		}
        //*/
		else {
			cout << "comando inexistente" << endl;
		}
	}
	return 0;
}