#ifndef GlobalVars_H
#define GlobalVars_H

const int NUMBER_TRACKS = 191;
const float ASPECT_RATIO = 4.0/3.0;

static float width_window = 1024;
static float height_window = 768;

enum character {
	CAGE,
	KANO,
	RAIDEN,
	LIU_KANG,
	SCORPION,
	SUB_ZERO,
	SONYA,
	GORO,
	SHANG_TSUNG
};

enum background {
	COURTYARD,
	GOROS_LAIR,
	PALACE_GATES,
	THE_PIT,
	THRONE_ROOM,
	WARRIOR_SHRINE
};

#endif