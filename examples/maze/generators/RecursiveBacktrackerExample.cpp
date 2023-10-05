#include "../World.h"
#include "Random.h"
#include "RecursiveBacktrackerExample.h"
#include <climits>
bool RecursiveBacktrackerExample::Step(World* w) 
{

  if (!initialized) 
  {

    initialized = true;
    Point2D startPoint = randomStartPoint(w);
    stack.push_back(startPoint);

  }



    if (!stack.empty()) 
    {

        w->SetNodeColor(stack.back(), Color::Red);

        if (visited[stack.back().x][stack.back().y]) 
        {
         w->SetNodeColor(stack.back(), Color::Black);
        }

         visited[stack.back().x][stack.back().y] = true;
   
        std::vector<Point2D> visitables = getVisitables(w, stack.back());

         if (visitables.empty())
         {
             stack.pop_back();
         } 

    else if (visitables.size() == 1)
    {
      stack.push_back(visitables[0]);

      if (visited[visitables[0].x][visitables[0].x]) {
        w->SetNodeColor(visitables[0], Color::Green);
      }
      
    } 
    else {
      int i = rand() % visitables.size();
      stack.push_back(visitables[i]);

      if (visited[visitables[i].x][visitables[i].x]) 
      {
        w->SetNodeColor(visitables[i], Color::Green);
      }
      
    }

    return true; 
    } 
    else 
    {
    false;
    }

  


}

void RecursiveBacktrackerExample::Clear(World* world) {
  visited.clear();
  stack.clear();
  initialized = false;
  auto sideOver2 = world->GetSize() / 2;

  for (int i = -sideOver2; i <= sideOver2; i++) {
    for (int j = -sideOver2; j <= sideOver2; j++) {
      visited[i][j] = false;
    }
  }
}
Point2D RecursiveBacktrackerExample::randomStartPoint(World* world) {
  auto sideOver2 = world->GetSize() / 2;

  // todo: change this if you want
  for (int y = -sideOver2; y <= sideOver2; y++)
    for (int x = -sideOver2; x <= sideOver2; x++)
      if (!visited[y][x]) return {x, y};
  return {INT_MAX, INT_MAX};
}

std::vector<Point2D> RecursiveBacktrackerExample::getVisitables(World* w, const Point2D& p) {
  auto sideOver2 = w->GetSize() / 2;
  std::vector<Point2D> visitables;
  if (!visited[p.LEFT.x][p.y]) 
  {
    visitables.push_back(p.LEFT);
  }
  if (!visited[p.RIGHT.x][p.y]) {
    visitables.push_back(p.RIGHT);
  }

  if (!visited[p.x][p.UP.y]) {
    visitables.push_back(p.UP);
  }

  if (!visited[p.x][p.DOWN.y]) {
    visitables.push_back(p.DOWN);
  }




  return visitables;
}
