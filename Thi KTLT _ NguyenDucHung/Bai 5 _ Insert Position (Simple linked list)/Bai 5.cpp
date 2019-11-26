#include<stdio.h>
#include<stdlib.h>

// CAU TRUC DU LIEU SIMPLE LINKED LIST
typedef struct Integeral{
	int Value;
	struct Integeral *next;
}Node;
Node *first, *last;

// NGUYEN MAU CAC HAM
void creatData(int a[], int n); 				 // tao random data luu vao mang a
void writeData(char *fileName, int a[], int n);  // ghi data vao file input
void readData(char *fileName, int a[], int n);   // doc du lieu tu file input
void display();								  // hien thi Ds
int insertHead(int value);					  // them 1 ptu dau Ds
int insertTail(int value);					  // them 1 ptu cuoi Ds
int insertPosition(int position, int value);  // them ptu tai 1 vtri trong Ds
int length();                                 // tinh chieu dai hien tai cua Ds

// Ham main
int main(){
	first=last=NULL; // khoi tao Ds rong
	int n, value, position, choice;
		
	printf("-- Exercise 5: ADD ELEMENT (in Simple linked list) _ NguyenDucHung --\n\n");
	printf(" - Number of List element : ");
	scanf("%d",&n);
	int a[n];
	creatData(a,n);
	writeData("input5.txt",a,n);
	readData("input5.txt",a,n);
	// xuat ket qua ra file output
	FILE *fout;
	fout = fopen("output5.txt","a");
	//
tt:	printf("\n - Insert 1 element       : position = ");
	scanf("%d",&position);
	if(position>=1 &&position<=length()+1){
		printf("                            value = ");
		scanf("%d",&value);
		insertPosition(position,value);
		printf(" - New Simple linked list : ");
		display();
		fprintf(fout, "\nResult: ");
		for(Node *p=first; p!=NULL; p=p->next)		fprintf(fout,"%d  ",p->Value);
	}
	else{
		printf("   Position is not valid");
		fprintf(fout, "\nResult: Position is not valid");
	}
	
	printf("\n\nDo you want to continue the program? (1.Yes / 2.No): ");
	scanf("%d",&choice);
	if(choice==1){
		printf(" - Simple linked list     : ");
		display();
		goto tt;
	}
	else{
		fclose(fout);
		printf("\n   Thank you for using the program!");
		return 0;
	}
}

// DINH NGHIA CAC HAM
void creatData(int a[], int n){
	for(int i=0; i<n; i++)	a[i]=rand()%10+1; // sinh so ngau nhien trong doan 1 -> 10
}

void writeData(char *fileName, int a[], int n){
	FILE *fw;
	fw = fopen(fileName, "w");
	fprintf(fw, "Simple linked list:\n");
	for(int i=0; i<n; i++)		fprintf(fw, "%d  ", a[i]);
	fclose(fw);
}

void readData(char *fileName, int a[], int n){
	FILE *fr;
	fr = fopen(fileName, "r");
	printf(" - Simple linked list     : ");
	for(int i=0; i<n; i++){
		fscanf(fr, "%d  ", &a[i]);
		insertTail(a[i]);
	}
	fclose(fr);
	display();
}


void display(){
	for(Node *p=first; p!=NULL; p=p->next)	printf("%d  ",p->Value);
}

int insertHead(int value){
	Node *p=(Node *)malloc(sizeof(Node));
	p->Value=value;
	p->next=first;
	first=p;	
}

int insertTail(int value){
	Node *p=(Node *)malloc(sizeof(Node));
	p->Value=value;
	p->next=NULL;
	if(first==NULL & last==NULL) 	first=p;
	else 	last->next=p;
	last=p;
}

int insertPosition(int position, int value){
 	if(position==1) 				insertHead(value); // TH1: them 1 ptu dau Ds
 	else if(position==length()+1)	insertTail(value); // TH2: them 1 ptu cuoi Ds
 	else{      // TH3: them 1 ptu vao vtri bat ki (o giua Ds)
 		Node *t=first;
	 	for(int i=1; i<position-1; i++) 	t=t->next;   // cho t tro den ptu tai vtri (position - 1)  
	 	Node *p=(Node *)malloc(sizeof(Node));
	 	p->Value=value;
	 	p->next=t->next;
	 	t->next=p;
	 }
}

int length(){
	int length=0;
	for(Node *p=first; p!=NULL; p=p->next)	length++;
	return length;
}


