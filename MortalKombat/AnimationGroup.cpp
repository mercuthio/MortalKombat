#include "AnimationGroup.h"

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



bool AnimationGroup::DoAnimation(RectangleShape& body, RectangleShape& shadow, RectangleShape& hitbox, bool mirrored,
		float hitbox_positions_X[], float hitbox_positions_Y[], Vector2<float> globalPosition, vector<RectangleShape> hitboxes,
		RectangleShape& damage_hitbox, float damage_hitbox_positions_X[], float damage_hitbox_positions_Y[], vector<RectangleShape> damage_hitboxes) {

	bool finished = animations[current_animation].DoAnimation(body, shadow, hitbox, mirrored, hitbox_positions_X, hitbox_positions_Y, globalPosition,
		hitboxes, damage_hitbox, damage_hitbox_positions_X, damage_hitbox_positions_Y, damage_hitboxes);
	if (finished) {
		current_animation++;
		if (current_animation == n_animations) {
			current_animation = 0;
			return true;
		}
	}
	return false;
}