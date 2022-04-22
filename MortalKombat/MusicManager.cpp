#include "MusicManager.h"

MusicManager::MusicManager() {
	
	//INTRO
	SoundBuffer buffer;
	Sound sound;

	for (int i = 0; i < 4; i++) { bufferIntro.push_back(buffer); intro.push_back(sound);}

	bufferIntro[0].loadFromFile("audio/musiccues/startIntro.ogg");
	intro[0].setBuffer(bufferIntro[0]);
	bufferIntro[1].loadFromFile("audio/musiccues/endIntro.ogg");
	intro[1].setBuffer(bufferIntro[1]);
	bufferIntro[2].loadFromFile("audio/musiccues/presents.ogg");
	intro[2].setBuffer(bufferIntro[2]);
	bufferIntro[3].loadFromFile("audio/musiccues/selector.ogg");
	intro[3].setBuffer(bufferIntro[3]);


	//MUSIC

	for (int i = 0; i < 2; i++) { bufferMusic.push_back(buffer); music.push_back(sound); }

	bufferMusic[0].loadFromFile("audio/music/mainTheme.ogg");
	music[0].setBuffer(bufferMusic[0]);
	bufferMusic[1].loadFromFile("audio/music/selectorTheme.ogg");
	music[1].setBuffer(bufferMusic[1]);



	//ANUNCIADOR

	for (int i = 0; i < 20; i++) { bufferAnnouncers.push_back(buffer); announcers.push_back(sound); }

	bufferAnnouncers[0].loadFromFile("audio/announcer/excellent.ogg");
	announcers[0].setBuffer(bufferAnnouncers[0]);
	bufferAnnouncers[1].loadFromFile("audio/announcer/fatality.ogg");
	announcers[1].setBuffer(bufferAnnouncers[1]);
	bufferAnnouncers[2].loadFromFile("audio/announcer/fight.ogg");
	announcers[2].setBuffer(bufferAnnouncers[2]);
	bufferAnnouncers[3].loadFromFile("audio/announcer/finishHer.ogg");
	announcers[3].setBuffer(bufferAnnouncers[3]);
	bufferAnnouncers[4].loadFromFile("audio/announcer/finishHim.ogg");
	announcers[4].setBuffer(bufferAnnouncers[4]);
	bufferAnnouncers[5].loadFromFile("audio/announcer/JhonnyCage.ogg");
	announcers[5].setBuffer(bufferAnnouncers[5]);
	bufferAnnouncers[6].loadFromFile("audio/announcer/JhonnyCageWins.ogg");
	announcers[6].setBuffer(bufferAnnouncers[6]);
	bufferAnnouncers[7].loadFromFile("audio/announcer/Kano.ogg");
	announcers[7].setBuffer(bufferAnnouncers[7]);
	bufferAnnouncers[8].loadFromFile("audio/announcer/KanoWins.ogg");
	announcers[8].setBuffer(bufferAnnouncers[8]);
	bufferAnnouncers[9].loadFromFile("audio/announcer/laugh.ogg");
	announcers[9].setBuffer(bufferAnnouncers[9]);
	bufferAnnouncers[10].loadFromFile("audio/announcer/LiuKang.ogg");
	announcers[10].setBuffer(bufferAnnouncers[10]);
	bufferAnnouncers[11].loadFromFile("audio/announcer/LiuKangWins.ogg");
	announcers[11].setBuffer(bufferAnnouncers[11]);
	bufferAnnouncers[12].loadFromFile("audio/announcer/Raiden.ogg");
	announcers[12].setBuffer(bufferAnnouncers[12]);
	bufferAnnouncers[13].loadFromFile("audio/announcer/RaidenWins.ogg");
	announcers[13].setBuffer(bufferAnnouncers[13]);
	bufferAnnouncers[14].loadFromFile("audio/announcer/Scorpion.ogg");
	announcers[14].setBuffer(bufferAnnouncers[14]);
	bufferAnnouncers[15].loadFromFile("audio/announcer/ScorpionWins.ogg");
	announcers[15].setBuffer(bufferAnnouncers[15]);
	bufferAnnouncers[16].loadFromFile("audio/announcer/SonyaBlade.ogg");
	announcers[16].setBuffer(bufferAnnouncers[16]);
	bufferAnnouncers[17].loadFromFile("audio/announcer/SonyaBladeWins.ogg");
	announcers[17].setBuffer(bufferAnnouncers[17]);
	bufferAnnouncers[18].loadFromFile("audio/announcer/SubZero.ogg");
	announcers[18].setBuffer(bufferAnnouncers[18]);
	bufferAnnouncers[19].loadFromFile("audio/announcer/SubZeroWins.ogg");
	announcers[19].setBuffer(bufferAnnouncers[19]);

	//UI

	for (int i = 0; i < 4; i++) { bufferUI.push_back(buffer); UI.push_back(sound); }

	bufferUI[0].loadFromFile("audio/ui/moveMain.ogg");
	UI[0].setBuffer(bufferUI[0]);
	bufferUI[1].loadFromFile("audio/ui/moveOptions.ogg");
	UI[1].setBuffer(bufferUI[1]);
	bufferUI[2].loadFromFile("audio/ui/moveSelector.ogg");
	UI[2].setBuffer(bufferUI[2]);
	bufferUI[3].loadFromFile("audio/ui/skipIntro.ogg");
	UI[3].setBuffer(bufferUI[3]);

	//History

	for (int i = 0; i < 1; i++) { bufferHistory.push_back(buffer); history.push_back(sound); }

	bufferHistory[0].loadFromFile("audio/musiccues/history.ogg");
	history[0].setBuffer(bufferHistory[0]);

	//Arenas

	for (int i = 0; i < 3; i++) { bufferArenas.push_back(buffer); arenas.push_back(sound); }

	bufferArenas[0].loadFromFile("audio/arenas/claps.ogg");
	arenas[0].setBuffer(bufferArenas[0]);
	bufferArenas[1].loadFromFile("audio/arenas/loosePublic.ogg");
	arenas[1].setBuffer(bufferArenas[1]);
	bufferArenas[2].loadFromFile("audio/arenas/victoryPublic.ogg");
	arenas[2].setBuffer(bufferArenas[2]);

	//Scorpion

	for (int i = 0; i < 2; i++) { bufferScorpion.push_back(buffer); scorpion.push_back(sound); }

	bufferScorpion[0].loadFromFile("audio/scorpion/comeHere.ogg");
	scorpion[0].setBuffer(bufferScorpion[0]);
	bufferScorpion[1].loadFromFile("audio/scorpion/getOverHere.ogg");
	scorpion[1].setBuffer(bufferScorpion[1]);
}

void MusicManager::startIntro() { intro[0].setVolume(volumeMusic); intro[0].play(); }
void MusicManager::endIntro() { intro[1].setVolume(volumeMusic); intro[1].play(); }
void MusicManager::presentsIntro() { intro[2].setVolume(volumeMusic); intro[2].play(); }
void MusicManager::selectorIntro() { intro[3].setVolume(volumeMusic); intro[3].play(); }

void MusicManager::mainTheme() { stopMusic(); stopIntros(); music[0].setVolume(volumeMusic); music[0].play(); music[0].setLoop(true); }
void MusicManager::selectorTheme() { stopMusic(); stopIntros(); music[1].setVolume(volumeMusic); music[1].play(); music[1].setLoop(true); }

void MusicManager::excellente() { announcers[0].setVolume(volumeEffects); announcers[0].play(); }
void MusicManager::fatality() { announcers[1].setVolume(volumeEffects); announcers[1].play(); }
void MusicManager::fight() { announcers[2].setVolume(volumeEffects); announcers[2].play(); }
void MusicManager::finishHer() { announcers[3].setVolume(volumeEffects); announcers[3].play(); }
void MusicManager::finishHim() { announcers[4].setVolume(volumeEffects); announcers[4].play(); }
void MusicManager::JhonnyCage() { announcers[5].setVolume(volumeEffects); announcers[5].play(); }
void MusicManager::JhonnyCageWins() { announcers[6].setVolume(volumeEffects); announcers[6].play(); }
void MusicManager::Kano() { announcers[7].setVolume(volumeEffects); announcers[7].play(); }
void MusicManager::KanoWins() { announcers[8].setVolume(volumeEffects); announcers[8].play(); }
void MusicManager::laugh() { announcers[9].setVolume(volumeEffects); announcers[9].play(); }
void MusicManager::LiuKang() { announcers[10].setVolume(volumeEffects); announcers[10].play(); }
void MusicManager::LiuKangWins() { announcers[11].setVolume(volumeEffects); announcers[11].play(); }
void MusicManager::Raiden() { announcers[12].setVolume(volumeEffects); announcers[12].play(); }
void MusicManager::RaidenWins() { announcers[13].setVolume(volumeEffects); announcers[13].play(); }
void MusicManager::Scorpion() { announcers[14].setVolume(volumeEffects); announcers[14].play(); }
void MusicManager::ScorpionWins() { announcers[15].setVolume(volumeEffects); announcers[15].play(); }
void MusicManager::SonyaBlade() { announcers[16].setVolume(volumeEffects); announcers[16].play(); }
void MusicManager::SonyaBladeWins() { announcers[17].setVolume(volumeEffects); announcers[17].play(); }
void MusicManager::SubZero() { announcers[18].setVolume(volumeEffects); announcers[18].play(); }
void MusicManager::SubZeroWins() { announcers[19].setVolume(volumeEffects); announcers[19].play(); }

void MusicManager::moveMain() { UI[0].setVolume(volumeEffects); UI[0].play(); }
void MusicManager::moveOptions() { UI[1].setVolume(volumeEffects); UI[1].play(); }
void MusicManager::moveSelector() { UI[2].setVolume(volumeEffects); UI[2].play(); }
void MusicManager::skipIntro() { UI[3].setVolume(volumeEffects); UI[3].play(); }

void MusicManager::History() { history[0].setVolume(volumeMusic); history[0].play(); }

void MusicManager::claps() { arenas[0].setVolume(volumeEffects); arenas[0].play(); }
void MusicManager::loosePublic() { arenas[1].setVolume(volumeEffects); arenas[1].play(); }
void MusicManager::victoryPublic() { arenas[2].setVolume(volumeEffects); arenas[2].play(); }

void MusicManager::comeHere() { scorpion[0].setVolume(volumeEffects); scorpion[0].play(); }
void MusicManager::getOverHere() { scorpion[1].setVolume(volumeEffects); scorpion[1].play(); }

void MusicManager::stopIntros() {
	for (int i = 0; i < intro.size(); i++) {
		intro[i].stop();
	}
}

void MusicManager::stopMusic() {
	for (int i = 0; i < music.size(); i++) {
		music[i].stop();
	}
}