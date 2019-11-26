#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10 // so ptu toi da cua Queue

// CAU TRUC DU LIEU QUEUE (sd mang)
struct Queue{
	int a[MAXSIZE+1];  // mang a luu cac ptu cua Queue, ptu a[0] khong dung den
	int head; 		   // danh dau ptu dau Queue dang la ptu thu may cua mang a
	int tail;		   // danh dau ptu cuoi Queue dang la ptu thu mau cua mang a
	int count;         // dem so ptu hien co trong Queue
};
struct Queue q; // q: bien cau truc

// NGUYEN MAU CAC HAM
void Put(int value); 	// them 1 ptu vao cuoi Queue
int Peek(); 			// ktra ptu dau Queue
int Get(); 				// xoa ptu dau Queue
void Display(); 		// hien thi Queue
bool IsEmpty(); 		// ktra Queue rong
bool IsFull(); 			// ktra Queue day
void MakeEmpty(); 		// lam rong Queue

// Ham main
int main(){
	// khoi tao Queue rong
	q.head = q.tail = q.count =0;
	for(int i=1; i<=MAXSIZE; i++) 	q.a[i]=0;   // tat ca cac ptu cua Queue rong gan bang 0
	int value, choice;
	
	printf("-- PROGRAM: QUEUE (use Array) _ NguyenDucHung --\n\n");
	printf("\nPlease choose task for Queue:");
	printf("\n  1. Put      5. IsEmpty");
	printf("\n  2. Get      6. IsFull");
	printf("\n  3. Peek     7. MakeEmpty");
	printf("\n  4. Display  0. Exit");
tt:	printf("\nYou choose: "); 		scanf("%d",&choice);
	switch(choice){
		case 1:
			if(q.count==MAXSIZE) 	printf("   Queue is full, cannot Put.\n");
			else{
				printf(" - New element: value = ");
				scanf("%d",&value);
				Put(value);
			}
			break;
		case 2:
			if(q.count==0) 	printf("   Queue is empty, cannot Get.\n");
			else{
				printf("   Removed element %d\n",Get());
			}
			break;
		case 3:
			if(q.count==0)	printf("   Queue is empty, head element is not exist\n");
			else 			printf("   Head element: %d\n",Peek());
			break;
		case 4:
			Display();
			break;
		case 5:
			if(IsEmpty()==true)		printf("   Queue is empty\n");
			else					printf("   Queue is not empty\n");
			break;
		case 6:
			if(IsFull()==true)		printf("   Queue is full\n");
			else 					printf("   Queue is not full\n");
			break;
		case 7:
			if(q.count==0)		printf("   Queue is empty before\n");
			else{
				MakeEmpty();
				Display();
			}
			break;
		default:
			printf("   Error choice! Please choose again!\n");
			break;
		case 0:
			printf("   Task finished! Do you want to continue the program? (1.Yes / 2.No): ");
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
	if(q.count==0){   // TH1:___ them ptu vao Queue rong
		q.head=q.tail=q.count=1;
		q.a[1]=value;
	}
	else{ 			  // TH2:___ them ptu vao Queue khong rong
		q.tail=(q.tail % MAXSIZE)+1;   // doi lai gtri cho bien tail (vtri ptu cuoi Queue so voi mang a)
		q.a[q.tail]=value;  // gan gtri cho ptu moi them vao Queue
		q.count++; // so luong ptu cua Queue tang them 1
	}	
}

int Get(){
	int value = q.a[q.head]; 	// value mang gtri cua ptu sap bi xoa
	q.count--; // so luong ptu Queue giam 1
	q.a[q.head]=0; 			// dat lai gtri cho ptu bi xoa (bang 0)
	q.head=(q.head % MAXSIZE)+1;  // doi bien head (vtri ptu dau cua Queue so voi mang a) 
	return value; // tra ve gtri cua ptu vua bi xoa
}

void Display(){
	printf("   head = %d,  tail = %d,  count = %d\n",q.head,q.tail,q.count);
	printf("   QUEUE:   ");
	for(int i=1; i<=MAXSIZE; i++)	printf("%d.   ",q.a[i]);
	printf("\n");
}

int Peek(){
	return q.a[q.head];
}

bool IsEmpty(){
	if(q.count==0) 	return true;
	else 			return false;
}

bool IsFull(){
	if(q.count==MAXSIZE) 	return true;
	else 					return false;
}

void MakeEmpty(){
	while(q.count>0){
		Get();
	}
}
