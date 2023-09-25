#include <stdio.h>
#include <pthread.h>
#define N 16
#define NUM_THREADS 4


int sum = 0;
int c = 0;
void* arraysum(void* arg) {
	for (int i = 0; i < N/NUM_THREADS; i++){
		sum += ((int*)arg)[c];
		c++;
	}
	pthread_exit(NULL);
}

int main() {
	pthread_t t[NUM_THREADS];
	int A[N] = {68,34,64,95,35,78,65,93,51,67, 7,77, 4,73,52,91};
	/* TODO: array sum */
	for (int i = 0; i < NUM_THREADS; i++)
		pthread_create(&t[i], NULL, arraysum, A);
	for (int i = 0; i < NUM_THREADS; i++)
		pthread_join(t[i], NULL);
	
	printf("%d\n", sum); /* 954 */
	return 0;
}
