
namespace JLNWCore {
#ifndef SINGLETON_H
#define SINGLETON_H

#pragma once
#include <typeinfo>

	template<typename ClassType>
	class Singleton {
	protected:
		static ClassType m_TypedInstance;
		static bool mInitialized;
	public:
		Singleton();

		template<typename U>
		Singleton(U arg);

		static bool applyTypedInstance(const ClassType& value);
		static ClassType& getTypedInstance();

		template<typename ClassType>
		bool operator != (const ClassType& other) const {
			return m_TypedInstance != other;
		}
		template<typename ClassType>
		bool operator == (const ClassType& other) const {
			return m_TypedInstance == other;
		}
		bool operator!=(int& other) const {
			return m_TypedInstance != other;
		}
		bool operator == (const int& other) const {
			return m_TypedInstance == other;
		}
	};

	template<typename ClassType>
	ClassType Singleton<ClassType>::m_TypedInstance;

	template<typename ClassType>
	bool Singleton<ClassType>::mInitialized;

	template<typename ClassType>
	Singleton<ClassType>::Singleton(){}

	template<typename ClassType>
	inline bool JLNWCore::Singleton<ClassType>::applyTypedInstance(const ClassType& value) {
		if (mInitialized) {
			printf("Singleton: %s applied more than once", typeid(ClassType).name());
			return false;
		}
		else {
			mInitialized = true;
			m_TypedInstance = value;
		}
	}

	template<typename ClassType>
	ClassType& JLNWCore::Singleton<ClassType>::getTypedInstance() {
		if (!mInitialized) {
			printf("Singleton %s not initialized yet, returning custom instance !", typeid(ClassType).name());
		}
		return m_TypedInstance;
	}

#endif
}