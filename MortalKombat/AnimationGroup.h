#ifndef AnimationGroup_H
#define AnimationGroup_H

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

	int current_animation = 0;

private:
	vector<Animation> animations;
	int n_animations = 0;

};

#endif //ANIMATION_GROUP_H

