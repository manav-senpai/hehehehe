#include<iostream>
#include<string>
#include <list>
using namespace std;
// creating LinkList
class Node
{
 public :
 Node *next;
 int priority;
 string data;
 Node(string d,int prior){
 priority = prior;
 data = d;
 next = NULL;
 }
};
class PriorityQueue{
 public:
 Node *front=NULL;

 //d is patient name , prior is priority
 void insert(string d,int prior){
 Node *temp,*rear;
 temp = new Node(d,prior);
 if(front == NULL){
 front = temp;
 }
 else
 {
 //compare until position is found
 rear = front;
 while(
 rear->next!=NULL &&
 rear->next->priority >= prior
 ){
 rear=rear->next;
 }
 temp->next = rear->next;
 rear->next = temp;
 }
 }
 //to get name of first patient
 void peek(){
 cout<<"First patient is:\t"<<front->data;
 }
 void pop(){
 //to remove first patient
 if(front==NULL)
 return;
 front=front->next;
 }
 //display all the queue
 void dis()
 {
 string currPrior="";
 if(front== NULL){
 cout<<endl<<"Empty queue."<<endl;
 return;
 }
 cout<<endl;
 Node *curr= front;
 while(curr!=NULL){
 //hardCode the category
 if(curr->priority!=0){
 if(curr->priority==3)
 currPrior="Serious patient";
 else if(curr->priority==2)
 currPrior="Not serious patient";
 else
 currPrior="General checkup";
 }
 cout<<curr->data<<" with priority:\t"<<currPrior<<endl;
 curr=curr->next;
 }
 }
};
int main(){
 string name;
 int priority,ch;
 cout<<endl;
 PriorityQueue q;
 do{
 cout<<endl<<"--- MAIN MENU ---";
 cout<<endl<<"1 -> Add patient";
 cout<<endl<<"2 -> Remove patient";
 cout<<endl<<"3 -> Get all patients";
 cout<<endl<<"0 -> Exit";
 cout<<endl<<"Choose an option (0-3):\t";
 cin>>ch;

 switch (ch)
 {
 case 1:
 {
 cout<<"Patient name is:\t";
 cin.ignore();
 getline(cin,name,'\n');
 cout<<endl<<"Enter priority (3-High, 2-Medium, 1-General):\t";
 cin>>priority;
 q.insert(name,priority);
 break;
 }
 case 2:
 {
 q.pop();
 break;
 }
 case 3:{
 q.dis();
 break;
 }
 case 0:
 cout<<endl<<"// END OF CODE\n\n";
 exit(1);
 break;

 default:
 break;
 }
 } while(ch!=0);
}
