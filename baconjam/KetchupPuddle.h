#ifndef KETCHUPPUDDLE_H
#define KETCHUPPUDDLE_H

#include <SFML/Graphics.hpp>

class KetchupPuddle : public sf::Sprite {
	public:
		KetchupPuddle();
		~KetchupPuddle();
		void update(float frameTime);
		void startCountdown();
		bool isFinished();

	private:
		float lifetime;
		bool countingDown;
		bool finished;
};

#endif
