//Used to get XCODE working/////////////////////////////////

#ifdef WINDOWS_MARKER
    #define resourcePath() string("Resources/")
#else
    #include "ResourcePath.hpp"
#endif

///////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <SFML/Main.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Library/json/json.h"
#include "Engine/testRenderSprite.h"
#include "Engine/InputHandler.h"
#include "Engine/subject.h"
#include "Engine/TestObserver.h"
#include "Engine/debug.h"
#include "Engine/entity.h"
#include "Engine/Window.h"
#include "Engine/desktop.h"
#include "Engine/mousePressButton.h"
#include "Engine/buttonRenderComponent.h"
#include "Engine/consoleIconRenderComponent.h"
#include "Engine/TreeCommands.h"
#include "Engine/NodeState.h"
#include "Engine/animatorComponent.hpp"
#include "Engine/textInputKeys.hpp"
#include "Engine/createWindow.h"
#include "Engine/createIcon.h"
#include "Engine/createButton.h"
#include "Engine/BorderDecorator.h"
#include "Engine/createDesktop.h"
#include "Engine/desktopExtractionComponent.hpp"

using namespace ppc;


//Note that this is placeholder for now
int main(int argc, char** argv) {

	//Scans Debug Flags
	Debug::scanOpts(argc, argv);
	DEBUGF("ac", argc);

    // Create the main sf::window
    sf::RenderWindow screen(sf::VideoMode(1000, 800), "SFML window");

	//Create the InputHandler <-- to be removed
	ppc::InputHandler* inputHandle = new InputHandler();

	///////////// Load Spritesheets/Textures //////////////
    sf::Image spriteSheet;
	spriteSheet.loadFromFile(resourcePath() + "Windows_UI.png");
    sf::Image iconSheet;
    iconSheet.loadFromFile(resourcePath() + "Icon_Sheet.png");
	//////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////
	///// CREATE THE PLAYER DESKTOP
	/////////////////////////////////////////////////////////
	ppc::NodeState* testState = new NodeState();
	testState->setUp();
	WindowInterface* desktopWindow = new Window(1800,1000,sf::Color(200, 200, 200));
	Desktop myDesktop(*desktopWindow, *testState);
	createPlayerDesktop(myDesktop, *desktopWindow, *inputHandle, iconSheet);

    ///////////////////////////////////////////////////////////////////
	// Start the game loop
	///////////////////////////////////////////////////////////////////
	sf::Clock deltaTime; //define deltaTime
    //Used to keep track time
    sf::Time framePeriod = sf::milliseconds(sf::Int32(1000.0f / 30.f));
    while (screen.isOpen()) {
        //Process sf::events
        sf::Event event;
        while (screen.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
				screen.close();

			//Input phase
			inputHandle->registerEvent(event);
        }

        if (deltaTime.getElapsedTime() > framePeriod) {

            // Clear screen
			screen.clear(sf::Color::White);

            //Draw Background
			//screen.draw(S);
            
            //Update all Windows in the Desktop
            sf::Time dt = deltaTime.restart();
			myDesktop.update(dt);

            //Draw all the Windows in the Desktop
			myDesktop.refresh();

			//Logger should not be used in place of passing
			//the actual drawn Desktop
			screen.draw(myDesktop);

            //Display final Window
			screen.display();
        }
    }
	
    return EXIT_SUCCESS;
}
