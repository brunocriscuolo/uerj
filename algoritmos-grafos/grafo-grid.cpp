#include <iostream>
using namespace std;

int main()
{

	int p;
	int q;
	int n;

	cout << endl;
	cout << "Insira o número de linhas do grafo: ";
	cin >> p;
	cout << "Insira o número de colunas do grafo: ";
	cin >> q;
	cout << endl;

	n = p*q;

	for (int i=1; i<=n; i++) {

			//Verifica se o vértice faz parte das extremidades, 
			//isto é, das quinas do grafo grid. Caso verdadeiro,
			//esse vertice possui dois vizinhos.
			if (i == 1) { //se é o vértice superior esquerdo...
				cout << "Os vizinhos de " << i << " são: " << i+1 << ", " << i+q << endl;//escreve os dois vértices adjacentes.
			}
			else if (i == q) { //se é o vértice superior direito...
				cout << "Os vizinhos de " << i << " são: " << i-1 << ", " << i+q << endl; //escreve os dois vértices adjacentes.
			}
			else if (i == (n-q)+1) { //se é o vértice  inferior esquerdo...
				cout << "Os vizinhos de " << i << " são: " << i-q << ", " << i+1 << endl; //escreve os dois vértices adjacentes.
			}
			else if (i == n) { //se é o vértice inferior direito...
				cout << "Os vizinhos de " << i << " são: " << i-q << ", " << i-1 << endl; //escreve os dois vértices adjacentes.
			}

			//Verifica se o vértice está na primeira linha do grafo.
			//Caso verdadeiro, esse vértice possui três vizinhos:
			//um a direita, outro a esquerda e um abaixo. 
			else if (i>1 && i<q) { //se está na primeira linha...
				cout << "Os vizinhos de " << i << " são: " << i-1 << ", " << i+1 << ", " << i+q << endl; //escreve os três vértices adjacentes.
			}

			//Verifica se o vértice está na última linha do grafo.
			//Caso verdadeiro, esse vértice possui três vizinhos:
			//um a cima, outro a esquerda e um a direita. 
			else if ((i>(n-q)+1) && (i<n)) { //se está na última linha...
				cout << "Os vizinhos de " << i << " são: " << i-q << ", " << i-1 << ", " << i+1 << endl; //escreve os três vértices adjacentes.
			}

			//Verifica se o vértice está na primeira coluna do grafo,
			//isto é, o vértice faz parte da extremidade lateral esquerda.
			//Caso verdadeiro, esse vértice possui três vizinhos:
			//um a cima, outro a direita e um abaixo.
			else if ((i!=1) && (i!=(n-q)+1) && (i%q==1)) { //se está na primeira coluna...
				cout << "Os vizinhos de " << i << " são: " << i-q << ", " << i+1 << ", " << i+q << endl; //escreve os três vértices adjacentes.
			}

			//Verifica se o vértice está na última coluna do grafo,
			//isto é, o vértice faz parte da extremidade lateral direita.
			//Caso verdadeiro, esse vértice possui três vizinhos:
			//um a cima, outro a esquerda e um abaixo.
			else if ((i!=1) && (i!=(n-q)+1) && (i%q==0)) { //se está na última coluna...
				cout << "Os vizinhos de " << i << " são: " << i-q << ", " << i-1 << ", " << i+q << endl; //escreve os três vértices adjacentes.
			}

			//Em último caso estão os vértices centrais do grafo grid,
			//isto é, os vértices que não fazem parte das extremidades do grafo.
			//Esses vértices possuem quatro vizinhos:
			//um a cima, um a esquerda, um a direita e outro abaixo.
			else //caso seja um vértice central... 
				cout << "Os vizinhos de " << i << " são: " << i-q << ", " << i-1 << ", " << i+1 << ", " << i+q << endl; //escreve os quatro vértices adjacentes.
	}
cout << endl;
return 0;
}