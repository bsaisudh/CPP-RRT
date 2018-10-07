#include <iostream>

#include "../include/Square.h"
#include "../include/Obstacle.h"
#include <vector>

using std::vector;


int main(){
//  Obstacle *ob[2];
  Square sq0,sq1;
  vector<Obstacle*> ob;

  ob.push_back(&sq0);
  ob.push_back(&sq1);

  ob[0]->setBoundary();
  ob[1]->setBoundary();


  return 0;
}
