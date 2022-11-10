#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int q[SIZE];
int rear=0,front=0;
void insertq(int item)
{
int r1=rear;
r1=(r1+1)%SIZE;
if(r1==front)
printf("Queue is full ");
else
{
rear=r1;
q[rear]=item;
}
}
int deleteq(int *status)
{
if(front==rear){
*status=0;
printf(" queue is empty \n" );}
else
{
front=(front+1)%SIZE;
*status=1;
return q[front];
}
}
int searchq(int item)
{
int t;
t=front;
t=(t+1)%SIZE;
while(t!=rear&&q[t]!=item)
t=(t+1)%SIZE;
if(q[t]==item)
return t+1;
else
return 0;
}
void main()
{
int item,opt,ans,status;
do
{
printf("\n 1.Insert \n ");
printf("\n 2.Delete \n ");
printf("\n 3.Search \n ");
printf("\n 4.Exit \n ");
printf("\n enter your option :");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("\n Data :");
scanf("%d",&item);
insertq(item);
printf("inserted %d",item);
break;
case 2: item=deleteq(&status);
if(status==1)
printf("Deleted %d",item);
break;
case 3:printf("Enter the number to search :");
scanf("%d",&item);
ans=searchq(item);
if(ans==0)
printf("not found");
else
printf("item found at %d position \n",ans);
break;
case 4:exit(0);
}
}
while(1);
}
