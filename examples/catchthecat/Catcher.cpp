#include "Catcher.h"
#include "World.h"
#include <stdexcept>
#include <queue>
#include <vector>
#include <unordered_map>


bool contain(const std::vector<Point2D> vector, Point2D value) { return std::find(vector.begin(), vector.end(), value) != vector.end(); }


Point2D Catcher::Move(World* world) {
  auto pos = world->getCat();
  auto rand = Random::Range(0, 5);

  std::unordered_map<Point2D, Point2D> points;

  std::vector<Point2D> finished;
  std::unordered_map<Point2D, int> costs;
  costs.emplace(pos, 0);

  std::queue<Point2D> searching;
  searching.push(pos);

  std::vector<Point2D> visited;
  visited.push_back(pos);

  Point2D chosenPath{0, 0};

  while (!searching.empty()) {
   
    if (!world->getContent(World::NE(searching.front())) && !contain(visited, World::NE(searching.front()))) {
      Point2D temp = World::NE(searching.front());

      points.emplace(temp, searching.front());
      costs.emplace(temp, costs.at(searching.front()) + 1);
      visited.push_back(temp);
      if (world->catWinsOnSpace(temp)) {
        finished.push_back(temp);
      } else {
        searching.push(temp);
      }
    }
    if (!world->getContent(World::NW(searching.front())) && !contain(visited, World::NW(searching.front()))) {
      Point2D temp = World::NW(searching.front());

      points.emplace(temp, searching.front());
      costs.emplace(temp, costs.at(searching.front()) + 1);
      visited.push_back(temp);
      if (world->catWinsOnSpace(temp)) {
        finished.push_back(temp);
      } else {
        searching.push(temp);
      }
    }
    if (!world->getContent(World::E(searching.front())) && !contain(visited, World::E(searching.front()))) {
      Point2D temp = World::E(searching.front());

      points.emplace(temp, searching.front());
      costs.emplace(temp, costs.at(searching.front()) + 1);
      visited.push_back(temp);
      if (world->catWinsOnSpace(temp)) {
        finished.push_back(temp);
      } else {
        searching.push(temp);
      }
    }
    if (!world->getContent(World::W(searching.front())) && !contain(visited, World::W(searching.front()))) {
      Point2D temp = World::W(searching.front());
      points.emplace(temp, searching.front());
      costs.emplace(temp, costs.at(searching.front()) + 1);
      visited.push_back(temp);
      if (world->catWinsOnSpace(temp)) {
        finished.push_back(temp);
      } else {
        searching.push(temp);
      }
    }
    if (!world->getContent(World::SW(searching.front())) && !contain(visited, World::SW(searching.front()))) {
      Point2D temp = World::SW(searching.front());
      points.emplace(temp, searching.front());
      costs.emplace(temp, costs.at(searching.front()) + 1);
      visited.push_back(temp);
      if (world->catWinsOnSpace(temp)) {
        finished.push_back(temp);
      } else {
        searching.push(temp);
      }
    }
    if (!world->getContent(World::SE(searching.front())) && !contain(visited, World::SE(searching.front()))) {
      Point2D temp = World::SE(searching.front());
      points.emplace(temp, searching.front());
      costs.emplace(temp, costs.at(searching.front()) + 1);
      visited.push_back(temp);
      if (world->catWinsOnSpace(temp)) {
        finished.push_back(temp);
      } else {
        searching.push(temp);
      }
    }
    searching.pop();
  }

  if (finished.empty()) {
    if (!world->getContent(World::NE(pos))) {
      return World::NE(pos);
    } else if (!world->getContent(World::NW(pos))) {
      return World::NW(pos);
    } else if (!world->getContent(World::E(pos))) {
      return World::E(pos);
    } else if (!world->getContent(World::W(pos))) {
      return World::W(pos);
    } else if (!world->getContent(World::SW(pos))) {
      return World::SW(pos);
    } else if (!world->getContent(World::SE(pos))) {
      return World::SW(pos);
    }
  } 
  else {
    for (int i = 0; i < finished.size(); i++) {
      if (costs.at(finished[i]) < costs.at(chosenPath) || (chosenPath.x == 0 && chosenPath.y == 0)) {
        chosenPath = finished[i];
      }
    }

    return chosenPath;
  }
}
  /* auto side = world->getWorldSideSize() / 2;
  for (;;) {
    Point2D p = {Random::Range(-side, side), Random::Range(-side, side)};
    auto cat = world->getCat();
    if (cat.x != p.x && cat.y != p.y && !world->getContent(p)) return p;
  }
}
*/