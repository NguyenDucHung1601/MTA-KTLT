#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define max 3 // so con toi da cua 1 node

// CAU TRUC DU LIEU
typedef struct Tree{
	int key;
	int data;
	struct Tree *c[max+1];
}Node;
Node *root; // con tro den Goc Cay

// NGUYEN MAU CAC HAM
void creatData(int a[], int n);					// tao randomData luu vao mang a
void writeData(char *fileName, int a[], int n); // ghi randomData vao file input
void readData(char *fileName, int a[], int n);  // doc randomData tu file input
void insertRoot(int key, int data); 							// tao node Root
void insertNode(int key, int data, int parentkey, int child_i); // tao cac node con chau cua Root
void creatFullTree(int a[], int n);                             // tao cay hoan chinh
void preOrder(Node *a, FILE *fout); // duyet cay Tien thu tu
void inOrder(Node *a, FILE *fout);  // duyet cay Trung thu tu
void postOrder(Node *a, FILE *fout);// duuet cay Hau thu tu
void levelOrder(FILE *fout);        // duyet cay theo Chieu rong
Node *search(int k);    // tim 1 key trong cay (tra ve con tro tim dc, neu khong tim thay thi tra ve NULL)

// Ham main
int main(){
	int choice, level ,n=0;
	root=NULL;
	printf("-- Group 2: TREE (PreOrder - InOrder - PostOrder - WidthPrint) _ NguyenDucHung --\n\n");
	do{
	printf("\nThe level of the Tree : ");   // chieu cao cua cay: tinh tu Root la 1, cac con cua Root la 2, cac chau cua Root la 3,...
	scanf("%d",&level);
	}while(level<1);
	for(int j=0; j<=level-1; j++){
		n = n + pow(3,j);  // tinh tong so node tren cay
	}
	printf("The number of nodes   : %d\n",n);
	int a[n];
	creatData(a,n);
	writeData("inputG2.txt",a,n);
	readData("inputG2.txt",a,n);
	creatFullTree(a,n);
    printf("\nPlease choose task for Tree:");
	printf("\n  1. PreOrder  (NLR)");
	printf("\n  2. InOrder   (LNR)");
	printf("\n  3. PostOrder (LRN)");
	printf("\n  4. WidthPrint");
	printf("\n  0. Exit");
tt:printf("\nYou choose: ");
	scanf("%d",&choice);
	FILE *fout;//
	switch(choice){
		case 1:
			fout = fopen("outputG2.txt","a");	
			fprintf(fout,"\n\n- PreOrder (NLR):\n");
			preOrder(root,fout);
			fclose(fout); 
			break;
		case 2:
			fout = fopen("outputG2.txt","a");
			fprintf(fout,"\n\n- InOrder (LNR):\n");
			inOrder(root,fout);
			fclose(fout);
			break;
		case 3:
			fout = fopen("outputG2.txt","a");
			fprintf(fout,"\n\n- PostOrder (LRN):\n");
			postOrder(root,fout);
			fclose(fout);
			break;
		case 4:
			fout = fopen("outputG2.txt","a");
			fprintf(fout,"\n\n- WidthPrint:\n");
			levelOrder(fout);
			fclose(fout);
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
			printf("   Error choie, please choose again!\n");
			break;
	}
	goto tt;
}

// DINH NGHIA CAC HAM

void creatData(int a[], int n){
	for(int i=0; i<n; i++) 		a[i]=rand()%1000+1;
}

void writeData(char *fileName, int a[], int n){
	FILE *fw = fopen(fileName, "w");
	fprintf(fw, "%d\n", n);
	for(int i=0; i<n; i++) 		fprintf(fw, "%d  ", a[i]);
	fclose(fw);
}

void readData(char *fileName, int a[], int n){
	FILE *fr = fopen(fileName, "r");
	for(int i=0; i<n; i++){
		fscanf(fr, "%d  ", &a[i]);
	}
	fclose(fr);
}

void insertRoot(int key, int data){
	Node *r = (Node *)malloc(sizeof(Node));
	r->key=key;	
	r->data=data;
	for(int i=1; i<=max; i++) 	r->c[i]=NULL; // r moi tao ra, chua co con, cho cac con cua no bang NULL
	root=r;
}

void insertNode(int key, int data, int parentkey, int child_i){
	Node *p;
	Node *r = (Node *)malloc(sizeof(Node));
	r->key=key;
	r->data=data;
	for(int i=1; i<=max; i++) 		r->c[i]=NULL; // r moi tao ra, chua co con, cho cac con cua no bang NULL
	p=search(parentkey);
	p->c[child_i]=r;
}

void creatFullTree(int a[], int n){
	// tao node goc (Root)
	insertRoot(0,a[0]);  
	// tao cac node con chau cua Root
	int i=1, parentkey=0;
	while(i<n){ 
			for(int child=1; child<=max; child++){
			insertNode(i, a[i], parentkey, child);
			i++;
		}
		parentkey++;
	}
}

void levelOrder(FILE *fout){ // sd Queue vong tron
	Node *p, *r, *h[1000]; // con tro, con tro, mang con tro
	int i, front, back, count; // bien chay, vtri dau Queue, vtri cuoi Queue, so ptu Queue
	h[1]=root;
	front=back=count=1;
	while(count>0){
		p=h[front];
		printf("  %3d: ( ", p->key); // in ra key
		fprintf(fout,"  %3d: ( ", p->key);//
		for(i=1; i<=max; i++){ // xet den cac con cua no
			r=p->c[i];
			if(r!=NULL){ // neu khong rong thi in ra key
				printf("%3d - ", r->key);
				fprintf(fout,"%3d - ", r->key);//
				back++;
				h[back]=r; // cho con moi ra sau Queue
				count++;
			}
			else{
				printf("___ - "); // neu rong
				fprintf(fout,"___ -");//
			}
		}
		printf(")\n");
		fprintf(fout,")\n");
		h[front]=NULL; // huy ptu dau Queue
		front++;
		count--;
	}	
}

void preOrder(Node *a, FILE *fout){
	if(a!=NULL){
		printf("  %3d. ( %d )\n", a->key, a->data);
		fprintf(fout,"  %3d. ( %d )\n", a->key, a->data );//
		for(int i=1; i<=max; i++){
			preOrder(a->c[i],fout);
		}
	}
}

void inOrder(Node *a, FILE *fout){
	if(a!=NULL){
		inOrder(a->c[1],fout);
		printf("  %3d. ( %d )\n", a->key, a->data);
		fprintf(fout,"  %3d. ( %d )\n", a->key, a->data );//
		for(int i=2; i<=max; i++){
			inOrder(a->c[i],fout);
		}
	}
}

void postOrder(Node *a, FILE *fout){
	if(a!=NULL){
		for(int i=1; i<=max; i++){
			postOrder(a->c[i],fout);
		}
		printf("  %3d. ( %d )\n",a->key, a->data);
		fprintf(fout,"  %3d. ( %d )\n", a->key, a->data );//
	}
}

Node *search(int k){ // sd Queue vong tron
	Node *p, *r, *h[1000]; // con tro, con tro, mang con tro(gom toi da 100 ptu)
	int i, front, back, count; // bien chay, vtri dau Queue, vtri cuoi Queue, so ptu Queue
	if(root==NULL)	   return NULL; // TH cay rong --> tra ve NULL
	h[1]=root; 
	front=back=count=1;
	while(count>0){
		p=h[front]; // lay p la ptu dau tien cua Queue
		if(p->key==k) 	return p; // p co key trung key can tim --> tra ve p
		for(i=1; i<=max; i++){ // neu khong, xet den cac con cua no
			r=p->c[i];
			if(r!=NULL){
				if(r->key==k) 	return r; // neu con co key trung key can tim --> tra ve r
				back++;
				h[back]=r; // dua con ra cuoi Queue
				count++;
			}
		}
		h[front]=NULL; // xoa ptu dau Queue
		front++;
		count--;
		/*  --> Moi lan xet 1 ptu*, dien tat ca cac con cua no vao duoi Queue roi xoa no khoi dau Queue */
	}
	return NULL; // khong tim thay key --> tra ve NULL
}

