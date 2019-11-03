#include <bits/stdc++.h>
using namespace std;

//Returns the precedence of an operator c , returns -1 if the character is not an operator
int getPrecedence(char c) 
{ 
    if(c == '^') 
        return 3; 
    else if(c == '*' || c == '/') 
        return 2; 
    else if(c == '+' || c == '-') 
        return 1; 
    else if(c == '(' || c == ')')
        return 0;
    else
        return -1; 
} 

//Function to convert infix expression to postfix expression
string convert(string infix){
    stack<char> s;      //Stack for operators
    string postfix = "(";      //Final postfix string
    s.push('(') ;

    //The expression must be enclosed inside () brackets
    //We added the ( bracket directly into the string and the stack from the beginning and append ) 
    //into the infix expression to denote the end of expression
    infix.push_back(')') ; 

    for(int i=0;i<infix.size();i++) {
        char current = infix[i]; 
        int precedence = getPrecedence(current) ;

        cout << "c = "<<current ;
        cout << "       precedence = " << precedence ;
        cout << "        postfix = "<<postfix <<endl ;
  
        if(precedence == -1){
            //Current char is an operand ... simply push into the postfix string and continue 
            postfix = postfix + current ;
        }
        else {
            //Current char is an operator
            //If it is a closing bracket ')' , pop all elements in stack till you get a an open bracket'('
            if(current == ')'){
                char topElement = ' ' ; 
                while(topElement != '('){
                    topElement = s.top() ;
                    if(topElement != '(')
                        postfix = postfix + topElement ;
                    s.pop();
                }
             //   postfix += ')' ;
            }
            else if (current == '('){
                //If current char is an opening bracket , do not pop anything and simply push it into the stack
                s.push(current) ; 
            }
            else {
                //Pop all operators with higher priority
                while(getPrecedence(s.top()) > getPrecedence(current)){
                    char topElement = s.top() ;
                    postfix = postfix + topElement ;
                    s.pop();
                }
                //Then push the current element into the stack
                s.push(current);
            }
        }
    }

    //Remove the extra '(' from postfix added in the beginning 
    postfix.erase(postfix.begin()) ;


    return postfix ; 
}


int main() {
    string infixExpression ;
    cin >> infixExpression ; 

    string postfix = convert(infixExpression) ;
    cout << postfix ; 


    return 0;
}
