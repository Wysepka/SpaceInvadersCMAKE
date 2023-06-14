#ifndef __EVENTSDISPATCHER_H
#define __EVENTSDISPATCHER_H

#pragma once
#include <vector>
#include <map>
#include <functional>
#include <eventpp/callbacklist.h>
#include "engine/core/Singleton.h"
#include "EventsLoop.h"

namespace JLNWCore {
	class EventDispatcher : public JLNWCore::Singleton<EventDispatcher> {
	private:
		eventpp::CallbackList<void()>* mTickCallbackList;
		void invokeTick();
		friend class EventsLoop;
	public:
		void init();
		void dispose();
		static eventpp::CallbackList<void()>::Handle registerToTick(const std::function<void()>& method);
		//static eventpp::CallbackList<void()>::Handle registerToTick(void method);
		static bool unregisterFromTick(eventpp::CallbackList<void()>::Handle handle);
		bool registerToEvent();
	};
};

#endif