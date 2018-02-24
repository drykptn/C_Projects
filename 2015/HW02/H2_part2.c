#include<stdio.h>
int main() {
	int toplam=0, sayi;
	
	for( sayi = 2; sayi <= 100; sayi += 2);
		toplam +=sayi;
		
	printf("toplam %d\n", toplam);
	
	return 0;
}
