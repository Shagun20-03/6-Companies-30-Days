class Solution {
public:
    string longestPrefix(string s) {
        vector<int>LPS(s.size(), 0);
	    int j=0, i=1;
	    
	    while(i<s.size()) {
	        if(s[i]==s[j]) {
	            LPS[i]=j+1;
	            j++;
	            i++;
	        }
	        else {
	            if(j==0)
	                i++;
	            else
	            //we will go to shorter prefix
	                j=LPS[j-1];
	        }
	    }
	     return s.substr(0, LPS.back());
    }
};
