#include<stdio.h>
#include<stdlib.h>

// CAU TRUC DU LIEU
typedef struct Node{
	int key;
	Node *left, *right;
}Tree;
Tree *root;

// NGUYEN MAU CAC HAM
void creatData(char *fileName, int a[], int n); // tao randomData luu vao file input
void readData(char *fileName, int a[], int n);  // doc randomData tu file input
void insertNode(int key); 				// chen node
void deleteNode(Node *p, Node *parent); // xoa node
Node *searchNode(int key);				// tim node
Node *searchParent(int key);			// tim node cha
void levelOrder(FILE *fout);						// duyet cay theo chieu rong
void preOrder(Node *a, FILE *fout);					// duyet cay Tien thu tu
void inOrder(Node *a, FILE *fout);					// duyet cay Trung thu tu
void postOrder(Node *a, FILE *fout);				// duyet cay Hau thu tu


int main(){
	root=NULL;
	int n, choice, key;
	int temp;
	printf("-- Exercise 17: BINARY SEARCH TREE _ NguyenDucHung --\n\n");
	printf("\nInput from file, the number of element: ");
	scanf("%d",&n);
	int a[n];
	creatData("input17.txt",a,n);
	readData("input17.txt",a,n);
	// xuat ket qua ra file output
	FILE *fout;
	//
	printf("\nPlease choose task for Binary Search Tree:");
	printf("\n  1. Insert         5. PreOrder");
	printf("\n  2. Delete         6. InOrder");
	printf("\n  3. Search         7. PostOrder");
	printf("\n  4. LevelOrder     0. Exit");
tt:	printf("\nYou choose: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			fout = fopen("output17.txt","a");
			printf(" - Insert: key = ");
			scanf("%d",&key);
			if(searchNode(key)!=NULL){
				printf("   Key %d is used, you need use another key.\n",key);
				fprintf(fout, "\nKey %d is used, you need use another key.",key);//
			}
			else{
				insertNode(key);
				printf("   Added element %d\n",key);
				fprintf(fout, "\nAdded element %d",key);//
			}
			fclose(fout);
			break;
		case 2:
			fout = fopen("output17.txt","a");
			if(root==NULL){
				printf("   Tree is empty, cannot delete.\n");
				fprintf(fout, "\nTree is empty, cannot delete.");//
			}
			else{
				printf(" - Delete: key = ");
				scanf("%d",&key);
				Node *s=searchNode(key);
				if(s==NULL){
					printf("   Node %d is not exist, canot delete.\n",key);
					fprintf(fout,"\nNode %d is not exist, canot delete.");//
				}
				else{
					Node *p=searchParent(key);
					deleteNode(s,p);
					printf("   Removed element %d\n",key);
					fprintf(fout, "\nRemoved elemet %d",key);//
				}
			}
			fclose(fout);
			break;
		case 3:
			fout = fopen("output17.txt","a");
			printf(" - Search: key = ");
			scanf("%d",&key);
			if(searchNode(key)!=NULL){
				printf("   Found key: %d\n",key);
				fprintf(fout,"\nFound key: %d",key);//
			}
			else{
				printf("   Key not found\n");
				fprintf(fout,"\nKey not found");//
			}
			fclose(fout);
			break;
		case 4:
			fout = fopen("output17.txt","a");
			printf("   LevelOrder:\n");
			fprintf(fout,"\nLevelOrder:\n");//
			if(root==NULL){
				fclose(fout);
				break;
			}
			else{
				levelOrder(fout);
				fclose(fout);
				break;
			}
		case 5:
			fout = fopen("output17.txt","a");
			printf("   PreOrder (NLR): ");
			fprintf(fout,"\nPreeOrder:\n");//
			preOrder(root,fout);
			printf("\n");
			fclose(fout);
			break;
		case 6:
			fout = fopen("output17.txt","a");
			printf("   InOrder (LNR): ");
			fprintf(fout,"\nInOrder:\n");//
			inOrder(root,fout);
			printf("\n");
			fclose(fout);
			break;
		case 7:
			fout = fopen("output17.txt","a");
			printf("   PostOeder (LRN): ");
			fprintf(fout,"\nPostOrder:\n");//
			postOrder(root,fout);
			printf("\n");
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
			printf("   Error choice, please choose again!\n");
			break;
	}
	goto tt;
}

void creatData(char *fileName, int a[], int n){
	FILE *fw = fopen(fileName,"w");
	fprintf(fw, "%d\n", n);
	for(int i=0; i<n; i++){
		a[i]=rand()%100+1;
		fprintf(fw, "%d  ", a[i]);
	}
	fclose(fw);
}

void readData(char *fileName, int a[], int n){
	FILE *fr = fopen(fileName,"r");
	for(int i=0; i<n; i++){
		fscanf(fr, "%d  ", &a[i]);
		insertNode(a[i]);
	}
	fclose(fr);
}

void insertNode(int key){
	Node *r = (Node *)malloc(sizeof(Node));
	r->key=key;
	r->left = r->right = NULL;
	if(root==NULL)	root=r;
	else{
		Node *p=root;
		while(p!=NULL){
			if(key < p->key){
				if(p->left != NULL)	p=p->left;
				else{
					p->left=r;
					p=NULL;
				}
			}
			else if(key > p->key){
				if(p->right!=NULL)	p=p->right;
				else{
					p->right=r;
					p=NULL;
				}
			}
			else	p=NULL;
		}
	}	
}

void deleteNode(Node *p, Node *parent){
	if(p->left==NULL && p->right==NULL){ // TH1. P KHONG CO CON
		if(p==root)		root=NULL;
		else{
			if(parent->left==p)		parent->left=NULL;
			if(parent->right==p)	parent->right=NULL;
		}
	}
	else if(p->left!=NULL && p->right==NULL){ // TH2.1 P CHI CO CON TRAI
		if(p==root)		root=p->left;
		else{
			if(parent->left==p)		parent->left=p->left;
			if(parent->right==p)	parent->right=p->left;
		}
	}
	else if(p->left==NULL && p->right!=NULL){// TH2.2 P CHI CO CON PHAI
		Node *temp=p;
		if(p==root)		root=p->right;
		else{
			if(parent->left==p)		parent->left=p->right;
			if(parent->right==p)	parent->right=p->right;
		}
	}
	else{ //TH3. P CO CA 2 CON
		Node *t1=p->left; // t1 la con trai cua p
		if(t1->right==NULL){ // neu t1 khong co con phai --> t1 la node phai nhat cay con trai cua p
			p->key=t1->key;
			p->left=t1->left;
		}
		else{  // neu t1 co con phai --> tim den node phai nhat
			Node *t2=t1->right;
			while(t2->right != NULL){
				t1=t2;
				t2=t2->right;
			}
			p->key=t2->key;
			t1->right=NULL;
		}
	
	}
}


Node *searchParent(int key){
	Node *p, *r, *h[1000];
	int i, front, back, count;
	h[1]=root;
	front=back=count=1;
	while(count>0){
		p=h[front];
		r=p->left; // ktra dinh Trai
		if(r!=NULL){
			if(r->key==key)	return p;
			else{
				back++;		h[back]=r; 		count++;
			}
		}
		r=p->right; // ktra dinh Phai
		if(r!=NULL){
			if(r->key==key) 	return p;
			else{
				back++; 	h[back]=r;		count++;
			}
		}
		h[front]=NULL;
		front++;
		count--;
	}
	return NULL;
}

Node *searchNode(int key){
	if(root!=NULL){
		Node *p=root;
		while(p!=NULL){
			if(key == p->key)	return p;
			else if(key < p->key)	p=p->left;
			else	p=p->right;
		}
		return NULL;	
	}
	else	return NULL;
}

void levelOrder(FILE *fout){
	int front, back, count;
	Node *p, *q, *h[1000];
	h[1]=root;
	front=back=count=1;
	while(count>0){
		q=h[front];
		printf("%3d: (",q->key);
		fprintf(fout, "\n%3d: (",q->key);//
		p=q->left; // xet dinh Trai
		if(p!=NULL){
			printf("%3d - ",p->key);
			fprintf(fout,"%3d - ",p->key);//
			back++;		h[back]=p;		count++;
		}
		else{
			printf("___ - ");
			fprintf(fout, "___ -");//
		}
		p=q->right; // xet dinh Phai
		if(p!=NULL){
			printf("%3d)\n",p->key);
			fprintf(fout,"%3d)",p->key);
			back++;		h[back]=p; 		count++;
		}
		else{
			printf("___)\n");
			fprintf(fout,"___)");//
		}
		h[front]=NULL;
		front++;
		count--;
	}
}


void preOrder(Node *a, FILE *fout){
	if(a!=NULL){
		printf("%3d ",a->key);
		fprintf(fout,"%3d",a->key);//
		preOrder(a->left,fout);
		preOrder(a->right,fout);
	}
}

void inOrder(Node *a, FILE *fout){
	if(a!=NULL){
		inOrder(a->left,fout);
		printf("%3d ",a->key);
		fprintf(fout,"%3d",a->key);//
		inOrder(a->right,fout);
	}
}

void postOrder(Node *a, FILE *fout){
	if(a!=NULL){
		postOrder(a->left,fout);
		postOrder(a->right,fout);
		printf("%3d ",a->key);
		fprintf(fout,"%3d",a->key);//
	}
}

