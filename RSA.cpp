#include <iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

class encrypt{
    private:
    char s[1000],msg[1000],en[1000], ms[1000];;
    long long int n,x=0,y=0,i,t,j,e,temp[1000];
    double d;
    
    long int cd(long long int a){
          long long int k=1;
          while(1){
              k=k+t;
              if(k%a==0){
                  return (k/a);
              }
          }
    }

    void encryalgo(){
        long int m=0;
         do{
            e=rand();
            m=e/2;
            for(int i=2;i<=m;i++){
                if(e%i==0){
                    e=rand();
                    m=e/2;
                    i=2;
                }
            }
         }while(e>t || e<1);
    
        d=cd(e);
        
        strcpy(msg,s);

        long int pt,ct,key=e,k,len;
        

        strcpy(ms,msg);

        i=0;
        len=strlen(msg);

        while(i!=len){
            pt=ms[i];
            pt=pt-96;
            k=1;
            for(j=0;j<key;j++){
                k=k*pt;
                k=k%n;
            }
            temp[i]=k;
            ct=k+96;
            en[i]=ct;
            i++;
        }
        en[i]=-1;
    
        cout<<"encrypted message: ";
        for(i=0;en[i]!=-1;i++){
            cout<<en[i];
        }
        cout<<endl;
    }
    
    void decryalgo(){
       long int pt,ct,k,key=d;

        i=0;
       while(en[i]!=-1){
           ct=temp[i];
           k=1;
           for(j=0;j<key;j++){
               k=k*ct;
               k=k%n;
           }
           pt=k+96;
           ms[i]=pt;
           i++;
       }
       ms[i]=-1;

       cout<<"decrypted message: ";
       for(int i=0;ms[i]!=-1;i++){
           cout<<ms[i];
       }
       cout<<endl;
    } 

    public:
    int prime1(){
        cout<<"Enter the 1st prime number: ";
        cin>>x;
        j=sqrt(x);
        for(i=2;i<=j;i++){
            if(x%i==0){
            cout<<"Re-enter"<<endl;
            return 0;
            }
        }
        return 1;
    }

    int prime2(){
        cout<<"Enter the 2nd prime number: ";
        cin>>y;
        j=sqrt(y);
        for(i=2;i<=j;i++){
            if(y%i==0){
            cout<<"Re-enter"<<endl;
            return 0;
            }
        }
        return 1;
    }

    encrypt(){
        int w,c;

        do{
        w=prime1();
        }while(w!=1);

        do{
        c=prime2();
        }while(c!=1);
        
        cout<<"Please enter the string:";
        cin>>s;
        n=x*y;
        t=(x-1)*(y-1);
        srand(time(0));
    }

    void callencry(){
        encryalgo();
    }

    void calldecry(){
        decryalgo();
    }
};

int main(){
    encrypt e;
    e.callencry();
    e.calldecry();
return 0;
}