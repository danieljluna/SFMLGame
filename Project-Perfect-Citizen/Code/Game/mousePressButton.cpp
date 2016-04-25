#include "../Engine/debug.h"
#include "mousePressButton.h"
#include <iostream>
#include <string>

#include "../Engine/FreeFunctionObserver.h"
#include "../Engine/event.h"

using namespace ppc;
const std::string MOUSE_DOWN_CODE = "MDC";
const std::string MOUSE_RELEASED_CODE = "MRC";
const std::string MOUSE_DOUBLE_CLICK_CODE = "MDDC";
const std::string OPEN_THE_CONSOLE = "OTC";
const std::string OPEN_THE_FILE = "OTF";
const std::string OPEN_THE_SETTINGS = "OTS";
const std::string OPEN_THE_CHAT = "OTCH";
const std::string OPEN_THE_SEARCH = "OTSER";
const std::string OPEN_THE_PIPELINE = "OTP";
const std::string OPEN_THE_HELP = "OTH";
const std::string OPEN_THE_BROWSER = "OTB";
const std::string OPEN_THE_EXPLORER = "OTE";
const std::string OPEN_THE_EMAIL = "OTEM";

const float DOUBLE_CLICK_TIME = 500.0f;

using namespace std;
mousePressButton::mousePressButton() : 
	InputComponent(3), buttonRect() {

}


mousePressButton::mousePressButton(ppc::InputHandler& ih, 
	sf::FloatRect rect, std::string iBP) : 
	InputComponent(3), buttonRect(rect), isBeingPressed(iBP){

	//add a new subject that is tied to the event
	ih.addHandle(sf::Event::MouseButtonPressed);
	ih.addHandle(sf::Event::MouseButtonReleased);
	ih.addHandle(sf::Event::MouseMoved);
	 
	//add an observer to the subject we just added
	watch(ih, sf::Event::MouseButtonPressed);
	watch(ih, sf::Event::MouseButtonReleased);
	watch(ih, sf::Event::MouseMoved);
	

}

void mousePressButton::clearObservers()
{
	for (size_t i = 0; i < observerCount_; ++i) {
		delete observerArray_[i];
	}
}


//void mousePressButton::addFunctionObserver(bool(*fnToAdd)(sf::Event &ev), mousePressButton* mpb, unsigned int placeToInsert)


void ppc::mousePressButton::injectEvent(ppc::Event ev)
{
	switch (ev.type) {
	case ppc::Event::EventTypes::AbleType:
		if (ev.able.disable == true) {
			setIsClickable(false);
			getEntity()->broadcastMessage(ev);
		}
		else if (ev.able.enable == true) {
			setIsClickable(true);
			getEntity()->broadcastMessage(ev);
		}
		break;
	default:
		break;
	}
	
}

mousePressButton::~mousePressButton() {

	//ignore(inputHandle, sf::Event::MouseButtonPressed);
	//ignore(inputHandle, sf::Event::MouseButtonReleased);
}

void mousePressButton::setInputHandle(ppc::InputHandler& ih) {

	ih.addHandle(sf::Event::MouseButtonPressed);
	ih.addHandle(sf::Event::MouseButtonReleased);
	ih.addHandle(sf::Event::MouseMoved);

	watch(ih, sf::Event::MouseButtonPressed);
	watch(ih, sf::Event::MouseButtonReleased);
	watch(ih, sf::Event::MouseMoved);

}

void mousePressButton::setFloatRect(sf::FloatRect rect) {
	buttonRect = rect;
}


sf::FloatRect mousePressButton::getFloatRect() const {
    return buttonRect;
}

void mousePressButton::setIsBeingPressed(std::string iBP) {
	isBeingPressed = iBP;
}

void ppc::mousePressButton::setIsClickable(bool c){
	isClickable = c;
}

bool ppc::mousePressButton::getIsClickable() {
	return isClickable;
}


bool mousePressButton::isCollision(sf::Vector2i mousePos) {
    //Gets the position as a Float Vector
    sf::Vector2f mouseFloatPos(float(mousePos.x), float(mousePos.y));
	//cout << "MOUSE X, Y: " << mousePos.x << ",  " << mousePos.y << endl;
	//cout << "ButtonRect LEFT, TOP: " << buttonRect.left << ",  "<< buttonRect.top << endl;

    //Returns if point is in foatRect
    return buttonRect.contains(mouseFloatPos);
}


bool mousePressButton::registerInput(sf::Event ev) {
    if (getEntity() != nullptr) {

		if (!isClickable) return true;

        /* Case: Mouse Pressed Event*/
        if (ev.type == sf::Event::MouseButtonPressed) {
            if (ev.mouseButton.button == sf::Mouse::Left &&
                isCollision({ ev.mouseButton.x ,ev.mouseButton.y })) {

                /* Send the mouse down event message regardless */
                // LEGACY CODE -> getEntity()->broadcastMessage(MOUSE_DOWN_CODE);
                
				ppc::Event ppcEv(ev);
				ppcEv.type = ppc::Event::ButtonType;
				ppcEv.buttons.isPushed = true;
				getEntity()->broadcastMessage(ppcEv);
				onPress_.sendEvent(ev);
				wasPressed_ = true;

                /* Handle Double Click Register */
                mouseTime = mouseClock.getElapsedTime().asMilliseconds();
                if (mouseTime > DOUBLE_CLICK_TIME) {
                    mouseClock.restart();
                } else if (mouseTime < DOUBLE_CLICK_TIME) {
					if (isBeingPressed == "folderIcon") {

						// Send string (legacy code)
						getEntity()->broadcastMessage(OPEN_THE_FILE);

						// Send struct event (new event system)
						ppc::Event ppcEv(ev);
						ppcEv.type = ppc::Event::ButtonType;
						ppcEv.buttons.isPushed = true;
						ppcEv.buttons.isLeft = true;
						getEntity()->broadcastMessage(ppcEv);
					}
					else if (isBeingPressed == "settingsIcon") {

						// Send string (legacy code)
						getEntity()->broadcastMessage(OPEN_THE_SETTINGS);

						// Send struct event (new event system)
						ppc::Event ppcEv(ev);
						ppcEv.type = ppc::Event::ButtonType;
						ppcEv.buttons.isPushed = true;
						ppcEv.buttons.isLeft = true;
						getEntity()->broadcastMessage(ppcEv);
					}
					else if (isBeingPressed == "chatIcon") {

						// Send string (legacy code)
						getEntity()->broadcastMessage(OPEN_THE_CHAT);

						// Send struct event (new event system)
						ppc::Event ppcEv(ev);
						ppcEv.type = ppc::Event::ButtonType;
						ppcEv.buttons.isPushed = true;
						ppcEv.buttons.isLeft = true;
						getEntity()->broadcastMessage(ppcEv);
					}
					else if (isBeingPressed == "searchIcon") {

						// Send string (legacy code)
						getEntity()->broadcastMessage(OPEN_THE_SEARCH);

						// Send struct event (new event system)
						ppc::Event ppcEv(ev);
						ppcEv.type = ppc::Event::ButtonType;
						ppcEv.buttons.isPushed = true;
						ppcEv.buttons.isLeft = true;
						getEntity()->broadcastMessage(ppcEv);
					}
					else if (isBeingPressed == "dataGraphIcon") {

						// Send string (legacy code)
						getEntity()->broadcastMessage(OPEN_THE_PIPELINE);

						// Send struct event (new event system)
						ppc::Event ppcEv(ev);
						ppcEv.type = ppc::Event::ButtonType;
						ppcEv.buttons.isPushed = true;
						ppcEv.buttons.isLeft = true;
						getEntity()->broadcastMessage(ppcEv);
					}
					else if (isBeingPressed == "helpIcon") {

						// Send string (legacy code)
						getEntity()->broadcastMessage(OPEN_THE_HELP);

						// Send struct event (new event system)
						ppc::Event ppcEv(ev);
						ppcEv.type = ppc::Event::ButtonType;
						ppcEv.buttons.isPushed = true;
						ppcEv.buttons.isLeft = true;
						getEntity()->broadcastMessage(ppcEv);
					}
					else if (isBeingPressed == "browserIcon") {

						// Send string (legacy code)
						getEntity()->broadcastMessage(OPEN_THE_BROWSER);

						// Send struct event (new event system)
						ppc::Event ppcEv(ev);
						ppcEv.type = ppc::Event::ButtonType;
						ppcEv.buttons.isPushed = true;
						ppcEv.buttons.isLeft = true;
						getEntity()->broadcastMessage(ppcEv);
					}
					else if (isBeingPressed == "hardDriveIcon") {

						// Send string (legacy code)
						getEntity()->broadcastMessage(OPEN_THE_EXPLORER);

						// Send struct event (new event system)
						ppc::Event ppcEv(ev);
						ppcEv.type = ppc::Event::ButtonType;
						ppcEv.buttons.isPushed = true;
						ppcEv.buttons.isLeft = true;
						getEntity()->broadcastMessage(ppcEv);
					}
					else if (isBeingPressed == "consoleIcon") {

						// Send string (legacy code)
						getEntity()->broadcastMessage(OPEN_THE_CONSOLE);

						// Send struct event (new event system)
						ppc::Event ppcEv(ev);
						ppcEv.type = ppc::Event::ButtonType;
						ppcEv.buttons.isPushed = true;
						ppcEv.buttons.isLeft = true;
						getEntity()->broadcastMessage(ppcEv);
					}
					else if (isBeingPressed == "emailIcon") {

						// Send string (legacy code)
						getEntity()->broadcastMessage(OPEN_THE_EMAIL);

						// Send struct event (new event system)
						ppc::Event ppcEv(ev);
						ppcEv.type = ppc::Event::ButtonType;
						ppcEv.buttons.isPushed = true;
						ppcEv.buttons.isLeft = true;
						getEntity()->broadcastMessage(ppcEv);

					}
                    getEntity()->broadcastMessage(MOUSE_DOUBLE_CLICK_CODE);
                    onDoublePress_.sendEvent(ev);
                }
            }
			else if (ev.mouseButton.button == sf::Mouse::Right &&
				isCollision({ ev.mouseButton.x ,ev.mouseButton.y })) {
				ppc::Event ppcEv(ev);
				ppcEv.type = ppc::Event::ButtonType;
				ppcEv.buttons.isPushed = true;
				ppcEv.buttons.isRight = true;
				getEntity()->broadcastMessage(ppcEv);
				onRelease_.sendEvent(ev);
				wasPressed_ = true;
			}
        }
        /* Case: Mouse Released Event*/
        else if ((wasPressed_) && (ev.type == sf::Event::MouseButtonReleased)) {
            if (ev.mouseButton.button == sf::Mouse::Left &&
                isCollision({ ev.mouseButton.x ,ev.mouseButton.y })) {

                /* Send the mouse release message regardless*/
                //LEGACY -> getEntity()->broadcastMessage(MOUSE_RELEASED_CODE);
                
				ppc::Event ppcEv(ev);
				ppcEv.type = ppc::Event::ButtonType;
				ppcEv.buttons.isReleased = true;
				ppcEv.buttons.isLeft = true;
				getEntity()->broadcastMessage(ppcEv);
				onRelease_.sendEvent(ev);
				wasPressed_ = false;
            }
			else if (ev.mouseButton.button == sf::Mouse::Right &&
				isCollision({ ev.mouseButton.x ,ev.mouseButton.y })) {
				ppc::Event ppcEv(ev);
				ppcEv.type = ppc::Event::ButtonType;
				ppcEv.buttons.openEmail = false;
				ppcEv.buttons.openHarddrive = false;
				ppcEv.buttons.openBrowser = false;
				ppcEv.buttons.openHelp = false;
				ppcEv.buttons.openPipeline = false;
				ppcEv.buttons.openSearch = false;
				ppcEv.buttons.openChat = false;
				ppcEv.buttons.openSettings = false;
				ppcEv.buttons.openFolder = false;
				ppcEv.buttons.openConsole = false;
				ppcEv.buttons.mouseX = ev.mouseButton.x;
				ppcEv.buttons.mouseY = ev.mouseButton.y;
				ppcEv.buttons.isReleased = true;
				ppcEv.buttons.isRight = true;

				if (isBeingPressed.compare("emailIcon") == 0) { ppcEv.buttons.openEmail = true; }
				else if (isBeingPressed.compare("hardDriveIcon") == 0) { ppcEv.buttons.openHarddrive = true;}
				else if (isBeingPressed.compare("browserIcon") == 0) { ppcEv.buttons.openBrowser = true; }
				else if (isBeingPressed.compare("helpIcon") == 0) { ppcEv.buttons.openHelp = true;}
				else if (isBeingPressed.compare("dataGraphIcon") == 0) { ppcEv.buttons.openPipeline = true;}
				else if (isBeingPressed.compare("searchIcon") == 0) { ppcEv.buttons.openSearch = true;}
				else if (isBeingPressed.compare("chatIcon") == 0) { ppcEv.buttons.openChat = true; }
				else if (isBeingPressed.compare("settingsIcon") == 0) { ppcEv.buttons.openSettings = true;}
				else if (isBeingPressed.compare("folderIcon") == 0) { ppcEv.buttons.openFolder = true; }
				else if (isBeingPressed.compare("consoleIcon") == 0) { ppcEv.buttons.openConsole = true;}
				getEntity()->broadcastMessage(ppcEv);
				onRelease_.sendEvent(ppcEv);
				wasPressed_ = false;

			}
        }
		/* Case: Mouse Move Event */
		else if ((ev.type == sf::Event::MouseMoved)) {
			if (isCollision({ ev.mouseButton.x, ev.mouseButton.y })) {
				ppc::Event ppcEv(ev);
				ppcEv.type = ppc::Event::ButtonType;
				ppcEv.buttons.isHovered = true;
				getEntity()->broadcastMessage(ppcEv);
				onHover_.sendEvent(ev);
			}
		}
    }
    return true;
}

bool ppc::DisableMPB(mousePressButton* ptr, Event ev) {
	if (ptr->getIsClickable() == true ) {
		ppc::Event ppcEv(ev);
		ppcEv.type = ppc::Event::AbleType;
		ppcEv.able.disable = true;
		ppcEv.able.enable = false;
		ptr->injectEvent(ppcEv);
	}
	else {
		ppc::Event ppcEv(ev);
		ppcEv.type = ppc::Event::AbleType;
		ppcEv.able.disable = false;
		ppcEv.able.enable = true;
		ptr->injectEvent(ppcEv);
	}
	
	return true;
}

