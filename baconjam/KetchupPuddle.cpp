#include "KetchupPuddle.h"

KetchupPuddle::KetchupPuddle() {
	lifetime = 2.0f;
	countingDown = false;
	finished = false;
}

KetchupPuddle::~KetchupPuddle() {
}

void KetchupPuddle::update(float frameTime) {
	if (countingDown) 
		lifetime -= frameTime;

	if (lifetime < 0)
		finished = true;
}

void KetchupPuddle::startCountdown() {
	countingDown = true;
}

bool KetchupPuddle::isFinished() {
	return finished;
}
