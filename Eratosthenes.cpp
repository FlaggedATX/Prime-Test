#include <iostream>
#include <vector>
#include <algorithm>

void nArray(std::vector<int>& n){
	n.reserve(1000000);
	for(int i = 2; i <= 1000002; i++){
		n.push_back(i);
	}
}

int buscaB(std::vector<int> n, int m){
	int max = n.size();
	int min = 0;
	int i = (max + min) / 2;
	while(m != n[i]){
		if(n[i] > m){max = i;}
		else if(n[i] < m){min = i;}
		i = (max + min) / 2;
	}
	return i;
}

//Calcular todos os multiplos de um numero x e marcalos, pegar o menor numero depois de x nao marcado e repetir, os numeros q sobram sao primos.
int main(){
	std::vector<int> n;
	nArray(n);
	std::size_t max = n.size();
	int i = 0;
	do{
		int buul = 1;
		int m = n[i];
		int x = m;
		while(buul == 1){
			if(m >= max){
				buul = 0;
			}
			else{
				m = m + x;
				int index = buscaB(n, m);
				n.erase(n.begin() + index);
			}
		}
		m = x;
		i++;
	}while(m <= max);
}
