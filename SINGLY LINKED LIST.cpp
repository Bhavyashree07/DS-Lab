#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
 int info;
 struct node *next;
}*start;
class single_llist
{
 public:
 node* create_node(int);
 void insert_begin();
 void delete_last();
 void delete_pos();
 void display();
 single_llist()
 {
 start = NULL;
 }
};
int main()
{
 int choice;
 single_llist sl,s2;
 start = NULL;
 do
 {
 cout<<"---------------------------------"<<endl;
 cout<<"Operations on singly linked list"<<endl;
 cout<<"---------------------------------"<<endl;
 cout<<"1.Insert at first"<<endl;
 cout<<"2.Delete at Last"<<endl;
 cout<<"3.Display"<<endl;
 cout<<"4.Exit "<<endl;
 cout<<"Enter your choice :";
 cin>>choice;
 switch(choice)
 {
 case 1: sl.insert_begin();
 sl.display();
 break;
 case 2: s2.delete_last();
 sl.display();
 break;
 case 3:sl.display();
 break;
 case 4:exit(0);
 break;
 default:cout<<"Wrong choice...???"<<endl;
 break;
 }
 }
 while(choice != 4);
}
node *single_llist::create_node(int value)
{
 struct node *temp, *s;
 temp = new(struct node);
 if (temp == NULL)
 {
 cout<<"Memory not allocated"<<endl;
 return 0;
 }
 else
 {
 temp->info = value;
 temp->next = NULL;
 return temp;
 }
}
void single_llist::insert_begin()
{
 int value;
 cout<<"Enter the value to be inserted : ";
 cin>>value;
 struct node *temp, *s;
 temp = create_node(value);
 if (start == NULL)
 {
 start = temp;
 start->next = NULL;
 cout<<temp->info<<" is inserted at first in the empty list"<<endl;
 }
 else
 {
 s = start;
 start = temp;
 start->next = s;
 cout<<temp->info<<" is inserted at first"<<endl;
 }
}
void single_llist::delete_last()
{
 int i, counter = 0;
 struct node *s, *ptr;
 if (start == NULL){}
 else
 {
 s = start;
 while (s != NULL)
 {
 s = s->next;
 counter++;
 }
 s = start;
 if (counter == 1)
 {
 start = s->next;
 cout<<s->info<<" deleted from last"<<endl;
 free(s);
 }
 else
 {
 for (i = 1;i < counter;i++)
 {
 ptr = s;
 s = s->next;
 }
 ptr->next = s->next;
 cout<<s->info<<" deleted from last"<<endl;
 free(s);
 }
 }
}
void single_llist::display()
{
 struct node *temp;
 if (start == NULL)
 cout<<"Linked list is empty...!!!"<<endl;
 else
 {
 cout<<"Linked list contains : ";
 temp = start;
 while (temp != NULL)
 {
 cout<<temp->info<<" ";
 temp = temp->next;
 }
 cout<<endl;
 }
}
