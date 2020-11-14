#include <iostream>
#include <cstdint>
#include <immintrin.h>

#define N 32

using namespace std;

int main() {
	cout << "HOGE" << endl;

	int i;
	uint8_t *arrayA, *arrayB, *arrayC;

	arrayA = (uint8_t*)_mm_malloc(N * sizeof(uint8_t), 32);
	arrayB = (uint8_t*)_mm_malloc(N * sizeof(uint8_t), 32);
	arrayC = (uint8_t*)_mm_malloc(N * sizeof(uint8_t), 32);

	for (i = 0; i < N; i++) {
		arrayA[i] = (uint8_t)i;
		arrayB[i] = (uint8_t)(2 * i);
	}

	arrayC = _mm_add_epi8(
		_mm256_loadu_si256(arrayA), 
		_mm256_loadu_si256(arrayB));
	

	for (i = 0; i < N; i++) {
		cout << (int)arrayA[i] << ", " << (int)arrayB[i] << endl;
	}


}


