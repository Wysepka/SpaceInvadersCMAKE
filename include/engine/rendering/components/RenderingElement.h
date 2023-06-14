#ifndef RENDERING_ELEMENT_H
#define RENDERING_ELEMENT_H

#pragma once
#include <string>
#include "Texture2D.h"
#include "../include/engine/core/Object.h"

class RenderingElement : public Object {
protected:
	RenderingElement() = default;
	//virtual bool loadTextures(std::string* paths);
public:
	RenderingElement(const RenderingElement&) = delete;
	RenderingElement(RenderingElement&&) = delete;
	RenderingElement& operator=(const RenderingElement&) = delete;

	virtual bool loadTexture(const std::string& path) = 0;
	virtual void render() = 0;
	//RenderingElement();
	virtual ~RenderingElement() = default;
};

#endif