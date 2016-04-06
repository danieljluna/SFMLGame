#include "../Engine/debug.h"
#include "buttonRenderComponent.h"

using namespace ppc;
const std::string MOUSE_DOWN_CODE = "MDC";
const std::string MOUSE_RELEASED_CODE = "MRC";
const std::string MOUSE_DOUBLE_CLICK_CODE = "MDDC";
const std::string ICON_TYPE = "ICON";
const std::string BUTTON_TYPE = "BUTTON";

buttonRenderComponent::buttonRenderComponent( sf::Image& image, 
	int x, int y, int r, int f) : buttonImage(image) {
	
	this->sprite = new sf::Sprite();
	this->texture = new sf::Texture();
    
    width = r;
    frameCount = f;
    xIndex = x;
    yIndex = y;
    

    _buttonType = BUTTON_TYPE;
    _willAnimate = false;

    
    rectSourceSprite = new sf::IntRect(xIndex*size,
                                       yIndex*size,
                                       width*size,
                                       size);
    
    /* Check that the file exists in the path */
    if (!texture->loadFromImage(image, *rectSourceSprite))
        std::exit(-1);

	sprite->setTexture(*texture);
	sprite->setPosition(0, 0);
	sprite->setScale(.5f, .5f);
}

buttonRenderComponent::~buttonRenderComponent() {
	delete texture;
	delete sprite;
    delete rectSourceSprite;
}

void buttonRenderComponent::setButtonType(std::string t) {
    if (t == ICON_TYPE) {
        _buttonType = t;
        sprite->setScale(0.5, 0.5);
    }
    else if (t == BUTTON_TYPE) _buttonType = t;
}

void buttonRenderComponent::renderPosition(sf::Vector2f pos) {
	sprite->setPosition(pos.x, pos.y);
}

void buttonRenderComponent::setImageScale(float ScaleX, float ScaleY) {
	sprite->setScale(ScaleX, ScaleY);
}

sf::Sprite*  buttonRenderComponent::getSprite() {
	return sprite;
}

void buttonRenderComponent::setSprite(int x, int y, int r) {
    if(!texture->loadFromImage(buttonImage, 
		sf::IntRect(x*size, y*size, r*size, size))) { exit(-1); }
}

void buttonRenderComponent::setButtonScale(int r) {
	sprite->setScale(r + 0.0f, r + 0.0f);
}

void buttonRenderComponent::animate() {
    if (_willAnimate) {
        if (rectSourceSprite->left == (frameCount * size)) {
            rectSourceSprite->left = 0;
            _willAnimate = false;
        } else
            rectSourceSprite->left += size;
        
        texture->loadFromImage(buttonImage, *rectSourceSprite);
        sprite->setTexture(*texture);
    }
}



bool buttonRenderComponent::willAnimate() {
    return _willAnimate;
}

void buttonRenderComponent::draw( sf::RenderTarget& target,
	sf::RenderStates states) const {
        target.draw(*sprite, states);
}

void buttonRenderComponent::recieveMessage(msgType code) {
    if (_buttonType == BUTTON_TYPE) {
        if(code.compare(MOUSE_DOWN_CODE) == 0)
            setSprite(xIndex+width, yIndex, width);
        if(code.compare(MOUSE_RELEASED_CODE) == 0)
            setSprite(xIndex, yIndex, width);
    } else {
       if(code.compare(MOUSE_DOUBLE_CLICK_CODE) == 0)
           _willAnimate = true;
    }
}