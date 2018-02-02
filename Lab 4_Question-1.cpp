#include<iostream>
using namespace std;


/* Node class to store the nodes */
class Node
{
  public:
  int data;
  Node* next;
  Node()
  {
    data=0;
    next=NULL;
  }
};


/*   Stack via Linked list   */
class StackLL
{
  public:
  Node* head;
  StackLL()
  {
    head=NULL;
  }
  void push(int num);
  void pop();
  void display();
};



/* Implementing Stack by Array */
class StackArr
{
             int stk[20];
             int top;
      public:
             StackArr()
              {
                top=-1;
              }
             void push(int x)
              {
                 if(top >  19)
                       {
                           cout <<"\n \nSTACK OVERFLOW !!!";
                           return;
                       }
                 stk[++top]=x;
                 cout <<"\nInserted " <<x<<endl;
               }
             void pop()
               {
                  if(top <0)
                   {
                         cout <<"\n \nSTACK UNDERFLOW !!!";
                         return;
                    }
                    cout <<"\nDeleted" <<stk[top--]<<endl;
                }
             void display()
               {
                   cout<<"\n \n";
                   if(top<0)
                    {
                            cout <<" EMPTY STACK !!!!";
                            return;
                    }
                    for(int i=top;i>=0;i--)
                    cout <<stk[i] <<" -> ";
                    cout<<"NULL";
                }
};


/* Implementing Queue via Array */
class QueueArr
{
              int queue1[20];
              int rear,front;
      public:
              QueueArr()
                {
                     rear=-1;
                     front=-1;
                }
              void enqueue(int x)
               {
                   if(rear >  19)
                    {
                       cout <<"\nQUEUE OVERFLOW !!!";
                       front=rear=-1;
                       return;
                    }
                    queue1[++rear]=x;
                    cout <<"\nInserted " <<x<<endl;
               }
              void dequeue()
               {
                   if(front==rear)
                     {
                         cout <<"\n \nUNDERFLOW !!!";
                         return;
                     }
                     cout <<"\n \nDeleted " <<queue1[++front];
                }
              void display()
               {
                   cout<<"\n \n";
                   if(rear==front)
                     {
                          cout <<"\n \nEMPTY !!!!";
                          return;
                     }
                   for(int i=front+1;i<=rear;i++)
                   cout <<queue1[i]<<" -> ";
                   cout<<"NULL";
               }
};

/*  Queue via linked list  */
class QueueLL
{
  public:
  Node* head;
  Node* tail;
  QueueLL()
  {
    head=NULL;
    tail=NULL;
  }
  void enqueue(int num);
  void dequeue();
  void display();
};


/*  pushing in a stack node  */
void StackLL::push(int num)
{
  Node* temp=new Node;
  temp->data=num;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp;
    return;
  }
  temp->next=head;
  head=temp;
}


/*  popping in a stack node  */
void StackLL::pop()
{
  Node* temp;
  if(head==NULL)
  { 
   cout<<"\n \nUNDERFLOW !!! The stack is empty";
   return;
  }
  temp=head;
  head=head->next;
  temp->next=NULL;
  cout<<"\n \n"<<temp->data<<" is being deleted from the stack";
  delete temp;
}


/*  displaying a stack  */
void StackLL::display()
{
  Node *curr = head;
  cout<<"\n \n";
  while (curr!=NULL)
  {
    cout << curr->data << "->" ;
    curr = curr->next;
  }
  cout << "NULL" <<endl;
}


/*  enqueuing in a queue  */
void QueueLL::enqueue(int num)
{
  Node *temp=new Node;
  temp->data=num;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp; 
  }
  else
  {
    tail->next=temp;
  }
  tail=temp;
}


/*  dequeuing a queue   */
void QueueLL::dequeue()
{
  Node* temp;
  if(head==NULL)
  {
   cout<<"\n \nQueue is empty !!!! UNDERFLOW";
   return;
  }
  temp=head;
  head=head->next;
  cout<<"\n \n"<<temp->data<<" is being deleted";
  temp->next=NULL;
  delete temp;
}


/*  displaying the queue   */
void QueueLL::display()
{
 {
  Node *curr = head;
  cout<<"\n \n";
  while (curr!=NULL)
  {
    cout << curr->data << "->" ;
    curr = curr->next;
  }
  cout << "NULL" <<endl;
 }
}

/* main function to test the codes */
int main()
{
  StackLL SLL;
  QueueLL QLL;
  StackArr SAR;
  QueueArr QAR;
  cout<<"\n \n****IMPLEMENTING STACK AND QUEUE USING ARRAY AND LINKED LIST****";
  
  /*Checking for stack and queue by linked list*/
  SLL.push(12);
  SLL.push(23);
  SLL.push(34);
  SLL.display();
  SLL.pop();
  SLL.display();
  QLL.enqueue(12);
  QLL.enqueue(23);
  QLL.enqueue(34);
  QLL.display();
  QLL.dequeue();
  QLL.display();
  
  /*Checking for stack and queue by Array*/
  SAR.push(12);
  SAR.push(23);
  SAR.push(34);
  SAR.display();
  SAR.pop();
  SAR.display();
  QAR.enqueue(12);
  QAR.enqueue(23);
  QAR.enqueue(34);
  QAR.display();
  QAR.dequeue();
  QAR.display();
  
  return 0;
}
