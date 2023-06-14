#ifndef SCENE_H
#define SCENE_H

#pragma once
#include <vector>
#include "../rendering/RenderingBuilder.h"
#include "engine/core/Object.h"

class Object;

class Scene {
private:
	std::vector<Object*> mRenderingElements;
public:
	void addObject(Object* object);
	void addObjects(std::vector<Object*> objects);
	void addObjects(Object* objects , size_t size);
};

#endif	