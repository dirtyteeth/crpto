#include<iostream>
#include <stdio.h>
#define swap(i, j) int t = i; i = j; j = t;
int main() 
{
	int i,j=0,iter,temp;
	int s[256];
	int k[7],ci[7];
	int key[] = {15,202,33,6,8};
	int data[] = {16,231,159,110,254,63,223};
	for (i = 0; i < 256; ++i)
		s[i] = i;
	for (i = 0; i < 256; ++i) {
		j = (j + s[i] + key[i%5]) % 256;
		swap(s[i], s[j]);
	}
	printf("Key Stream: ");
	for (iter = 0; data[iter] != '\0'; ++iter) {
		i = (i+1) % 256;
		j = (j + s[i]) % 256;
		swap(s[i], s[j]);
		k[iter]=(s[(s[i] + s[j]) %256]);
		printf("%d ", (s[(s[i] + s[j]) %256]));
	}
	printf("\nCipher Text: ");
	for (iter = 0; data[iter] != '\0'; ++iter) {
		ci[iter]=k[iter] ^ data[iter];
		printf("%d ", k[iter] ^ data[iter]);
	}
	printf("\nOriginal Text: ");
	for (iter = 0; data[iter] != '\0'; ++iter) {
		printf("%d ", k[iter] ^ ci[iter]);
	}
	return 0;
}
