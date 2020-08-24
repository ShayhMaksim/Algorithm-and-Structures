#ifndef EXERCICE1_2_q_H
#define EXERCICE1_2_q_H

#include<string>
#include<iostream>

int partial(int a[],int first,int last);
int chooser(int a[],int first,int last);

void quicksort(int *a,const int first,const int last)
{
    if (first >=last ) return;

    int j=partial(a,first,last);

    quicksort(a,first,j-1);
    quicksort(a,j+1,last);
}

int partial(int *a,const int first,const int last)
{
    int main=a[first];
    int next=first+1;
    for(int i=first+1;i<last;i++){
        if (main>a[i]){
            std::swap(a[i],a[next]);
            next++;
        }
    }
    std::swap(a[first],a[next-1]);
    return next-1;
}
int chooser(int *a,const int first,const int last)
{
    return first;
}



#endif // EXERCICE1_2_H
