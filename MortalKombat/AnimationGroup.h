#ifndef AnimationGroup_H
#define AnimationGroup_H

#include "Animation.h"

using namespace sf;
using namespace std;

class AnimationGroup {
public:
	AnimationGroup() = default;
	AnimationGroup(Animation anim);
	bool DoAnimation(RectangleShape& body, RectangleShape& shadow, RectangleShape& hitbox, bool mirrored, bool player2,
		float hitbox_positions_X[], float hitbox_positions_Y[], Vector2<float> globalPosition, vector<RectangleShape> hitboxes,
		RectangleShape& damage_hitbox, float damage_hitbox_positions_X[], float damage_hitbox_positions_Y[], vector<RectangleShape> damage_hitboxes);
	void AddAnimation(Animation anim);
	bool RecieveFlagEvent();
	void ResetAnimation();

	vector<Animation> animations;
	int current_animation = 0;

private:
	int n_animations = 0;

};

#endif //ANIMATION_GROUP_H

