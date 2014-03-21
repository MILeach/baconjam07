#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "AppState.h"

class GameState : public AppState {
	public:
		GameState();
		~GameState();
		virtual void init();
		virtual void exit();
		virtual void update();
		virtual void render();

	private:
	protected:
};

#endif
