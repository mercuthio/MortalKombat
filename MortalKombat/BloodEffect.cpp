#include "BloodEffect.h"

BloodEffect::BloodEffect() {

	frame = 0;
	finished = true;

	spriteSheet = new Texture();
	Image spriteSheetImage;
	Color back = Color(165, 231, 255, 255);

	spriteSheetImage.loadFromFile("resources/Sprites/Varios/Menus.png");
	spriteSheetImage.createMaskFromColor(back);

	spriteSheet->loadFromImage(spriteSheetImage);

	body.setTexture(spriteSheet);

	cout << "[!] Loaded blood textures." << endl;

}

void BloodEffect::Update() {

	if (internalTimer >= 0.05) {
		internalTimer = 0.0f;
		if (!finished) {
			finished = bloodEffectAnimation();
		}
	}
	else {
		internalTimer += 0.015f;
	}
}

void BloodEffect::bloodEffectAt(BloodType type, Vector2f position) {
	animationInProgress = type;
	body.setPosition(position);
	finished = false;
}

bool BloodEffect::bloodEffectAnimation() {

	IntRect uvRect;
	Vector2f size_right = Vector2f(60.0f, 31.0f);
	Vector2f size_left = Vector2f(68.0f, 36.0f);
	Vector2f size_ground = Vector2f(48.0f, 46.0f);
	Vector2f size_up = Vector2f(49.0f, 64.0f);

	int maxFrames = totalFrames[(int) animationInProgress];
	int frameAux;

	if (frame < maxFrames) {
		switch (animationInProgress)
		{
		case BloodType::RIGHT:
			body.setSize(size_right);
			body.setScale(3.0f, 3.0f);
			uvRect.left = 5406.0f + (size_right.x + 1) * frame;
			uvRect.top = 360.0f;
			uvRect.width = size_right.x;
			uvRect.height = size_right.y;
			body.setTextureRect(uvRect);
			break;
		case BloodType::LEFT:
			body.setSize(size_left);
			body.setScale(3.0f, 3.0f);
			uvRect.left = 5406.0f + (size_left.x + 1) * frame;
			uvRect.top = 393.0f;
			uvRect.width = size_left.x;
			uvRect.height = size_left.y;
			body.setTextureRect(uvRect);
			break;
		case BloodType::UP:
			body.setSize(size_up);
			body.setScale(3.0f, 3.0f);
			uvRect.left = 5406.0f + (size_up.x + 1) * frame;
			uvRect.top = 246.0f;
			uvRect.width = size_up.x;
			uvRect.height = size_up.y;
			body.setTextureRect(uvRect);
			break;
		case BloodType::GROUND:
			frameAux = frame;
			if (frameAux > 2) frameAux = 2;
			body.setSize(size_ground);
			body.setScale(3.0f, 3.0f);
			uvRect.left = 5609.0f + (size_ground.x + 1) * frameAux;
			uvRect.top = 312.0f;
			uvRect.width = size_ground.x;
			uvRect.height = size_ground.y;
			body.setTextureRect(uvRect);
			break;
		default:
			break;
		}
		frame++;
	}
	else {
		frame = 0;
		return true;
	}

	return false;

}

void BloodEffect::draw(RenderWindow& window) {

	if (!finished) {
		window.draw(body);
	}

}