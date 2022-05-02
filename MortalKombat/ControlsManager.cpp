#include "ControlsManager.h"

Keyboard::Key jumpButton = Keyboard::W;
Keyboard::Key forwButton = Keyboard::D;
Keyboard::Key backButton = Keyboard::A;
Keyboard::Key downButton = Keyboard::S;
Keyboard::Key punchButton = Keyboard::F;        
Keyboard::Key punchButton2 = Keyboard::G;    
Keyboard::Key kickButton = Keyboard::H;        
Keyboard::Key grabButton = Keyboard::Unknown;
Keyboard::Key specialButton = Keyboard::Unknown;
Keyboard::Key blockButton = Keyboard::T;        

Keyboard::Key jumpButtonP2 = Keyboard::Up;
Keyboard::Key forwButtonP2 = Keyboard::Right;
Keyboard::Key backButtonP2 = Keyboard::Left;
Keyboard::Key downButtonP2 = Keyboard::Down;
Keyboard::Key punchButtonP2 = Keyboard::J;    
Keyboard::Key punchButton2P2 = Keyboard::K;    
Keyboard::Key kickButtonP2 = Keyboard::L;    
Keyboard::Key grabButtonP2 = Keyboard::Unknown;    
Keyboard::Key specialButtonP2 = Keyboard::Unknown;    
Keyboard::Key blockButtonP2 = Keyboard::I;    

ControlsManager::ControlsManager(Texture* texture, Font font_) {

	font = font_;
	choosenOption = 0;
	clock_flash = 0;
	flash = false;
	playerTwo = false;
	changing_key = false;

	text[0].setString("J1 ATRAS");
	text[1].setString("J1 DELANTE");
	text[2].setString("J1 SALTAR");
	text[3].setString("J1 AGACHAR");
	text[4].setString("J1 BLOQUEAR");
	text[5].setString("J1 PUÑETAZO");
	text[6].setString("J1 MULTI-PUÑO");
	text[7].setString("J1 PATADA");
	text[8].setString("J2 ATRAS");
	text[9].setString("J2 DELANTE");
	text[10].setString("J2 SALTAR");
	text[11].setString("J2 AGACHAR");
	text[12].setString("J2 BLOQUEAR");
	text[13].setString("J2 PUÑETAZO");
	text[14].setString("J2 MULTI-PUÑO");
	text[15].setString("J2 PATADA");

	for (int i = 0; i < NUM_CONTROLS; i++) {
		text[i].setFont(font);
		text[i].setFillColor(Color::White);
		text[i].setCharacterSize(CHAR_SIZE_CONTROLS);
		keys[i].setFont(font);
		keys[i].setFillColor(Color::White);
		keys[i].setCharacterSize(CHAR_SIZE_CONTROLS);
		shadow[i] = text[i];
		shadow[i].setFillColor(Color::Black);
	}

	uvRect.width = 390;
	uvRect.height = 250;
	uvRect.left = 1440;
	uvRect.top = 885;

	backg.setPosition(0, 0);
	backg.setTextureRect(uvRect);
	backg.setTexture(texture);

	Texture* texture2 = new Texture;
	texture2->loadFromFile("resources/Imagenes/Menus/icon30x30.png");
	logo.setTexture(texture2);
	logo.setPosition(0, 0);
	logo.setSize(Vector2f(CHAR_SIZE_CONTROLS, CHAR_SIZE_CONTROLS));
}

void ControlsManager::Update() {

	Color yellow = Color(255, 255, 0, 255);

	for (int i = 0; i < NUM_CONTROLS; i++) {
		text[i].setFillColor(Color::White);
		keys[i].setFillColor(Color::White);
	}

	text[choosenOption].setFillColor(yellow);

	//Keys
	keys[0].setString(fromKtoS(backButton));
	keys[1].setString(fromKtoS(forwButton));
	keys[2].setString(fromKtoS(jumpButton));
	keys[3].setString(fromKtoS(downButton));
	keys[4].setString(fromKtoS(blockButton));
	keys[5].setString(fromKtoS(punchButton));
	keys[6].setString(fromKtoS(punchButton2));
	keys[7].setString(fromKtoS(kickButton));
	keys[8].setString(fromKtoS(backButtonP2));
	keys[9].setString(fromKtoS(forwButtonP2));
	keys[10].setString(fromKtoS(jumpButtonP2));
	keys[11].setString(fromKtoS(downButtonP2));
	keys[12].setString(fromKtoS(blockButtonP2));
	keys[13].setString(fromKtoS(punchButtonP2));
	keys[14].setString(fromKtoS(punchButton2P2));
	keys[15].setString(fromKtoS(kickButtonP2));

}

void ControlsManager::draw(RenderWindow& window) {
	backg.setSize(Vector2f(width_window, height_window));
	window.draw(backg);

	if (changing_key) clock_flash++;
	if (clock_flash == 7) {

		clock_flash = 0;
		Color yellow = Color(255, 255, 0, 255);

		if (flash) keys[choosenOption].setFillColor(Color::White);
		else keys[choosenOption].setFillColor(Color::Yellow);

		flash = !flash;
	}

	for (int i = 0; i < NUM_CONTROLS / 2; i++) {
		text[i].setPosition(Vector2f(width_window / 6 + 20, height_window / 7 + CHAR_SIZE_CONTROLS * (i + 1) + 100));
		shadow[i].setPosition(Vector2f(width_window / 6 + 5 + 20, height_window / 7 + CHAR_SIZE_CONTROLS * (i + 1) + 5 + 100));
		keys[i].setPosition(Vector2f(width_window / 2.5 + 20, height_window / 7 + CHAR_SIZE_CONTROLS * (i + 1) + 100));
		if (i == choosenOption) {
			logo.setPosition(text[i].getPosition().x - 50, text[i].getPosition().y + 10);
		}

		window.draw(shadow[i]);
		window.draw(text[i]);
		window.draw(keys[i]);
		window.draw(logo);
	}

	for (int i = NUM_CONTROLS / 2; i < NUM_CONTROLS; i++) {
		text[i].setPosition(Vector2f(width_window / 1.9 + 20, height_window / 7 + CHAR_SIZE_CONTROLS * (i - (NUM_CONTROLS / 2) + 1) + 100));
		shadow[i].setPosition(Vector2f(width_window / 1.9 + 5 + 20, height_window / 7 + CHAR_SIZE_CONTROLS * (i - (NUM_CONTROLS / 2) + 1) + 5 + 100));
		keys[i].setPosition(Vector2f(width_window / 1.3 + 20, height_window / 7 + CHAR_SIZE_CONTROLS * (i - (NUM_CONTROLS / 2) + 1) + 100));
		if (i == choosenOption) {
			logo.setPosition(text[i].getPosition().x - 50, text[i].getPosition().y + 10);
		}

		window.draw(shadow[i]);
		window.draw(text[i]);
		window.draw(keys[i]);
		window.draw(logo);
	}

}

void ControlsManager::Right() {

	if (!changing_key) {
		if (!playerTwo)	choosenOption += NUM_CONTROLS / 2;
		playerTwo = true;
	}
	else {
		changeKey(Keyboard::D);
	}
}

void ControlsManager::Enter() {

	if (!changing_key) {
		changing_key = true;
	}
	else {
		changeKey(Keyboard::Enter);
	}
}

void ControlsManager::Izquierda() {

	if (!changing_key) {
		if (playerTwo) choosenOption -= NUM_CONTROLS / 2;
		playerTwo = false;
	}
	else {
		changeKey(Keyboard::A);
	}
}

void ControlsManager::MoveCursor(bool arriba) {

	if (!changing_key) {
		if (!playerTwo) {
			if (arriba) {
				if (choosenOption - 1 >= 0) { music.moveOptions();  choosenOption--; }
			}
			else {
				if (choosenOption + 1 < NUM_CONTROLS / 2) { music.moveOptions(); choosenOption++; }
			}
		}
		else {
			if (arriba) {
				if (choosenOption - 1 >= NUM_CONTROLS / 2) { music.moveOptions();  choosenOption--; }
			}
			else {
				if (choosenOption + 1 < NUM_CONTROLS) { music.moveOptions(); choosenOption++; }
			}
		}
	}
	else {
		if (arriba) changeKey(Keyboard::W);
		else changeKey(Keyboard::S);
	}
}

void ControlsManager::changeKey(Keyboard::Key k) {

	if (changing_key) {
		switch (choosenOption) {
		case 0:
			backButton = k;
			break;
		case 1:
			forwButton = k;
			break;
		case 2:
			jumpButton = k;
			break;
		case 3:
			downButton = k;
			break;
		case 4:
			blockButton = k;
			break;
		case 5:
			punchButton = k;
			break;
		case 6:
			punchButton2 = k;
			break;
		case 7:
			kickButton = k;
			break;
		case 8:
			backButtonP2 = k;
			break;
		case 9:
			forwButtonP2 = k;
			break;
		case 10:
			jumpButtonP2 = k;
			break;
		case 11:
			downButtonP2 = k;
			break;
		case 12:
			blockButtonP2 = k;
			break;
		case 13:
			punchButtonP2 = k;
			break;
		case 14:
			punchButton2P2 = k;
			break;
		case 15:
			kickButtonP2 = k;
			break;
		}

		changing_key = false;
		Update();
	}
}
