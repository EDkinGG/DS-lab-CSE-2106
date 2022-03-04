#include <bits/stdc++.h>

using namespace std;
//---------------------STACK IMPLEMENTATION--------------------//
int sz = 0;
class node
{
public:
	double data;
	node *link;
};

node *st_top =NULL , *temp = NULL;

void push( double value )
{
	node *ptr;
	ptr = new node();

	ptr->data = value;
	ptr->link = st_top;
	st_top = ptr;
	sz++;
}

void pop()
{
	if( st_top == NULL)
	{
		cout<<"No more element left\n";
	}
	else
	{
		temp = st_top;
		st_top = st_top->link;
		free(temp);
		sz--;
	}
}

double top()
{
	return st_top->data;
}

int st_size()
{
	return sz;
}

bool isEmpty()
{
	if( st_top == NULL )
	{

		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------STACK END---------------------------//

bool isOperator( char ch )
{
	if( ch == '+' || ch == '-' || ch =='*' || ch =='/' )
		return true;
	return false;
}

bool isDigit( char ch )
{
	if( ch >= '0' && ch<='9' )
		return true;
	return false;
}

double operation( double a, double b, char op )
{
	if( op == '+' )
		return a+b;
	if( op == '-' )
		return a-b;
	if( op == '*' )
		return a*b;
	if( op == '/' )
		return a/b;

	return 0;
}

double evaluatePostfixExpression( string exp )
{
	for( int i = 0 ; i < (int)exp.length() ; i++ )
	{
		if( exp[i] == ' ' || exp[i] == ',' )
		{
			continue;
		}
		else if( isOperator(exp[i]) )
		{
			if( st_size() < 2 )
			{
				cout<<"invalid expression"<<endl;
                exit(0);
			}
			else
			{
				double op1,op2,result;
				op1 = top();
				pop();
				op2 = top();
				pop();
				result = operation( op2 , op1 , exp[i] );
				push(result);
			}
		}
		else if( isDigit(exp[i]) )
		{
			double operand = 0;

			while( (i < (int)exp.length()) && isDigit(exp[i]) )
			{
				operand = operand*10 + (exp[i]-'0');
				i++;
			}
			i--;
			push(operand);
		}
		else
		{
			cout<<"The expression contain wrong symbol.\n";
			exit(0);
		}
	}
	return top();
}

int main()
{
	string exp;
	cout<<"Enter the Expression:\n";
	getline(cin,exp);

	double result = evaluatePostfixExpression(exp);
	cout<<result<<endl;
	return 0;
}

//sample input & output
//100 200 + 2 / 5 * 7 +
//757
//
//2 3 * 5 4 * + 9 -
//17