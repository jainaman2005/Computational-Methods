#include<bits/stdc++.h>
#define tolerance 0.01
float function(int coff[],int order,float x);
float bisection_method(float a,float b,int coff[],int order);
int main(){
    //for equation:
    int order;
    std::cout<<"Enter the order of polynomial:"<<std::endl;
    std::cin>>order;
    int coff[order+1];
    std::cout<<"Enter the coefficient in increasing order:";
    for(int i = 0;i<=order;i++)
    std::cin>>coff[i];

    //interval 
    float a,b;
    std::cout<<"Enter the root bracket interval: ";
    std::cin>>a>>b;

    //root finding by bisection method :
    float root  =  bisection_method(a,b,coff,order);

    return 0;
}
float function(int coff[],int order,float x){
    float y = coff[0];
    for(int i =1;i<=order;i++){
        y+=(pow(x,i)*coff[i]);
    }
    return y;
}
float bisection_method(float a,float b,int coff[],int order){
    float ya = function(coff,order,a);
    float yb = function(coff,order,b);
    if(ya*yb > 0){
        std::cout<<"incoreect initial guess.";
        return -100000.0;
    }
    float c,yc;
    do{
        c = (a+b)/2;
        ya = function(coff,order,a);
        yb = function(coff,order,b);
        yc = function(coff,order,c);
        if(ya*yc < 0)
        b = c;
        else 
        a  = c;
    }while((yc)> tolerance);
    return c;
}