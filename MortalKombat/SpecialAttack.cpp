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

	float maxInitTimer = 0.f;

	switch (animationInProgress)
	{
	case SpecialType::LIU_KANG:
		maxInitTimer = 0.33f;
		break;
	case SpecialType::SCORPION:
		maxInitTimer = 0.05f;
		break;
	case SpecialType::SONYA:
		maxInitTimer = 0.10f;
		break;
	default:
		break;
	}


	if (!finished) {
		if (initInternalTimer >= maxInitTimer) {
			if (internalTimer >= 0.05f) {
				internalTimer = 0.0f;

				if ((looking_at == LookingAt::RIGHT && body.getPosition().x >= screenRightHardLimit)
					|| (looking_at == LookingAt::LEFT && body.getPosition().x - body.getSize().x <= screenLeftHardLimit)) {
					finished = true;
					started = false;
				}
				else {
					if (!hasHit) {
						float posX = body.getPosition().x;
						float posY = body.getPosition().y;
						body.setPosition(Vector2f(posX + 60, posY));
					}
					else {
						cout << "debug" << endl;
						body.setPosition(Vector2f(body.getPosition().x, initY - 50*3));
					}

					finished = SpecialAttackAnimation();
					started = !finished;
				}
			}
			else {
				internalTimer += 0.025f;
			}
		}
		else if (initInternalTimer == 0.17f) {
			music.liuKangSpecial01();
			initInternalTimer += 0.01f;
		}
		else {
			initInternalTimer += 0.01f;
		}
	}
}

void SpecialAttack::SpecialAttackAt(SpecialType type, Vector2f position, bool mirrored) {
	animationInProgress = type;
	body.setPosition(position);
	switch (type)
	{
	case SpecialType::SCORPION:
		body.setOrigin(size_scorpionAnim.x, 0);
		break;
	default:
		body.setOrigin(0, 0);
		break;
	}
	initY = position.y;
	finished = false;
	started = false;
	hasHit = false;
	initInternalTimer = 0;
}

bool SpecialAttack::SpecialAttackAnimation() {
	IntRect uvRect;

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
			if (!hasHit) {
				body.setSize(size_scorpionAnim);
				body.setScale(3.0f, 3.0f);
				uvRect.left = 3.0f;
				uvRect.top = 124.0f + (size_scorpionAnim.y + 2) * frame;
				uvRect.width = size_scorpionAnim.x;
				uvRect.height = size_scorpionAnim.y;
				body.setTextureRect(uvRect);

				if (frame == maxFrames - 1) {
					frame = 0;
				}
				else {
					frame++;
				}
			}
			else {
				body.setSize(size_scorpionHit);
				body.setScale(3.0f, 3.0f);
				uvRect.left = 3.0f;
				uvRect.top = 262.0f + (size_scorpionHit.y + 2) * frame;
				uvRect.width = size_scorpionHit.x;
				uvRect.height = size_scorpionHit.y;
				body.setTextureRect(uvRect);
				frame++;
			}
			break;
		case SpecialType::SONYA:
			if (!hasHit) {
				body.setSize(size_sonyaAnim);
				body.setScale(3.0f, 3.0f);
				uvRect.left = 2.0f;
				uvRect.top = 454.0f;
				uvRect.width = size_sonyaAnim.x;
				uvRect.height = size_sonyaAnim.y;
				body.setTextureRect(uvRect);

				if (frame == maxFrames - 1) {
					frame = 0;
				}
				else {
					frame++;
				}
			}
			else {
				body.setSize(size_sonyaHit);
				body.setScale(3.0f, 3.0f);
				uvRect.left = 47.0f + (size_sonyaHit.x + 2) * frame;
				uvRect.top = 400.0f;
				uvRect.width = size_sonyaHit.x;
				uvRect.height = size_sonyaHit.y;
				body.setTextureRect(uvRect);
				frame++;
			}
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
	if (started && !finished) {
		window.draw(body);
	}
}