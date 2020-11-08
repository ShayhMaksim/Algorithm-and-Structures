#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{

   Apex Arad("Arad");
   Apex Zerind("Zerind");
   Apex Oradea("Oradea");
   Apex Sibiu("Sibiu");
   Apex Timisoara("Timisoara");
   Apex Lugoj("Lugoj");
   Apex Mehadia("Mehadia");
   Apex Drobeta("Drobeta");
   Apex Craiova("Craiova");
   Apex Pitesti("Pitesti");
   Apex Fagaras("Fagaras");
   Apex RimnicuVilcea("Rimnicu Vilcea");
   Apex Bucharest("Bucharest");
   Apex Giorgiu("Giorgiu");
   Apex Urzicenu("Urzicenu");
   Apex Eforie("Eforie");
   Apex Hirsova("Hirsova");
   Apex Vaslui("Vaslui");
   Apex Iasi("Iasi");
   Apex Neamt("Neamt");


   std::list<Edge> listing={
     Edge{&Arad,&Zerind,75},Edge{&Zerind,&Arad,75},
     Edge{&Zerind,&Oradea,71},Edge{&Oradea,&Zerind,71},

     Edge{&Oradea,&Sibiu,151},Edge{&Sibiu,&Oradea,151},
     Edge{&Sibiu,&Fagaras,99},Edge{&Fagaras,&Sibiu,99},

     Edge{&Fagaras,&Bucharest,211},Edge{&Bucharest,&Fagaras,211},
     Edge{&Sibiu,&RimnicuVilcea,80},Edge{&RimnicuVilcea,&Sibiu,80},

     Edge{&RimnicuVilcea,&Pitesti,97},Edge{&Pitesti,&RimnicuVilcea,97},
     Edge{&RimnicuVilcea,&Craiova,146},Edge{&Craiova,&RimnicuVilcea,146},

     Edge{&Craiova,&Pitesti,138},Edge{&Pitesti,&Craiova,138},
     Edge{&Pitesti,&Bucharest,101},Edge{&Bucharest,&Pitesti,101},

     Edge{&Arad,&Sibiu,140},Edge{&Sibiu,&Arad,140},
     Edge{&Arad,&Timisoara,118},Edge{&Timisoara,&Arad,118},

     Edge{&Timisoara,&Lugoj,111},Edge{&Lugoj,&Timisoara,111},
     Edge{&Lugoj,&Mehadia,70},Edge{&Mehadia,&Lugoj,70},

     Edge{&Mehadia,&Drobeta,75},Edge{&Drobeta,&Mehadia,75},
     Edge{&Drobeta,&Craiova,120},Edge{&Craiova,&Drobeta,120},

     Edge{&Giorgiu,&Bucharest,90},Edge{&Bucharest,&Giorgiu,90},
     Edge{&Neamt,&Iasi,87}, Edge{&Iasi,&Neamt,87},

     Edge{&Iasi,&Vaslui,92}, Edge{&Vaslui,&Iasi,92},
     Edge{&Vaslui,&Urzicenu,142},Edge{&Urzicenu,&Vaslui,142},

     Edge{&Eforie,&Hirsova,86},Edge{&Hirsova,&Eforie,86},
     Edge{&Hirsova,&Urzicenu,98},Edge{&Urzicenu,&Hirsova,98},
     Edge{&Hirsova,&Bucharest,85},Edge{&Bucharest,&Hirsova,85},
   };

  DIJKSTRA(listing,&Arad, &Bucharest);

   std::cout << "Algorithm's DIJKSTRA---------------------------------------"<< std::endl;

  std::cout << Bucharest.name << " " << Bucharest.len <<endl;

  auto iterator = Bucharest.before;

  while (iterator!=nullptr){
      std::cout << iterator->name << " " << iterator->len <<endl;
      iterator=iterator->before;
      if (iterator->before==nullptr) {
          std::cout << iterator->name << " " << iterator->len <<endl;
          break;
        }

    }


  std::cout << "Breadth First Search -----------------------------------------"<< std::endl;
    auto res=BFS(listing,&Bucharest);

    for(auto it:res){
        std::cout << it->name <<" " <<it->flag <<std::endl;
    }
      std::cout << std::endl;
  return 0;
}
