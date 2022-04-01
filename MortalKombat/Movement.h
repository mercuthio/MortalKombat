#pragma once
#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "AnimationGroup.h"

struct Movement {
	AnimationGroup animation;
	Vector2<float> traslation;
};

#endif //MOVEMENT_H