#include<stdio.h>
#define MAX 20
int parent[MAX];
int rank[MAX];
void Create(int n)
{
int i;
for(i=0;i<n;i++)
{
parent[i]=i;
rank[i]=0;
}
printf("Disjoint sets ceated successfully.\n");
}
int Find(int x)
{
if(parent[x]!=x)
parent[x]=Find(parent[x]);
return parent[x];
}
void Union(int x,int y)
{
int rootX=Find(x);
int rootY=Find(y);
if(rootX==rootY)
{
printf("Both elements belong to the same set.\n");
return;
}
if(rank[rootX]<rank[rootY])
{
parent[rootX]=rootY;
}
else if(rank[rootX]>rank[rootY])
{
parent[rootY]=rootX;
rank[rootX]++;
}
printf("Union operation completed successfully.\n");
}
void Display(int n )
{
int i;
printf("\nElement\tparent\tRepresentative\n");
for(i=0;i<n;i++)
{
printf("%d\t%d\t%d\n",i,parent[i],Find(i));
}
}
int main()
{
int n,choice,x,y;
printf("Enter number of elements:");
scanf("%d",&n);
if(n<=0||n>MAX)
{
printf("invalid number of elements!\n");
return 0;
}
do
{
printf("\n------DISJOINT SET ADT--------\n");
printf("1.create\n");
printf("2.union\n");
printf("3.find\n");
printf("4.display\n");
printf("5.exit\n");
printf("Enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
Create(n);
break;
case 2:
printf("Enter two elements:");
scanf("%d%d",&x,&y);
if(x>=0&&x<n&&y>=0&&y<n)
Union(x,y);
else
printf("invalid elements!\n");
break;
case 3:
printf("Enter element to find:");
scanf("%d", &x);
if(x>=0&&x<n)
printf("Representative of %d is%d\n",x,Find(x));
else
printf("invalid element!\n");
break;
case 4:
Display(n);
break;
case 5:
printf("Existing program....\n");
break;
default:
printf("invalid choice!\n");
}
}
while(choice!=5);
return 0;
}



