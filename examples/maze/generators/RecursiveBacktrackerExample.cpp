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
    w->SetNodeColor(stack.back(), Color::Black);
    stack.pop_back();
    } 

    else if (visitables.size() == 1)
    {
       

        if (visitables[0].x > stack.back().x) 
        {
          w->SetEast(stack.back(), false);
          w->SetWest(visitables[0], false);

        }
        else if (visitables[0].x < stack.back().x)
        {
        w->SetEast(visitables[0], false);
        w->SetWest( stack.back(), false);
        }
        else if (visitables[0].y > stack.back().y) 
        {
        w->SetSouth(stack.back(), false);
        w->SetNorth(visitables[0], false);
        }
        else if (visitables[0].y < stack.back().y) 
        {
        w->SetSouth(visitables[0], false);
        w->SetNorth(stack.back(), false);
        }

        stack.push_back(visitables[0]);
        w->SetNodeColor(visitables[0], Color::Green);
      
    } 
    else {
      int i = rand() % visitables.size();

      if (visitables[i].x > stack.back().x) {
        w->SetEast(stack.back(), false);
        w->SetWest(visitables[i], false);
      } else if (visitables[i].x < stack.back().x) {
        w->SetEast(visitables[i], false);
        w->SetWest(stack.back(), false);
      } else if (visitables[i].y > stack.back().y) {
        w->SetSouth(stack.back(), false);
        w->SetNorth(visitables[i], false);
      } else if (visitables[i].y < stack.back().y) {
        w->SetSouth(visitables[i], false);
        w->SetNorth(stack.back(), false);
      }




      stack.push_back(visitables[i]);
        w->SetNodeColor(visitables[i], Color::Green);
      
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
      if (!visited[x][y]) return {x, y};
  return {INT_MAX, INT_MAX};
}

std::vector<Point2D> RecursiveBacktrackerExample::getVisitables(World* w, const Point2D& p) {
  auto sideOver2 = w->GetSize() / 2;
  std::vector<Point2D> visitables;
  if (!visited[p.Left().x][p.y] && p.Left().x > -sideOver2+-1) 
  {
    visitables.push_back(p.Left());
  }
  if (!visited[p.Right().x][p.y] && p.Right().x < sideOver2+1) {
    visitables.push_back(p.Right());
  }

  if (!visited[p.x][p.Up().y] && p.Up().y > -sideOver2-1) {
    visitables.push_back(p.Up());
  }

  if (!visited[p.x][p.Down().y] && p.Down().y < sideOver2+1) {
    visitables.push_back(p.Down());
  }




  return visitables;
}
