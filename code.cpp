#include<bits/stdc++.h>
using namespace std;

string zeros(string x){ //removes trailing zeros at the beginning
    int j=x.length()-1;
    for(int i=0;i<j;i++){
        if(x[0]=='0'){
            x.erase(0,1);
        }
        else{
            break;
        }
    }
    return x;
}

//addition of two numbers using strings
string add(string a,string b){
    int aindex,bindex,carry=0;
    string sol="";
    aindex=a.length()-1;
    bindex=b.length()-1;
    while(aindex>=0 || bindex>=0 || carry!=0){
        if(aindex>=0){
            carry+=a[aindex]-'0';
            aindex--;
        }
        if(bindex>=0){
            carry+=b[bindex]-'0';
            bindex--;
        }
        sol.insert(sol.begin(),'0'+(carry%10));
        carry/=10;
    }
    return sol;

}
//multiplying numbers using string
string mult(string x,string y){
    string tmp,sum="0";
    x=zeros(x);
    y=zeros(y);
    int m,n,pro,carry;
    for(int i=y.length()-1;i>=0;i--){
            carry=0;
            m=int(y[i]-'0');
            tmp="";
        for(int j=x.length()-1;j>=0;j--){
            n=int(x[j]-'0');
            pro=(m*n+carry)%10;
            tmp=char(pro+'0')+tmp;
            carry=(m*n+carry)/10;
        }
        if(carry!=0)tmp=char(carry+'0')+tmp;
        for(int k=y.length()-1;k>i;k--){
            tmp=tmp+'0';
        }
        sum=add(tmp,sum);
    }
    return zeros(sum);
}

int main(){
    string x,y;
    cin>>x>>y;
    cout<<mult(x,y)<<'\n';
    return 0;
}
