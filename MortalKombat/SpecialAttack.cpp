#include "SpecialAttack.h"

SpecialAttack::SpecialAttack() {
	frame = 0;
	resetSpecial();

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
	float midTimer = 0.f;

	switch (animationInProgress)
	{
	case SpecialType::LIU_KANG:
		maxInitTimer = 0.33f;
		midTimer = 0.17f;
		break;
	case SpecialType::SCORPION:
		maxInitTimer = 0.00f;
		break;
	case SpecialType::SONYA:
		midTimer = 0.03f;
		maxInitTimer = 0.10f;
		break;
	default:
		break;
	}


	if (!finished) {
		cout << "Animation" << endl;
		cout << "Started: " << started << endl;
		cout << "Finished: " << finished << endl;
		cout << "------------------------------------" << endl;
		if (initInternalTimer >= maxInitTimer) {
			if (internalTimer >= 0.05f) {
				internalTimer = 0.0f;

				if ((looking_at == LookingAt::RIGHT && body.getPosition().x >= screenRightHardLimit)
					|| (looking_at == LookingAt::LEFT && body.getPosition().x - body.getSize().x <= screenLeftHardLimit)) {
					if (looking_at == LookingAt::RIGHT) {
						cout << "CIAO ============================= RIGHT" << endl;
					} else if (looking_at == LookingAt::LEFT) {
						cout << "CIAO ============================= LEFT" << endl;
					}
					else {
						cout << "CIAO ============================= NONE" << endl;
					}
					resetSpecial();
				}
				else {
					if (!hasHit) {
						float posX = body.getPosition().x;
						float posY = body.getPosition().y;
						if (mirrored) body.setPosition(Vector2f(posX - 60, posY));
						else body.setPosition(Vector2f(posX + 60, posY));
					}
					else {
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
		else if (initInternalTimer == midTimer) {
			cout << "timer" << endl;
			switch (animationInProgress)
			{
			case SpecialType::LIU_KANG:
				music.liuKangSpecial01();
				break;
			case SpecialType::SCORPION:
				//
				break;
			case SpecialType::SONYA:
				music.sonyaSpecial01();
				break;
			default:
				break;
			}
			initInternalTimer += 0.01f;
		}
		else {
			initInternalTimer += 0.01f;
		}
	}
}

void SpecialAttack::SpecialAttackAt(SpecialType type, Vector2f position, bool _mirrored) {
	if (!started && finished) {
		cout << "NEW ATTACK" << endl << endl << endl << endl << endl << endl;
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
		mirrored = _mirrored;

		if (mirrored) looking_at = LookingAt::LEFT;
		else looking_at = LookingAt::RIGHT;
		initInternalTimer = 0;
	}
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
				if (mirrored) uvRect.width = -size_liuAnim.x;
				else uvRect.width = size_liuAnim.x;
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
				if (mirrored) uvRect.width = -size_liuHit.x;
				else uvRect.width = size_liuHit.x;
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
				uvRect.top = 144.0f + (size_scorpionAnim.y + 2) * frame;
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
				body.setSize(size_scorpionHit1);
				body.setScale(3.0f, 3.0f);
				uvRect.left = 3.0f;
				uvRect.top = 262.0f + (size_scorpionHit1.y + 2) * frame;
				uvRect.width = size_scorpionHit1.x;
				uvRect.height = size_scorpionHit1.y;
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
				if (mirrored) uvRect.width = -size_sonyaAnim.x;
				else uvRect.width = size_sonyaAnim.x;
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
				if (mirrored) uvRect.width = -size_sonyaHit.x;
				else uvRect.width = size_sonyaHit.x;
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
		cout << "Draw" << endl;
		window.draw(body);
	}
}