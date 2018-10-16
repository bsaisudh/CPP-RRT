#include <iostream>
#include <vector>
#include <memory>

#include "../include/InputMap.h"
#include "../include/RobotWorkspace.h"
#include "../include/Obstacle.h"
#include "../include/Square.h"
#include "../include/Circle.h"
#include "../include/PathDisplay.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main() {

  std::shared_ptr<RobotWorkspace> _ws(new RobotWorkspace);
  _ws->setBoundary(cin, cout);
  _ws->setStart(cin, cout);
  _ws->setGoal(cin, cout);
  _ws->dispWorkspace(cout);
  cout << "Enter number of obstacles : ";

  int noOb;
  cin >> noOb;
  vector<std::shared_ptr<Obstacle>> ob;
  for (int i = 0; i < noOb; i++) {
    int obType;
    cout << "Enter type: \n 1. Square \n 2. Circle";
    cin >> obType;
    switch (obType) {
      case 1:
        ob.emplace_back(new Square);
        ob[i]->setBoundary(cin, cout);
        break;
      case 2:
        ob.emplace_back(new Circle);
        ob[i]->setBoundary(cin, cout);
        break;
      default:
        cout << "By default square obstacle is considered\n";
        ob.emplace_back(new Square);
        ob[i]->setBoundary(cin, cout);
        break;
    }
  }

  for (const auto& i : ob) {
    i->dispBoundary(cout);
  }

  for (const auto& i : ob) {
    int x, y;
    cout << "enter 2 numbers:";
    cin >> x >> y;
    (i->inObstacle(x, y)) ? (cout << "yes" << endl) : (cout << "no" << endl);
  }
  std::shared_ptr<InputMap> im(new InputMap);
  im->addObstacle(ob);
  im->setWorkspace(std::move(_ws));
  im->computeConfigSpace();
  im->dispConfigSpace(std::cout);
  PathDisplay path;
  path.updateInputMap(std::move(im));
  path.displayPath(std::cout);
  return 0;
}
