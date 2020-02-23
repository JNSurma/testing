/* Strictly --- Enter Only Integer Data otherwise It'll go in Infinite Loop */
#include <iostream>
//#include <process.h>
#include <cstdlib>
using namespace std;
class linklist
{
	linklist *next;
	int data;
public:
	linklist * ifirst(linklist *);	
	void traverse(linklist *);
	linklist * ilast(linklist *);
	void del(linklist *);
};
linklist * linklist::ifirst(linklist *temp)
{
	linklist *newlink;
	newlink=new linklist;
	cout<<"\nEnter Data\n";
	cin>>newlink->data;
	if (cin.fail()) exit(1);
	newlink->next=temp;
	temp=newlink;
	return temp;
}
void linklist::traverse(linklist *temp)
{
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	
}

linklist * linklist::ilast(linklist *temp)
{
	linklist *newlink;
	newlink=new linklist;
	if (temp==NULL)
	{
		linklist *newlink;
		newlink=new linklist;
		cout<<"\nEnter Data :";
		cin>>newlink->data;
		if (cin.fail()) exit(1);
		newlink->next=temp;
		temp=newlink;		
	}
	else
	{
		linklist *cur;
		cur=temp;
		while(cur->next!=NULL)
		{
			cur=cur->next;
		}
		cout<<"\nEnter Data :";
		cin>>newlink->data;
		if (cin.fail()) exit(1);
		newlink->next=NULL;
		cur->next=newlink;		
	}
	return temp;

}
int main()
{
	linklist *first=NULL,l1;
	int choice;
	while(1)
	{
		cout<<"**************** LINK LIST (Only For Integer) ****************\n\n";
		cout<<"Choices Are :-\n=> [1] For Insert First\n=> [2] For Insert Last\n=> [3] For Traverse\n=> [4] For Exit";
		cout<<"\n\nEnter Your choice : ";
		cin>>choice;
		if (cin.fail()) break;

		switch (choice)
		{
		case 1:
			first=l1.ifirst(first);
			break;
		case 2:
			first=l1.ilast(first);
			break;
		case 3:
			l1.traverse(first);
			break;
		case 4:
			exit(0);

		}
	
	}
return 0;
}



