#include<stdio.h>
#include<stdlib.h>

void creat(int a[], int n);   	// ham sinh so ngau nhien vao mang a
void writeFile(char *fileName, int a[], int n);   // ghi vao file
void readFile(char *fileName, int a[], int n);  // doc tu file

int main(){
	int n=100000;
	int a[n];
	creat(a,n);
	writeFile("data.txt",a,n);
	readFile("data.txt",a,n);
	return 0;
}

void creat(int a[], int n){
	for(int i=0; i<n; i++){
		a[i] = rand()%100; // gtri ngau nhien chay tu 0 -> 99
	}
}

void writeFile(char *fileName, int a[], int n){
		FILE *fw;
		fw = fopen(fileName, "w");
		fprintf(fw, "%d\n", n);
		for(int i=0; i<n; i++){
			fprintf(fw, "%d ", a[i]);
		}
		printf("Finished!\n");
		fclose(fw);
}

void readFile(char *fileName, int a[], int n){
	FILE *fr;
	fr = fopen(fileName, "r");
	fscanf(fr, "%d\n", &n);
	printf("%d\n",n);
	for(int i=0; i<n; i++){
		fscanf(fr, "%d ", &a[i]);
		printf("%d ", a[i]);
	}

}
