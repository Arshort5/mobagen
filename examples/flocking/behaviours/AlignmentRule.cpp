#include "AlignmentRule.h"
#include "../gameobjects/Boid.h"

Vector2f AlignmentRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  // Try to match the heading of neighbors = Average velocity
  Vector2f averageVelocity = Vector2f::zero();
  int i = 0;
  for (i; i < neighborhood.size(); i++) 
  {
    averageVelocity += neighborhood[i]->getVelocity();
  }
  averageVelocity += boid->getVelocity();
  averageVelocity = averageVelocity / (i + 1);

  return Vector2f::normalized(averageVelocity);
}