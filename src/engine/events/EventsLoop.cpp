#include "../../../include/engine/events/EventsLoop.h"

void JLNWCore::EventsLoop::initEventLoop() {
	//initEventDispatcher();
	SDL_Event engineEvents;
	mIsReceivingEvents = true;
	while (mIsReceivingEvents){
		while (SDL_PollEvent(&engineEvents) != 0) {
			if (engineEvents.type == SDL_QUIT) {
				mIsReceivingEvents = false;
				mEventDispatcher->dispose();
			}
		}
		//mEventDispatcher->invokeTick();
		EventDispatcher::getTypedInstance().invokeTick();
	}
}

void JLNWCore::EventsLoop::initEventDispatcher() {
	mEventDispatcher = new EventDispatcher();
	JLNWCore::EventDispatcher::applyTypedInstance(*mEventDispatcher);
	JLNWCore::EventDispatcher::getTypedInstance().init();
	//mEventDispatcher->init();
}

bool JLNWCore::EventsLoop::getIsApplicationNotClosed() { return mIsReceivingEvents;  }