class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
       vector<string> ans;
        int n=transactions.size();
        vector<string> name(n), city(n);
        vector<int> time(n), amount(n), invalid(n, 0);
        
        for(int i=0;i<n;i++){
            stringstream ss(transactions[i]);
            string tmp;
            
            getline(ss, tmp, ',');
            name[i]=tmp;
            
            getline(ss, tmp, ',');
            time[i]=stoi(tmp);
            
            getline(ss, tmp, ',');
            amount[i]=stoi(tmp);
            
            getline(ss, tmp, ',');
            city[i]=tmp;
        }
        for(int i=0;i<n;i++){
            if(amount[i]>1000) invalid[i]=1;
            for(int j=i+1;j<n;j++){
                if(abs(time[j]-time[i])<=60 && name[i]==name[j] && city[i]!=city[j])
                    invalid[i]=invalid[j]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(invalid[i])
                ans.push_back(transactions[i]);
        }
        return ans;
    }
};
