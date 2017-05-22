#ifndef __ENEMY_2CASTLETURRET_H__
#define __ENEMY_2CASTLETURRET_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_2CannonTurret : public Enemy
{

private:
	iPoint original_pos;
	fPoint distance;
	Animation closed, closed_hit, closed_damaged;
	Animation attacking, attacking_hit, attacking_damaged;
	int counter = 0;

	Path path;
public:
	Enemy_2CannonTurret(int x, int y, int option);
	void Shoot();
	void Move();
	int initcounter = 0;
	float aux_float;
	fPoint speeds;
};
#endif