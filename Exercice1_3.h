#ifndef EXERCICE1_3_H
#define EXERCICE1_3_H

#include <string>


/**
 * @brief replace
 * @param a
 * @param size
 * @return
 * очень плохой вариант, правильная с конца переставлять, а элементы брать с самого начала
 */
std::string replace(std::string a, size_t size)
{
    std::string result="";
    for(int j=0;j<size;j++)
    {
        if (int(a[j])==32){
            result+="20%";
        } else {
            result+=a[j];
        }
    }
    return result;
}


std::string replace2(std::string a)
{
    int spaceCount=0;
    int old_size=a.size();
    for(int i=0;i<a.size();i++){
        if (int(a[i])==32)
        spaceCount++;
    }

    int newLength=a.size()+spaceCount*2;

    a.resize(newLength,char(32));

    for(int i=old_size-1;i>=0;i--){
        if (int(a[i])==32){
            a[newLength-1]='0';
            a[newLength-2]='2';
            a[newLength-3]='%';
            newLength=newLength-3;
        } else {
            a[newLength-1]=char(a[i]);
            newLength=newLength-1;
        }
    }
    return a;
}


#endif // EXERCICE1_3_H
