#include<bits/stdc++.h>

using namespace std;

//-------------------------Linked List Implementation----------------------//
//-------------------------------------------------------------------------//

class node
{
public:
	int info;
	node *link;
};

node *head = NULL, *temp = NULL;



//-----------------------------Initial Creation-----------------------------//
//--------------------------------------------------------------------------//
 void creation( int item )
 {
 	node *ptr;
 	ptr = new node();

 	ptr->info = item;
 	ptr->link = NULL;
 	if( head == NULL )
 	{
 		head = ptr;
 		temp = ptr;
 	}
 	else
 	{
 		temp->link = ptr;
 		//Temp holds the previous item. So we are just putting new item 
 		//ptr's address in the previous item's (temp) link;

 		temp = ptr;
 		//Updating the temp for the next insertion

 	}
 }


//---------------------------------TRAVERSE---------------------------------//
//--------------------------------------------------------------------------//
 void traverse()
 {
 	node *str;

 	for( str = head ; ; )
 	{
 		if( str->link != NULL )
 		{
 			cout<<str->info<<" ";
 			str = str->link;
 		}
 		else
 		{
 			cout<<str->info<<endl;
 			break;
 		}
 	}
 }

//---------------------------Different Insertion---------------------------//
//-------------------------------------------------------------------------//

//------>FIRST INSERT

void first_insert()
{
	int item;
	cout<<"Enter the item you want to insert at the first"<<endl;
	cin>>item;

	node *ptr = new node();
	ptr->info = item;
	ptr->link = head;
	head = ptr;
}

//---->LAST INSERT

void last_insert()
{
	int item;
	cout<<"Enter the item you want to insert at the last"<<endl;
	cin>>item;

	node *ptr;
	ptr = new node();
	ptr->info = item;

	node *str;
	for( str = head ; ; )
	{
		if( str->link == NULL )
		{
			str->link = ptr;
			break;
		}
		else
		{
			str = str->link;
		}
	}
}

//----->BEFORE INSERT

void before_insert()
{
	int s_item;
	cout<<"Enter the reference before value: \n";
	cin>>s_item;

	node *str , *tmp;

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
				cout<<"Enter the item you want to insert \n";
				cin>>item;

				node *ptr;
				ptr = new node();

				ptr->info = item;

				ptr->link = str;
				tmp->link = ptr;

				break;
			}

		}
		else
		{
			tmp = str;
			str = str->link;
		}

		if( str == NULL )
		{
			cout<<"The reference before value not found"<<endl;
			break;
		}
	}
}

//----->AFTER INSERT

void after_insert()
{
	int s_item;
	cout<<"Enter the reference after value: \n";
	cin>>s_item;

	node *str,*tmp;

	for( str = head ; ; )
	{
		if( str->info == s_item )
		{
			if( str->link == NULL )
			{
				last_insert();
				break;
			}
			else
			{
				int item;
				cout<<"Enter the item you want to insert \n";
				cin>>item;

				node *ptr = new node();
				ptr->info = item;

				tmp = str->link;
				ptr->link = tmp;
				str->link = ptr;
				//or u can directly use
				//-->
				//ptr->link = str->link
				//str->link = ptr;

				break;
			}
		}
		else
		{
			str = str->link;
		}

		if( str == NULL )
		{
			cout<<"The reference after value not found"<<endl;
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
			str = str->link;
		}

		if( str == NULL )
		{
			cout<<"Item not found"<<endl;
			break;
		}
	}
}

//---------------------------------Deletion--------------------------------//
//-------------------------------------------------------------------------//

//----->FIRST ITEM DELETE
void first_delete()
{
	head = head->link;
} 

//----->LAST ITEM DELETE
void last_delete()
{
	node *str,*tmp;

	for( str = head ; ; )
	{
		if( str->link == NULL )
		{
			tmp->link = NULL;
			break;
		}
		else
		{
			tmp = str;
			str = str->link;
		}
	}
}

//----->GIVEN ITEM DELETE
void given_item_delete()
{
	int s_item;
	cout<<"Enter the value to be deleted: \n";
	cin>>s_item;

	node *str, *tmp;

	for( str = head ; ; )
	{
		if( str->info == s_item )
		{
			if( str == head )
			{
				first_delete();
				break;
			}
			else if( str->link == NULL )
			{
				last_delete();
				break;
			}
			else
			{
				tmp->link = str->link;
				break;
			}	
		}
		else
		{
			tmp = str;
			str = str->link; 
		}

		if( str == NULL )
		{
			cout<<"Item not found"<<endl;
			break;
		}
	}
}

//----->AFTER ITEM DELETE(deleting an item locate after a given item)
void after_item_delete()
{
	int s_item;
	cout<<"Enter the after reference value: \n";
	cin>>s_item;

	node *str, *tmp;

	for( str = head ; ; )
	{
		if( str->info == s_item )
		{
			if( str->link == NULL )
			{
				cout<<"invalid input"<<endl;
				break;
			}
			else
			{
				tmp = str->link;
				str->link = tmp->link;
				break;
			}	
		}
		else
		{
			str = str->link; 
		}

		if( str == NULL )
		{
			cout<<"Item not found"<<endl;
			break;
		}
	}
}

//----->BEFORE ITEM DELETE(deleting an item locate before a given item) 
void before_item_delete()
{
	int s_item;
	cout<<"Enter the before reference value: \n";
	cin>>s_item;

	node *str, *tmp,*prev;

	for( str = head ; ; )
	{
		if( str->info == s_item )
		{
			if( str == head )
			{
				cout<<"invalid input"<<endl;
				break;
			}
			else
			{
				if( tmp == head )
				{
					first_delete();
					break;
				}
				else
				{
					prev->link = str;
					break;
				}
			}	
		}
		else
		{
			prev = tmp;
			tmp = str;
			str = str->link; 
		}

		if( str == NULL )
		{
			cout<<"Item not found"<<endl;
			break;
		}
	}
}

//----------------------------------Main---------------------------------//
//-------------------------------------------------------------------------//
int main()
{
	int n,item;
	cout<<"Enter the Number of Elements : "<<endl;
	cin>>n;

	for( int i = 0 ; i < n ; i++ )
	{
		item = rand()%50;//RANDOM DATA INPUT
		creation(item);
	}

	cout<<"The linked list is :"<<endl;
	traverse();

	int x = -1;
	while( x != 0 )
	{
		cout<<"Main menu:\n";
		cout<<"Enter 1 for Traverse\n";
		cout<<"Enter 2 for First Insert\n";
		cout<<"Enter 3 for Last Insert\n";
		cout<<"Enter 4 for After Insert\n";
		cout<<"Enter 5 for Before Insert\n";
		cout<<"Enter 6 for First Delete\n";
		cout<<"Enter 7 for Last Delete\n";
		cout<<"Enter 8 for Given item delete\n";
		cout<<"Enter 9 for After Item delete\n";
		cout<<"Enter 10 for Before Item delete\n";
		cout<<"Enter 11 for Search in the List\n";
		cout<<"Enter 0 to Exit\n";
		cout<<"Enter Your Choice:\n";
		cin>>x;

		switch(x)
		{
			case 0:
				break;
			case 1:
				traverse();
				break;
			case 2:
				first_insert();
				cout<<"Edited List:\n";
				traverse();
				break;
			case 3:
				last_insert();
				cout<<"Edited List:\n";
				traverse();
				break;
			case 4:
				after_insert();
				cout<<"Edited List:\n";
				traverse();
				break;
			case 5:
				before_insert();
				cout<<"Edited List:\n";
				traverse();
				break;
			case 6:
				first_delete();
				cout<<"Edited List:\n";
				traverse();
				break;
			case 7:
				last_delete();
				cout<<"Edited List:\n";
				traverse();
				break;
			case 8:
				given_item_delete();
				cout<<"Edited List:\n";
				traverse();
				break;
			case 9:
				after_item_delete();
				cout<<"Edited List:\n";
				traverse();
				break;
			case 10:
				before_item_delete();
				cout<<"Edited List:\n";
				traverse();
				break;
			case 11:
				search();
				break;
			default:
				cout<<"Invalid Input"<<endl;	
		}
		cout<<"\n";

	}
   
    return 0;
}