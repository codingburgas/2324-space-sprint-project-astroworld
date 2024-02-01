#pragma once
#include "pch.h"

class Textures {
public:
	// Constructor which loads all textures.
	Textures() {
		loadAllTextures();
	}

	// Destructor which unloads all textures.
	~Textures() {
		unloadAllTextures();
	}

	// Getter which returns the resized background.
	const Texture2D& getResizedBackground() const {
		return resizedBackground;
	}

private:
	Texture2D resizedBackground = { 0 };
	// Loads all textures.
	void loadAllTextures() {
		Image background = LoadImage("../images/mainMenuBg.png");
		ImageResize(&background, GetScreenWidth(), GetScreenHeight());
		resizedBackground = LoadTextureFromImage(background);
		UnloadImage(background);

	}

	// Unloads all textures.
	void unloadAllTextures() const {
		UnloadTexture(resizedBackground);

	}
};