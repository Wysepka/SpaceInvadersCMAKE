#include "../../../../include/engine/rendering/components/Texture2D.h"

Texture2D::Texture2D() {
	mWidth = NULL;
	mHeight = NULL;
	mRenderer = NULL;
	mWindow = NULL;
	mTexture = NULL;
	mSurfacePixels = NULL;
}

Texture2D::~Texture2D() {
	free();
}

bool Texture2D::loadTexture(const std::string& path , SDL_Renderer* renderer , SDL_Window* window){
	//Load pixels
	mRenderer = renderer;
	mWindow = window;
	if (!loadPixelsFromFile(path))
	{
		printf("Failed to load pixels for %s!\n", path.c_str());
	}
	else
	{
		//Load texture from pixels
		if (!loadFromPixels())
		{
			printf("Failed to texture from pixels from %s!\n", path.c_str());
		}
	}

	//Return success
	return mTexture != NULL;
}

bool Texture2D::loadFromPixels()
{
	//Only load if pixels exist
	if (mSurfacePixels == NULL)
	{
		printf("No pixels loaded!\n");
	}
	else
	{
		//Color key image
		SDL_SetColorKey(mSurfacePixels, SDL_TRUE, SDL_MapRGB(mSurfacePixels->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(mRenderer, mSurfacePixels);
		if (mTexture == NULL)
		{
			printf("Unable to create texture from loaded pixels! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = mSurfacePixels->w;
			mHeight = mSurfacePixels->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(mSurfacePixels);
		mSurfacePixels = NULL;
	}

	//Return success
	return mTexture != NULL;
}

bool Texture2D::loadPixelsFromFile(const std::string& path)
{
	//Free preexisting assets
	free();

	//Load image at specified path
	TCHAR buffer[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, buffer, MAX_PATH);
	printf("Dir %s\n", buffer);
	wchar_t buffer2[MAX_PATH] = { 0 };
	_wgetcwd(buffer2, MAX_PATH);
	printf("Dir CWD: %s \n" , buffer2);
	char* pathBase = SDL_GetBasePath();
	printf("Dir SDL Base: %s \n", pathBase);
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Convert surface to display format
		mSurfacePixels = SDL_ConvertSurfaceFormat(loadedSurface, SDL_GetWindowPixelFormat(mWindow), 0);
		if (mSurfacePixels == NULL)
		{
			printf("Unable to convert loaded surface to display format! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = mSurfacePixels->w;
			mHeight = mSurfacePixels->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return mSurfacePixels != NULL;
}

void Texture2D::free()
{
	//Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}

	//Free surface if it exists
	if (mSurfacePixels != NULL)
	{
		SDL_FreeSurface(mSurfacePixels);
		mSurfacePixels = NULL;
	}
}

void Texture2D::render(float xPos, float yPos) {
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { xPos, yPos, mWidth, mHeight };

	/*
	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	*/

	//Render to screen
	SDL_RenderCopy(mRenderer, mTexture, NULL, NULL);
	//SDL_RenderCopyEx(mRenderer, mTexture, NULL, &renderQuad, angle, center, flip);
}