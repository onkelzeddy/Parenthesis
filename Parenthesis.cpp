#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main()
{
    stack <char> stOp;
	stack <char> stCl;
    string str;
    cin>>str;
    
    for(int i = 0;i<str.size();i++){
		
		if (i != str.size() - 1){
			if ((str[i]== '[' && str[i+1]== ']' )||( str[i]== '{' && str[i+1]== '}' )||( str[i]== '(' && str[i+1]== ')')){
				str[i] = '0';
				str[i+1] = '0';
			}
		}

		if (str[i]== '[')
            stOp.push('1');
		if (str[i]== '{' )
            stOp.push('2');
		if (str[i]=='(')
            stOp.push('3');
    }
    
    for(int i = str.size()-1;i>=0;i--){
        if (str[i]== ']')
            stCl.push('1');
		if ( str[i]== '}' )
            stCl.push('2');
		if (str[i]==')')
            stCl.push('3');
    }
    
    if (stCl.size() != stOp.size()){ 
        cout << "Not OK" << endl;    
        return 0;
    }
    
	for(int i = 0;i<stCl.size();i++){
		if (stOp.top()!= stCl.top()){
		    cout << "Not OK" << endl;
			return 0;
		}
		stOp.pop();
		stCl.pop();
		
	}
	cout << "OK" << endl; 

    return 0;
}
