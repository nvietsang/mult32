#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define N_TEST 10000

void mult32(unsigned int *z, unsigned int x, unsigned int y);

int main()
{
  srand(time(NULL));
	unsigned int x, y, z[2], i;
	unsigned int z0, z1;
	unsigned long long zt;
	int is_ok = 0;

	for (i = 0; i < N_TEST; i++){
		x = rand();
		y = rand();
		zt = ((unsigned long long) x) * ((unsigned long long) y);
		z0 = zt & 0xFFFFFFFF;
		z1 = zt >> 32;

		mult32(z, x, y);

		if (z[1] != z1 || z[0] != z0){
			printf("Error: \n");
			printf("x = %u, y = %u \n", x, y);
			printf("Expected: z1 = %u, z0 = %u \n", z1, z0);
			printf("Obtained: z1 = %u, z0 = %u \n", z[1], z[0]);
			is_ok = -1;
			break;
		}
	}
	if (is_ok == 0){
		printf("OK\n");
	}
  return 0;
}