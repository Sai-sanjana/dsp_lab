//program for n ary tree

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Word
{
	//level1
	char root_name[10];
	struct Category *child;
};

struct Word *root;

struct Category
{
	//level2
	char cat_name[20];
	struct Category *sibling;
	struct Sub_word *word_ptr;
};

struct Category *cat;

struct Sub_word
{
	//level3
	char word_name[20];
	int word_count;//level4
	struct Sub_word *next;
};


struct Category * find_category(char *term);
void insert_category(struct Category *c1);
struct Sub_word * find_word(char *term);
void display_word(struct Category *);
struct Category * create_category();
void insert_word(struct Category *);
void descending_order();
void display_leaf();
void degree();
void depth();


void main()
{
	int ch,flag=0;
	char term[100]={};
	root = (struct Word*)malloc(sizeof(struct Word)); //creating root
	strcpy(root->root_name,"rootword");
	root->child= NULL;
	struct Category *c2;
	
	while(1)
	{
		printf("\n\n\n-----------------------------------------------------------");
		printf("\n\n\n welcome to n ary \n");
		printf("\n 1. create category");
		printf("\n 2. insert word");
		printf("\n 3. display");
		printf("\n 4. display only leaf node");
		printf("\n 5. depth of a node ");
		printf("\n 6. degree of node ");
		printf("\n 7. display words in frequency descesnding order ");
		printf("\n 0. Exit\n");
		printf("\n Enter ur choice : ");
		scanf("%d",&ch);
		if(ch==1)
		{
			if(flag==0){
				cat = create_category();
				root->child= cat;
				flag=1;
				printf("\n 1st Category created successfully !!!");
			}
			else
			{
				insert_category(cat);
			}			
		}
		else if(ch==2)
		{
			printf("\n In to which category do you want to insert word : ");
			scanf("%s",term);
			c2 = find_category(term);
			if(c2==NULL)
			{
				printf("\n Category not found.. Insert the category..");
			}
			else
			{
				insert_word(c2);
			}
		}
		else if(ch==3)
		{
			display_word(cat);
		}
		else if(ch==4)
		{
			//display only leaf
			display_leaf();
		}
		else if(ch==5)
		{
			//depth
			depth();
		}
		else if(ch==6)
		{
			//degree of a node
			degree();		
		}
		else if(ch==7)
		{
			//words in frequency descending order
			descending_order();
			
		}
		else if(ch==0)
		{
			break;
		}
	
	
	}
}


struct Category * create_category()  //fuction to create 1st category
{
	char phrase[100];
	struct Category *c1;
	c1 = (struct Category*)malloc(sizeof(struct Category));
	printf("\n Enter 1st category name : ");
	scanf("%s",phrase);
	strcpy(c1->cat_name,phrase);
	c1->sibling = NULL;
	c1->word_ptr = NULL;
	return c1;
	
}

void insert_category(struct Category *c1) // function to insert category 
{
	int flag=0;
	char phrase[100];
	struct Category *c2;
	c2 = root->child;
	printf("\n Enter Category name to be created : ");
	scanf("%s",phrase);
	while(c2!=NULL)
	{
		if(strcmp(c2->cat_name,phrase)==0)    //checking if category is already present or not
		{
			flag=1;
			printf("\n Category already present...!!!");
			return;
		}
		c2=c2->sibling;
	}
	c2 = (struct Category *)malloc(sizeof(struct Category));  //creating a new category
	strcpy(c2->cat_name,phrase);
	c2->sibling = NULL;
	c2->word_ptr=NULL;	
	if(c1->sibling==NULL)
	{
		c1->sibling=c2;
	}
	else
	{
		while(c1->sibling!=NULL)
		{
			c1=c1->sibling;
		}
		c1->sibling=c2;
	}
	printf("\n New category inserted sucessfully !!!");
	
}


void insert_word(struct Category * c1)  //function for inserting a word in to given category
{
	int f,flag=0;
	if(c1 == NULL)
	return;
	
	struct Sub_word *w1,*w2;
	w1 = (struct Sub_word*)malloc(sizeof(struct Sub_word));
	char phrase[100]={};
	printf("\n Enter word to be inserted in to category %s: ",c1->cat_name);
	scanf("%s",phrase);
	if(c1->word_ptr==NULL){    	// creating 1st word
		c1->word_ptr=w1;
		strcpy(w1->word_name,phrase);
		w1->word_count = 1;
		w1->next = NULL;
		printf("\n In this category first node is created...!!!");
	}
	else
	{
		//checking if word is already present or not
		w2=c1->word_ptr;
		while((w2!=NULL))
		{
			if(strcmp(w2->word_name,phrase)==0)
			{
				flag=1;//word is present
				f = ++(w2->word_count);
				printf("\n Word already present, its frequency is updated to %d",f);
				break;
			}
			w2=w2->next;
		}
		if(flag==0)
		{
			//word is not present, create a new word
			w2=c1->word_ptr;
			while((w2->next!=NULL)) // to get last position for insertion
			{
				if(strcmp(w2->word_name,phrase)==0)
				{
					break;
				}
				w2=w2->next;
			}
			w2->next = w1;
			strcpy(w1->word_name,phrase);
			w1->word_count = 1;
			w1->next = NULL;
			printf("\n New word inserted sucessfully... !!!");
		}
	}	
}



void display_word(struct Category *c1)  // fucntion to display all categories and words 
{
	printf("\n\n Root node value  is rootword");
	while(c1!=NULL)
	{	
		printf("\n\n Printing words inside category %s",c1->cat_name);
		if(c1->word_ptr==NULL){
			printf("\n No words inside this category\n");
		}
		else
		{
			struct Sub_word *w1;
			w1=c1->word_ptr;
			while(w1!=NULL)
			{
				printf("\n word name : %s",w1->word_name);
				printf("\n word count : %d",w1->word_count);
				w1=w1->next;
				
			}
			
		}
		c1=c1->sibling;
	}
}




void depth()    // function to calculate depth of a node, depth is distance of a node from root 
{
	char phrase[100]={};
	int i,j;
	printf("\n Enter node value : ");
	scanf("%s",phrase);
	if(!strcmp(phrase,"rootword")) //depth of root node is zero
	{
		printf("\n depth is 0, it it root word");
	}
	else if ((find_category(phrase))!=NULL)		// depth of category is 1 because category is child of root
	{
		printf("\n depth of %s is 1, it is category",phrase);
	}
	else if ((find_word(phrase))!=NULL)   //depth of word is 2, because word is direct child of catrgory
	{
		printf("\n depth of %s is 2, it is word",phrase);
	}
	else
	{
		printf("\n given node is not present");
	}
}


struct Category * find_category(char *term)    //function to know if given category is present or not
{
	int flag=0;
	struct Category *c1;
	c1=root->child;
	while(c1!=NULL)
	{
		if(strcmp(c1->cat_name,term)==0)
		{
			flag=1;
			return c1;
		}
		c1=c1->sibling;
	}
	if(flag==0)
	{
		return NULL;
	}
}




struct Sub_word * find_word(char *term)  // function to find wheather given word is present or not
{
	int flag=0;
	struct Category *c1;
	struct Sub_word *w1;
	c1=root->child;
	while(c1!=NULL)
	{
		w1=c1->word_ptr;
		while(w1!=NULL)
		{
			if(strcmp(w1->word_name,term)==0)
			{
				flag=1;
				return w1;
			}
			w1=w1->next;
		}
		c1=c1->sibling;
	}
	return NULL;
}


void degree()	 //function to find the degree of a node, degree is number of children a node contains
{
	char phrase[100]={};
	int i,j,count;
	struct Category *c1;
	struct Sub_word *w1;
	printf("\n Enter node value : ");
	scanf("%s",phrase);
	if(!strcmp(phrase,"rootword"))	 	// if it is root node, degree is number of categories
	{
		c1=root->child;
		while(c1!=NULL)
		{
			count++;
			c1=c1->sibling;
		}		
		printf("\n degree of root word is %d ",count);				
	}
	else if ((c1=(find_category(phrase)))!=NULL) 	// if it category, degree is number of words inside that category
	{
		w1=c1->word_ptr;
		while(w1!=NULL)
		{
			count++;
			w1=w1->next;
				
		}
		printf("\n degree of %s is %d, ",phrase,count);
	}
	else if ((w1=find_word(phrase))!=NULL)   //word contains a degree only if its frequency is greater than 1
	{
		if(w1->word_count>1) 
		{
			printf("\n degree of %s is 1\n",phrase);
		}
		else
		{
			printf("\n It is the leaf node, it do not have any children\n");
		}
	}
	else
	{
		printf("\n given node is not present");
	}
	
}

void descending_order()  //a function to display words in desecending order
{
	int max;
	struct Category *c1;
	struct Sub_word *w1;
	c1=root->child;
	w1=c1->word_ptr;
	max=w1->word_count;
	while(c1!=NULL)   // calculating maximun word count
	{
		w1=c1->word_ptr;
		while(w1!=NULL)
		{
			if(w1->word_count>max)
			{
				max=w1->word_count;
			}
			w1=w1->next;
		}
		c1=c1->sibling;
	}
	

	while(max)   //displaying words in frequency desecending order
	{
		c1=root->child;
		w1=c1->word_ptr;
		while(c1!=NULL)
		{
			w1=c1->word_ptr;
			while(w1!=NULL)
			{
				if(w1->word_count==max)
				{
					printf("\n frequency - %d \t word -  %s  ",w1->word_count,w1->word_name);
				}
				w1=w1->next;
			}
			c1=c1->sibling;
		}
		max--;		
	}
	
}


void display_leaf()
{
	//display leaf nodes excluding level 4
	struct Category *c1;
	struct Sub_word *w1;
	c1=root->child;
	printf("\n\n leaf nodes are: ");
	while(c1!=NULL)
	{
		if(c1->word_ptr == NULL)
		{
			//if category is leaf node , category doesnt have any children
			printf("\n %s",c1->cat_name);
		}
		else
		{
			//category is not leaf, it has children
			w1=c1->word_ptr;
			while(w1!=NULL)
			{
				if(w1->word_count == 1)
				{
					// it is leaf node because its frequency is just one
					printf("\n %s",w1->word_name);
				}
				w1=w1->next;
			}			
		}
		c1=c1->sibling;	
	}
}




