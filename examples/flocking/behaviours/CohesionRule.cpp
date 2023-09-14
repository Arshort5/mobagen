#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2f CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  Vector2f cohesionForce;
  Vector2f centerOfMass;
  int i = 0;

  for (i; i < neighborhood.size(); i++) 
  {
    centerOfMass = centerOfMass + neighborhood[i]->transform.position;

  }
  centerOfMass = centerOfMass / neighborhood.size();


  if ((centerOfMass - boid->getPosition()).getMagnitude() <= boid->getDetectionRadius()) 
  {
    cohesionForce = (centerOfMass - boid->getPosition()) / boid->getDetectionRadius();
  } 
  else 
  {
    cohesionForce = Vector2f::zero();
  }
 


  return cohesionForce;
}