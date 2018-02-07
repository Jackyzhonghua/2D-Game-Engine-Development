#ifndef _INPUT_H_
#define _INPUT_H_

#include <iostream>
#include <SDL.h>
#include <map>

enum GetKeycode
{
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	Space,

};


class Input
{
public:
	~Input();
	static SDL_Event* GetInstance();
	static bool GetButtonDown(GetKeycode keycode);
	//static bool GetButtonUp(GetKeycode keycode);
	//static bool GetButton(GetKeycode keycode);

private:
	static SDL_Event* event;
	static std::map<GetKeycode, SDL_Keycode> m_keyCodeMap;
	static const Uint8 *keystate;

private:
	Input();

};

#endif

