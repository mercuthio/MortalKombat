#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H

#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class MusicManager {
public:
	MusicManager();
	~MusicManager() = default;

	void presentsIntro();
	void startIntro();
	void endIntro();
	void selectorIntro();

	void excellente();
	void fatality();
	void fight();
	void finishHer();
	void finishHim();
	void JhonnyCage();
	void JhonnyCageWins();
	void Kano();
	void KanoWins();
	void laugh();
	void LiuKang();
	void LiuKangWins();
	void Raiden();
	void RaidenWins();
	void Scorpion();
	void ScorpionWins();
	void SonyaBlade();
	void SonyaBladeWins();
	void SubZero();
	void SubZeroWins();

	void moveMain();
	void moveOptions();
	void moveSelector();
	void skipIntro();

	void History();

	void claps();
	void loosePublic();
	void victoryPublic();

	void comeHere();
	void getOverHere();

	void reduceVolumeMusic() { volumeMusic -= 20.f;};
	void addVolumeMusic() { volumeMusic += 20.f;};

	void reduceVolumeEffects() { volumeEffects -= 20.f; };
	void addVolumeEffects() { volumeEffects += 20.f; };

private:
	Sound intro[4];
	Sound announcers[20];
	Sound UI[5];
	Sound history;
	Sound arenas[3];
	Sound scorpion[2];

	SoundBuffer bufferIntro[4];
	SoundBuffer bufferAnnouncers[20];
	SoundBuffer bufferUI[5];
	SoundBuffer bufferHistory;
	SoundBuffer bufferArenas[3];
	SoundBuffer bufferScorpion[2];

	float volumeMusic = 80.f;
	float volumeEffects = 80.f;

};

#endif

