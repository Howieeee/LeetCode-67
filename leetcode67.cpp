class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        if(a.size()==b.size()){ // 11 11 ->  110   size+1
            vector<char> str (a.size()+1,'0');
            bool carry = false;
            for(int i=a.size()-1,j=0;i>=0;i--,j++){ // 10 01   00  11
                //cout << "i:"<< i << " " << a[i] << " " << b[i]  << " c:" << carry << endl;
                if(a[i] xor b[i]){// 10, 01
                    if(carry){ // 10,1  01,1
                        str[j] = '0';
                        carry = true;
                    }else{//10,0  01,0  
                        str[j] = '1';
                    }
                }else{//00, 11
                    // cout << "123 "<< (a[i] && b[i]) <<endl;
                    if(a[i]=='1' && b[i]=='1'){//11
                        if(carry){//11,1
                            str[j] = '1';
                        }else{//11,0
                            str[j] = '0';
                            carry = true;
                        }
                    }else{// 00
                        if(carry){//00,1
                            str[j] = '1';
                            carry = false;
                        }else{//00,0
                            str[j] = '0';
                        }
                    }
                }
                if(i==0 && carry){
                    str[j+1] = '1';
                }
            }
            reverse(str.begin(),str.end());

            for(auto s:str){
                ans += s;
            }
             if(ans[0] == '0')
                ans.erase(0,1);
             
            
        }else{//size 不同
            string l_str = a.size() >= b.size() ? a:b;
            string s_str = l_str == a ? b : a;
            vector<char> str (l_str.size()+1,'0');
            bool carry = false;
            int j=0;
            for(int i=s_str.size()-1,l_i =l_str.size()-1;i>=0;i--,l_i--,j++){
                //cout << "i:"<< i << " " << l_str[l_i] << " " << s_str[i]  << " c:" << carry << " str:";
                if(l_str[l_i] xor s_str[i]){//10 01
                    if(carry){//10,1 01,1
                        str[j] = '0';
                    }else{//10,0 01,0
                        str[j] = '1';
                    }
                }else{//11 00
                    if(l_str[l_i]=='1' && s_str[i]=='1'){//11
                        if(carry){//11,1
                            str[j] ='1';
                        }else{//11 ,0
                            str[j] = '0';
                            carry = true;
                        }
                    }else{// 00
                        if(carry){// 00, 1
                            str[j] = '1';
                            carry = false;
                        }else{// 00,0
                            str[j] = '0';
                        }
                    }
                }
            }
              int dif = l_str.size() - s_str.size() -1;
             for(int i=dif;i>=0;i--,j++){
                 if(l_str[i] =='1'){
                     if(carry){//1,1
                         str[j] = '0';
                     }else{//1,0
                         str[j] = '1';
                     }
                 }else{ //0
                     if(carry){//0,1
                         str[j] = '1';
                         carry = false;
                     }else{//0 0
                         str[j] = '0';
                     }
                 }
             }
            if(carry && str[j] =='0')
                str[j] = '1';
           
             reverse(str.begin(),str.end());
              for(auto s:str){
                 ans += s;
              }
          
            if(ans[0] == '0')
                ans.erase(0,1); 
        }
        return ans;
    }
};
