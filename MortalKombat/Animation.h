#ifndef Animation_H
#define Animation_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>

#include "GlobalVars.h"
#include "Recover.h"

constexpr bool DEBUG = false;

using namespace sf;
using namespace std;

class Animation {
public:
	Animation() = default;
	Animation(int _duration, Texture *_sprite_sheet, Texture* _sprite_sheetP2, Vector2<int> _first_frame, Vector2<int> _size, int _offset, bool backwards, bool _lock, vector<Recover> _recovery, vector<int> _flagged_frames, int _wait_until);
	//~Animation() = delete;
	bool DoAnimation(RectangleShape& body, RectangleShape& shadow, RectangleShape& hitbox, bool mirrored, bool player2,
			float hitbox_positions_X[], float hitbox_positions_Y[], Vector2<float> globalPosition, vector<RectangleShape> hitboxes,
			RectangleShape& damage_hitbox, float damage_hitbox_positions_X[], float damage_hitbox_positions_Y[], vector<RectangleShape> damage_hitboxes);
	void ResetAnimation();
	bool RecieveFlagEvent();

	int frame_number = 1;

private:
	Texture* sprite_sheet = new Texture();						// Spritesheet de la animacion
	Texture* sprite_sheetP2 = new Texture();

	int	duration = 0;							// Total de imagenes de la animacion
	bool isPersistent = false;
	bool lock = false;
	int this_recovery = 0;
	int this_recover_frame = 0;
	vector<Recover> recovery;
	bool recovering = false;
	bool waiting_flag = false;

	Vector2<int> first_frame = Vector2<int>();					// Localización del primer frame en el Sprite Sheet
	Vector2<int> this_frame = Vector2<int>();
	Vector2<int> size = Vector2<int>();
	Vector2<int> offset = Vector2<int>();						// Cuanto varia el ejeX hasta llegar al principio del siguiente frame
	vector<int> flagged_frames = vector<int>();
	int n_of_flagged_frames = 0;
	int this_flagged_frame = 0;

	int current_wait = 0;
	int wait_until = 0;
};

/*
	Crea una animacion compuesta por una sprite-sheet de imagenes
	
	@param _duration:		Cuantas imaagenes componen la animacion
	@param _sprite_sheet:	Sprite-sheet del cual está compuesta 
	@param _first_frame:	Localización del primer sprite en '_sprite_sheet'
	@param _size:			Tamanyo de cada frame de la animacion
	@param _offset:			Distancia en pixeles entre los frames de la animacion. Siempre es un valor positivo
	@param backwards:		'false' Si el desplazamiento se hace de izquierda a derecha. 'true' si es de izquierda a derecha 
	@param _lock:			'true' si se tiene que hacer la animacion completa antes de continuar o 'false' si se puede cancelar
	@param _recovery:		Número de frames los cuales tarda el personaje en recuperarse antes de terminar la animación
	@param _flagged_frames:	Frames los cuales la animación esperará a algún evento
	@param _mirrored:		'false' pinta el sprite tal y como aparece en _sprite_sheet. 'true' lo pinta mirando al lado opuesto en el eje x
*/

#endif