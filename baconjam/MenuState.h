#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "AppState.h"

class MenuState : public AppState {
	public:
		MenuState();
		~MenuState();
		virtual void init();
		virtual void exit();
		virtual void update();
		virtual void render();

	private:
	protected:
};

#endif
