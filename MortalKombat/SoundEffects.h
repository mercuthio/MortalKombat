#ifndef SOUNDEFFECTS_H
#define SOUNDEFFECTS_H

#include "GlobalVars.h"

static void characterFall01(CharacterType character) {
	switch (character) {
	case LIU_KANG:
		music.liuKangFall01();
		break;
	case SCORPION:
		break;
	case SONYA:
		music.sonyaFall01();
		break;
	}
}
static void characterFall02(CharacterType character) {
	switch (character) {
	case LIU_KANG:
		music.liuKangFall02();
		break;
	case SCORPION:
		break;
	case SONYA:
		music.sonyaFall02();
		break;
	}
}
static void characterFall03(CharacterType character) {
	switch (character) {
	case LIU_KANG:
		music.liuKangFall03();
		break;
	case SCORPION:
		break;
	case SONYA:
		music.sonyaFall03();
		break;
	}
}
static void characterFall04(CharacterType character) {
	switch (character) {
	case LIU_KANG:
		music.liuKangFall04();
		break;
	case SCORPION:
		break;
	case SONYA:
		music.sonyaFall04();
		break;
	}
}


#endif