//problem link:-https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3362/

class Solution {
public:
    bool ipv4(string s){
        int dot=0;
        vector<string>v;
        string str="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='.'){
                dot++;
                if(str.size()==0 or str=="" or str==" "){
                    return false;
                }
                v.push_back(str);
                str="";
            }
            else if(s[i]>='0' and s[i]<='9'){
                str+=s[i];
            }
            else{
                return false;
            }
        }
        v.push_back(str);
        str="";
        cout<<v.size()<<endl;
        if(dot!=3){
            return false;
        }
        else{
            if(v.size()!=4){
                return false;
            }
            else{
                int ok=1;
                for(int i=0;i<v.size();i++){
                    string ans=v[i];
                    if(ans=="" or ans.length()==0){
                        ok=0;
                        break;
                    }
                    else if(ans.length()>1 and ans[0]=='0'){
                        ok=0;
                        break;
                    }
                    else if(ans.length()>=1){
                        stringstream ss(ans);
                        int x=0;
                        ss>>x;
                        if(x<0 or x>=256){
                            ok=0;
                            break;
                        }
                    }
                }
                return ok==1;
            }
        }
        return false;
    }
    
    bool ipv6(string s){
        int colon=0;
        vector<string>v;
        string str="";
        for(int i=0;i<s.length();i++){
            if(s[i]==':'){
                colon++;
                v.push_back(str);
                str="";
            }
            else{
                str+=s[i];
            }
        }
        v.push_back(str);
        str="";
        if(colon!=7){
            return false;
        }
        else{
            for(int i=0;i<v.size();i++){
                string ans=v[i];
                if(ans==""){
                    return false;
                }
                else if(ans.size()==0 or ans.size()>4){
                    return false;
                }
                else{
                    int ok=1;
                    for(int i=0;i<ans.length();i++){
                        if(ans[i]>='A' and ans[i]<='F'){
                            continue;
                        }
                        else if(ans[i]>='a' and ans[i]<='f'){
                            continue;
                        }
                        else if(ans[i]>='0' and ans[i]<='9'){
                            continue;
                        }
                        else{
                            ok=0;
                            break;
                        }
                    }
                    if(ok==0){
                        return false;
                    }
                }
            }
            return true;
        }
        return false;
    }

    string validIPAddress(string IP) {
        if(ipv4(IP)){
            return "IPv4";
        }
        else if(ipv6(IP)){
            return "IPv6";
        }
        else{
            return "Neither";
        }
    }
};
