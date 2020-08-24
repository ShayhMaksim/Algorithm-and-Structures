#ifndef EXERCICE1_1
#define EXERCICE1_1

#include <string>

/**
 * @brief findAbsolute
 * @param name
 * @return
 * Дополнительные структуры данных запрещены
 */
bool findA(char a,std::string name,int position)
{
    for (int i=0;i<name.size();i++){
        if (i==position) continue;
        char re=name[i];
        if (re==a)
        {
            return false;
        }
    }
    return true;
}

bool findAbsolute(std::string name)
{
    bool key=true;
    for(int i=0;i<name.size();i++){
        char a=name[i];
        key=findA(a,name,i);
        if (key==false) return false;
    }
    return key;
}

/**
 * @brief findAbsolute2
 * @param name
 * @return
 * решение через ASCII
 */

bool findAbsolute2(std::string name)
{
    if (name.size()>128) return false;
    bool Keys[128];
    bool key=true;
    for(int i=0;i<name.size();i++){
        int val=name[i];
        if (Keys[val]){
            return false;
        }
        Keys[val]=true;
    }
    return true;
}



#endif // EXERCICE1_1
