#include<stdio.h>
#include<stdlib.h>

// NGUYEN MAU CAC HAM
void creatData(int a[], int n);
void writeData(char *fileName, int a[], int n);
void readData(char *fileName, int a[], int n);
void display(int a[], int n);
void quickSort(int a[], int left, int right);
void swap(int &a, int &b);
bool binarySearch(int a[], int n, int x);

// Ham main
int main(){
	int n, choice, value;
	printf("-- Exercise 2: QUICK SORT - SEARCH BINARY _ NguyenDucHung --\n\n");
	printf("\nThe number of chain elements: ");
	scanf("%d",&n);
	int a[n];
	creatData(a,n);
	writeData("input2.txt",a,n);
	readData("input2.txt",a,n); // doc file input de lay du lieu cua mang a
	printf("\n - Chain read from file: ");
	display(a,n);
	// xuat ket qua ra file output
	FILE *fout;
	fout = fopen("output2.txt", "a");
	fprintf(fout, "\n\n\n- Chain read from file : ");
	for(int i=0; i<n; i++) 	fprintf(fout, "%d  ", a[i]);
	//
	printf("\n\nPlease choose algorithm:");
	printf("\n  1. Quick Sort");
	printf("\n  2. Binary Search");
tt:	printf("\nYou choose: ");
	scanf("%d", &choice);
	switch(choice){
		case 1:
//			readData("input2.txt",a,n); // doc lai file input, lay du lieu goc truoc khi sap xep
			quickSort(a, 0, n-1);
			printf(" - Chain after sort     : ");
			display(a,n);
			printf("\n");
			fprintf(fout, "\n\n- Chain after sort     : ");
			for(int i=0; i<n; i++) 	fprintf(fout, "%d  ", a[i]);
			break;
		case 2:
			printf(" - Binary Search: value = ");
			scanf("%d", &value);
			quickSort(a,0,n-1); // phai sap xep truoc khi tim kiem nhi phan
			if(binarySearch(a,n,value)==true){
				printf("   Element %d is found\n",value);
				fprintf(fout, "\n\n- Element %d is found",value);
			}
			else{
				printf("   Element %d is not found\n",value);
				fprintf(fout, "\n\n- Element %d is not found",value);
			}
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
	for(int i=0; i<n; i++) 		a[i]=rand()%10000+1;
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
	fr = fopen(fileName, "r");
	for(int i=0; i<n; i++){
		fscanf(fr, "%d  ", &a[i]);
	}
	fclose(fr);
}

void display(int a[], int n){
	for(int i=0; i<n; i++) 		printf("%d  ",a[i]);
}

void quickSort(int a[], int left, int right){
	int i = left;
	int j = right;
	int pivot = a[(left + right)/2];
	while(i<=j){
		while(a[i]<pivot) 	i++;
		while(a[j]>pivot) 	j--;
		if(i<=j){
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if(right>i) 	quickSort(a, i, right);
	if(left<j) 		quickSort(a, left, j);
}

void swap(int &a, int &b){
	int temp = b;
	b = a;
	a = temp;
}

bool binarySearch(int a[], int n, int x){
	int left = 0;
	int rigth = n-1;
	while(left<=rigth){
		int mid = (left+rigth)/2;
		if(a[mid]==x) 		return true;
		else if(a[mid]>x) 	rigth = mid-1;
		else 				left = mid+1;
	}
	return false;
}

