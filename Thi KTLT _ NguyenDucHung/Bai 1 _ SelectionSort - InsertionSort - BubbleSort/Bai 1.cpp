#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//NGUYEN MAU CAC HAM
void creatData(int a[], int n); 				// tao random data luu vao mang a
void writeData(char *fileName, int a[], int n); // ghi random data vao file input
void readData(char *fileName, int a[], int n);  // doc random data tu file input
float selectionSort(int a[], int n);  // sap xep lua chon
float insertionSort(int a[], int n);  // sap xep chen
float bubbleSort(int a[], int n);     // sap xep noi bot
void swap(int &a, int &b);            // doi cho a va b
void display(int a[], int n); 		  // hien thi mang


// Ham main
int main(){
	int n, choice;
	float runtime; // bien chi thoi gian chay cua thuat toan
	printf("-- Exercise 1: SELECTION SORT - BUBBLE SORT - INSERT SORT _ NguyenDucHung --\n\n");
	printf("\nThe number of chain elements: ");
	scanf("%d",&n);
	int a[n];
	creatData(a,n);
	writeData("input1.txt", a, n);
	readData("input1.txt", a, n); // doc file input de lay du lieu cua mang a
	printf("\n - Chain read form file: ");
	for(int i=0; i<n; i++) 	printf("%d  ",a[i]);
	// xuat ket qua ra file output
	FILE *fout = fopen("output1.txt","a");
	fprintf(fout,"\n\n\n- Chain read from file: "); //
	for(int i=0; i<n; i++) 	fprintf(fout, "%d  ",a[i]); //
	fprintf(fout, "\n"); //
	//
	printf("\n\nPlease choose algorithm:");
	printf("\n  1. Selection sort");
	printf("\n  2. Insertion sort");
	printf("\n  3. Bubble sort");
	printf("\n  4. Review first chain");
	printf("\n  0. Exit");
tt:	printf("\nYou choose: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			readData("input1.txt",a,n);   // lay lai du lieu mang a ban dau truoc khi sap xep
			runtime = selectionSort(a,n);
			display(a,n);
			printf("\n - Runtime SelectionSort: %0.3f (ms)\n",runtime);
			fprintf(fout,"\n- Chain after sort (Selection Sort): "); // (xuat ra file output)
			for(int i=0; i<n; i++) 		fprintf(fout,"%d  ",a[i]); // 
			fprintf(fout, "\n- Runtime: %0.3f (ms)\n",runtime); //
			break;
		case 2:
			readData("input1.txt",a,n);   // lay lai du lieu mang a ban dau truoc khi sap xep
			runtime = insertionSort(a,n);
			display(a,n);
			printf("\n - Runtime InsertionSort: %0.3f (ms)\n",runtime);
			fprintf(fout,"\n- Chain after sort (Insertion Sort): "); //
			for(int i=0; i<n; i++) 		fprintf(fout,"%d  ",a[i]); //
			fprintf(fout, "\n- Runtime: %0.3f (ms)\n",runtime); //
			break;
		case 3:
			readData("input1.txt",a,n);   // lay lai du lieu mang a ban dau truoc khi sap xep
			runtime = bubbleSort(a,n);
			display(a,n);
			printf("\n - Runtime BubbleSort: %0.3f (ms)\n",runtime);
			fprintf(fout,"\n- Chain after sort (Bubble Sort): "); //
			for(int i=0; i<n; i++) 		fprintf(fout,"%d  ",a[i]); //
			fprintf(fout, "\n- Runtime: %0.3f (ms)\n",runtime); //
			break;
		case 4:
			readData("input1.txt",a,n); // lay lai du lieu mang a ban dau
			printf(" - Chain read from file: ");
			for(int i=0; i<n; i++) 	printf("%d  ",a[i]);
			printf("\n");			
			break;
		case 0:
			printf("   Do you want to continue the program with other chain? (1.Yes / 2.No): ");
			scanf("%d",&choice);
			if(choice==1){
				system("cls");
				return main();
			}
			else{
				fclose(fout);
				printf("\n   Thank you for using the program!\n");
				return 0;
			}
		default:
			printf("   Error choice, please choose again!\n");
			break;
		
	}
	goto tt;	
}

// DINH NGHIA CAC HAM
void creatData(int a[], int n){
	for(int i=0; i<n; i++) 	  a[i]=rand()%10000+1;
}

void writeData(char *fileName, int a[], int n){
	FILE *fw;
	fw = fopen(fileName, "w");
	fprintf(fw, "%d\n", n);
	for(int i=0; i<n; i++) 		fprintf(fw, "%d  ", a[i]);
	fclose(fw);
}

void readData(char *fileName, int a[], int n){
	FILE *fr;
	fr = fopen(fileName,"r");
	for(int i=0; i<n; i++){
		fscanf(fr, "%d  ", &a[i]); // doc tung ptu cua mang a
	}
	fclose(fr);
}

float selectionSort(int a[], int n){
	int min;
	clock_t start = clock();
	for(int i=0; i<n-1; i++){
		min = i;
		for(int j=i+1; j<n; j++){
			if(a[j]<a[min])		min = j;
		}
		swap(a[i], a[min]);
	}
	clock_t end = clock();
	return (float) ((end-start)*1000/CLOCKS_PER_SEC);
}

float insertionSort(int a[], int n){
	int j,temp;
	clock_t start = clock();
	for(int i=1; i<n; i++){
		j=i-1;
		temp=a[i];
		while(temp<a[j] && j>=0){
			a[j+1] = a[j];
			j--;
		}
		a[j+1]=temp;
	}
	clock_t end = clock();
	return (float) ((end-start)*1000/CLOCKS_PER_SEC);
}

float bubbleSort(int a[], int n){
	clock_t start = clock();
	for(int i=0; i<n-1; i++){
		for(int j=n-1; j>i; j--){
			if(a[j]<a[j-1]) 	swap(a[j], a[j-1]);
		}
	}
	clock_t end = clock();
	return (float) ((end-start)*1000/CLOCKS_PER_SEC);
}

void swap(int &a, int &b){
	int temp;
	temp = b;
	b = a;
	a = temp;
}

void display(int a[], int n){
	printf(" - Chain after sort: ");
	for(int i=0; i<n; i++) 	printf("%d  ", a[i]);
}

