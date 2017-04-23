#include<math.h>
#include "Application.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleCastleScene.h"

#include "Enemy_Redbomb.h"
#include "ModuleCollision.h"
#include "SDL/include/SDL_timer.h"

Enemy_Redbomb :: Enemy_Redbomb(int x, int y, int option) : Enemy(x, y, option)
{
	
	fly.PushBack({ 100, 58, 28, 32 });
	fly.PushBack({ 128, 58, 28, 32 });
	fly.PushBack({ 156, 58, 28, 32 });
	fly.PushBack({ 184, 58, 28, 32 });
	fly.PushBack({ 100, 90, 28, 32 });
	fly.PushBack({ 128, 90, 28, 32 });
	fly.PushBack({ 156, 90, 28, 32 });
	fly.PushBack({ 184, 90, 28, 32 });

	fly.speed = 0.3f;

	animation = &fly;

	hp = 1.0f;

	if (option == 0)
	{
		path.PushBack({ 0.0f, 0.55f }, 600);
		path.PushBack({ 1.75f, 1.75f }, 2000);
	}

	if (option == 1)
	{
		path.PushBack({ 0.0f, 2.0f }, 10000);
	}
	if (option == 2)
	{
		path.PushBack({ 0.0f, 0.55f }, 1500);
		path.PushBack({ -2.0f, 0.55f }, 18);
		path.PushBack({ 0.0f, 0.55f }, 30);
		path.PushBack({ 0.0f, 2.0f }, 1000);
	}
	if (option == 3)
	{
		path.PushBack({ 0.0f, 0.55f }, 1500);
		path.PushBack({ -2.0f, 0.55f }, 33);
		path.PushBack({ 0.0f, 0.55f }, 30);
		path.PushBack({ 0.0f, 2.0f }, 1000);
	}
	if (option == 4)
	{
		path.PushBack({ 0.0f, 0.55f }, 1500);
		path.PushBack({ -2.0f, 0.55f }, 49);
		path.PushBack({ 0.0f, 0.55f }, 30);
		path.PushBack({ 0.0f, 2.0f }, 1000);
	}
	if (option == 5)
	{
		path.PushBack({ 0.0f, 0.55f }, 1500);
		path.PushBack({ -2.0f, 0.55f }, 64);
		path.PushBack({ 0.0f, 0.55f }, 30);
		path.PushBack({ 0.0f, 2.0f }, 1000);
	}
	if (option == 6)
	{
		path.PushBack({ 0.0f, 0.55f }, 1500);
		path.PushBack({ -2.0f, 0.55f }, 80);
		path.PushBack({ 0.0f, 0.55f }, 30);
		path.PushBack({ 0.0f, 2.0f }, 1000);
	}
	if (option == 7)
	{
		path.PushBack({ 0.0f, 0.55f }, 1500);
		path.PushBack({ -2.0f, 0.55f }, 96);
		path.PushBack({ 0.0f, 0.55f }, 30);
		path.PushBack({ 0.0f, 2.0f }, 1000);
	}
	if (option == 8)
	{
		path.PushBack({ 0.0f, 0.55f }, 1500);
		path.PushBack({ -2.0f, 0.55f }, 112);
		path.PushBack({ 0.0f, 0.55f }, 30);
		path.PushBack({ 0.0f, 2.0f }, 1000);
	}

	if (option == 9)
	{
		path.PushBack({ 0.0f, 0.55f },2120);
		path.PushBack({ 0.0f, 3.0f }, 100000);
	}

	if (option == 10)
	{
		path.PushBack({ 0.0f, 0.55f }, 2050);
		path.PushBack({ 0.0f, 0.55f }, 70);//this is done in order to allow the bombs to start tracking the player when they appear in the screen. More questions, ask Lori�n/Witiza
		path.PushBack({ 0.0f, 3.0f }, 100000);
	}

	collider = App->collision->AddCollider({ 0, 0,  28, 32 }, COLLIDER_TYPE::COLLIDER_ENEMY_F, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
	original_x = x;

	death_type = SMALL_ENEMY;

	flying = true;
}

void Enemy_Redbomb::Move()
{
	if (pathoption == 10 && following == false)
	{
		if (path.Get_current_step() > 1)
		{
			
			int x = position.x - App->player->position.x ;
			int y = position.y - App->player->position.y;
			float time = y / 3.0f;
			
			path.steps[2].speed.x = (x / time);
			path.steps[2].speed.y = 3.0f;
			
			following = true;
		}
	}
		position = original_pos + path.GetCurrentPosition();
	
}

void Enemy_Redbomb::Shoot()
{
	
}
