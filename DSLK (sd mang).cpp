#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10   // so ptu lon nhat ma Dslk co the co

// CAU TRUC DU LIEU DSLK SD MANG
struct Node{
	int a[MAXSIZE+1];  // mang a luu cac ptu cau Ds, ptu a[0] khong dung den
	int last; // vtri cuoi cua Ds, cung la vtri cuoi cua mang, dong thoi la so ptu cua Ds hien tai
}n;

// NGUYEN MAU CAC HAM
void insertHead(int value);      			  // them 1 ptu vao dau Ds
void insertTail(int value); 				  // them 1 ptu vao cuoi Ds
void insertPosition(int position, int value); // them 1 ptu vao 1 vtri trong Ds
int deleteHead(); 				 			  // xoa 1 ptu dau Ds
int deleteTail(); 						      // xoa 1 ptu cuoi Ds
int deletePosition(int position); 			  // xoa 1 ptu o 1 vtri trong Ds
void deleteValue(int value); 				  // xoa cac ptu co gtri value
void deleteSameValue();			 			  // xoa cac ptu trung nhau, chi de lai 1 ptu vs moi gtri
void display(); 							  // hien thi Ds
bool isEmpty(); 							  // ktra Ds rong
bool isFull(); 					              // ktra Ds day
void makeEmpty(); 				              // lam rong Ds
void seekPosition(int value);                 // tim vtri cua nut co gtri bat ki trong Ds
void sortAsending(); 						  // sap xep Ds tang dan
void sortDesending(); 						  // sap xep Ds giam dan
void swap(int &a, int &b);					  // dao gtri a va b

// Ham main
int main(){
	int choice,value,position;
	n.last=0; // khoi tao Ds rong
	for(int i=1; i<=MAXSIZE; i++)	n.a[i]=0; // khi ds rong, tat ca cac ptu co gtri = 0
	
	printf("-- PROGRAM: LINKED LIST (use Array) _ NguyenDucHung --\n");
	printf("\nPlease choose task for the Linked list:");
	printf("\n  1. Insert Head         6. Delete Position       11. Make Empty");
	printf("\n  2. Insert Tail         7. Delate Value          12. Seek Position");
	printf("\n  3. Insert Position     8. Delete Same Value     13. Sort Asending");
	printf("\n  4. Delete Head         9. Is Empty              14. Sort Desending");
	printf("\n  5. Delete Tail         10. Is Full              0. Exit\n");
tt:	printf("\nYou choose: "); 	scanf("%d",&choice);
	switch(choice){
		case 1:
			if(n.last==MAXSIZE) 	printf("   Linked list if full, cannot insert.\n");
			else{
				printf(" - New node: value = ");
				scanf("%d",&value);
				insertHead(value);
				display();
			}
			break;
		case 2:
			if(n.last==MAXSIZE) 	printf("   Linked list if full, cannot insert.\n");
			else{
				printf(" - New node: value = ");
				scanf("%d",&value);
				insertTail(value);
				display();
			}
			break;
		case 3:
			if(n.last==MAXSIZE) 	printf("   Linked list is full, cannot insert.\n");
			else{
				printf(" - New node: position =  ");
				scanf("%d",&position);
				if(position>n.last || position<1)	printf("   Position is not valid\n");
				else{
					printf(" - New node: value = ");
					scanf("%d",&value);
					insertPosition(position,value);
				}
				display();
			}
			break;
		case 4:
			if(n.last==0) 	printf("   Linked list is empty, cannot delete.\n");
			else{
				printf("   Removed element %d\n", deleteHead());
				display();
			}
			break;
		case 5:
			if(n.last==0) 	printf("   Linked list is empty, cannot delete.\n");
			else{
				printf("   Removed element %d\n", deleteTail());
				display();
			}
			break;
		case 6:
			if(n.last==0) 	printf("   Linked list is empty, cannot delete.\n");
			else{
				printf(" - New node: postion = ");
				scanf("%d",&position);
				if(position>n.last || position<1) 	printf("   Position is not valid\n");
				else 	printf("   Removed element %d\n",deletePosition(position));
				display();
			}
			break;
		case 7:
			printf(" - Value = ");
			scanf("%d",&value);
			deleteValue(value);
			display();
			break;
		case 8:
			deleteSameValue();
			display();
			break;
		case 9:
			if(isEmpty()==true)		printf("   Linked list is empty\n");
			else					printf("   Linked list is not empty\n");
			break;
		case 10:
			if(isFull()==true)		printf("   Linked list is full\n");
			else					printf("   Linked list is not full\n");
			break;
		case 11:
			if(n.last==0) 	printf("   Linked list is empty before\n");
			else{
				makeEmpty();
				display();
			}
			break;
		case 12:
			printf(" - Value = ");
			scanf("%d",&value);
			seekPosition(value);
			printf("\n");
			break;
		case 13:
			printf(" - Sort Asending:");
			sortAsending();
			display();
			break;
		case 14:
			printf(" - Sort Desending:");
			sortDesending();
			display();
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
		default:
			printf("   Error choice! Please choose again!\n");
			break;
	}
	goto tt;
}

// DINH NGHIA CAC HAM
void display(){
	printf("   Linked list: ");
	for(int i=1; i<=MAXSIZE; i++) 	printf("%d   ",n.a[i]);
	printf("\n");
}

void insertHead(int value){
	for(int i=MAXSIZE; i>=2; i--){  // dich chuyen cac ptu con lai ve dau mang di 1 o nho
		n.a[i]=n.a[i-1];
	}
	n.a[1]=value;
	n.last++;
}

void insertTail(int value){
	n.last++; 
	n.a[n.last]=value;
}

void insertPosition(int position, int value){
	for(int i=n.last+1; i>=position+1; i--){ // dich chuyen cac ptu trong khoang[position; last] ve phia cuoi mang di 1 o nho
		n.a[i]=n.a[i-1];
	}
	n.last++;
	n.a[position]=value;
}

int deleteHead(){
	int value;
	value = n.a[1];
	for(int i=1; i<=MAXSIZE-1; i++){  //dich chuyen cac ptu con lai cua Ds ve dau mang di 1 o nho
		n.a[i]=n.a[i+1];
	}
	n.a[n.last]=0;
	n.last--;
	return value;
}

int deleteTail(){
	int value;
	value = n.a[n.last];
	n.a[n.last]=0;
	n.last--;
	return value;
}

int deletePosition(int position){
	int value;
	value = n.a[position];
	n.a[position]=0;
	for(int i=position; i<=n.last-1; i++){ // dich chuyen cac ptu trong khoang [positon;last] ve dau Ds di 1 o nho
		n.a[i]=n.a[i+1];
	}
	n.a[n.last]=0;
	n.last--;
	return value;
}

bool isEmpty(){
	if(n.last==0) 	return true;
	else 			return false;
}

bool isFull(){
	if(n.last==MAXSIZE) 	return true;
	else 					return false;
}

void makeEmpty(){
	while(n.last>0){
		deleteTail();
	}
}

void seekPosition(int value){
	int count=0;
	for(int i=1; i<=n.last; i++){
		if(n.a[i]==value) 	count++; // dem so ptu co gtri = value
	}
	if(count==0) 	printf("   Element %d is not found",value);
	else{
		if(count==1) 	printf("   Element %d is found at 1 position: ",value);
		if(count>1)		printf("   Element %d is found at %d positions: ",value,count);
		for(int i=1; i<=n.last; i++){
			if(n.a[i]==value) 		printf("%d   ",i);  // in ra cac vtri thoa man
		}
	}
}

void sortAsending(){
	int temp;
	for(int i=1; i<=n.last-1; i++){
		for(int j=i+1; j<=n.last; j++){
			if(n.a[i] > n.a[j])		swap(n.a[i], n.a[j]);
		}
	}
}

void sortDesending(){
	int temp;
	for(int i=1; i<=n.last-1; i++){
		for(int j=i+1; j<=n.last; j++){
			if(n.a[i] < n.a[j])		swap(n.a[i], n.a[j]);
		}
	}	
}

void deleteValue(int value){
	int count=0;
	for(int i=1; i<=n.last; i++){
		if(n.a[i]==value) 	count++; // dem so ptu co gtri bang value
	}
	if(count==0) 	printf("   Element %d is not exist\n",value); // khong ton tai ptu co gtri bang value
	else{ 
		for(int j=count; j>1; j--){
				if(n.a[1]==value)	deletePosition(1); // ptu can xoa o dau Ds
				else{ // ptu can xoa k o dau Ds
					int i=1;
					while(i<=n.last && n.a[i]!=value)	i++; // khi chua het Ds va chua tim thay ptu thoa man
					if(n.a[i]==value) 	deletePosition(i);
				}
		}
	}
}

void deleteSameValue(){
	int count=0, value;
	for(int j=1; j<=n.last; j++){ // xet den gtri tung ptu trong Ds
		value=n.a[j];
		for(int i=1; i<=n.last; i++){
			if(n.a[i]==value) 	count++; // dem so ptu co gtri bang value
		}
		if(count>1){ 
			for(int j=count; j>1; j--){
				if(n.a[1]==value)	deletePosition(1); // ptu can xoa o dau Ds
				else{ // ptu can xoa khong o dau Ds
					int k=1;
					while(k<=n.last && n.a[k]!=value)	k++; // khi chua het Ds va chua tim thay ptu thoa man
					if(n.a[k]==value) 	deletePosition(k);
				}
			}
		}
		count=0; // dat lai count=0 de ktra ptu tiep theo trong Ds
	}
}

void swap(int &a, int &b){
	int temp=b;
	b=a;
	a=temp;
}
