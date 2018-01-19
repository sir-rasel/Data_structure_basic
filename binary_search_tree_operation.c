#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct node *left;
    struct node *right;
}node;

node *root=NULL;

node* getnode(int data);
node* insert(node *p,int data);
node* Delete(node *root, int data);
void display(node *p,int data);
void preorder(node *p);
void postorder(node *p);
void inorder(node *p);
int search(node *p,int data);
int findmin(node *p);
int findmax(node *p);
int hieght(node *p);

int main(){
    int choice,i,n,data,count=1;
    while(1){
        printf(" 1.INSERT\n 2.REMOVE\n 3.DISPLAY\n 4.SEARCH\n");
        printf(" 5.MINIMUM\n 6.MAXIMUM\n 7.HIEGHT\n ANY KEY TO EXIT\n ENTER YOUR CHOICE: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("How many node: ");
            scanf("%d",&n);
            for(i=0;i<n;i++){
                printf("Give data: ");
                scanf("%d",&data);
                root=insert(root,data);
            }
            break;
        case 2:
            printf("Give data be deleted: ");
            scanf("%d",&data);
            root=Delete(root,data);
            break;
        case 3:
            printf("\t1.Preorder\n\t2.Postorder\n\tAny to Inorder: ");
            scanf("%d",&data);
            printf("Nodes are: ");
            display(root,data);
            printf("\n");
            break;
        case 4:
            printf("Give data be searched: ");
            scanf("%d",&data);
            if(search(root,data)) printf("Found\n");
            else printf("Not-Found\n");
            break;
        case 5:
            printf("Minimum value is: %d\n",findmin(root));
            break;
        case 6:
            printf("Maximum value is: %d\n",findmax(root));
            break;
        case 7:
            printf("Hieght of tree is: %d\n",hieght(root));
            break;
        default:
            count=0;
            break;
        }
        if(count==0) break;
    }
    return 0;
}

node* getnode(int data){
    node *p=(node*)malloc(sizeof(node));
    p->data=data;
    p->left=p->right=NULL;
    return p;
}
node* insert(node *p,int data){
    if(p==NULL){
        p=getnode(data);
    }
    else if(p->data<=data){
        p->right=insert(p->right,data);
    }
    else{
        p->left=insert(p->left,data);
    }
    return p;
}
void display(node *p,int data){
    if(data==1) preorder(p);
    else if(data==2) postorder(p);
    else inorder(p);
}
void preorder(node *p){
    if(p!=NULL){
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}
void postorder(node *p){
    if(p!=NULL){
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }
}
void inorder(node *p){
    if(p!=NULL){
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}
int search(node *p,int data){
    if(p==NULL) return 0;
    else if(p->data==data) return 1;
    else if(p->data<=data){
        search(p->right,data);
    }
    else search(p->left,data);
}
int findmin(node *p){
    if(p==NULL){
        printf("Empty Tree\n");
        return -1;
    }
    else if(p->left==NULL){
        return p->data;
    }
    else return findmin(p->left);
}
int findmax(node *p){
    if(p==NULL){
        printf("Empty Tree\n");
        return -1;
    }
    else if(p->right==NULL){
        return p->data;
    }
    else return findmax(p->right);
}
int hieght(node *p){
    int ll,lr;
    if(p==NULL){
        return -1;
    }
    ll=hieght(p->left);
    lr=hieght(p->right);
    if(ll>lr) return ll+1;
    else return lr+1;
}
node* Delete(node *root, int data) {
	if(root == NULL) return root;
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) {
			free(root);
			root = NULL;
		}
		//Case 2: One child
		else if(root->left == NULL) {
			node *temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL) {
			node *temp = root;
			root = root->left;
			free(temp);
		}
		// case 3: 2 children
		else {
			int temp = findmin(root->right);
			root->data = temp;
			root->right = Delete(root->right,temp);
		}
	}
	return root;
}
