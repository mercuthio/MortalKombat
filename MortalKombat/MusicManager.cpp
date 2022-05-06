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
	
	//MALE
	for (int i = 0; i < 1; i++) { bufferMale.push_back(buffer); male.push_back(sound); }
	bufferMale[0].loadFromFile("audio/male/mk1-00215.ogg");
	male[0].setBuffer(bufferMale[0]);


	//HITS
	for (int i = 0; i < 11; i++) { bufferHits.push_back(buffer); hits.push_back(sound); }
	bufferHits[0].loadFromFile("audio/hitsounds/mk1-00131.ogg"); //Blood
	hits[0].setBuffer(bufferHits[0]);

	bufferHits[1].loadFromFile("audio/hitsounds/mk1-00054.ogg"); //Hit
	hits[1].setBuffer(bufferHits[1]);
	bufferHits[2].loadFromFile("audio/hitsounds/mk1-00055.ogg");
	hits[2].setBuffer(bufferHits[2]);
	bufferHits[3].loadFromFile("audio/hitsounds/mk1-00056.ogg");
	hits[4].setBuffer(bufferHits[3]);
	bufferHits[4].loadFromFile("audio/hitsounds/mk1-00058.ogg");
	hits[4].setBuffer(bufferHits[4]);

	bufferHits[5].loadFromFile("audio/hitsounds/mk1-00059.ogg"); // No hit
	hits[5].setBuffer(bufferHits[5]);
	bufferHits[6].loadFromFile("audio/hitsounds/mk1-00060.ogg");
	hits[6].setBuffer(bufferHits[6]);
	bufferHits[7].loadFromFile("audio/hitsounds/mk1-00061.ogg");
	hits[7].setBuffer(bufferHits[7]);

	bufferHits[8].loadFromFile("audio/hitsounds/mk1-00061.ogg"); //Blood2
	hits[8].setBuffer(bufferHits[8]);

	bufferHits[9].loadFromFile("audio/hitsounds/mk1-00325.ogg"); //Block
	hits[9].setBuffer(bufferHits[9]);

	bufferHits[10].loadFromFile("audio/hitsounds/mk1-90059.ogg"); //Double jump
	hits[10].setBuffer(bufferHits[10]);


	//MUSIC

	for (int i = 0; i < 9; i++) { bufferMusic.push_back(buffer); music.push_back(sound); }

	bufferMusic[0].loadFromFile("audio/music/mainTheme.ogg");
	music[0].setBuffer(bufferMusic[0]);
	bufferMusic[1].loadFromFile("audio/music/selectorTheme.ogg");
	music[1].setBuffer(bufferMusic[1]);
	bufferMusic[2].loadFromFile("audio/music/historyTheme.ogg");
	music[2].setBuffer(bufferMusic[2]);
	bufferMusic[3].loadFromFile("audio/music/courtyardTheme.ogg");
	music[3].setBuffer(bufferMusic[3]);
	bufferMusic[4].loadFromFile("audio/music/thepitTheme.ogg");
	music[4].setBuffer(bufferMusic[4]);
	bufferMusic[5].loadFromFile("audio/music/warriorshrineTheme.ogg");
	music[5].setBuffer(bufferMusic[5]);
	bufferMusic[6].loadFromFile("audio/music/throneroomTheme.ogg");
	music[6].setBuffer(bufferMusic[6]);
	bufferMusic[7].loadFromFile("audio/music/victoryTheme.ogg");
	music[7].setBuffer(bufferMusic[7]);
	bufferMusic[8].loadFromFile("audio/music/defeatTheme.ogg");
	music[8].setBuffer(bufferMusic[8]);


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

	//Arenas

	for (int i = 0; i < 3; i++) { bufferArenas.push_back(buffer); arenas.push_back(sound); }

	bufferArenas[0].loadFromFile("audio/arenas/clapsPublic.ogg");
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

	//LiuKang

	for (int i = 0; i < 8; i++) { bufferLiuKang.push_back(buffer); liukang.push_back(sound); }

	bufferLiuKang[0].loadFromFile("audio/liukang/mk1-00228.ogg"); //Hit 1
	liukang[0].setBuffer(bufferLiuKang[0]);
	bufferLiuKang[1].loadFromFile("audio/liukang/mk1-00225.ogg"); //Kick 1
	liukang[1].setBuffer(bufferLiuKang[1]);
	bufferLiuKang[2].loadFromFile("audio/liukang/mk1-00224.ogg"); //Fall 1
	liukang[2].setBuffer(bufferLiuKang[2]);
	bufferLiuKang[3].loadFromFile("audio/liukang/mk1-00231.ogg"); //Fall 2 (Death)
	liukang[3].setBuffer(bufferLiuKang[3]);
	bufferLiuKang[4].loadFromFile("audio/liukang/mk1-00236.ogg"); //Fall 3 (Death)
	liukang[4].setBuffer(bufferLiuKang[4]);
	bufferLiuKang[5].loadFromFile("audio/liukang/mk1-00230.ogg"); //Fall 4
	liukang[5].setBuffer(bufferLiuKang[5]);
	bufferLiuKang[6].loadFromFile("audio/hitsounds/mk1-00250.ogg"); //Special fireball
	liukang[6].setBuffer(bufferLiuKang[6]);
	bufferLiuKang[7].loadFromFile("audio/hitsounds/mk1-00242.ogg"); //Special Hit
	liukang[7].setBuffer(bufferLiuKang[7]);

	//Sonya

	for (int i = 0; i < 6; i++) { bufferSonya.push_back(buffer); sonya.push_back(sound); }

	bufferSonya[0].loadFromFile("audio/sonya/mk1-00432.ogg");
	sonya[0].setBuffer(bufferSonya[0]);
	bufferSonya[1].loadFromFile("audio/sonya/mk1-00433.ogg");
	sonya[1].setBuffer(bufferSonya[1]);
	bufferSonya[2].loadFromFile("audio/sonya/mk1-00442.ogg");
	sonya[2].setBuffer(bufferSonya[2]);
	bufferSonya[3].loadFromFile("audio/sonya/mk1-00443.ogg");
	sonya[3].setBuffer(bufferSonya[3]);
	bufferSonya[4].loadFromFile("audio/sonya/mk1-00444.ogg");
	sonya[4].setBuffer(bufferSonya[4]);
	bufferSonya[5].loadFromFile("audio/sonya/mk1-00445.ogg");
	sonya[5].setBuffer(bufferSonya[5]);
}

void MusicManager::startIntro() { intro[0].setVolume(volumeMusic); intro[0].play(); }
void MusicManager::endIntro() { intro[1].setVolume(volumeMusic); intro[1].play(); }
void MusicManager::presentsIntro() { intro[2].setVolume(volumeMusic); intro[2].play(); }
void MusicManager::selectorIntro() { intro[3].setVolume(volumeMusic); intro[3].play(); }

void MusicManager::mainTheme() { stopMusic(); stopIntros(); music[0].setVolume(volumeMusic); music[0].play(); music[0].setLoop(true); }
void MusicManager::selectorTheme() { stopMusic(); stopIntros(); music[1].setVolume(volumeMusic); music[1].play(); music[1].setLoop(true); }
void MusicManager::historyTheme() { stopMusic(); stopIntros(); music[2].setVolume(volumeMusic); music[2].play(); music[2].setLoop(false); }
void MusicManager::victoryTheme() { stopMusic(); stopIntros(); music[7].setVolume(volumeMusic); music[7].play(); music[7].setLoop(true); }
void MusicManager::defeatTheme() { stopMusic(); stopIntros(); music[8].setVolume(volumeMusic); music[8].play(); music[8].setLoop(true); }

void MusicManager::skipHistoryTheme() { music[2].setPlayingOffset(seconds(6.65f)); }

void MusicManager::maleJump() { male[0].setVolume(volumeEffects); male[0].play(); }

void MusicManager::hit1() { hits[0].setVolume(volumeEffects); hits[0].play(); }
void MusicManager::hit9() { hits[8].setVolume(volumeEffects); hits[8].play(); }

void MusicManager::hit2() { hits[1].setVolume(volumeEffects); hits[1].play(); }
void MusicManager::hit3() { hits[2].setVolume(volumeEffects); hits[2].play(); }
void MusicManager::hit4() { hits[3].setVolume(volumeEffects); hits[3].play(); }
void MusicManager::hit5() { hits[4].setVolume(volumeEffects); hits[4].play(); }

void MusicManager::hit6() { hits[5].setVolume(volumeEffects); hits[5].play(); }
void MusicManager::hit7() { hits[6].setVolume(volumeEffects); hits[6].play(); }
void MusicManager::hit8() { hits[7].setVolume(volumeEffects); hits[7].play(); }

void MusicManager::doubleJump() { hits[10].setVolume(volumeEffects); hits[10].play(); }

void MusicManager::hitBlock() { hits[9].setVolume(volumeEffects); hits[9].play(); }

void MusicManager::courtyardTheme() { stopMusic(); stopIntros(); music[3].setVolume(volumeMusic); music[3].play(); music[3].setLoop(true); }
void MusicManager::thepitTheme() { stopMusic(); stopIntros(); music[4].setVolume(volumeMusic); music[4].play(); music[4].setLoop(true); }
void MusicManager::warriorshrineTheme() { stopMusic(); stopIntros(); music[5].setVolume(volumeMusic); music[5].play(); music[5].setLoop(true); }
void MusicManager::throneroomTheme() { stopMusic(); stopIntros(); music[6].setVolume(volumeMusic); music[6].play(); music[6].setLoop(true); }

void MusicManager::excellent() { announcers[0].setVolume(volumeEffects); announcers[0].play(); }
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

void MusicManager::clapsPublic() { arenas[0].setVolume(volumeEffects); arenas[0].play(); }
void MusicManager::loosePublic() { arenas[1].setVolume(volumeEffects); arenas[1].play(); }
void MusicManager::victoryPublic() { arenas[2].setVolume(volumeEffects); arenas[2].play(); }

void MusicManager::comeHere() { scorpion[0].setVolume(volumeEffects); scorpion[0].play(); }
void MusicManager::getOverHere() { scorpion[1].setVolume(volumeEffects); scorpion[1].play(); }

void MusicManager::liuKangPunch01() { liukang[0].setVolume(volumeEffects); liukang[0].play(); }
void MusicManager::liuKangKick01() { liukang[1].setVolume(volumeEffects); liukang[1].play(); }
void MusicManager::liuKangFall01() { liukang[2].setVolume(volumeEffects); liukang[2].play(); }
void MusicManager::liuKangFall02() { liukang[3].setVolume(volumeEffects); liukang[3].play(); }
void MusicManager::liuKangFall03() { liukang[4].setVolume(volumeEffects); liukang[4].play(); }
void MusicManager::liuKangFall04() { liukang[5].setVolume(volumeEffects); liukang[5].play(); }
void MusicManager::liuKangSpecial01() { liukang[6].setVolume(volumeEffects); liukang[6].play(); }
void MusicManager::liuKangSpecial02() { liukang[7].setVolume(volumeEffects); liukang[7].play(); }

void MusicManager::sonyaPunch01() { sonya[0].setVolume(volumeEffects); sonya[0].play(); }
void MusicManager::sonyaKick01() { sonya[1].setVolume(volumeEffects); sonya[1].play(); }
void MusicManager::sonyaFall01() { sonya[2].setVolume(volumeEffects); sonya[2].play(); }
void MusicManager::sonyaFall02() { sonya[3].setVolume(volumeEffects); sonya[3].play(); }
void MusicManager::sonyaFall03() { sonya[4].setVolume(volumeEffects); sonya[4].play(); }
void MusicManager::sonyaFall04() { sonya[5].setVolume(volumeEffects); sonya[5].play(); }

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