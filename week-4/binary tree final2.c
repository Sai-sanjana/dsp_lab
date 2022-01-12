//displaying using queue
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define COUNT 10


struct node {
    int data;
    struct node* left_child;
    struct node* right_child;
};


struct node2
{
	int data;
	struct node *addrs_value;
	struct node2 *next;
};
struct node2 *front=NULL,*rear=NULL;

void enqueue(struct node* root3);
void dequeue();
void display();
int is_empty();


struct node* create();
struct node* create_tree(int [], int [], int , int );
void display_Inorder(struct node* node);
void display_Preorder(struct node* node);
void display_Postorder(struct node* node);
int find_index(int arr[], int strt, int end, int value);
int len;
void level_order(struct node* root2);
int find_height(struct node* node);
int arr[100],h;
//void print_tree();
void insertion(struct node *ptr, int val,int side);

void print_tree(struct node *root);
void display_tree(struct node *root, int space);





void main(){
	int i,j,ele,ch,temp=0;
	struct node* root;
	while(1){
		printf("\n\n 1.Create Binary Tree");
		printf("\n 2. calculate height");
		printf(" \n 3. Display Inorder traversal");
		printf(" \n 4. Display Preorder traversal");
		printf(" \n 5. Display Postorder traversal ");
		printf("\n 6. display tree in tree format ");
		printf(" \n  0. Exit");
		printf("\n Enter ur choice:");		
		if(scanf("%d",&ch)==1){
			if(ch==1) {
				//root = create();
					int val;
					struct node *roott;
					root= (struct node *)malloc(sizeof(struct node));
					printf("\n Enter root node value: ");
					scanf("%d",&root->data);
					root->left_child=NULL;
					root->right_child=NULL;
					//printf("\n root %d",root->data);	
					printf("\n Enter left child of %d (-1 for no node) : ",root->data);
					scanf("%d",&val);
					if(val!=-1)
					{
						insertion(root,val,1);
					}
					printf("\n Enter right child of %d (-1 for no node) : ",root->data);
					scanf("%d",&val);
					if(val!=-1)
					{
						insertion(root,val,2);
					}			
			}
			else if(ch==2){
				h=find_height(root);
				printf("\n height is %d",h);
			}
			else if (ch==3){
				printf("\n Inorder values are\n ");
				display_Inorder(root);
			}
			else if(ch==4){
				printf("\n Preorder values are\n ");
				display_Preorder(root);
			}
			else if(ch==5){
				printf("\n Postorder values are\n ");
				display_Postorder(root);
			}
			else if(ch==6){
				//level_order(root);
				//print_tree();
				 print_tree(root);
			}
			
			else if(ch==0){
				break;
			}
			else{
				printf(" \nInvalid choice.. Try again\n");
			}
		}
		else{
			printf("\n Invalid input");
			exit(0);
		}
	}
	
}


void insertion(struct node *ptr, int val,int side){
	int ele;
	struct node *ptr2;
	ptr2=(struct node*)malloc(sizeof(struct node));
	if(side==1){
		ptr->left_child=ptr2;
	}
	if(side==2){
		ptr->right_child=ptr2;
	}
	
	ptr2->data=val;
	ptr2->left_child=NULL;
	ptr2->right_child=NULL;
	
	printf("\n enter left child of %d, (-1 for no node) : ",val);
	scanf("%d",&ele);
	if(ele!=-1){
		insertion(ptr2,ele,1);
	}
	printf("\n enter right child of %d, (-1 for no node) : ",val);
	scanf("%d",&ele);
	if(ele!=-1){
		insertion(ptr2,ele,2);
	}
	
}

int find_height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lval = find_height(node->left_child);
        int rval = find_height(node->right_child);
 
        /* use the larger one */
        if (lval > rval)
            return (lval + 1);
        else
            return (rval + 1);
    }
}


void display_Inorder(struct node* node)
{
    if (node == NULL)
        return;

    display_Inorder(node->left_child);
    printf("%d ", node->data);
    display_Inorder(node->right_child);
}

void display_Preorder(struct node* node){
	 if (node == NULL)
        return;
	printf("%d ", node->data);
	display_Preorder(node->left_child);    
    display_Preorder(node->right_child);
	
}

void display_Postorder(struct node* node)
{
    if (node == NULL)
        return;

    display_Postorder(node->left_child);    
    display_Postorder(node->right_child);
    printf("%d ", node->data);
}


void display_tree(struct node* root2, int space)
{
    int i;
	if (root2 == NULL)
        return;
 
    space += COUNT; 
    display_tree(root2->right_child,space);
    printf("\n");
    for ( i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root2->data);
    display_tree(root2->left_child,space);
}
 

void print_tree(struct node* root)
{
   display_tree(root, 0);
}
 

