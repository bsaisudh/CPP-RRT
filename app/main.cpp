#include <iostream>
#include <vector>
#include <memory>

#include "../include/Square.h"
#include "../include/Obstacle.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main() {
  int noOb;
  cout << "Enter number of obstacles : ";
  cin >> noOb;
  vector<std::unique_ptr<Obstacle>> ob;
  for (int i = 0; i < noOb; i++) {
    int type;
    cout << "Enter type: \n 1. Square \n";
    cin >> type;
    switch (type) {
      case 1:
        ob.emplace_back(new Square);
        ob[i]->setBoundary();
        break;
      default:
        cout << "By default square obstacle is considered\n";
        ob.emplace_back(new Square);
        ob[i]->setBoundary();
        break;
    }
  }
  for (const auto& i : ob) {
    i->dispBoundary();
  }

  for (const auto& i : ob) {
    int x,y;
    cout << "enter 2 numbers:";
    cin >> x >> y;
    (i->inObstacle(x,y))?(cout<<"yes"):(cout<<"no");
  }
  return 0;
}
