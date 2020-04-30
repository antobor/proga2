#include "CIntN0.hpp"

int CIntN0::output(){
    ofstream out;
    out.open(file.c_str());
    for (int i=0;i<len+1;i++){
        out << k[i];
    }
    out.close();

    return 0;
}

CIntN0 operator+(CIntN& first, CIntN& second){
    if(first.len != second.len){
        cout << "SUM ERROR, CANCELED " << endl;
    }
    int i,t=0;
    int len = first.len;
    CIntN0 sum(first.len);
    sum.file = first.file;

    if ((first.k[0]==0 && second.k[0]==0)||(first.k[0]==1 && second.k[0]==1)){


    for(i=0;i<len;i++)
    {
        sum.k[len-i]=first.k[len-i]+second.k[len-i];
    }
    for(i=0;i<len-1;i++)
    {
        if (sum.k[len-i]>9)
        {
            sum.k[len-i]=sum.k[len-i]-10;
            sum.k[len-1-i]=sum.k[len-1-i]+1;
        }
    }
    if(sum.k[1]>9 || sum.k[1]<1)
    {
        for(i=0;i<len+1;i++)
        {
            sum.k[i]=0;
        }
        cout << "SUM ERROR, CANCELED " << endl;
    }
    if(first.k[0]==0){
        sum.k[0]=0;
    }
    else{
        sum.k[0]=1;
    }

    return sum;
    }



    else{
            for(i=0;i<len;i++)
    {
        sum.k[len-i]=first.k[len-i]-second.k[len-i];
    }
    for(i=0;i<len-1;i++)
    {
        if (sum.k[len-i]<0)
        {
            sum.k[len-i]=sum.k[len-i]+10;
            sum.k[len-1-i]=sum.k[len-1-i]-1;
        }
    }
    if(sum.k[1]>9 || sum.k[1]<-9)
    {
        for(i=0;i<len+1;i++)
        {
            sum.k[i]=0;
        }
        cout << "SUM ERROR, CANCELED " << endl;
    }
    if(sum.k[1]<0){
        sum.k[1]=abs(sum.k[1]);
        t=1;
    }

    if(first.k[0]==0){
            if(t==1){
                sum.k[0]=1;
            }
        else{sum.k[0]=0;}
    }
    else{
            if(t==1){
                sum.k[0]=0;
            }
        else{sum.k[0]=1;}
    }

    return sum;
    }
}
