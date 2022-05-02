#include "SpecialAttack.h"

SpecialAttack::SpecialAttack() {
	frame = 0;
	finished = true;
	hasHit = false;

	spriteSheet = new Texture();
	Image spriteSheetImage;
	Color back = Color(165, 231, 255, 255);

	spriteSheetImage.loadFromFile("resources/Sprites/Personajes/Special.png");
	spriteSheetImage.createMaskFromColor(back);

	spriteSheet->loadFromImage(spriteSheetImage);

	body.setTexture(spriteSheet);

	cout << "[!] Loaded special attack textures." << endl;
}

void SpecialAttack::Update() {

	if (internalTimer >= 0.05) {
		internalTimer = 0.0f;

		if (looking_at == LookingAt::RIGHT && body.getPosition().x >= screenRightHardLimit) {
			finished = true;
		} else if (looking_at == LookingAt::LEFT && body.getPosition().x - body.getSize().x <= screenLeftHardLimit) {
			finished = true;
		}

		if (!finished) {
			if (!hasHit) {
				float posX = body.getPosition().x;
				float posY = body.getPosition().y;
				body.setPosition(Vector2f(posX + 25, posY));
			}

			finished = SpecialAttackAnimation();
		}
	}
	else {
		internalTimer += 0.025f;
	}
}

void SpecialAttack::SpecialAttackAt(SpecialType type, Vector2f position, bool mirrored) {
	animationInProgress = type;
	body.setPosition(position);
	finished = false;
	hasHit = false;
}

bool SpecialAttack::SpecialAttackAnimation() {

	IntRect uvRect;
	Vector2f size_liuAnim = Vector2f(68.0f, 11.0f);
	Vector2f size_liuHit = Vector2f(65.0f, 87.0f);

	Vector2f size_sonyaAnim = Vector2f(41.0f, 35.0f);
	Vector2f size_sonyaHit = Vector2f(43.0f, 129.0f);

	int maxFrames;
	if (!hasHit) {
		maxFrames = totalFramesAnim[(int)animationInProgress];
	}
	else {
		maxFrames = totalFramesHit[(int)animationInProgress];
	}

	if (frame < maxFrames) {
		switch (animationInProgress)
		{
		case SpecialType::LIU_KANG:
			if (!hasHit) {
				body.setSize(size_liuAnim);
				body.setScale(3.0f, 3.0f);
				uvRect.left = 3.0f + (size_liuAnim.x + 1) * frame;
				uvRect.top = 57.0f;
				uvRect.width = size_liuAnim.x;
				uvRect.height = size_liuAnim.y;
				body.setTextureRect(uvRect);

				if (frame == maxFrames - 1) {
					frame = 0;
				}
				else {
					frame++;
				}
			}
			else {
				body.setSize(size_liuHit);
				body.setScale(3.0f, 3.0f);
				uvRect.left = 142.0f + (size_liuHit.x + 2) * frame;
				uvRect.top = 12.0f;
				uvRect.width = size_liuHit.x;
				uvRect.height = size_liuHit.y;
				body.setTextureRect(uvRect);
				frame++;
			}
			break;
		case SpecialType::SCORPION:
			break;
		case SpecialType::SONYA:
			break;
		default:
			break;
		}
	}
	else {
		frame = 0;
		return true;
	}
	return false;
}

void SpecialAttack::draw(RenderWindow& window) {
	if (!finished) {
		window.draw(body);
	}
}