#ifndef Movement_H
#define Movement_H

#include "AnimationGroup.h"

struct Movement {
	AnimationGroup animation;
	Vector2<float> traslation;
	float hitbox_positions_X[30];
	float hitbox_positions_Y[30];
};

#endif //MOVEMENT_H