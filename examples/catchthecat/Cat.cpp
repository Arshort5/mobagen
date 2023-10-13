#include "Cat.h"
#include "World.h"
#include <stdexcept>
#include <queue>
#include <vector>
#include <unordered_map>



bool contains(const std::vector<Point2D> vector, Point2D value) {return std::find(vector.begin(), vector.end(), value) != vector.end();
}



Point2D Cat::Move(World* world) {
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


    while (!searching.empty())
    {
      if (!world->getContent(World::NE(searching.front())) && !contains(visited, World::NE(searching.front()))) 
         {
          Point2D temp = World::NE(searching.front());
          points.emplace(temp, searching.front());
          costs.emplace(temp, costs.at(searching.front()) + 1);
          visited.push_back(temp);
           if (world->catWinsOnSpace(temp))
           {
             finished.push_back(temp);
           } 
           else {
             searching.push(temp);
           }
         } 
       if (!world->getContent(World::NW(searching.front())) && !contains(visited, World::NW(searching.front()))) {
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
        if (!world->getContent(World::E(searching.front())) && !contains(visited, World::E(searching.front()))) {
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
         if (!world->getContent(World::W(searching.front())) && !contains(visited, World::W(searching.front()))) {
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
          if (!world->getContent(World::SW(searching.front())) && !contains(visited, World::SW(searching.front()))) {
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
           if (!world->getContent(World::SE(searching.front())) && !contains(visited, World::SE(searching.front()))) {
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


    //no valid spots
    if (finished.empty()) 
    {
       
        while (true) {
           int rand = Random::Range(0, 5);
           if (!world->getContent(World::NE(pos)) && rand == 0) {
             return World::NE(pos);
           } else if (!world->getContent(World::NW(pos)) && rand == 1) {
             return World::NW(pos);
           } else if (!world->getContent(World::E(pos)) && rand == 2) {
             return World::E(pos);
           } else if (!world->getContent(World::W(pos)) && rand == 3) {
             return World::W(pos);
           } else if (!world->getContent(World::SW(pos)) && rand == 4) {
             return World::SW(pos);
           } else if (!world->getContent(World::SE(pos)) && rand == 5) {
             return World::SE(pos);
           }
        }
    } 
    else {
        for (int i = 0; i < finished.size(); i++) {
           if (costs.at(finished[i]) < costs.at(chosenPath) || (chosenPath.x == 0 && chosenPath.y == 0)) {
             chosenPath = finished[i];
           }
        }

        while (points.at(chosenPath).x != pos.x || points.at(chosenPath).y != pos.y) {
           chosenPath = points.at(chosenPath);
        }

        return chosenPath;
    
    }
    
    
 
}
