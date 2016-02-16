#pragma once

#include <iostream>
#include <fstream>
#include <SFML/Main.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Window.h"
#include "inputComponent.h"
#include "InputHandler.h"
#include "Entity.h"
#include "subject.h"
#include "textInputRenderComponent.hpp"
#include "textInputKeys.hpp"
#include "InputHandler.h"
#include "animatorComponent.hpp"
#include "mousePressButton.h"
#include "consoleIconRenderComponent.h"
#include "buttonRenderComponent.h"
#include "consoleUpdateComponent.h"
#include "NodeState.h"
#include "iconInputComponent.h"

///////////////////////////////////////////////////////////////////////
/// @brief A toolkit of functions that turn entities into useable icons
/// @author Alex Vincent 
/// @details Create an entity (statically or dynamically) and pass them
/// by reference to any one of these functions. The passed entity will
/// be augmented by the function you called on it.
///////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable folder Icon
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnFolderIcon(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spriteSheet, float x, float y, float size, float animSpeed);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable settings Icon
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnSettingsIcon(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spriteSheet, float x, float y, float size, float animSpeed);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable chat Icon
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnChatIcon(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spriteSheet, float x, float y, float size, float animSpeed);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable search Icon
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnSearchIcon(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spriteSheet, float x, float y, float size, float animSpeed);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable pipeline extraction Icon
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnDataGraphIcon(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spriteSheet, float x, float y, float size, float animSpeed);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable help Icon
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnHelpIcon(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spriteSheet, float x, float y, float size, float animSpeed);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable browser Icon
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnBrowserIcon(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spriteSheet, float x, float y, float size, float animSpeed);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable hard drive Icon
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnHardDriveIcon(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spriteSheet, float x, float y, float size, float animSpeed);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable console Icon
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnConsoleIcon(ppc::Entity& entityToModify, ppc::Desktop& dt, ppc::InputHandler& ih, sf::Image& spriteSheet, float x, float y, float size, float animSpeed);



