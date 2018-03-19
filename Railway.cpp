//============================================================================
// Name        : Rails.cpp
// Author      : Pragya Gupta
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<cstdlib>
#include<string>
#include<string.h>
#include<cstdio>
using namespace std;

class node
{
private:
        int n;
        bool b;
        int a;
        char s;
        node *next,*prev;
public:
       node()
       {
         n = 0;
         b = 0;
         next = NULL;
         prev = NULL;
       }
       friend class list;
};


class list
{
private:
        int i,j,x,ag;
		char sx;
		int z;
        node *head[6];
public:
       list()
       {
         for(i=0;i<6;i++)
         {
           head[i] = NULL;
         }
       }
       void create();
       void book();
       void del();
       void print();
       int genderCheck(char sx);
 };

 int list::genderCheck(char sx){
   if(sx=='m')
    return 0;
   else if(sx=='f')
    return 1;
    else
    return -1;
 }


 void list::create()
 {
   node *temp;
   temp = new node;
   temp->next = NULL;
   temp->prev = NULL;
   for(i=0;i<6;i++)
   {
     for(j=0;j<4;j++)
     {
       if(head[i]==NULL)
       {
         node *m ;
         m = new node;
         m->next = NULL;
         m->prev = NULL;
         m->b = 0;
         head[i] = m;
       }
       else if(j==3)
       {
         temp = head[i];
         while(temp->next!=NULL)
         {
           temp = temp->next;
         }
         node *m;
         m = new node;
         m->next = NULL;
         m->prev = NULL;
         m->b = 0;
         temp->next = m;
         m->prev = temp;
         m->next = head[i];
         head[i]->prev = m;
       }
       else
       {
        temp = head[i];
        while(temp->next!=NULL)
        {
          temp = temp->next;
        }
        node *m;
        m = new node;
        m->b = 0;
        temp->next = m;
        m->prev = temp;
       }
     }
   }
   node *curr;
   curr = new node;
   int count = 1;
   for(i=0;i<6;i++)
   {
     curr = head[i];
     for(j=0;j<4;j++)
     {
       curr->n = count;
       curr = curr->next;
       count++;
     }
   }
 }



   void list::book()
   {
     cout<<"Enter the SEAT N.O. : ";
     cin>>x;
     cout<<"Enter your AGE : ";
     cin>>ag;
     cout<<"Enter your GENDER(m/f) : ";
     cin>>sx;
     int z=genderCheck(sx);
     int v;
     if(x%4==0)
     {
       v = (x-1)/4;
     }
     else
     {
       v = x/4;
     }
     node *temp;
     temp = new node;
     temp->next = NULL;
     temp->prev = NULL;
     temp = head[v];
     for(j=0;j<4;j++)
     {
       if(temp->n==x)
       {
         if(temp->b==0)
         {
           if(ag>50&&(temp->n==1||temp->n==2||temp->n==5||temp->n==6))
           {
            temp->b = 1;
            cout<<"\n\tSEAT has been BOOKED\n\n";
            break;
		   }
           else if(ag<50&&(temp->n==1||temp->n==2||temp->n==5||temp->n==6))
           {
             cout<<"\tSEAT IS RESERVED FOR ELDER PEOPLE\n\n";
            break;
		   }
           if((z==0)&&(temp->n==3||temp->n==4||temp->n==7||temp->n==8))
           {
             cout<<"\tSEAT has been RESERVED FOR WOMEN\n\n";
             break;
		   }
		   else if(z==-1){
		   	cout<<"ENTER VALID CHARACTER\n";
		    break;
		   }

           else if(ag<50&&(temp->n!=1||temp->n!=2||temp->n!=3||temp->n!=4||temp->n!=5||temp->n!=6||temp->n!=7||temp->n!=8))
           {
             temp->b = 1;
             cout<<"\tSEAT has been BOOKED\n\n";
             break;
		   }
           else if((z==1)&&(temp->n==3||temp->n==4||temp->n==7||temp->n==8))
           {
             temp->b = 1;
             cout<<"\tSEAT has been BOOKED\n\n";
             break;
		   }
		   else if(z==-1){
		    cout<<"ENTER VALID CHARACTER\n";
			break;
		   }
           /*else*/
         }
         else if(temp->b==1)
         {
           cout<<"SORRY !! SEAT has been ALREADY BOOKED!!\n";
         }
         temp = temp->next;
       }
       else
       {
         temp = temp->next;
       }
     }
   }


   void list::del()
   {
     int w;
     cout<<"Enter the BOOKED SEAT N.O. : ";
     cin>>x;
     if(x%4==0)
     {
       w = (x-1)/4;
     }
     else
     {
       w = x/4;
     }
     node *curr,*d;
     curr = new node;
     curr =  head[w];
     for(j=0;j<4;j++)
     {
       if(curr->n==x)
       {
         if(curr->b==1)
         {
           curr->b = 0;
           cout<<"\n\tYour booking has been CANCELLED\n";
         }
         else
         {
           cout<<"\n\tSEAT has NOT been BOOKED!!\n";
         }
         break;
       }
       else
       {
         curr = curr->next;
       }
     }
   }



   void list::print()
   {
   	 cout<<"\n  *WELCOME TO INDIAN BUS SERVICES*\n\n";
     node *curr;
     for(i=0;i<6;i++)
     {
       curr = head[i];
       for(j=0;j<4;j++)
       {
         if(curr->b==0)
         {
          cout<<curr->n<<"\t";
          if((j%2)!=0)
          {
            cout<<"\t";
          }
         }
         else if(curr->b==1)
         {
           cout<<"-\t";
           if((j%2)!=0)
           {
             cout<<"\t";
           }
         }
         curr = curr->next;
       }
       cout<<endl;
     }
     cout<<endl;
     cout<<"SEAT N.O. - 3,4,7,8 is RESERVED FOR WOMEN\nSEAT N.O. - 1,2,5,6 is RESERVED FOR ELDER PEOPLE\n\n";
   }


int main()
{
  list l;
  int g,n,i;
  l.create();
  while(1)
  {
    cout<<"\t\t1)DISPLAY the SEATS\n\t\t2)BOOK the SEATS\n\t\t3)CANCEL the SEATS\n\t\t4)EXIT\n";
    cout<<"ENTER THE CHOICE : ";
    cin>>g;
    switch(g)
    {
      case 1:
             l.print();
             break;
      case 2:
      	     cout<<endl<<"ENTER NUMBER OF TICKETS TO BE BOOKED : ";
      	     cin>>n;
      	     for(i=0;i<n;i++)
      	     {
              l.book();
             }
             break;
      case 3:
              l.del();
              break;
      case 4:
              exit(1);
      default:
              cout<<"\tENTERED INVALID CHOICE!!\n";
    }
  }
}
