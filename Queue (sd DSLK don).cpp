#include<stdio.h>
#include<stdlib.h>

// CAU TRUC DU LIEU QUEUE (sd DSLK don)
typedef struct Queue{
	int Value; 	// bien luu gtri ptu cua Queue
	struct Queue *next; // con tro tro toi ptu tiep theo
}queue;
queue *first, *last; // con tro tro toi vtri dau tien, cuoi cung cua DSLK don

// NGUYEN MAU CAC HAM
void Put(int value);       // them 1 ptu vao duoi Queue
int Get(); 				   // xoa ptu dau Queue
int Peek(); 			   // ktra ptu dau Queue
void Display(); 		   // hien thi Queue
bool IsEmpty(); 		   // ktra Queue rong
bool IsFull(int maxsize);  // ktra Queue day
void MakeEmpty(); 		   // lam rong Queue
int Count(); 			   // dem so ptu hien tai cua Queue

// Ham main
int main(){
	int choice, value, count, maxsize;
	first=NULL; // khoi tao Queue rong

	printf("-- PROGRAM: QUEUE (use Simple linked list) _ NguyenDucHung --\n");
	printf("\nMax size of Queue: "); 	scanf("%d",&maxsize);
	
	printf("Please choose task for Queue:");
	printf("\n  1. Put        5. IsEmpty");
	printf("\n  2. Get        6. IsFull");
	printf("\n  3. Peek       7. MakeEmpty");
	printf("\n  4. Display    0. Exit");
tt:	printf("\nYou choose: "); 		scanf("%d",&choice);
	switch(choice){
		case 1:
			if(Count()==maxsize) 		printf("   Queue is full, cannot Put.\n");
			else{
				printf(" - New element: value = ");
				scanf("%d",&value);
				Put(value);
			}
			break;
		case 2:
			if(first==NULL) 	printf("   Queue is empty, cannot Get.\n");
			else				printf("   Removed element %d\n",Get());
			break;
		case 3:
			if(first==NULL) 	printf("   Queue is empty, head element is not exist.\n");
			else 				printf("   Head element: %d\n",Peek());
			break;
		case 4:
			Display();
			break;
		case 5:
			if(IsEmpty()==true)		printf("   Queue is empty\n");
			else					printf("   Queue is not empty\n");
			break;
		case 6:
			if(IsFull(maxsize)==true)	printf("   Queue is full\n");
			else						printf("   Queue is not full\n");
			break;
		case 7:
			if(first==NULL) 	printf("   Queue is empty before\n");
			else{
				MakeEmpty();
				Display();
			}
			break;
		default:
			printf("   Error choice! Please choose again!\n");
			break;
		case 0:
			printf("   Task finished. Do you want to continue the program? (1.Yes / 2.No): ");
			scanf("%d",&choice);
			if(choice==1){
				system("cls");
				return main();
			}
			else{
				printf("\n   Thank you for using the program!\n");
				return 0;
			}
	}
	goto tt;
}

// DINH NGHIA CAC HAM
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
	if(first==NULL) 	return true;
	else 				return false;
}

bool IsFull(int maxsize){
	if(Count()==maxsize) 	return true;
	else 					return false;	
}

void MakeEmpty(){
	while(first!=NULL){
		Get();
	}
}

int Count(){
	int count=0;;
	for(queue *p=first; p!=NULL; p=p->next) 	count++;
	return count;
}

