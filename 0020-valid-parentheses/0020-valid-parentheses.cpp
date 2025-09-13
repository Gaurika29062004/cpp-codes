class Solution {
public:
    bool isValid(string s) {
    stack<int> st;
    for(auto it : s){
        if(!st.empty() && (it == ')' && st.top()=='('||it == ']' && st.top()=='['||it == '}' && st.top()=='{')){
            st.pop();   
        }
        else{
            st.push(it);
        }  
    }
    return st.empty() ;
    }
};