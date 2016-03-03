#ifdef WINDOWS_MARKER
#define resourcePath() string("Resources/")
#else
#include "ResourcePath.hpp"
#endif

#include "Vertex.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "debug.h"
#include <iostream>
const int ppc::Vertex::fontSize_ = 20;
const float ppc::Vertex::radius_ = 30.f;

ppc::Vertex::Vertex(){

	color_ = sf::Color::Yellow;

	circ_.setRadius(radius_);
	circ_.setFillColor(color_);
	circ_.setPosition(0, 0);
	text_.setPosition(radius_ / 2.f, radius_ / 2.f);
	setTextFontLoad(resourcePath() + "consola.ttf");
}

ppc::Vertex::Vertex(const Vertex & other){
	color_ = other.color_;
	char_ = other.char_;
	circ_ = other.circ_;
	text_ = other.text_;
	font_ = other.font_;

}

ppc::Vertex& ppc::Vertex::operator=(const Vertex& other){
	if (this != &other) {
		color_ = other.color_;
		char_ = other.char_;
		circ_ = other.circ_;
		text_ = other.text_;
		font_ = other.font_;
	}
	return *this;
}

ppc::Vertex::~Vertex() {
}

sf::Color ppc::Vertex::getColor() const {
	return color_;
}

void ppc::Vertex::setColor(sf::Color col) {
	color_ = col;
	circ_.setFillColor(color_);
}

sf::Vector2f ppc::Vertex::getPosCenter() const {
	sf::Vector2f p = getPosition();
	sf::FloatRect f = circ_.getGlobalBounds();
	p.x += (f.width / 2.f);
	p.y += (f.height / 2.f);
	return p;
}

sf::FloatRect ppc::Vertex::getLocalBounds() const {
	sf::FloatRect fRect = circ_.getLocalBounds();
	fRect.left = getPosition().x;
	fRect.top = getPosition().y;
	return fRect;
}

sf::FloatRect ppc::Vertex::getGlobalBounds() const {
	sf::FloatRect fRect = circ_.getGlobalBounds();
	fRect.left = getPosition().x;
	fRect.top = getPosition().y;
	return fRect;
}

ppc::PipelineCharacter ppc::Vertex::getCharacter() const {
	return char_;
}

void ppc::Vertex::setCharacter(ppc::PipelineCharacter ch) {
	char_ = ch;

	text_.setString(char_.getSSN().substr(0, 2));
}

void ppc::Vertex::setTextFont(sf::Font f) {
	font_ = f;
	text_.setFont(font_);
	text_.setString(char_.getSSN().substr(0, 2));
	text_.setCharacterSize(fontSize_);
	text_.setColor(sf::Color::Black);
}

void ppc::Vertex::setTextFontLoad(std::string fontPath) {
	font_.loadFromFile(fontPath);
	setTextFont(font_);
}

void ppc::Vertex::applyDraggable(ppc::DraggableInput &di, ppc::InputHandler &ih) {
	di.watch(ih, sf::Event::MouseButtonPressed);
	di.watch(ih, sf::Event::MouseButtonReleased);
	di.watch(ih, sf::Event::MouseMoved);
}

void ppc::Vertex::draw(sf::RenderTarget& target,
	sf::RenderStates states) const {

	states.transform *= getTransform();
	
	target.draw(circ_, states);
	target.draw(text_, states);
}