//program for avl tree insetion , deletion , inorder, preorder, post order, level order, sum of level sub tree
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// An AVL tree node
struct Tree_node
{
    int value;
    struct Tree_node *left;
    struct Tree_node *right;
    int length;
};

struct Queue_Node
{
	int data;
	struct Tree_node *addrs_value;
	struct Queue_Node *next;
};
struct Queue_Node *front=NULL,*rear=NULL;



int high_val(int x, int y);
int length(struct Tree_node *N);
struct Tree_node* newNode(int value);
struct Tree_node *rightRotate(struct Tree_node *y);
struct Tree_node *leftRotate(struct Tree_node *x);
int balance_factor(struct Tree_node *N);
struct Tree_node* insertion(struct Tree_node* node, int value);
struct Tree_node * minValueNode(struct Tree_node* node);
struct Tree_node* deleteNode(struct Tree_node* root, int value);
void pre_order(struct Tree_node *root);
void in_order(struct Tree_node *root);
void post_order(struct Tree_node *root);


void enqueue(struct Tree_node* root3);
int is_empty();
void dequeue();
void level_order(struct Tree_node* root2);

int sum_sub_tree(struct Tree_node* l);



void main(){
	int ch,val,sum;
	struct Tree_node *root = NULL;
	while(1){
		printf("\n 1. Insertion in to AVL tree ");
		printf("\n 2. Deletion from AVL tree");
		printf("\n 3. Display Inorder ");
		printf("\n 4. Display Preorder");
		printf("\n 5. Display Postorder");
		printf("\n 6. Display Level order");
		printf("\n 7. Sum of left sub tree");
		printf("\n 0. Exit");
		printf("\n\n Enter ur choice: ");
		if(scanf("%d",&ch)==1){
			if(ch==1){
				//insertion
				printf("\n Enter value to be inserted: ");
				scanf("%d",&val);
				root = insertion(root,val);
			}
			else if(ch==2){
				//Deletion
				printf("\n Enter value to be deleted: ");
				scanf("%d",&val);
				root = deleteNode(root, val);
			}
			else if(ch==3){
				//inorder
				in_order(root);
			}
			else if(ch==4){
				//preorder
				pre_order(root);
			}
			else if(ch==5){
				//postorder
				post_order(root);
			}
			else if(ch==6){
				//level order
				level_order(root);
			}
			else if(ch==7){
				//sum of left sub tree
				if((root->left)!=NULL){
					sum = sum_sub_tree(root->left);
					printf("\n sum of left sub tree value is %d\n",sum);
				}
				else{
					printf("\n Tree doesnt have left sub tree...\n");
				}
			}
			else if(ch==0){
				break;
			}
			else{
				printf("\n Wrong choice... Try again...!!!");
			}
		}
		else{
			printf("\n Invalid choice... !!!");
			exit(0);
		}
	}
}


int length(struct Tree_node *N)
{
    if (N == NULL)
        return 0;
    return N->length;
}

int high_val(int x, int y)
{
    return (x > y)? x : y;
}

struct Tree_node* newNode(int value)
{
    struct Tree_node* node = (struct Tree_node*) malloc(sizeof(struct Tree_node));
    node->value   = value;
    node->left   = NULL;
    node->right  = NULL;
    node->length = 1;
    return(node);
}

struct Tree_node *rightRotate(struct Tree_node *y)
{
    struct Tree_node *x = y->left;
    struct Tree_node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->length = high_val(length(y->left), length(y->right))+1;
    x->length = high_val(length(x->left), length(x->right))+1;

    // Return new root
    return x;
}

// A function to left rotate subtree rooted with x
struct Tree_node *leftRotate(struct Tree_node *x)
{
    struct Tree_node *y = x->right;
    struct Tree_node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->length = high_val(length(x->left), length(x->right))+1;
    y->length = high_val(length(y->left), length(y->right))+1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int balance_factor(struct Tree_node *N)
{
    if (N == NULL)
        return 0;
    return length(N->left) - length(N->right);
}

struct Tree_node* insertion(struct Tree_node* node, int value)
{
    if (node == NULL)
        return(newNode(value));

    if (value < node->value)
        node->left  = insertion(node->left, value);
    else if (value > node->value)
        node->right = insertion(node->right, value);
    else // Equal keys not allowed
        return node;

    /*  Update length of this ancestor node */
    node->length = 1 + high_val(length(node->left), length(node->right));

    /*  Get the balance factor of this ancestor to check whether this node became unbalanced */
    int balance = balance_factor(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && value < node->left->value)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && value > node->right->value)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && value > node->left->value)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->value)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

/* Given a non-empty binary search tree, return the node with minimum value value found in that tree. */
struct Tree_node * minValueNode(struct Tree_node* node)
{
    struct Tree_node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Recursive function to delete a node with given value
// from subtree with given root. It returns root of
// the modified subtree.
struct Tree_node* deleteNode(struct Tree_node* root, int value)
{

    if (root == NULL)
        return root;

    // If the value to be deleted is smaller than the root
    if ( value < root->value )
        root->left = deleteNode(root->left, value);

    // If the value to be deleted is greater than the root
    else if( value > root->value )
        root->right = deleteNode(root->right, value);

    // if value is same as root's value
    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Tree_node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
            *root = *temp;
            free(temp);
        }
        else
        {
            // node with two children
            struct Tree_node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->length = 1 + high_val(length(root->left), length(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = balance_factor(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && balance_factor(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && balance_factor(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && balance_factor(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && balance_factor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


void pre_order(struct Tree_node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->value);
        pre_order(root->left);
        pre_order(root->right);
    }
}


void in_order(struct Tree_node *root)
{
    if(root != NULL)
    {
        in_order(root->left);
		printf("%d ", root->value);
        in_order(root->right);
    }
}


void post_order(struct Tree_node *root)
{
    if(root != NULL)
    {
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->value);
    }
}



void level_order(struct Tree_node* root2){
	struct Tree_node* current;
	if(root2 == NULL) return;

	enqueue(root2);
	while(is_empty()){
		current = front->addrs_value;
		printf("\t %d",current->value);
		if(current->left != NULL){
			enqueue(current->left);
		}
		if(current->right != NULL){
			enqueue(current->right);
		}
		dequeue();
	}
}


void enqueue(struct Tree_node* root3){
	struct Queue_Node *ptr;
	ptr=(struct Queue_Node *)malloc(sizeof(struct Tree_node));
	if(front==NULL){
		front=ptr;
		rear=ptr;
		ptr->addrs_value=root3;
		ptr->data=root3->value;
		ptr->next=NULL;
	}
	else{
		ptr->addrs_value=root3;
		ptr->data=root3->value;
		ptr->next=NULL;
		rear->next=ptr;
		rear=ptr;
		rear->next=NULL;
	}
}

int is_empty(){
	if(front==NULL) return 0;
	return 1;
}


void dequeue(){
	struct Queue_Node *ptr;
	if(front==NULL)
	printf("\nQueue is empty");
	else{
		ptr=front;
		//printf("\n deleted element is %d", ptr->data);
		front=ptr->next;
		free(ptr);
		//return ptr;

	}
}


int sum_sub_tree(struct Tree_node* l){
	int sum1,sum2,res;
	if(l!=NULL){
		sum1=sum_sub_tree(l->left);
		sum2=sum_sub_tree(l->right);
		res = (sum1+sum2+(l->value));
		return res;
	}
	else
	{
		return 0;
	}

}

