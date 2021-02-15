#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
	int hd;//for the topview part for knowing whether the node is visited or not;
}node;

node* createNode(int value)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->left=NULL;
	temp->right=NULL;
	temp->data=value;

	return temp;
}

node *root=NULL;

void insertnode(int value)
{
	node *temp=createNode(value);
	
	node *p=root;
	node *pp=NULL;
	
	while(p)
	{
		pp=p;
		if(p->data < value)
		{
			p=p->right;
		}
		else
		{
			p=p->left;
		}
	}
	if(p==root)
	{
		root=temp;
	}
	else{
		if(pp->data < value)
		{
			pp->right=temp;
		}
		else{
			pp->left=temp;
		}
	}
}

void search_tree(int ele)
{
	node *p=root;
	
		
	if(p==NULL)
	{
		cout<<"No tree is being constructed\n";
		return;
	}
	else
	{
		while(p)
		{
			
			if(p->data==ele)
			{
				cout<<"Element found\n";
				return;
			}
			else if(p->data<ele)
			{
				p=p->right;
			}
			else{
				p=p->left;
			}		
		}
		cout<<"Element not found\n";
		return;
	}
	
}

void delete_node(int key)
{
	node *current_node=root;
	node *prev=NULL;
	
	while(current_node!=NULL && current_node->data!=key)
	{
		prev=current_node;
		if(key<current_node->data)
		{
			current_node=current_node->left;
		}
		else
		{
			current_node=current_node->right;
		}
	}
	if(current_node==NULL)
	{
		cout<<"Key not found ";
		return;
	}
	
	//case 1&2 0 child or 1 child;
	if(current_node->left==NULL || current_node->right==NULL)
	{
		node *nextchild;
		
		if(current_node->left==NULL)
		{
			nextchild=current_node->right;
		}
		if(current_node->right==NULL)
		{
			nextchild=current_node->left;
		}
		
		if(prev==NULL)
		{
			//it indiacates that the node to deleted is root;
			root=nextchild;
			return;
		}
		
		if(current_node==prev->left)
		{
			prev->left=nextchild;
		}
		else{
			prev->right=nextchild;
		}
		
		free(current_node);
		return;
	}
	else
	{
		//here it indicates that it has two children;
		//so get the inorder successor of the node;
		//go to right and traverse to complete left;
		
		node *temp=current_node->right;
		node *p=NULL;
		
		while(temp->left)
		{
			p=temp;
			temp=temp->left;
		}
		
		if(p!=NULL)
		{
			//it indicates that there is some bottom tree stuff after the right child;
			p->left=temp->right;
		}
		else
		{
			current_node->right=temp->right;
		}
		
		current_node->data=temp->data;
		free(temp);
		return;
		
	}
	
}
	
	
		
	
void inorder(node *x)
{
	//l,key,r;
	if(x==NULL)
	{
		return;
	}
	else{
		inorder(x->left);
		cout<<x->data<<" ";
		inorder(x->right);
	}
}

void preorder(node *x)
{
	//key,l,r;
	if(x==NULL)
	{
		return;
	}
	else{
		cout<<x->data<<" ";
		preorder(x->left);
		preorder(x->right);
	}
}

void postorder(node *x)
{
	//l,r,key;
	if(x==NULL)
	{
		return;
	}
	else{
		preorder(x->left);
		preorder(x->right);
		cout<<x->data<<" ";
	}
}

void levelorder(node *x)
{
	if(x==NULL)
	{
		return;
	}
	queue<node *> q;
	
	q.push(x);
	
	
	
	//doing bfs level order for the tree;
	
	while(q.empty()==false)
	{
		node *temp=q.front();
		
		//deque;
		q.pop();
		
		
		cout<<temp->data<<" ";
		
		//now enque;
		
		if(temp->left!=NULL)
		{
			q.push(temp->left);
		}
		if(temp->right!=NULL)
		{
			q.push(temp->right);
		}
	}
}

int height(node *temp)
{
	if(temp==NULL)
	{
		return 0;
	}
	int l=1;
	int r=1;
	if(temp->left!=NULL)
	{
		l=l+height(temp->left);
	}
	if(temp->right!=NULL)
	{
		r=r+height(temp->right);
	}
	if(l<=r)
	{
		return r;
	}
	else{
		return l;
	}
}

//for the right view of the tree we need to take the last element in the level order traversal;

void printRightView(node *temp)
{
	if(temp==NULL)
	{
		return;
	}
	
	//here we use list so we can get the number of nodes at a particular level easily;
	
	int i=0;
	list<node *> mqueue;
	mqueue.push_back(temp); //here the first temp will be the root node;
	
	while(mqueue.empty()==false)
	{
		int size=mqueue.size();
		i=0;
		while(i++<size)
		{
			node *current=mqueue.front();
			mqueue.pop_front();
			
			if(i==size)
			{
				cout<<current->data<<" ";
			}
			if(current->left!=NULL)
			{
				mqueue.push_back(current->left);
			}
			if(current->right!=NULL)
			{
				mqueue.push_back(current->right);
			}
		}
	}
}

void printTopView(node *Root)
{
	if(Root==NULL)
	{
		return;
	}
	
    queue<node *> q;
	
	map<int,int> m;
	
	int hd=0;
	
	Root->hd=hd;
	
	q.push(Root);
	
	
	//do a level order traversal and while going to the left do hd-1 and going to the right do hd+1; we need to print the first nodes in the vertical order traversal;
	while(q.empty()==false)
	{
		hd=Root->hd;
		
		if(m.count(hd)==0)
		{
			m[hd]=Root->data;
		}
		
		//in the above check the first node in the vertical traversal;
		
		if(Root->left)
		{
			Root->left->hd=hd-1;
			q.push(Root->left);
		}
		if(Root->right)
		{
			Root->right->hd=hd+1;
			q.push(Root->right);
		}
		q.pop();
		Root=q.front();
	}
	for(auto i=m.begin();i!=m.end();i++)
	{
		cout<<i->second<<" ";
	}
		
	
}
	
//mirror of a tree can be done in two ways; recursive and iterative;
//in iterative way do level order traversal; at each node that we get from the queue swap the left and right nodes;

void mirror(node *currentnode)
{
	if(currentnode==NULL)
	{
		return;
	}
	node *temp;
	mirror(currentnode->left);
	mirror(currentnode->right);
	
	//swap the two nodes;
	temp=currentnode->left;
	currentnode->left=currentnode->right;
	currentnode->right=temp;
}
			
	
	
	
	
	

int main()
{
	
	int n;
	cout<<"Enter the number of nodes u want to enter\n";
	cin>>n;
	
	cout<<"Enter the "<<n<<" nodes\n";
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	for(int i=0;i<n;i++)
	{
		insertnode(arr[i]);
	}
	
	
	//for searching a value in bst;
	
	int ele_search;
	cout<<"\nEnter the element that you want to search\n";
	cin>>ele_search;
	
	search_tree(ele_search);
	
	int ele_delete;
	cout<<"\nEnter the element that yu want to delete\n";
	cin>>ele_delete;
	delete_node(ele_delete);
	
	cout<<"\nInorder:\n\n";
	inorder(root);
	
	cout<<"\n\nPreOrder:\n";
	preorder(root);
	
	cout<<"\n\nPostOrder:\n";
	postorder(root);
	
	cout<<"\n\nLevelOrder:\n";
	levelorder(root);
	
	cout<<"\n Height of the tree is:"<<height(root);
	
	cout<<"\nRight view of tree is:";
	printRightView(root);
	
	cout<<"\nTop view of the tree is:";
	printTopView(root);
	
	cout<<"\nMirror tree;now tree gets changed:";
	mirror(root);
	inorder(root);
	
	return 0;
}