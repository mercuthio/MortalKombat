#ifndef ANIMATION_GROUP_H
#define ANIMATION_GROUP_H

#include "Animation.h"

using namespace sf;
using namespace std;

class AnimationGroup {
public:
	AnimationGroup() = default;
	AnimationGroup(Animation anim);
	bool DoAnimation(RectangleShape& body);
	void AddAnimation(Animation anim);
	bool RecieveFlagEvent();
	void ResetAnimation();

private:
	vector<Animation> animations;
	int n_animations;
	int current_animation = 0;
};

AnimationGroup::AnimationGroup(Animation anim) {
	animations = vector<Animation>();
	animations.push_back(anim);
	n_animations = 1;
}

void AnimationGroup::AddAnimation(Animation anim) {
	animations.push_back(anim);
	n_animations++;
}

bool AnimationGroup::RecieveFlagEvent() {
	return animations[current_animation].RecieveFlagEvent();
}

void AnimationGroup::ResetAnimation() {
	for (int i = 0; i < n_animations; i++) {
		animations[i].ResetAnimation();
	}		
	current_animation = 0;
}

bool AnimationGroup::DoAnimation(RectangleShape& body) {
	bool finished = animations[current_animation].DoAnimation(body);
	if (finished) {
		current_animation++;
		if (current_animation == n_animations) {
			current_animation = 0;
			return true;
		}
	}
	return false;
}

#endif //ANIMATION_GROUP_H

