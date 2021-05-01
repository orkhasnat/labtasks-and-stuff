#include <iostream>
#include <vector>
#include <cstring>

int a[100];
int size = 0;

void pushback(int n){
    a[size]=n;
    size++;
}
void popback(){
    size--;
}

void insert(int index,int n){
    int tmp[100];
    for(int i=index,j=0;i<size;i++,j++)
        tmp[j]=a[i];
    a[index]=n;
    size++;
    for (int i = 0,j=index+1;j<size; i++,j++)
        a[j]=tmp[i];
}
void erase(int start,int end){
    int tmp[100];
    for(int i=0;i<size;i++)
        tmp[i]=a[i]; //copy
    for(int i=end,j=start;i<size;i++,j++)
        a[j]=tmp[i+1]; 
    size-=end-start+1;  
}

void print(){
    for (int i = 0; i < size; i++)
        std::cout<<a[i]<<" ";   
    std::cout<<std::endl;
}

int main(){
    std::vector <int> yum;
    yum.push_back(10);
    yum.push_back(45);
    yum.push_back(15);
    yum.push_back(745);
    yum.push_back(4);
    yum.insert(yum.begin()+3,12);
    yum.pop_back();
    yum.erase(yum.begin()+2,yum.begin()+4);
    for(auto it:yum) std::cout<<it<<" ";
    std::cout << "\nThis part is for arrays!!\n";
    //memset(a,-1,sizeof(a));
    pushback(10);
    pushback(11);
    pushback(13);
    pushback(14);
    insert(2,12);
    //popback();
    erase(1,2);
    print();
}
