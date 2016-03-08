#include "emailListElementRenderComponent.h"

using namespace ppc;

emailListElementRenderComponent::emailListElementRenderComponent(sf::Font& f, std::string subjectLine, int boxX, int boxY, int boxWidth, int boxHeight, int x, int y, int size) : font(f) {
	
	this->text = new sf::Text();
	text->setFont(font);
	text->setColor(sf::Color::Black);
	text->setPosition(float(x), float(y));
	text->setCharacterSize(size);
	text->setString(subjectLine);

	emailListElementBox.setPosition(sf::Vector2f(boxX, boxY));
	emailListElementBox.setSize(sf::Vector2f(boxWidth, boxHeight));
	emailListElementBox.setFillColor(sf::Color::White);
	
}

emailListElementRenderComponent::~emailListElementRenderComponent() {

}


void emailListElementRenderComponent::draw(sf::RenderTarget& target,
	sf::RenderStates states) const {
	target.draw(this->emailListElementBox, states);
	target.draw(*(this->text), states);
}

void emailListElementRenderComponent::recieveMessage(msgType code) {
	// Recieve messages if needed here
}