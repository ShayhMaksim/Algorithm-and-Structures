#ifndef EXERCICE1_2_H
#define EXERCICE1_2_H

#include <algorithm>
#include <string>



int partial(std::string a,int first,int last);
int chooser(std::string a,int first,int last);

void quicksort(std::string a,const int first,const int last)
{
    if (first >=last ) return;

    int j=partial(a,first,last);

    quicksort(a,first,j-1);
    quicksort(a,j+1,last);
}

int partial(std::string a,const int first,const int last)
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
int chooser(std::string a,const int first,const int last)
{
    return first;
}


bool isEqual(std::string str1,std::string str2)
{
    if (str1.length()!=str2.length()) return false;
    quicksort(str1,0,str1.size());
    quicksort(str2,0,str2.size());

    bool key=true;
    for(int i=0;i<str1.size();i++){
        if (str1[i]!=str2[i]){
            return false;
        }
    }
    return key;
}


#endif // EXERCICE1_2_H
