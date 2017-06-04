#include<math.h>
#include "Application.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleCastleScene.h"
#include "ModuleVillageScene.h"
#include "Enemy_FlyingGunner.h"
#include "ModuleCollision.h"
#include "SDL/include/SDL_timer.h"

Enemy_FlyingGunner::Enemy_FlyingGunner(int x, int y, int option) : Enemy(x, y, option)
{
	status = OPENING;

	nothing.PushBack({ 866, 328, 32, 33 });
	
	arriving_left1.PushBack({ 836, 380, 32, 36 });
	arriving_left1.PushBack({ 836, 422, 32, 36 });
	arriving_left1.PushBack({ 836, 338, 32, 36 });
	arriving_left1.PushBack({ 836, 380, 32, 36 });
	arriving_left1.PushBack({ 836, 422, 32, 36 });
	arriving_left1.PushBack({ 836, 338, 32, 36 });
	arriving_left1.PushBack({ 836, 380, 32, 36 });
	arriving_left1.PushBack({ 836, 422, 32, 36 });
	arriving_left1.PushBack({ 836, 338, 32, 36 });

	arriving_left1.PushBack({ 874, 338, 32, 36 });
	arriving_left1.PushBack({ 874, 422, 32, 36 });
	arriving_left1.PushBack({ 732, 380, 32, 36 });
	arriving_left1.PushBack({ 764, 338, 32, 36 });
	arriving_left1.PushBack({ 764, 380, 32, 36 });
	arriving_left1.loop = false;
	arriving_left1.speed = 0.37f;
		
	arriving_left2.PushBack({ 798, 338, 32, 36 });
	arriving_left2.PushBack({ 798, 380, 32, 36 });
	arriving_left2.PushBack({ 798, 422, 32, 36 });
	arriving_left2.PushBack({ 798, 338, 32, 36 });
	arriving_left2.PushBack({ 798, 380, 32, 36 });
	arriving_left2.PushBack({ 798, 422, 32, 36 });
	arriving_left2.PushBack({ 798, 338, 32, 36 });
	arriving_left2.loop = false;
	arriving_left2.speed = 0.37f;

	arriving_left3.PushBack({ 764, 380, 32, 36 });
	arriving_left3.PushBack({ 764, 422, 32, 36 });
	arriving_left3.PushBack({ 764, 338, 32, 36 });
	arriving_left3.PushBack({ 764, 465, 32, 36 });
	arriving_left3.speed = 0.37f;

	staying.PushBack({ 732, 380, 32, 36 });
	staying.PushBack({ 732, 422, 32, 36 });
	staying.PushBack({ 732, 338, 32, 36 });
	staying.loop = true;
	staying.speed = 0.3f;

	arriving_right1.PushBack({ 798, 380, 32, 36 });
	arriving_right1.PushBack({ 798, 422, 32, 36 });
	arriving_right1.PushBack({ 798, 338, 32, 36 });
	arriving_right1.PushBack({ 798, 380, 32, 36 });
	arriving_right1.PushBack({ 798, 422, 32, 36 });
	arriving_right1.PushBack({ 798, 338, 32, 36 });
	arriving_right1.PushBack({ 798, 380, 32, 36 });
	arriving_right1.PushBack({ 798, 422, 32, 36 });
	arriving_right1.PushBack({ 798, 338, 32, 36 });

	arriving_right1.PushBack({ 764, 380, 32, 36 });
	arriving_right1.PushBack({ 764, 338, 32, 36 });
	arriving_right1.PushBack({ 732, 422, 32, 36 });
	arriving_right1.PushBack({ 874, 338, 32, 36 });
	arriving_right1.loop = false;
	arriving_right1.speed = 0.3f;

	arriving_right2.PushBack({ 836, 338, 32, 36 });
	arriving_right2.PushBack({ 836, 380, 32, 36 });
	arriving_right2.PushBack({ 836, 422, 32, 36 });
	arriving_right2.PushBack({ 836, 338, 32, 36 });
	arriving_right2.PushBack({ 836, 380, 32, 36 });
	arriving_right2.PushBack({ 836, 422, 32, 36 });
	arriving_right2.PushBack({ 836, 338, 32, 36 });
	arriving_right2.loop = false;
	arriving_right3.speed = 0.3f;

	arriving_right3.PushBack({ 874, 338, 32, 36 });
	arriving_right3.PushBack({ 874, 380, 32, 36 });
	arriving_right3.PushBack({ 874, 422, 32, 36 });
	arriving_right3.PushBack({ 874, 465, 32, 36 });
	arriving_right3.speed = 0.3f;

	animation = &nothing;

	hp = 1.0f;

	if (option == 0)
	{
		path.PushBack({ 0.0f, 0.4f }, 1700); 
		path.PushBack({ 0.6f, 0.4f }, 51);
		path.PushBack({ 0.0f, 0.4f }, 45);
	}

	if (option == 1)
	{
		path.PushBack({ 0.0f, 0.4f }, 1700); 
		path.PushBack({ -0.6f, 0.4f }, 51);
		path.PushBack({ 0.0f, 0.4f }, 45);
	}

	collider = App->collision->AddCollider({ 0, 0,  32, 36 }, COLLIDER_TYPE::COLLIDER_ENEMY_F, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
	original_x = x;

	death_type = SMALL_ENEMY;

	flying = true;
	killscore = 200;
}

void Enemy_FlyingGunner::Move()
{
	position = original_pos + path.GetCurrentPosition();

	if (pathoption == 0 && position.y == -50) { hasfinishedleft = true; }
	if (pathoption == 1 && position.y == -50) { hasfinishedright = true; }
	
	if (status == OPENING && hasfinishedleft == true)
	{
		status = NORMAL;  animation = &arriving_left1;
	}
	if (status == OPENING && hasfinishedright == true && pathoption == 1 && position.y == -50)
	{
		status = NORMAL;  animation = &arriving_right1;
	}
	if (status == NORMAL && animation->Finished() == true && pathoption == 0) 
	{	
		animation = &arriving_left2; 
	}
	if (status == NORMAL && animation->Finished() == true && pathoption == 1)
	{
		animation = &arriving_right2;
	}
	if (status == NORMAL && animation->Finished() == true && pathoption == 0)
	{
		animation = &arriving_left3;
	}
	if (status == NORMAL && animation->Finished() == true && pathoption == 1)
	{
		animation = &arriving_right3;
	}
	if (status == NORMAL && animation->Finished() == true)
	{
		animation = &staying;
	}

}

