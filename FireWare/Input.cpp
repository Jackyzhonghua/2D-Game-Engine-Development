#include "Input.h"


SDL_Event* Input::event = new SDL_Event;
const Uint8 * Input::keystate = SDL_GetKeyboardState(NULL);
std::map<GetKeycode, SDL_Keycode> Input::m_keyCodeMap = { { A, SDLK_a },{ B, SDLK_b },{ C, SDLK_c },{ D, SDLK_d },{ E, SDLK_e },{ F, SDLK_f },
{ G, SDLK_g },{ H, SDLK_h },{ I, SDLK_i },{ J, SDLK_j },{ K, SDLK_k },{ L, SDLK_l },{ M, SDLK_m },
{ N, SDLK_n },{ O, SDLK_o },{ P, SDLK_p },{ Q, SDLK_q },{ R, SDLK_r },{ S, SDLK_s },{ T, SDLK_t },
{ U, SDLK_u },{ V, SDLK_v },{ W, SDLK_w },{ X, SDLK_x },{ Y, SDLK_y },{ Z, SDLK_z },{ Space, SDLK_SPACE },
};

Input::Input()
{
	
}


Input::~Input()
{
	delete event;
}

SDL_Event * Input::GetInstance()
{
	if (event == nullptr)
	{
		event = new SDL_Event;
	}
	return event;
}

bool Input::GetButtonDown(GetKeycode keycode)
{
	if (keystate[SDL_GetScancodeFromKey(m_keyCodeMap[keycode])])
	{
		return true;
	}
	return false;
}
