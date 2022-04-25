#pragma once

#include "Character.h";
#include "GlobalVars.h";

class IA {
public:
	IA() = default;
	IA(map<AnimationType, Movement> _animations, RectangleShape & _body, RectangleShape & _shadow, map<AnimationType, vector<RectangleShape>> _hitboxes, Difficulty _difficulty, Character _opponent);
	//~Character() = delete;

	void Update(float time);
	void UpdateIA(float time);
	void debugDraw(RenderWindow & window);

	void GetHit(int life);

	void initPosition(Vector2<float> initPos);

	float GetLife();

	LookingAt lookingAt() {
		return looking_at;
	}

	float GetXPosition() {
		return global_position.x;
	}

	void SetXPosition(float x) {
		global_position.x += x;
	}

	void Mirror();

	void setPlayer(int p) {
		player = p;
	}

	void setFreeze(bool freeze_) {
		freeze = freeze_;
	};
private:
	RectangleShape body;
	RectangleShape shadow;
	RectangleShape hitbox;
	Character opponent;
	Difficulty difficulty;
	EstadoIA estado;
	int duracionEstadoActual = 0;

	Vector2<float> global_position;
	map<AnimationType, Movement> animations; // mapa de enum -> animacion
	map<AnimationType, vector<RectangleShape>> hitboxes;

	float internalTimer = 0.05f;
	int freezeTimer = 0;

	int life = 100;

	bool doing_animation = false;

	bool on_air = false;
	bool punching = false;
	bool crouching = false;
	bool blocking = false;
	bool fallen = false;
	bool dying = false;
	bool wait_air = false;
	bool fightKeyPressed = false;
	bool removePunchNext = false;
	bool freeze = true;		//Para el comienzo de partidas, no permite mover
	bool mirrorOnEnd = false;
	bool mirroring = false;

	LookingAt looking_at = LookingAt::LEFT;

	Vector2<float> speed;

	bool mirrored = false;

	int player = 0;

	AnimationType animation_in_process;

	void EndAndResetAnimation();

	void DoAnimation();
	void EndAnimation();

	void CheckAnimation();
	void CheckCollisions();
	bool CheckScreenCollisions(float movement);
	void ChangeState();
};