//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    
    bool isMatching(char a, char b){
        if(a == '(' && b == ')'){
            return true;
        }
        else if(a == '[' && b == ']'){
            return true;
        }
        else if(a == '{' && b == '}'){
            return true;
        }
        return false;
    }
    
    bool ispar(string x)
    {
        // Your code here
        int len = x.length();
        if(len%2 != 0){
            return false;
        }
        else{
            stack<char> st;
            for(char ch:x){
                if(ch == '(' || ch == '{' || ch == '['){
                    st.push(ch);
                }
                else{
                    if(st.empty()){
                        return false;
                    }
                    else if(isMatching(st.top(), ch)){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
            return st.size()==0;
        }
        
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends