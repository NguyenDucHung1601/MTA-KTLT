#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10   // so ptu lon nhat ma Dslk co the co

// CAU TRUC DU LIEU DSLK SD MANG
struct Node{
	int a[MAXSIZE+1];  // mang a luu cac ptu cau Ds, ptu a[0] khong dung den
	int last; // vtri cuoi cua Ds, cung la vtri cuoi cua mang, dong thoi la so ptu cua Ds hien tai
}n;

// NGUYEN MAU CAC HAM
void creatData(int a[], int n);                  // tao random data luu vao mang a
void writeData(char *fileName, int a[], int n);  // ghi random data vao file input
void readData(char *fileName, int a[], int n);   // doc random data tu file inpput

void insertHead(int value);     	     	  // them 1 ptu vao dau Ds
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


// Ham main
int main(){
	int choice,value,position;
	int b[MAXSIZE+1];
	
	// Ban dau Ds rong (tat ca cac ptu cua mang bang 0)
	 	
	printf("-- Exercise 3: LINKED LIST (use Array) _ NguyenDucHung --\n");
	
	creatData(b,MAXSIZE+1);
	writeData("input3.txt",b,MAXSIZE+1);
	readData("input3.txt",b,MAXSIZE+1);
	// xuat ket qua ra file
	FILE *fout;
	fout = fopen("output3.txt", "a");
	//
	printf("\n\nPlease choose task for the Linked list:");
	printf("\n  1. Insert Head         7. Delete Value");
	printf("\n  2. Insert Tail         8. Delate Same Value");
	printf("\n  3. Insert Position     9. Is Empty");
	printf("\n  4. Delete Head         10. Is Full");
	printf("\n  5. Delete Tail         11. Make Empty");
	printf("\n  6. Delete Position     0. Exit");
tt:	printf("\nYou choose: "); 	scanf("%d",&choice);
	switch(choice){
		case 1:
			if(n.last==MAXSIZE){
				printf("   Linked list if full, cannot insert.\n");
				fprintf(fout, "\nLinked list is full, cannot insert.");
			}
			else{
				printf(" - New node: value = ");
				scanf("%d",&value);
				insertHead(value);
				display();
				fprintf(fout, "\nLinked list: ");
				for(int i=1; i<=MAXSIZE; i++) 	fprintf(fout, "%d   ",n.a[i]);
			}
			break;
		case 2:
			if(n.last==MAXSIZE){
				printf("   Linked list if full, cannot insert.\n");
				fprintf(fout, "\nLinked list is full, cannot insert.");
			}
			else{
				printf(" - New node: value = ");
				scanf("%d",&value);
				insertTail(value);
				display();
				fprintf(fout, "\nLinked list: ");
				for(int i=1; i<=MAXSIZE; i++) 	fprintf(fout, "%d   ",n.a[i]);
			}
			break;
		case 3:
			if(n.last==MAXSIZE){
				printf("   Linked list is full, cannot insert.\n");
				fprintf(fout, "\nLinked list is full, cannot insert.");
			}
			else{
				printf(" - New node: position =  ");
				scanf("%d",&position);
				if(position>n.last || position<1){
					printf("   Position is not valid\n");
					fprintf(fout, "\nPosition is not valid");
				}
				else{
					printf(" - New node: value = ");
					scanf("%d",&value);
					insertPosition(position,value);
				}
				display();
				fprintf(fout, "\nLinked list: ");
				for(int i=1; i<=MAXSIZE; i++) 	fprintf(fout, "%d   ",n.a[i]);
			}
			break;
		case 4:
			if(n.last==0){
				printf("   Linked list is empty, cannot delete.\n");
				fprintf(fout, "\nLinked list is empty, cannot delete.");
			}
			else{
				int dh = deleteHead(); // tranh deleteHead 2 lan
				printf("   Removed element %d\n", dh);
				fprintf(fout, "\nRemoved element %d", dh);
				display();
				fprintf(fout, "\nLinked list: ");
				for(int i=1; i<=MAXSIZE; i++) 	fprintf(fout, "%d   ",n.a[i]);
			}
			break;
		case 5:
			if(n.last==0){
				printf("   Linked list is empty, cannot delete.\n");
				fprintf(fout, "\nLinked list is empty, cannot delete.");
			}
			else{
				int dt = deleteTail(); // tranh deleteTail 2 lan
				printf("   Removed element %d\n", dt);
				fprintf(fout, "\nRemoved element %d", dt);
				display();
				fprintf(fout, "\nLinked list: ");
				for(int i=1; i<=MAXSIZE; i++) 	fprintf(fout, "%d   ",n.a[i]);
			}
			break;
		case 6:
			if(n.last==0){
				printf("   Linked list is empty, cannot delete.\n");
				fprintf(fout, "\nLinked list is empty, cannot delete.");
			}
			else{
				printf(" - New node: postion = ");
				scanf("%d",&position);
				if(position>n.last || position<1){
					printf("   Position is not valid\n");
					fprintf(fout, "\nPosition is not valid");
				}
				else{
					int dp = deletePosition(position);  // tranh daletePosition 2 lan
					printf("   Removed element %d\n",dp);
					fprintf(fout, "\nRemoved element %d", dp);
				}
				display();
				fprintf(fout, "\nLinked list: ");
				for(int i=1; i<=MAXSIZE; i++) 	fprintf(fout, "%d   ",n.a[i]);
			}
			break;
		case 7:
			printf(" - Value = ");
			scanf("%d",&value);
			deleteValue(value);
			display();
			fprintf(fout, "\nLinked list: ");
			for(int i=1; i<=MAXSIZE; i++) 	fprintf(fout, "%d   ",n.a[i]);
			break;
		case 8:
			deleteSameValue();
			display();
			fprintf(fout, "\nLinked list: ");
			for(int i=1; i<=MAXSIZE; i++) 	fprintf(fout, "%d   ",n.a[i]);
			break;
		case 9:
			if(isEmpty()==true){
				printf("   Linked list is empty\n");
				fprintf(fout, "\nLinked list is empty");
			}
			else{
				printf("   Linked list is not empty\n");
				fprintf(fout, "\nLinked list is not empty");
			}
			break;
		case 10:
			if(isFull()==true){
				printf("   Linked list is full\n");
				fprintf(fout, "\nLinked list is full");
			}
			else{
				printf("   Linked list is not full\n");
				fprintf(fout, "\nLinked list is not full");
			}
			break;
		case 11:
			if(n.last==0){
				printf("   Linked list is empty before\n");
				fprintf(fout, "\nLinked list is empty before");
			}
			else{
				makeEmpty();
				display();
				fprintf(fout, "\nLinked list: ");
				for(int i=1; i<=MAXSIZE; i++) 	fprintf(fout, "%d   ",n.a[i]);
			}
			break;
		case 0:
			printf("   Task finished. Do you want to continue the program? (1.Yes / 2.No): ");
			scanf("%d",&choice);
			if(choice==1){
				makeEmpty(); // dat lai Ds rong
				system("cls");
				return main();
			}
			else{
				fclose(fout);
				printf("\n   -- Thank you for using the program --");
				return 0;
			}
		default:
			printf("\n   Error choice, please choice again!");
			break;
	}
	goto tt;
}

// DINH NGHIA CAC HAM
void creatData(int b[], int n){
	for(int i=0; i<n; i++) 		b[i]=rand()%10+1; // gtri ngau nhien tu 1 -> 10
}

void writeData(char *fileName, int b[], int n){
	FILE *fw;
	fw = fopen(fileName, "w");
	fprintf(fw, "Linked list: maxsize = %d\n",n-1);
	// khong dung den ptu b[0]
	for(int i=1; i<n; i++) 		fprintf(fw, "%d   ", b[i]); // ghi tung ptu cua mang b vao file input
	fclose(fw);
}

void readData(char *fileName, int b[], int n){
	FILE *fr;
	fr = fopen(fileName, "r");
	printf("\nLink list: ");
	// khong dung den ptu b[0]
	for(int i=1; i<n; i++){
		fscanf(fr, "%d   ", &b[i]);   // doc tung ptu tu mang b
		insertTail(b[i]); // them ptu vua doc dc vao mang a
		printf("%d  ",b[i]); // in ptu vua them ra man hinh
	}
	fclose(fr);
}


void display(){
	printf("   Linked list: ");
	for(int i=1; i<=MAXSIZE; i++) 	printf("%d   ",n.a[i]);
	printf("\n");
}

void insertHead(int value){
	for(int i=n.last+1; i>=2; i--){  // dich chuyen cac ptu con lai ve cuoi mang di 1 o nho
		n.a[i]=n.a[i-1];
	}
	n.a[1]=value;
	n.last++;
}

void insertTail(int value){
	n.last++;  // tang so ptu them 1
	n.a[n.last]=value; // gan gtri cho ptu moi
}

void insertPosition(int position, int value){
	for(int i=n.last+1; i>=position+1; i--){ // dich chuyen cac ptu trong khoang[position; last] ve phia cuoi mang di 1 o nho
		n.a[i]=n.a[i-1];
	}
	n.last++; // tang so ptu them 1
	n.a[position]=value; // gan gtri co ptu moi nam tai vtri position
}

int deleteHead(){
	int value;
	value = n.a[1];
	for(int i=1; i<=n.last-1; i++){  //dich chuyen cac ptu con lai cua Ds ve dau mang di 1 o nho
		n.a[i]=n.a[i+1];
	}
	n.a[n.last]=0; // cho ptu cuoi cung bang 0 (coi nhu xoa di)
	n.last--; // giam so ptu di 1
	return value;
}

int deleteTail(){
	int value;
	value = n.a[n.last];
	n.a[n.last]=0; // cho ptu cuoi cung bang 0 (coi nhu xoa di)
	n.last--; // giam so ptu di 1
	return value;
}

int deletePosition(int position){
	int value;
	value = n.a[position];
	n.a[position]=0; // cho ptu tai vtri position bang 0 (coi nhu xoa di)
	for(int i=position; i<=n.last-1; i++){ // dich chuyen cac ptu trong khoang [positon;last] ve dau mang di 1 o nho, ptu a[position+1] da de len a[position} --> coi nhu a[position] da bi xoa di
		n.a[i]=n.a[i+1];
	}
	n.a[n.last]=0; // cho ptu cuoi bang 0 (coi nhu xoa di)
	n.last--; // giam so ptu di 1
	return value;
}

void deleteValue(int value){
	int count=0;
	for(int i=1; i<=n.last; i++){
		if(n.a[i]==value) 	count++; // dem so ptu co gtri bang value
	}
	if(count==0) 	printf("   Element %d is not exist\n",value); // khong ton tai ptu co gtri bang value
	else{
	 	for(int j=count; j>0; j--){ // xoa cac ptu co gtri value, den khi count=0 thi dung lai
	 		if(n.a[1]==value) 	deletePosition(1);
	 		else{
	 			int k=1;
	 			while(k<=n.last && n.a[k]!=value)	k++;  // khi "chua het Ds" va "chua tim thay ptu thoa man"
	 			deletePosition(k); // da tim thay ptu co gtri value tai vtri k --> xoa di
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
		if(count>1){ // co tu 2 ptu tro len co gtri trung nhau
			for(int j=count; j>1; j--){ // xoa cac ptu co gtri value, den khi count=1 thi dung lai
				if(n.a[1]==value) 	deletePosition(1);
				else{
					int k=1;
					while(k<=n.last && n.a[k]!=value) 	k++; 	// khi "chua het Ds" va "chua tim thay"
					deletePosition(k); // da tim thay ptu co gtri value tai vtri k --> xoa di
				}
			}
		}
		count=0; // dat lai count=0 de ktra ptu tiep theo trong Ds
	}
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
		deleteHead();
	}
}

