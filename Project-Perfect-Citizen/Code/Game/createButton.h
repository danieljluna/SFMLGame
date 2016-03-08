#pragma once

#include <iostream>
#include <fstream>
#include <SFML/Main.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "../Engine/Window.h"
#include "../Engine/inputComponent.h"
#include "../Engine/InputHandler.h"
#include "../Engine/Entity.h"
#include "../Engine/subject.h"
#include "textInputRenderComponent.hpp"
#include "textInputKeys.hpp"
#include "../Engine/InputHandler.h"
#include "animatorComponent.hpp"
#include "mousePressButton.h"
#include "consoleIconRenderComponent.h"
#include "buttonRenderComponent.h"
#include "consoleUpdateComponent.h"
#include "../Engine/NodeState.h"
#include "databaseSearchInputComponent.h"
#include "../Engine/TestFunctionClass.h"



//typedef bool (databaseSearchInputComponent::*backFn)(sf::Event&);
///////////////////////////////////////////////////////////////////////
/// @brief A toolkit of functions that turn entities into useable buttons
/// @author Alex Vincent 
/// @details Create an entity (statically or dynamically) and pass them
/// by reference to any one of these functions. The passed entity will
/// be augmented by the function you called on it.
///////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable back button
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations at (0, 3, 1), (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
template <class T>
void spawnBackButton(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spritesheet,
	float x, float y, float size, bool(*obsFunction)(T* functionOject, sf::Event& ev), T* nestedObject ) 
 {
	/* Render Component */
	buttonRenderComponent* buttonRender = new buttonRenderComponent(spritesheet, 0, 0, 2, 1);
	buttonRender->setImageScale(size, size);
	buttonRender->renderPosition(sf::Vector2f(x, y));

	/* Input Component*/
	mousePressButton* mpb = new mousePressButton(ih, buttonRender->getSprite()->getGlobalBounds(), "backButton");
	//this is deleting the observer thats in charge of clicking the button
	//mpb->clearObservers();

	FreeFunctionObserver<T>* backFunction = new FreeFunctionObserver<T>(obsFunction, nestedObject);
	//mpb->addFunctionObserver<T>(obsFunction, mpb, 0);

	entityToModify.addComponent(buttonRender);
	entityToModify.addComponent(mpb);
}

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable start button
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations at (0, 3, 1), (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnStartButton(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spritesheet, float x, float y, float size);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable next button
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnNextButton(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spritesheet, float x, float y, float size);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable blank large button
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnBlankLargeButton(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spritesheet, float x, float y, float size);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a okay button
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnOkayButton(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spritesheet, float x, float y, float size);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a cancel button
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnCancelButton(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spritesheet, float x, float y, float size);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable close button
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnCloseButton(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spritesheet, float x, float y, float size);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable maximize button
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnMaximizeButton(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spritesheet, float x, float y, float size);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable minimize button
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnMinimizeButton(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spritesheet, float x, float y, float size);


//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable blank small button
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnBlankSmallButton(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spritesheet, float x, float y, float size);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable up button
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnUpButton(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spritesheet, float x, float y, float size);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable down button
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnDownButton(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spritesheet, float x, float y, float size);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable right button
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnRightButton(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spritesheet, float x, float y, float size);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable left button
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnLeftButton(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spritesheet, float x, float y, float size);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable scroll bar container
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnScrollBarContainer(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spritesheet, float x, float y, float size);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable scroll bar handle
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnScrollBarHandle(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spritesheet, float x, float y, float size);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable confirmed icon (non clickable)
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnConfirmedIcon(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spritesheet, float x, float y, float size);

//////////////////////////////////////////////////////////////////////
/// @brief Turns the passed entity into a useable alert icon (non clickable)
/// Pass it the entity, a shared input handler, a spritesheet with 
/// the button animations, (x, y position), and a square scale size.
///////////////////////////////////////////////////////////////////////
void spawnAlertIcon(ppc::Entity& entityToModify, ppc::InputHandler& ih, sf::Image& spritesheet, float x, float y, float size);