#include <iostream>
#include <vector>
#include <chrono>
#include <math.h>

int TAMANHO = 100; //Defines the number up until we want to calculate the primes



void nArray(std::vector<int>& n){
	n.reserve(TAMANHO);
	int num = 1;
	for(int i = 0; i <= TAMANHO; i++){
		n.push_back(num);
	}
}
//Binary Search, ended up unused
/*int buscaB(std::vector<int> n, int m){
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
*/

//Applies the sieve of Eratosthenes
int main(){
	auto start = std::chrono::high_resolution_clock::now();

	std::vector<int> n;
	nArray(n);
	n[0] = 0;
	n[1] = 0;
	std::size_t max = n.size();
	int i = 2;
	int m = -1;
	int cont;
	do{
		m = i;
		int x = m;
		cont = 1;
		while(m < max){
			if(cont == 1){m = m * m;} // optimizes a lil, more noticible at higher values
			else{m = m + x;}
			//m = m + x;
			if(m < max){n[m] = 0;}
			cont = 0;
		}
		//std::cout << "Rodando..." << std::endl;
		m = x;
		i++;
	}while(m < sqrt(max));

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsed = end - start;
	std::cout << "Execution time: " << elapsed.count() << "ms" << std::endl;

	// Optional snippet to see the numbers
	
	for(int i = 2; i < TAMANHO; i++){
		if(n[i] == 1){
			std::cout << i << std::endl;
		}
	}
	 
}
