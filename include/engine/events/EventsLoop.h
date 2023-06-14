#ifndef __EVENTSLOOP_H
#define __EVENTSLOOP_H

#pragma once
#include <SDL.h>
#include "EventDispatcher.h"


namespace JLNWCore {
	class EventDispatcher;

	class EventsLoop {
	private:
		JLNWCore::EventDispatcher* mEventDispatcher;
		bool mIsReceivingEvents;
	public:
		void initEventLoop();
		void initEventDispatcher();
		bool getIsApplicationNotClosed();
		JLNWCore::EventDispatcher* getEventDispatcher();
	};
}
#endif
