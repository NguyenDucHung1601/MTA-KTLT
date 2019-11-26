#include<stdio.h>
#include<stdlib.h>

// CAU TRUC DU LIEU QUEUE (sd DSLK don)
typedef struct Queue{
	int Value; 	// bien luu gtri ptu cua Queue
	struct Queue *next; // con tro tro toi ptu tiep theo
}queue;
queue *first, *last; // con tro tro toi vtri dau tien, cuoi cung cua Queue

// NGUYEN MAU CAC HAM
void creatData(int a[], int n);                  // tao random data luu tai mang a
void writeData(char *fileName, int a[], int n);  // ghi random data vao file input
void readData(char *fileName, int a[], int n);   // doc random data tu file input
void Put(int value);       // them 1 ptu vao duoi Queue
int Get(); 				   // xoa ptu dau Queue
int Peek(); 			   // ktra ptu dau Queue
void Display(); 		   // hien thi Queue
bool IsEmpty(); 		   // ktra Queue rong
bool IsFull(int maxsize);  // ktra Queue day
void MakeEmpty(); 		   // lam rong Queue
int Length(); 			   // tinh chieu dai hien tai cua Queue

// Ham main
int main(){
	int n, choice, value, maxsize;
	first=last=NULL; // khoi tao Queue rong

	printf("-- Exercise 15: QUEUE (use Simple linked list) _ NguyenDucHung --\n");
	printf("\nMax size of Queue: "); 	scanf("%d",&maxsize);
	
	int a[maxsize];
	creatData(a,maxsize);
	writeData("input15.txt",a,maxsize);
	readData("input15.txt",a,maxsize);
	
	printf("\n\nPlease choose task for Queue:");
	printf("\n  1. Put        5. IsEmpty");
	printf("\n  2. Get        6. IsFull");
	printf("\n  3. Peek       7. MakeEmpty");
	printf("\n  4. Length     0. Exit");
tt:	printf("\nYou choose: "); 		scanf("%d",&choice);
    // xuat ket qua ra file output
    FILE *fout;
    fout = fopen("output15.txt", "a");
    //
	switch(choice){
		case 1:
			if(Length()==maxsize){
				printf("   Queue is full, cannot Put.\n");
				fprintf(fout,"\nQueue is full, cannot Put.");//
			}
			else{
				printf(" - New element: value = ");
				scanf("%d",&value);
				Put(value);
				Display();
				fprintf(fout,"\nQUEUE: ");//
				for(queue *p=first; p!=NULL; p=p->next) 	fprintf(fout," %d .",p->Value);//
			}
			break;
		case 2:
			if(first==NULL){
				printf("   Queue is empty, cannot Get.\n");
				fprintf(fout,"\nQueue is empty, cannot Get.");//
			}
			else{
				int get = Get(); // tranh goi ham Get 2 lan (lay ra 2 ptu dau Queue)
				printf("   Removed element %d\n",get);
				fprintf(fout,"\nRemove element %d",get);//
				Display();
				fprintf(fout,"\nQUEUE: ");//
				for(queue *p=first; p!=NULL; p=p->next) 	fprintf(fout," %d .",p->Value);//
			}
			break;
		case 3:
			if(first==NULL){
				printf("   Queue is empty, head element is not exist.\n");
				fprintf(fout,"\nQueue is empty, head element is not exist.");//
			}
			else{
				printf("   Head element: %d\n",Peek());
				fprintf(fout,"\nHead element: %d",Peek());
			}
			break;
		case 4:
			printf("   Length of Queue now: %d\n",Length());
			fprintf(fout, "\nLength of Queue now: %d",Length());
			break;
		case 5:
			if(IsEmpty()==true){
				printf("   Queue is empty\n");
				fprintf(fout,"\nQueue is empty");//
			}
			else{
				printf("   Queue is not empty\n");
				fprintf(fout, "\nQueue is not empty");//
			}
			break;
		case 6:
			if(IsFull(maxsize)==true){
				printf("   Queue is full\n");
				fprintf(fout, "\nQueue is full");//
			}
			else{
				printf("   Queue is not full\n");
				fprintf(fout, "\nQueue is not full");//
			}
			break;
		case 7:
			if(Length()==0){
				printf("   Queue is empty before\n");
				fprintf(fout,"\nQueue is empty before");//
			}
			else{
				MakeEmpty();
				Display();
				fprintf(fout,"\nQUEUE: ");//
				for(queue *p=first; p!=NULL; p=p->next) 	fprintf(fout,"%d  ",p->Value);//
			}
			break;
		default:
			printf("   Error choice, please choice again!\n");
			break;
		case 0:
			printf("   Task finished. Do you want to continue the program? (1.Yes / 2.No): ");
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
	}
	goto tt;
}

// DINH NGHIA CAC HAM

int Length(){
	int L=0;
	for(queue *p=first; p!=NULL; p=p->next) 	L++;
	return L;
}

void Put(int value){
	queue *p = (queue *)malloc(sizeof(queue));
	p->Value=value;
	p->next=NULL;
	if(first==NULL) 	first=p;
	else				last->next=p;
	last=p;
}

int Get(){
	int value=first->Value;
	queue *temp=first;
	first=first->next;
	free(temp);
	return value;
}

int Peek(){
	return first->Value;		
}

void Display(){
	printf("   QUEUE:   ");
	for(queue *p=first; p!=NULL; p=p->next) 	printf("%d.   ",p->Value);
	printf("\n");
}

bool IsEmpty(){
	if(first==NULL)	  return true;
	else		      return false;
}

bool IsFull(int maxsize){
	if(Length()==maxsize) 	return true;	
	else 					return false;
}


void MakeEmpty(){
	while(first!=NULL){
		Get();
	}
}

void creatData(int a[], int n){
	for(int i=0; i<n; i++) 	  a[i]=rand()%100+1; // gtri ngau nhien trong doan 1 -> 100
}

void writeData(char *fileName, int a[], int n){
	FILE *fw;
	fw = fopen(fileName, "w");
	fprintf(fw, "Queue: maxsize = %d\n",n);
	for(int i=0; i<n; i++) 		fprintf(fw, "%d  ",a[i]);
	fclose(fw);
}

void readData(char *fileName, int a[], int n){
	FILE *fr;
	fr = fopen(fileName, "r");
	printf("\nQUEUE:  ");
	for(int i=0; i<n; i++){
		fscanf(fr, "%d  ",&a[i]); // doc tung ptu cua mang a luu trong file input
		Put(a[i]); // them ptu vua doc vao duoi Queue
		printf(" %d .",a[i]); // in ra ptu vua Put
	}
	fclose(fr);
}

