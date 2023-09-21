#include "JohnConway.h"

// Reference: https://playgameoflife.com/info
void JohnConway::Step(World& world) 
{ 
	for (int c = 0; c < world.SideSize(); c++) {
        for (int l = 0; l < world.SideSize(); l++) {
            if (CountNeighbors(world, {c, l}) < 2 && world.Get({c, l}) == true) {
            world.SetNext({c, l}, false);
            } 
            else if ((CountNeighbors(world, {c, l}) == 2 || CountNeighbors(world, {c, l}) == 3) && world.Get({c, l}) == true) 
            {
            world.SetNext({c, l}, true);
            } 
            else if (CountNeighbors(world, {c, l}) > 3 && world.Get({c,l}) == true) 
            {
            world.SetNext({c, l}, false);
            } 
            else if (CountNeighbors(world, {c, l}) == 3 && world.Get({c, l}) == false) 
            {
            world.SetNext({c, l}, true);
            }
        }
    }
}

int JohnConway::CountNeighbors(World& world, Point2D point) { 
    return 
        world.Get(point.Up().Left()) + 
        world.Get(point.Up()) + 
        world.Get(point.Up().Right())+ 
        world.Get(point.Left()) + 
        world.Get(point.Right())+ 
        world.Get(point.Down().Left()) + 
        world.Get(point.Down().Right()) + 
        world.Get(point.Down());





}
