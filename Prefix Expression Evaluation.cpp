#include <bits/stdc++.h>
using namespace std;

//-----------------STACK START-----------------------//
int sz = 0;
class node
{
public:
    double data;
    node *link;
};
 
node *st_top = NULL, *temp = NULL;
 
void push(double value )
{
    node *ptr = new node();
    ptr->data = value;
    ptr->link = st_top;
    st_top = ptr;
    sz++;
}
 
double top()
{
    return st_top->data;
}
 
void pop()
{
    if( st_top == NULL )
    {
        cout<<"No more element left"<<endl;
    }
    else
    {
        temp = st_top;
        st_top = st_top->link;
        free(temp);
        sz--;
    }
}

int st_size()
{
    return sz;
}
bool isEmpty()
{
    if(st_top == NULL)
    {
        cout<<"\nStack Underflow!!\n\n";
        return true;
    }
    return false;
}
//---------------------------STACK DONE------------------------//
 
bool isOperator(char op )
{
    if(op == '+' || op == '-' || op == '*' || op == '/')
        return true;
    return false;
}
 
bool isDigit(char dg )
{
    if(dg >= '0' && dg <= '9')
        return true;
    return false;
}
 
double perform(double a, double b, char op)
{
    if( op == '+')
        return a+b;
    if( op == '-')
        return a-b;
    if( op == '*')
        return a*b;
    if( op == '/')
        return a/b;

    return 0;
}
 
double evaluatePrefixExpression(string exp)
{

    for(long long i = exp.length()-1 ; i >= 0; i--)
    {
        if(exp[i] == ' ' || exp[i] == ',')
        {
            continue;
        }
        else if(isOperator(exp[i]))
        {
            if( st_size() < 2 )
            {
                cout<<"invalid expression"<<endl;
                exit(0);
            }
            double op1 = top();
            pop();
            double op2 = top();
            pop();
            double result  = perform(op1, op2, exp[i]);
            push(result);
        }
        else if(isDigit(exp[i]))
        {
            double operand = 0;
            int j = 0;

            while( i >= 0 && isDigit(exp[i]) )
            {
                operand = operand + (exp[i]-'0')*pow(10,j) ;
                j++;
                i-- ;
            }
            i++;
            push(operand);
        }
        else
        {
            cout<<exp[i]<<endl;
            cout<<"The expression contains wrong symbol.\n";
            exit(0);
        }
    }
    return top();
}
 
int main()
{
    string exp;

    getline(cin, exp);

    double result = evaluatePrefixExpression(exp);
    cout<<result<<endl;

    return 0;
}

//sample input & output
//+ 9 * 2 6
//21
//
//- + 8 / 6 3 2
//8
//
//- + 7 * 4 5 + 2 0
//25