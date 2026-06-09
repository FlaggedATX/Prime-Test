#include <iostream>
#include <vector>
#include <chrono>
#include <math.h>

int TAMANHO = 100; //Defines the number up until we want to calculate the primes

void nArray(std::vector<int>& n){
	n.reserve(TAMANHO + 1);
	int num = 1;
	for(int i = 0; i <= TAMANHO; i++){
		n.push_back(num);
	}
}

//Applies the sieve of Eratosthenes
int main(){
	auto start = std::chrono::high_resolution_clock::now();

	std::vector<int> n;
	nArray(n);
	n[0] = 0;
	n[1] = 0;
	std::size_t max = n.size();
	int i = 2;
	int m;
	float sq = sqrt(max);
	do{
		m = i;
		m = m * m;
		while(m < max){
			n[m] = 0;
			m = m + i;
		}
		i++;
	}while(i < sq);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsed = end - start;
	std::cout << "Execution time: " << elapsed.count() << "ms" << std::endl;

	// Optional snippet to see the numbers
	/*
	for(int i = 2; i < TAMANHO; i++){
		if(n[i] == 1){
			std::cout << i << std::endl;
		}
	}
	*/
}
