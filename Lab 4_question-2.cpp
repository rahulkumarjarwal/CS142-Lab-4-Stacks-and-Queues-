// Queue using stacks
#include <iostream>
using namespace std;
//Structure for the nodes
struct node
{
	int data;
	node *next;
};

//class definition for the queue
class queue
{
	private:
	node *top1,*top2;//The TOP elements for the two stacks

	public:
	
	//Default constructor
	queue()
	{
		top1=NULL;
		top2=NULL;
	}
	
	//Function to enqueue an element
	void enqueue(int val)
	{
		node *temp=new node;
		temp->data=val;
		temp->next=NULL;//A new node has been created
		if(top1==NULL)
		{
			top1=temp;
			cout<<"\n Insertion success!";
		}
		else
		{
			temp->next=top1;
			top1=temp;//THe element inserted in the front of the queue****NOTE:::ELEMENTS CAN ONLY BE INSERTED IN THE FRONT
			cout<<"\n Insertion success!";
		}
	}
	
	//function to dequeue an element
	/* In this function , the LIFO property of stack is used
	   The stack 1 is copied in reverse into stack 2
	   The top2 element of stack 2 is removed
	   Now The stack 2 is copied in reverse into stack 1
	   This now corresponds to the FIFO property of Queue
	   Thus the dequeue operation has been implemented by using stacks*/
	void dequeue()
	{
                       int m=0,n=0;
                       m=countitems1();
                       //Loop to copy stack 1 into stack 2 in reverse
                       for(int i=0;i<m;i++)
                       {
		if(top1==NULL)
		{
			cout<<"\n***ERROR*** The queue is empty!";
		}
		else
		{
			node *temp=new node;
			temp=top1;
			if(top1->next!=NULL){top1=top1->next;}//the succeeding element of top is assigned as the new top element
		            if(top2==NULL)
			{
				top2=temp;
				top2->next=NULL;
				
			}
			else
			{
				temp->next=top2;
				top2=temp;//THe element inserted in the top of the stack ****NOTE:::ELEMENTS CAN ONLY BE INSERTED IN THE TOP
				
			} 
		}
                       }	
	
	           //removing the front element
		if(top2==NULL)
		{
			cout<<"\n***ERROR*** The queue is empty!";
		}
		else
		{
			node *temp=new node;
			temp=top2;
			top2=top2->next;//the succeeding element of top is assigned as the new top element
			delete temp;//the prev top element is deleted ****NOTE:THE ELEMENTS ON THE TOP ONLY CAN BE DELETED
			cout<<"\nDeletion success!";
		}
		n=countitems2();
	            top1=NULL;
	//loop to copy stack2 into stack 1 in reverse
	for(int i=0;i<n;i++)
                       {
		if(top2==NULL)
		{
			cout<<"\n***ERROR*** The stack is empty!";
		}
		else
		{
			node *temp=new node;
			temp=top2;
			if(top2->next!=NULL){top2=top2->next;}//the succeeding element of top is assigned as the new top element
		            if(top1==NULL)
			{
				top1=temp;
				top1->next=NULL;
				
			}
			else
			{
				temp->next=top1;
				top1=temp;//THe element inserted in the top of the stack ****NOTE:::ELEMENTS CAN ONLY BE INSERTED IN THE TOP
				
			} 
		}
                       }	
	
	
	
	}
	//The function to count the number of elements in stack1
	int countitems1()
	{
		node *temp=new node;
		int x=0;
		temp=top1;
		do
		{
			x++;
			temp=temp->next;
		}while(temp->next!=NULL);
		return x+1;
	}
	//The function to count the number of elements in stack1
	int countitems2()
	{
		node *temp=new node;
		int x=0;
		temp=top2;
		do
		{
			x++;
			temp=temp->next;
		}while(temp->next!=NULL);
		return x+1;
	}
	
	

	
	void display1()
	{
		node *gamma=new node;
		gamma=top1;
		if(gamma==NULL)
		{
			cout<<"\n****ERROR**** The queue is empty!";
			
		}
		else if(gamma->next==NULL)
		{
			cout<<"\nRear-->"<<gamma->data<<"-->Front";
		}
		else
		{
			cout<<"\nRear-->";
			
			do
			{
				cout<<gamma->data<<"-->";
				gamma=gamma->next;
			}while(gamma->next!=NULL);//displaying from the top to end
			cout<<gamma->data<<"-->Front";
		}
	}
            
            	
	
};

int main() {
            queue a;
	int choice, val,again,num;
            cout<<"\n:: Queue using stacks ::\n";
            cout<<"\n Do you have the initial elements to be queued? 1. Yes 2. No";
            cin>>choice;
            switch(choice)
            {
            	case 1: cout<<"\n Enter the number of elements to be queued ";
            	        cin>>num;
            	        cout<<"\n Enter the values";
            	        for(int i=0;i<num;i++)
            	        {
            	        	cin>>val;
            	        	a.enqueue(val);
            	        }
            	        a.display1();
            	        break;
            	 case 2:cout<<"\n Please Proceed!";
            	        break;
            	 default:cout<<"\n wrong info!!";
            	 break;
            }
            do{
            cout<<"\n--->OPTIONS<---\n";
            cout<<"1. EnQueue\n2. Dequeue\n";
            cout<<"Enter your choice: ";
            cin>>choice;
            switch(choice){
	 case 1: cout<<"\nEnter the value to be insert: ";
                     cin>>val;
	         a.enqueue(val);
	         a.display1();
	         break;
	 case 2: a.dequeue();
	         a.display1();
	         break;
	 default: cout<<"\nError!! Wrong info\n";
      }
      cout<<"\n\n Do you want to edit the stack ?\n1. Yes \n2. No";
      cin>>again;
   }while(again!=2);

	return 0;
}
