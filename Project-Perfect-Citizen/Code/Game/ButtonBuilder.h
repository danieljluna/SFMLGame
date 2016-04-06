#pragma once

#include "../Engine/renderComponent.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Engine/renderComponent.h"
#include "../Engine/InputHandler.h"

namespace ppc {

	///////////////////////////////////////////////////////////////////////
	/// @brief Designated Generic Builder Object for Buttons
	/// @author Alex Vincent 
	/// @details A package with API function calls allowing for individual
	/// creations and augmentations of a button. This augments and returns 
	///////////////////////////////////////////////////////////////////////
	class ButtonBuilder {
	private:
		int sheetX;
		int sheetY;
		int width;
		int frames;
		float size;

		float posX;
		float posY;

		sf::Sprite* sprtUp;
		sf::Sprite* sprtDown;

		sf::Image* spriteSheet; 
		ppc::InputHandler* inputHandle;

	public:
		///////////////////////////////////////////////////////////////////////
		/// @brief Constructor for buttonRenderComponent
		/// @details Creates a default button
		///////////////////////////////////////////////////////////////////////
		ButtonBuilder();

		~ButtonBuilder();

		///////////////////////////////////////////////////////////////////////
		/// @brief Set the down and up sprite when the button is pressed
		///////////////////////////////////////////////////////////////////////
		void setSpritesByIndicies(int x, int y, int r, int f);

		void setSize(float s);

		///////////////////////////////////////////////////////////////////////
		/// @brief Set the down and up sprite when the button is pressed
		///////////////////////////////////////////////////////////////////////
		void setSprites(sf::Sprite&, sf::Sprite&);

		///////////////////////////////////////////////////////////////////////
		/// @brief Set the function the button will execute when pressed
		///////////////////////////////////////////////////////////////////////
		void setFunction();

		///////////////////////////////////////////////////////////////////////
		/// @brief Set the position of the button
		///////////////////////////////////////////////////////////////////////
		void setButtonPosition(float x, float y);

		///////////////////////////////////////////////////////////////////////
		/// @brief Set the position of the button
		///////////////////////////////////////////////////////////////////////
		void setButtonPosition(sf::Vector2f pos);

		///////////////////////////////////////////////////////////////////////
		/// @brief Set the sprite sheet of the button
		///////////////////////////////////////////////////////////////////////
		void setSpriteSheet(sf::Image&);

		///////////////////////////////////////////////////////////////////////
		/// @brief Set the input handle of the button
		///////////////////////////////////////////////////////////////////////
		void setInputHandle(ppc::InputHandler&);

		///////////////////////////////////////////////////////////////////////
		/// @brief Returns the constructed button
		///////////////////////////////////////////////////////////////////////
		void create(Entity&);

	};


};
