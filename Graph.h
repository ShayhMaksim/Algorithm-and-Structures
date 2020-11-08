#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
#include <set>
#include <stack>


/**
 * @brief The Apex struct - вершина
 */
struct Apex
{
    bool flag=false;
    std::string name;
    int f_topo=0;
    // предыдущая вершина
    Apex * before = nullptr;
    // значение для len()=ininity
    size_t len=1000000;
    Apex(std::string name):name(name){}
};


/**
 * @brief The Edge struct - ребро
 * @arg first - начало
 * @arg second - конец
 */
struct Edge
{
    Apex * first;
    Apex * second;
    size_t distance;
    Edge(Apex * first,Apex * second,size_t distance=0):first(first),second(second),distance(distance){}
};


/**
 * @brief BFS - обратите внимание, что через меняются по ссылке флаги вершин
 * @param listing
 * @param s
 * @param typeOfGraph
 * @return
 *
 */
std::list<Apex*> BFS(std::list<Edge> listing,Apex * s,bool clear=true,bool flag=true){
    std::list<Apex*> result;

    s->flag=true;

    result.push_back(s);

    std::queue<Apex*> queue;
    queue.push(s);


    while (!queue.empty())
    {
       Apex *v=queue.front();
       queue.pop();
       for(auto it=listing.begin(); it!=listing.end();it++){
           if (it->first==v)
           {
               if(it->second->flag==false) {
                   it->second->flag=true;
                   result.push_back(it->second);
                   queue.push(it->second);
               }
           } else if ((it->second==v)&&(flag==true)) {
               if(it->first->flag==false){
               it->first->flag=true;
               result.push_back(it->first);
               queue.push(it->first);
               }
           }

       }
    }

    if (clear==true)
    for(auto it:result)
        it->flag=false;

    return result;
}


std::map<Apex*,int> distByBFS(std::list<Edge> listing,Apex *s,bool clear=true,bool flag=true)
{
    s->flag=true;
    std::map<Apex*,int> distanceMap;
    distanceMap.insert(std::pair<Apex*,int>(s,0));
    std::queue<Apex*> queue;
    queue.push(s);

    while (!queue.empty())
    {
       Apex *v=queue.front();

       queue.pop();
       for(auto it=listing.begin(); it!=listing.end();it++){
           if (it->first==v)
           {
               if(it->second->flag==false) {
                   it->second->flag=true;
                   distanceMap[it->second]=distanceMap[v]+1;
                   queue.push(it->second);
               }
           } else if ((it->second==v)&&(flag==true)) {
               if(it->first->flag==false){
                   it->first->flag=true;
                   distanceMap[it->first]=distanceMap[v]+1;
                   queue.push(it->first);
               }
           }
       }
    }

    if (clear==true)
    for(auto it:distanceMap)
        it.first->flag=false;

    return distanceMap;
}


std::vector<std::list<Edge>> UCC(std::list<Edge> listing,std::list<Apex*> Apexs,bool clear=true,bool flag=true)
{
   std::vector<std::list<Edge>> Edges;

   for(auto it:Apexs){
       if (it->flag==false){
           std::list<Edge> current;
           it->flag=true;
           std::queue<Apex*> queue;
           queue.push(it);
           while (!queue.empty())
           {
               Apex *v=queue.front();

               queue.pop();
               for(auto it=listing.begin(); it!=listing.end();it++){
                   if (it->first==v)
                   {
                       if(it->second->flag==false) {
                           it->second->flag=true;
                           queue.push(it->second);
                       }
                       current.push_back(*it);
                   } else if ((it->second==v)&&(flag==true)) {
                       if(it->first->flag==false){
                           it->first->flag=true;
                           queue.push(it->first);
                       }
                   }
               }

           }
           Edges.push_back(current);
       }
   }

   if (clear==true)
   for(auto it:Apexs)
       it->flag=false;

   return Edges;
}

std::list<Apex*> DFS(std::list<Edge> listing,Apex * s,bool clear=true,bool flag=true)
{
    std::list<Apex*> result;
    std::stack<Apex*> stack;

    stack.push(s);

    while (!stack.empty())
    {
        Apex *v=stack.top();
        stack.pop();

        if (v->flag!=true)
        {
            v->flag=true;
            result.push_back(v);
            for(auto it=listing.begin(); it!=listing.end();it++){
                if (it->first==v)
                {
                    stack.push(it->second);
                } else if ((it->second==v)&&(flag==true)) {
                    stack.push(it->first);
                }

            }
        }
    }

    if (clear==true)
        for(auto it:result)
            it->flag=false;

    return result;
}

void reqursionDFS(std::list<Edge> listing,Apex * s,std::list<Apex*> & result,bool clear=true,bool flag=true)
{
    s->flag=true;
    result.push_back(s);
    for(auto it=listing.begin(); it!=listing.end();it++){
        if (it->first==s)
        {
            auto v=it->second;
            if(v->flag==false){
                reqursionDFS(listing,v,result,clear,flag);
            }
        } else if ((it->second==s)&&(flag==true)){
            auto v=it->first;
            if(v->flag==false){
                reqursionDFS(listing,v,result,clear,flag);
            }
        }
    }
}


void DFS_topo(std::list<Edge> listing,Apex * s,int & curLabel,std::list<Apex*> & result,bool clear=true,bool flag=true)
{
    s->flag=true;
    result.push_back(s);

    for(auto it=listing.begin(); it!=listing.end();it++){
        if (it->first==s)
        {
            auto v=it->second;
            if(v->flag==false){
                DFS_topo(listing,v,curLabel,result,clear,flag);
            }
        }

    }

    s->f_topo=curLabel;
    curLabel=curLabel-1;
}

void DFS_TOPOSORT(std::list<Edge> listing,Apex * s,std::list<Apex *> lister,std::list<Apex*> & result,bool clear=true,bool flag=true)
{
    int curLabel=lister.size();
    for(auto it=lister.begin(); it!=lister.end();it++){
            if((*it)->flag==false){
                DFS_topo(listing,*it,curLabel,result,clear,flag);
        }
    }
    if (clear==true)
        for(auto it:result)
            it->flag=false;
}

void DIJKSTRA(std::list<Edge> listing,Apex *s,Apex * v)
{
      std::list<Apex*> X;

      s->len=0;
      X.push_back(s);

      for (auto x : X) {
          std::vector<Apex*> pool;
          for(auto it=listing.begin(); it!=listing.end();it++){
              if ((it->first==x) && (it->second!=x)){
                  if (it->second->len>(it->first->len+it->distance)) {
                      it->second->len=it->first->len+it->distance;
                      it->second->before=it->first;          
                      X.push_back(it->second);
                    }
                }
            }
        }
      return;
}


size_t h(std::string name)
{
  if (name ==("Arad")) return 366;
  if (name ==("Zerind")) return 374;
  if (name == ("Oradea")) return 380;
  if (name ==("Sibiu")) return 253;
  if (name ==("Timisoara")) return 329;
  if (name == ("Lugoj")) return 244;
  if (name == ("Mehadia")) return 241;
  if (name == ("Drobeta")) return 242;
  if (name == ("Craiova")) return 160;
  if (name == ("Pitesti")) return 100;
  if (name == ("Fagaras")) return 176;
  if (name == ("Rimnicu Vilcea")) return 193;
  if (name == ("Bucharest")) return 0;
  if (name == ("Giorgiu")) return 77;
  if (name ==("Urzicenu")) return 80;
  if (name == ("Eforie")) return 161;
  if (name == ("Hirsova")) return 151;
  if (name == ("Vaslui")) return 199;
  if (name == ("Iasi")) return 226;
  if (name == ("Neamt")) return 234;

  return 0;
}


Apex* minimum (std::vector<Apex*> Q,std::map<Apex*,size_t> f) {
    size_t min=100000;
    Apex* element=nullptr;
   for (auto it: Q) {
       if (f[it]<min)
         {
           min = f[it];
           element=it;
         }
     }
   return element;
}

bool AStar(std::list<Edge> listing,Apex *s,Apex * v){

  // prepare
  for(auto it=listing.begin(); it!=listing.end();it++){
      it->first->len=1000000;
    }

  //std::map<Apex*,size_t> g;
  std::map<Apex*,size_t> f;


  std::vector<Apex*> Q;
  std::vector<Apex*> U;

  s->len=0;
  Q.push_back(s);
  f.insert(std::pair<Apex*,size_t>(s,s->len+h(s->name)));

  while(Q.size()!=0) {
      auto current = minimum(Q,f);
      if (current==v) return true;
      for (auto q=Q.begin();q!=Q.end();q++){
          if (*q==current)
            {
              Q.erase(q);
              break;
            }
        }
      U.push_back(current);
      for(auto it=listing.begin(); it!=listing.end();it++){
          if ((it->first==current) && (it->second!=current)) {
              auto tentativeScore = current->len + it->distance;
              for (auto u=U.begin();u!=U.end();u++){
                  if ((*u==it->second) &&  (tentativeScore>=it->second->len)) continue;
                }
              if (tentativeScore<it->second->len) {
                  it->second->before=current;
                  it->second->len = tentativeScore;
                  f[it->second] = it->second->len + h(v->name);
                  for (auto q=Q.begin();q!=Q.end();q++){
                      if (*q==it->second) {
                          continue;
                        }
                    }
                  Q.push_back(it->second);
                }
            }
        }
    }
  return false;
}


#endif // GRAPH_H
