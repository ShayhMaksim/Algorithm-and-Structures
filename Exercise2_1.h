#ifndef EXERCISE2_1_H
#define EXERCISE2_1_H

#include <list>
#include <map>

void deleteDublicate(std::list<int> list)
{
    std::map<int,bool> count;

    for(auto it:list){
        auto finder = count.find(it);
        if (finder==count.end())
        {
            count[it]=true;
            continue;
        }
        if (finder!=count.end()){
            list.remove(it);
        }
    }
}


#endif // EXERCISE2_1_H
