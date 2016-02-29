//
//  characterRender.cpp
//  Project-Perfect-Citizen
//
//  Created by Michael Lowe on 2/28/16.
//  Copyright © 2016 Hyperfocus Games. All rights reserved.
//

#include "characterRender.hpp"


characterRender::characterRender(sf::Image& image): faceImage(image) {
    
    this->body = new sf::Sprite();
    this->shirt = new sf::Sprite();
    
    this->irisL = new sf::Sprite();
    this->irisR = new sf::Sprite();
    this->eyeL = new sf::Sprite();
    this->eyeR = new sf::Sprite();
    
    this->mouth = new sf::Sprite();
    
    this->texture = new sf::Texture();
    
    if(!texture->loadFromImage(faceImage, sf::IntRect(0*grid_size,
                                                      0*grid_size,
                                                      11*grid_size,
                                                      10*grid_size)))
    { exit(-1);}
    
    
    initializeSkinTones();
    
    generateCharacterValues();
    applyCharacterValues();
}

characterRender::~characterRender() {
    delete texture;
    delete body;
    delete shirt;
    delete irisL;
    delete irisR;
    delete eyeL;
    delete eyeR;
    delete mouth;
    //delete rectSourceSprite;
}

void characterRender::generateCharacterValues() {
    
    srand(time(NULL));

    
    // Random color
    sf::Color sc(rand() % 250 + 100,
                 rand() % 250 + 100,
                 rand() % 250 + 100);
    shirtColor = sc;
    
    
    // Random color
    sf::Color ec(rand() % 255,
                 rand() % 255,
                 rand() % 255);
    eyeColor = ec;
    
    
    // Randomly generated number
    // Eyes are between points (0,0) and (0,3) on our sprite sheet
    // So this randomly generates the y value  between 0-3
    // Used in the sf::IntRect when loading eyes from the texture map
    int e = rand() % 3;
    eyeType = e;
    
    
    // Randomly generated number
    // Mouths are between points (0,4) and (0,6) on our sprite sheet
    // So this randomly generates the y value  between 4-6
    // Used in the sf::IntRect when loading eyes from the texture map
    int m = rand() % 7 + 4;
    mouthType = m;
    

    // Randomly generated number
    // The skinTones vector holds 8 possible sf::Color values
    // This picks a random index
    // skinColor then becomes the element at this random index
    int s = rand() % 8;
    skinType = s;
    skinColor = skinTones.at(s);
}

void characterRender::applyCharacterValues() {
    
    ////////////////////////////////////
    /// DRAWING THE BODY
    ////////////////////////////////////
    body->setTexture(*texture);
    body->setTextureRect(sf::IntRect(2*grid_size,
                                     0*grid_size,
                                     5*grid_size,
                                     5*grid_size));
    body->setScale(1.2f, 1.2f);

    body->setColor(skinColor);
    body->setPosition(75, 75);
    
    
    shirt->setTexture(*texture);
    shirt->setTextureRect(sf::IntRect(2*grid_size,
                                     5*grid_size,
                                     5*grid_size,
                                     5*grid_size));
    shirt->setScale(1.2f, 1.2f);
    
    shirt->setColor(shirtColor);
    shirt->setPosition(75, 75);
    
    
    ////////////////////////////////////
    /// DRAWING THE EYE IRIS
    ////////////////////////////////////
    irisL->setTexture(*texture);
    irisL->setTextureRect(sf::IntRect(0*grid_size,
                                      3*grid_size,
                                      grid_size,
                                      grid_size));
    irisL->setColor(eyeColor);
    irisL->setPosition(300, 300);
    
    irisR->setTexture(*texture);
    irisR->setTextureRect(sf::IntRect(1*grid_size,
                                      3*grid_size,
                                      grid_size,
                                      grid_size));
    irisR->setColor(eyeColor);
    irisR->setPosition(450,300);
    
    
    ////////////////////////////////////
    /// DRAWING THE EYES
    ////////////////////////////////////
    
    eyeL->setTexture(*texture);
    eyeL->setTextureRect(sf::IntRect(0*grid_size,
                                     eyeType*grid_size,
                                     grid_size,
                                     grid_size));
    eyeL->setPosition(300, 300);
    
    eyeR->setTexture(*texture);
    eyeR->setTextureRect(sf::IntRect(1*grid_size,
                                     eyeType*grid_size,
                                     grid_size,
                                     grid_size));
    eyeR->setPosition(450, 300);
    
    
    
    ////////////////////////////////////
    /// DRAWING THE MOUTH
    ////////////////////////////////////
    mouth->setTexture(*texture);
    mouth->setTextureRect(sf::IntRect(0*grid_size,
                                      mouthType*grid_size,
                                      2*grid_size,
                                      grid_size));
    mouth->setPosition(365, 470);
    mouth->setScale(0.7f, 0.7f);
    
    
}

void characterRender::initializeSkinTones() {
    skinTones.push_back(sf::Color(255,220,177));
    skinTones.push_back(sf::Color(229,194,152));
    skinTones.push_back(sf::Color(228,185,143));
    skinTones.push_back(sf::Color(227,161,115));
    skinTones.push_back(sf::Color(217,145,100));
    skinTones.push_back(sf::Color(204,132, 67));
    skinTones.push_back(sf::Color(199,122, 88));
    skinTones.push_back(sf::Color(165, 67,  0));
    skinTones.push_back(sf::Color(134,  4,  0));
    skinTones.push_back(sf::Color(113,  2,  0));
    skinTones.push_back(sf::Color( 68,  0,  0));
    skinTones.push_back(sf::Color(255,224,196));
    skinTones.push_back(sf::Color(238,207,180));
    skinTones.push_back(sf::Color(222,171,127));
    skinTones.push_back(sf::Color(224,177,132));
    skinTones.push_back(sf::Color(223,166,117));
    skinTones.push_back(sf::Color(190,114, 60));
    skinTones.push_back(sf::Color(100, 25,  0));
    skinTones.push_back(sf::Color(91,   0,  0));
    skinTones.push_back(sf::Color(253,228,200));
    skinTones.push_back(sf::Color(239,214,189));
    skinTones.push_back(sf::Color(187,109, 74));
    skinTones.push_back(sf::Color(189,151,120));
    skinTones.push_back(sf::Color(225,173,164));
}


void characterRender::draw( sf::RenderTarget& target,
                           sf::RenderStates states) const {
    target.draw(*body, states);
    target.draw(*shirt, states);
    target.draw(*irisL, states);
    target.draw(*irisR, states);
    target.draw(*eyeL, states);
    target.draw(*eyeR, states);
    target.draw(*mouth, states);
}










