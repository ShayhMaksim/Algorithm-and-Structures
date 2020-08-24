#include "Exercise2stack.h"
#include "Exercise2queue.h"
#include "Graph.h"
#include <iostream>
using namespace std;


int main()
{
    Apex s("s");
    Apex a("a");
    Apex b("b");
    Apex c("c");
    Apex d("d");
    Apex e("e");

    Apex x("x");
    Apex y("y");



    std::list<Edge> listing={
        Edge{&s,&b},
        Edge{&s,&a},
        Edge{&a,&c},
        Edge{&b,&c},
        Edge{&b,&d},
        Edge{&c,&e},
        Edge{&c,&d},
        Edge{&d,&e},
        Edge{&x,&y},
    };


    std::list<Apex *> lister={
        &s,&a,&b,&c,&d,&e,&x,&y,
    };


//  auto res=BFS(listing,&e);

//  for(auto it:res){
//      std::cout << it->name <<" " <<it->flag <<std::endl;
//  }
//    std::cout << std::endl;
//    auto Map=distByBFS(listing,&e);
//    for(auto it:Map){
//        std::cout <<it.first->name <<" " <<it.second <<std::endl;
//    }

//    std::cout<<std::endl;

//    auto lis=UCC(listing,lister);

//    for(unsigned int i=0;i<lis.size();i++){
//        for (auto l:lis[i]){
//            std::cout <<l.first->name <<" " <<l.second->name <<std::endl;
//        }
//        std::cout<<std::endl;
//    }


//    auto arg=DFS(listing,&s);
//    for(auto it:arg){
//        std::cout << it->name <<" " <<it->flag <<std::endl;
//    }

//    std::list<Apex*>  result;
//    reqursionDFS(listing,&s,result);
//    for(auto it:result){
//        std::cout << it->name <<" " <<it->flag <<std::endl;
//    }


    Apex q("q");
    Apex v("v");
    Apex w("w");
    Apex t("t");


    std::list<Edge> listing2={
        Edge{&q,&v},
        Edge{&q,&w},
        Edge{&v,&t},
        Edge{&w,&t},
    };


    std::list<Apex *> lister2={
        &v,&t,&q,&w,
    };


    std::cout <<std::endl;
    std::list<Apex*> res2;

    DFS_TOPOSORT(listing2,&q,lister2,res2);

    for(auto it:res2){
        std::cout << it->name <<" " <<it->f_topo <<std::endl;
    }
}
