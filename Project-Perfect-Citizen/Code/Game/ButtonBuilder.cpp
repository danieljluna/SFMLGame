#include "ButtonBuilder.h"
#include "buttonRenderComponent.h"
#include "../Game/mousePressButton.h"
#include "../Engine/debug.h"
#include <ostream>
#include "TextDisplayRenderComponent.h"

ppc::ButtonBuilder::ButtonBuilder() 
{
	sheetX = 0;
	sheetY = 0;
	width = 0;
	frames = 0;
	size = 1;

	posX = 0.f;
	posY = 0.f;

	sprtUp = nullptr;
	sprtDown = nullptr;

	spriteSheet = nullptr;
	inputHandle = nullptr;

	label = "DEFAULT";

	isLargeCustom = false;
}

ppc::ButtonBuilder::~ButtonBuilder()
{
}

void ppc::ButtonBuilder::setSpritesByIndicies(int x, int y, int r, int f)
{
	sheetX = x;
	sheetY = y;
	width = r;
	frames = f;
}

void ppc::ButtonBuilder::setSize(float s) {
	size = s;
}

void ppc::ButtonBuilder::setSprites(sf::Sprite&, sf::Sprite&)
{

}

void ppc::ButtonBuilder::setFunction() {
}

void ppc::ButtonBuilder::setButtonPosition(float x, float y)
{
	posX = x;
	posY = y;
}

void ppc::ButtonBuilder::setButtonPosition(sf::Vector2f pos)
{
	posX = pos.x;
	posY = pos.y;
}

void ppc::ButtonBuilder::setLabelMessage(std::string l) 
{
	label = l;
}

void ppc::ButtonBuilder::setLabelFont(sf::Font& f)
{
	font = &f;
}

void ppc::ButtonBuilder::setLabelSize(int lS)
{
	labelSize = lS;
}

void ppc::ButtonBuilder::setIsLargeCustom(bool size) {
	isLargeCustom = size;
}

void ppc::ButtonBuilder::setSpriteSheet(sf::Image& sheet)
{
	spriteSheet = &sheet;
}

void ppc::ButtonBuilder::setInputHandle(ppc::InputHandler& ih)
{
	inputHandle = &ih;
}

void ppc::ButtonBuilder::create(Entity& e)
{

	/* Render Components */
	buttonRenderComponent* buttonRender;
		
	/* Case: Custom Buttom (Defaults to small button)*/
	if (label.compare("DEFAULT") != 0) {
		if (isLargeCustom) buttonRender = new buttonRenderComponent(*spriteSheet, 4, 1, 2, 1);
		else buttonRender = new buttonRenderComponent(*spriteSheet, 6, 3, 1, 1);
	}

	/* Default: Button from Sprite Sheet Indicies */
	else {
		buttonRender = new buttonRenderComponent(*spriteSheet, sheetX, sheetY, width, frames);
	}

	buttonRender->setImageScale(size, size);
	buttonRender->renderPosition(sf::Vector2f(posX, posY));

	TextDisplayRenderComponent* labelRender = 
		new TextDisplayRenderComponent(*font, sf::Color::Black, 100, 100, size, label);

	/* Input Component*/
	mousePressButton* mpb = new mousePressButton(*inputHandle, buttonRender->getSprite()->getGlobalBounds(), "GENERIC_BUTTON");

	e.addComponent(buttonRender);
	e.addComponent(labelRender);
	e.addComponent(mpb);
	buttonRender->renderPosition(sf::Vector2f(posX, posY));

}

