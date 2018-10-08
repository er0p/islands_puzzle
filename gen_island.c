#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


void shuffle(unsigned char *array, size_t array_size, size_t shuff_size) {
	if (array_size > 1) {
		size_t i;
		for (i = 0; i < shuff_size - 1; i++) {
			size_t j = i + rand() / (RAND_MAX / (array_size - i) + 1);
			unsigned char t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
	}
}

int main (int argc, char *argv[]) {
	unsigned int x,y,c,s,rand_count,total_count,i,j;
	unsigned char *in_arr;
	if(argc != 3) {
		printf("bad args\n");
		_exit(123);
	}
	x=atoi(argv[1]);
	y=atoi(argv[2]);
	//c=atoi(argv[2]);
	total_count = x*y;
	in_arr = (unsigned char*)calloc(1,total_count);
	s=0;
#ifdef REAL_RAND
	srand(time(NULL));
#else
	srand(s);
#endif

	rand_count = 0;

	for (i=0; i < total_count ; i++) {
		int tmp = random() % 2;
		in_arr[i] = tmp;
		if(tmp) {
			rand_count++;
		}
	}
	shuffle(in_arr, total_count, total_count);
	
	for (i=0,j=0; i < total_count ; i++, j++) {
		printf("%c", in_arr[i] ? '*' : ' ');
		if(j==(x-1)) {
			j=-1;
			printf("|\n");
		}
	}
	printf("x=%d,y=%d,total_count=%d,random=%d\n",x,y,total_count,rand_count);

	_exit(0);
}
