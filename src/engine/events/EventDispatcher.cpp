#include "../../../include/engine/events/EventDispatcher.h"

void JLNWCore::EventDispatcher::init() {
	mTickCallbackList = new eventpp::CallbackList<void()>();
}

void JLNWCore::EventDispatcher::dispose() {
	delete mTickCallbackList;
}

eventpp::CallbackList<void()>::Handle JLNWCore::EventDispatcher::registerToTick(const std::function<void()>& method) {
//TickSubscribers.push_back(method);
	
	return getTypedInstance().mTickCallbackList->append(method);
}

bool JLNWCore::EventDispatcher::unregisterFromTick(eventpp::CallbackList<void()>::Handle handle) {
	auto mTickCallbackListInstance = getTypedInstance().mTickCallbackList;
	if ( mTickCallbackListInstance->ownsHandle(handle)) {
		mTickCallbackListInstance->remove(handle);
		return true;
	}
	else {
		printf("This Callbacklist: %s does not contain Handle\n", std::string("mTickCallbackList").c_str());
		return false;
	}
}

void JLNWCore::EventDispatcher::invokeTick() {
	(*mTickCallbackList)();
}