#include <bits/stdc++.h>
using namespace std;

//-----------------Two Way Linked list Implementation----------------------//
//-------------------------------------------------------------------------//

class node
{
public:
	int info;
	node *prev;
	node *next;
};

node *head = NULL, *tail = NULL, *temp = NULL;

//-----------------------------Initial Creation----------------------------//
//-------------------------------------------------------------------------//


void creation( int item )
{
	node *ptr;
	ptr = new node();
	ptr->info = item;
	ptr->prev = NULL;
	ptr->next = NULL;

	if( head == NULL )
	{
		head = ptr;
		tail = ptr;
	}
	else
	{
		ptr->prev = tail;
		tail->next = ptr;
		tail = ptr;
	}
}

//----------------------------------Traverse--------------------------------//
//-------------------------------------------------------------------------//

void forward_traverse()
{
	node *str;
	for( str = head ; ; )
	{
		if( str != tail )
		{
			cout<<str->info<<" ";
			str = str->next;
		}
		else
		{
			cout<<str->info<<endl;
			break;
		}
	}
}

void backward_traverse()
{
	node *str;
	for( str = tail ; ; )
	{
		if( str != head )
		{
			cout<<str->info<<" ";
			str = str->prev;
		}
		else
		{
			cout<<str->info<<endl;
			break;
		}
	}
}

//----------------------------------Insert---------------------------------//
//-------------------------------------------------------------------------//

void first_insert()
{
	int item;
	cout<<"Enter the item you want to insert"<<endl;
	cin>>item;

	node *ptr;
	ptr = new node();
	ptr->info = item;
	ptr->prev = NULL;
	ptr->next = head;
	head->prev = ptr;

	head = ptr;
}

void last_insert()
{
	int item;
	cout<<"Enter the item you want to insert"<<endl;
	cin>>item;

	node *ptr;
	ptr = new node();
	ptr->info = item;
	ptr->prev = tail;
	ptr->next = NULL;
	tail->next = ptr;

	tail = ptr;
}

void after_insert()
{
	int s_item;
	cout<<"Enter the reference after value: \n";
	cin>>s_item;

	node *str;

	for( str = head ; ; )
	{
		if( str->info == s_item )
		{
			if( str == tail )
			{
				last_insert();
				break;
			}
			else
			{
				int item;
				cout<<"Enter the item you want to insert"<<endl;
				cin>>item;

				node *ptr,*tmp;
				ptr = new node();

				tmp = str->next;

				ptr->info = item;

				ptr->prev = str;
				ptr->next = tmp;
				str->next = ptr;
				tmp->prev = ptr;
				break;

			}
		}
		else
		{
			str = str->next;
		}

		if( str == NULL )
		{
			cout<<"The reference after value not found"<<endl;
			break;
		}
	}

}

void before_insert()
{
	int s_item;
	cout<<"Enter the reference before value:"<<endl;
	cin>>s_item;

	node *str;
	for( str = head ; ; )
	{
		if( str->info == s_item )
		{
			if( str == head )
			{
				first_insert();
				break;
			}
			else
			{
				int item;
				cout<<"Enter the item you want to insert"<<endl;
				cin>>item;

				node *ptr,*tmp;
				ptr = new node();

				tmp = str->prev;

				ptr->info = item;
				ptr->prev = tmp;
				ptr->next = str;
				tmp->next = ptr;
				str->prev = ptr;
				break;
			}
		}	
		else
		{
			str = str->next;
		}

		if( str == NULL )
		{
			cout<<"The reference before value not found"<<endl;
			break;
		}		
	}
}
//---------------------------------Deletion---------------------------------//
//-------------------------------------------------------------------------//

void first_delete()
{
	node *ptr;

	ptr = head;

	head = head->next;
	head->prev = NULL;

	delete(ptr);
}

void last_delete()
{
	node *ptr;

	ptr = tail;

	tail = tail->prev;
	tail->next = NULL;

	delete(ptr);
}

void given_delete()
{
	int item;
	cout<<"Enter the item you want to delete"<<endl;
	cin>>item;

	node *str;

	for( str = head ; ; )
	{
		if( str->info == item)
		{
			if( str == head )
			{
				first_delete();
				break;
			}
			else if( str == tail )
			{
				last_delete();
				break;
			}
			else
			{
				node *tmp1,*tmp2;

				tmp1 = str->prev;
				tmp2 = str->next;

				tmp1->next = tmp2;
				tmp2->prev = tmp1;
				break;
			}
		}
		else
		{
			str= str->next;
		}

		if( str == NULL )
		{
			cout<<"Given item not found"<<endl;
			break;
		}
	}
}

void after_delete()
{
	int s_item;
	cout<<"Enter the reference after value:"<<endl;
	cin>>s_item;

	node *str;

	for( str = head ; ; )
	{
		if( str->info == s_item )
		{
			if( str == tail )
			{
				cout<<"Invaild Request"<<endl;
				break;
			}
			else if( str->next == tail )
			{
				last_delete();
				break;
			}
			else
			{
				node *tmp1,*tmp2;

				tmp1 = str->next;
				tmp2 = tmp1->next;

				str->next = tmp2;
				tmp2->prev = str;
				break;
			}
		}
		else
		{
			str = str->next;
		}

		if( str == NULL )
		{
			cout<<"The reference after value not found"<<endl;
			break;
		}
	}
}

void before_delete()
{
	int s_item;
	cout<<"Enter the reference before value:"<<endl;
	cin>>s_item;

	node *str;

	for( str = head ; ; )
	{
		if( str->info == s_item )
		{
			if( str == head )
			{
				cout<<"Invaild Request"<<endl;
				break;
			}
			else if( str->prev == head)
			{
				first_delete();
				break;
			}
			else
			{
				node *tmp1,*tmp2;

				tmp1 = str->prev;
				tmp2 = tmp1->prev;

				str->prev = tmp2;
				tmp2->next = str;
				break;
			}
		}
		else
		{
			str = str->next;
		}

		if( str == NULL )
		{
			cout<<"The reference before value not found"<<endl;
			break;
		}
	}
}

//----------------------------------Search---------------------------------//
//-------------------------------------------------------------------------//

void search()
{
	int s_item;
	cout<<"Enter the value to be searched: \n";
	cin>>s_item;

	node *str;

	for( str = head ; ; )
	{
		if( str->info == s_item )
		{
			cout<<"Found"<<endl;
			break;
		}
		else
		{
			str = str->next;
		}

		if( str == NULL )
		{
			cout<<"Item not found"<<endl;
			break;
		}
	}
}

//----------------------------------MAIN-----------------------------------//
//-------------------------------------------------------------------------//

int main()
{
	int n,item;

	cout<<"Enter the number of element:\n";
	cin>>n;

	for( int  i = 0 ; i<n ; i++ )
	{
		item = rand()%50;
		creation(item);
	}

	forward_traverse();


	int x = -1;
	while( x != 0 )
	{
		cout<<"Main menu:\n";
		cout<<"Enter 1 for Forward Traverse\n";
		cout<<"Enter 2 for Backward Traverse\n";
		cout<<"Enter 3 for First Insert\n";
		cout<<"Enter 4 for Last Insert\n";
		cout<<"Enter 5 for After Insert\n";
		cout<<"Enter 6 for Before Insert\n";
		cout<<"Enter 7 for First Delete\n";
		cout<<"Enter 8 for Last Delete\n";
		cout<<"Enter 9 for Given item delete\n";
		cout<<"Enter 10 for After Item delete\n";
		cout<<"Enter 11 for Before Item delete\n";
		cout<<"Enter 12 for Search in the List\n";
		cout<<"Enter 0 to Exit\n";
		cout<<"Enter Your Choice:\n";
		cin>>x;

		switch(x)
		{
			case 0:
				break;
			case 1:
				forward_traverse();
				break;
			case 2:
				backward_traverse();
				break;
			case 3:
				first_insert();
				cout<<"Edited List:\n";
				forward_traverse();
				break;
			case 4:
				last_insert();
				cout<<"Edited List:\n";
				forward_traverse();
				break;
			case 5:
				after_insert();
				cout<<"Edited List:\n";
				forward_traverse();
				break;
			case 6:
				before_insert();
				cout<<"Edited List:\n";
				forward_traverse();
				break;
			case 7:
				first_delete();
				cout<<"Edited List:\n";
				forward_traverse();
				break;
			case 8:
				last_delete();
				cout<<"Edited List:\n";
				forward_traverse();
				break;
			case 9:
				given_delete();
				cout<<"Edited List:\n";
				forward_traverse();
				break;
			case 10:
				after_delete();
				cout<<"Edited List:\n";
				forward_traverse();
				break;
			case 11:
				before_delete();
				cout<<"Edited List:\n";
				forward_traverse();
				break;
			case 12:
				search();
				break;
			default:
				cout<<"Invalid Input"<<endl;	
		}
		cout<<"\n";

	}

}