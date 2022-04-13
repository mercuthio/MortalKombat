#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H

#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class MusicManager {
public:
	MusicManager() = default;
	MusicManager();
	void startIntro();
	void endIntro();

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

private:
	Sound intro[2];
	Sound announcers[20];
	Sound UI[5];
	Sound history;
	Sound arenas[3];
	Sound scorpion[2];
};

MusicManager::MusicManager() {

	SoundBuffer buffer;
	//INTRO
	buffer.loadFromFile("audio/musiccues/startIntro.ogg");
	intro[0].setBuffer(buffer);
	buffer.loadFromFile("audio/musiccues/endIntro.ogg");
	intro[1].setBuffer(buffer);
	//ANUNCIADOR
	buffer.loadFromFile("audio/announcer/excellent.ogg");
	announcers[0].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/fatality.ogg");
	announcers[1].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/fight.ogg");
	announcers[2].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/finishHer.ogg");
	announcers[3].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/finishHim.ogg");
	announcers[4].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/JhonnyCage.ogg");
	announcers[5].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/JhonnyCageWins.ogg");
	announcers[6].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/Kano.ogg");
	announcers[7].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/KanoWins.ogg");
	announcers[8].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/laugh.ogg");
	announcers[9].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/LiuKang.ogg");
	announcers[10].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/LiuKangWins.ogg");
	announcers[11].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/Raiden.ogg");
	announcers[12].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/RaidenWins.ogg");
	announcers[13].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/Scorpion.ogg");
	announcers[14].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/ScorpionWins.ogg");
	announcers[15].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/SonyaBlade.ogg");
	announcers[16].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/SonyaBladeWins.ogg");
	announcers[17].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/SubZero.ogg");
	announcers[18].setBuffer(buffer);
	buffer.loadFromFile("audio/announcer/SubZeroWins.ogg");
	announcers[19].setBuffer(buffer);
	//UI
	buffer.loadFromFile("audio/ui/moveMain.ogg");
	UI[0].setBuffer(buffer);
	buffer.loadFromFile("audio/ui/moveOptions.ogg");
	UI[1].setBuffer(buffer);
	buffer.loadFromFile("audio/ui/moveSelector.ogg");
	UI[2].setBuffer(buffer);
	buffer.loadFromFile("audio/ui/skipIntro.ogg");
	UI[3].setBuffer(buffer);
	//History
	buffer.loadFromFile("audio/musiccues/history.ogg");
	history.setBuffer(buffer);
	//Arenas
	buffer.loadFromFile("audio/arenas/claps.ogg");
	arenas[0].setBuffer(buffer);
	buffer.loadFromFile("audio/arenas/loosePublic.ogg");
	arenas[1].setBuffer(buffer);
	buffer.loadFromFile("audio/arenas/victoryPublic.ogg");
	arenas[2].setBuffer(buffer);
	//Scorpion
	buffer.loadFromFile("audio/scorpion/comeHere.ogg");
	scorpion[0].setBuffer(buffer);
	buffer.loadFromFile("audio/scorpion/getOverHere.ogg");
	scorpion[1].setBuffer(buffer);

}

void MusicManager::startIntro() { intro[0].play(); }
void MusicManager::endIntro() { intro[1].play(); }

void MusicManager::excellente() { announcers[0].play(); }
void MusicManager::fatality() { announcers[1].play(); }
void MusicManager::fight() { announcers[2].play(); }
void MusicManager::finishHer() { announcers[3].play(); }
void MusicManager::finishHim() { announcers[4].play(); }
void MusicManager::JhonnyCage() { announcers[5].play(); }
void MusicManager::JhonnyCageWins() { announcers[6].play(); }
void MusicManager::Kano() { announcers[7].play(); }
void MusicManager::KanoWins() { announcers[8].play(); }
void MusicManager::laugh() { announcers[9].play(); }
void MusicManager::LiuKang() { announcers[10].play(); }
void MusicManager::LiuKangWins() { announcers[11].play(); }
void MusicManager::Raiden() { announcers[12].play(); }
void MusicManager::RaidenWins() { announcers[13].play(); }
void MusicManager::Scorpion() { announcers[14].play(); }
void MusicManager::ScorpionWins() { announcers[15].play(); }
void MusicManager::SonyaBlade() { announcers[16].play(); }
void MusicManager::SonyaBladeWins() { announcers[17].play(); }
void MusicManager::SubZero() { announcers[18].play(); }
void MusicManager::SubZeroWins() { announcers[19].play(); }

void MusicManager::moveMain() { UI[0].play(); }
void MusicManager::moveOptions() { UI[1].play(); }
void MusicManager::moveSelector() { UI[2].play(); }
void MusicManager::skipIntro() { UI[3].play(); }

void MusicManager::History() { intro[0].play(); }

void MusicManager::claps() { arenas[0].play(); }
void MusicManager::loosePublic() { arenas[1].play(); }
void MusicManager::victoryPublic() { arenas[2].play(); }

void MusicManager::comeHere() { scorpion[0].play(); }
void MusicManager::getOverHere() { scorpion[1].play(); }


#endif

