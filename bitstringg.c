#include<stdio.h>
#define MAX 8
void display(int set[])
{
int i,empty=1;
printf("{");
for(i=0;i<MAX;i++)
{
if(set[i]==1)
{
printf("%d",i+1);
empty=0;
}}
if(empty)
printf("Empty");
printf("}\n");
}
void add(int set[],int element)
{
if(element>=1&&element<=MAX)
{
set[element-1]=1;
printf("%d added successfully\n",element);
}
else
printf("Invalid element\n");
}
void removeElement(int set[],int element)
{
if(element>=1&&element<=MAX)
{
set[element-1]=0;
printf("%d removed successfully.\n",element);
}
else
printf("Invalid element\n");
}
void unionSet(int A[],int B[],int C[])
{
int i;
for(i=0;i<MAX;i++)
C[i]=A[i]|B[i];
}
void intersectionSet(int A[],int B[],int C[])
{
int i;
for(i=0;i<MAX;i++)
C[i]=A[i]&B[i];
}
void differenceSet(int A[],int B[],int C[])
{
int i;
for(i=0;i<MAX;i++)
C[i]=A[i]&(~B[i]);
}
int main()
{
int A[MAX]={0};
int B[MAX]={0};
int C[MAX]={0};
int choice,element,i;
printf("Enter number of elements in Set A:");
scanf("%d",&element);
printf("Enter elements of Set A(1 to %d):",MAX);
for(i=0;i<element;i++)
{
int x;
scanf("%d",&x);
if(x>=1&&x<=MAX)
A[x-1]=1;
else
printf("Invalid element %d ignored.\n",x);
}
printf("\nEnter number of elements in Set B:");
scanf("%d",&element);
printf("Enter elements of Set B(1 to %d):",MAX);
for(i=0;i<element;i++)
{
int x;
scanf("%d",&x);
if(x>=1&&x<=MAX)
B[x-1]=1;
else
printf("Invalid element %d ignored.\n",x);
}
do
{
printf("\n----SET ADT USING BIT STRINGS----\n");
printf("1.Display Sets\n");
printf("2.Add elements to set A\n");
printf("3.Remove elements from set A\n");
printf("4.Union(AUB)\n");
printf("5.Intersection(AnB)\n");
printf("6.Difference(A-B)\n");
printf("7.Difference(B-A)\n");
printf("8.Exit\n");
printf("Enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Set A=");
display(A);
printf("Set B=");
display(B);
break;
case 2:
printf("Enter elements to add:");
scanf("%d",&element);
add(A,element);
break;
case 3:
printf("Enter elements to remove:");
scanf("%d",&element);
removeElement(A,element);
break;
case 4:
unionSet(A,B,C);
printf("Union=");
display(C);
break;
case 5:intersectionSet(A,B,C);
printf("Intersection=");
display(C);
break;
case 6:
differenceSet(A,B,C);
printf("Difference(A-B)=");
display(C);
break;
case 7:
differenceSet(A,B,C);
printf("Difference(B-A)=");
display(C);
break;
case 8:printf("Exiting program..\n");
break;
default:
printf("invalid choice!Try again\n");
}}
while(choice!=8);
return 0;
}
