// Complaint list for a company

#include <iostream>
#include <string.h>
using namespace std;
// The Structure for the elements of the queue
struct node
{
	string name;
	string number;
	string description;
	node *next;
};

//Class Definition

class QueueLL
{
	private:
	node *front,*rear;
	
	public:
	QueueLL()//Defaut constructor
	{
		front=NULL;
		rear=NULL;
	}


           /* The following function (I.e.)
              strelen()
              reverse()
              palindrome()
              are used to check whether the Name entered is a palindrome or not*/
              
            // This func is used to determine the lenth of the string  
	int strlen(string c)
{           int k=0;
            
	while(c[k]!='\0')
	{
		k++;
		
	}
	return k;
}


//This func is used to reverse the string
string reverse(string c)
{
	string h;
	int j=strlen(c),k=strlen(c);
	h=c;
	j--;
	for(int i=0;i<k;i++,j--)
	{
		h[i]=c[j];//Copying in reverse element wise
	}
	return h;
}


//This func is used to check whether the name is a palindrome or not
//It compares the reverse string and the original string
int palindrome(string l)
{
	string q;
	q=reverse(l);
	int i,k=strlen(l);
	for(i=0;i<k;i++)
	{
		if(q[i]!=l[i])//Checking element wise
		{
		break;
		}
		else 
		continue;
	}

	if(i==k)
	return 1;//Returns 1 if it is a palindrome
	else
	return 0;//Returns 0 if it is not a palindrome
}

	
	/*This is the enqueue func of the queue
	  The only difference from the normal enqueue fuc of a stack is that
	  On The occurance of a palindrome name
	  Instead of adding at the rear end of the queue
	  The entry is added in the front
	  Thus the complaints with palindrome names are served first
	  LUCKY BEINGS INDEED!
	  */
	  
	void enqueue(string a,string n,string d)
	{
		node *temp=new node;
		string b;
		temp->name=a;
		temp->number=n;
		temp->description=d;
		temp->next=NULL;// A new node has been created 
		int p=palindrome(a);
		if(p==1) //Case of a palindrome
		{
		   temp->next=front;
		   front=temp;
		}
		else//case of a non palindrome
		{
		if(rear==NULL)
		{
			front=temp;
			rear=temp;
			
		}
		else
		{
			rear->next=temp;
			rear=temp;
			cout<<"\n An entry has been added to the complaint register!";//An entry has been added to the complaint register!
		}
		}
	}
	
	/* This func is used to remove an entry after service*/
	void dequeue()
	{
		node *temp=new node;
		temp=front;
		if(front==NULL)
		{
			cout<<"\n The queue is empty!";
		}
		else
		{
			front=front->next;
			cout<<"\n A complaint has been resolved and removed from the register \t The complaint named ::!"<< temp->name;
			delete temp;
			//The element at the front position is deleted
		}
	}
	
	// This func displays the Complaint register
	void display()
	{
		node *temp=new node;
		int i=1;
		temp=front;
		cout<<"\n-------------------------------------------------------"<<"\n            LIST OF COMPLAINTS               "<<"\n-------------------------------------------------------\n\n";
		
		while(temp->next!=NULL)
		{
			cout<<"Issue #"<<i;
			i++;
			cout<<"\n\t----------------------------------------------------";
			cout<<"\n\t Name         :"<< temp->name<<"\n\t Phone NUmber : "<<temp->number<<"\n\t Description  : "<<temp->description;
			cout<<"\n\t----------------------------------------------------";
			temp=temp->next;
			cout<<"\n";
		}
			cout<<"Issue #"<<i;
			cout<<"\n\t----------------------------------------------------";
			cout<<"\n\t Name         :"<< temp->name<<"\n\t Phone NUmber : "<<temp->number<<"\n\t Description  : "<<temp->description;
			cout<<"\n\t----------------------------------------------------";
		
		
	}
};
int main() {
            QueueLL a;
	int choice,again;
	string str1,str2,str3;
            cout<<"\n-------------------------------------------------------\n******************************************************* \n                  COMPLAINT REGISTER                \n*******************************************************\n-------------------------------------------------------";
            cout<<"\n Enter the initial list of five complaints: ";
            cout<<"\n Enter the Name(in Capital), Phone number and the Description of the issue for 10 complaints:";
            for(int i=0;i<10;i++)
            {
          	        	getline(cin,str1);
          	        	getline(cin,str2);
          	        	getline(cin,str3);
          	        	a.enqueue(str1,str2,str3);
        	 }
                    a.display();
            do{
            cout<<"\n--->OPTIONS<---\n";
            cout<<"1. Register Complaint\n2. Remove resolved complaint\n";
            cout<<"Enter your choice: ";
            cin>>choice;
            switch(choice){
	 case 1: cout<<"\n Enter the Name(in Capital), Phone number and the Description of the issue: ";
                     getline(cin,str1);
          	        	getline(cin,str2);
          	        	getline(cin,str3);;
	         a.enqueue(str1,str2,str3);
	         a.display();
	         break;
	 case 2: a.dequeue();
	         a.display();
	         break;
	 default: cout<<"\nError!! Wrong info\n";
      }
      cout<<"\n\n Do you want to add or delete any entry ?\n1. Yes \n2. No";
      cin>>again;
   }while(again!=2);
 
	return 0;
}
