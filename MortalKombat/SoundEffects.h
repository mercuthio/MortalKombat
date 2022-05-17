#ifndef SOUNDEFFECTS_H
#define SOUNDEFFECTS_H

#include "GlobalVars.h"

static void characterFall01(CharacterType character) {
	switch (character) {
	case LIU_KANG:
		music.liuKangFall01();
		break;
	case SCORPION:
		music.maleFall01();
		break;
	case SONYA:
		music.sonyaFall01();
		break;
	case CAGE:
		music.maleFall01();
		break;
	}
}
static void characterFall02(CharacterType character) {
	switch (character) {
	case LIU_KANG:
		music.liuKangFall02();
		break;
	case SCORPION:
		music.maleFall02();
		break;
	case SONYA:
		music.sonyaFall02();
		break;
	case CAGE:
		music.maleFall02();
		break;
	}
}
static void characterFall03(CharacterType character) {
	switch (character) {
	case LIU_KANG:
		music.liuKangFall03();
		break;
	case SCORPION:
		music.maleFall03();
		break;
	case SONYA:
		music.sonyaFall03();
		break;
	case CAGE:
		music.maleFall03();
		break;
	}
}
static void characterFall04(CharacterType character) {
	switch (character) {
	case LIU_KANG:
		music.liuKangFall04();
		break;
	case SCORPION:
		music.maleFall04();
		break;
	case SONYA:
		music.sonyaFall04();
		break;
	case CAGE:
		music.maleFall04();
		break;
	}
}

static void characterJump01(bool male) {
	if (male) music.maleJump();
	else music.sonyaJump01();
}


#endif