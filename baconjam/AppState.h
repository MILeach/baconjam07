#ifndef APPSTATE_H
#define APPSTATE_H

class AppState {
	public:
		AppState();
		virtual ~AppState();
		virtual void init() = 0;
		virtual void exit() = 0;
		virtual void update() = 0;
		virtual void render() = 0;

	private:

};

#endif
