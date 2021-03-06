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
#include "Engine/Engine.h"
#include "Game/mousePressButton.h"
#include "Game/buttonRenderComponent.h"
#include "Game/consoleIconRenderComponent.h"
#include "Game/TreeCommands.h"
#include "Game/animatorComponent.hpp"
#include "Game/textInputKeys.hpp"
#include "Game/createWindow.h"
#include "Game/createIcon.h"
#include "Game/createButton.h"
#include "Game/createDesktop.h"
#include "Game/desktopExtractionComponent.hpp"
#include "Game/expressionistParser.hpp"
#include "Game/PipelineCharacter.h"
#include "Game/Database.h"
#include "Game/BootLoader.hpp"
#include "Game/characterRender.hpp"
#include "Game/interpolateUpdateComponent.hpp"

#include "Game/bootLoadingUpdateComponent.hpp"
#include "Game/bootLoadingAnimationRender.hpp"
#include "Game/endAnimationUpdateComponent.hpp"
#include "Game/endingAnimationRender.hpp"

#include "Game/TextBubble.h"


using namespace ppc;



void runBootDesktop(ppc::Desktop& myDesktop) {
    
    Window* bootWindow = new Window(1800,1000,sf::Color(30,32,33));

    Entity loading;
    
    sf::Font font;
    font.loadFromFile(resourcePath() + "consola.ttf");
    
   
    textLabelComponent* textLabel = new textLabelComponent(font,sf::Color::Green, 0,0, 20, " PCOS(C) , UNMOS. UNAUTHORIZED USE OF THIS TERMINAL CAN RESULT IN PENALTY BY DEATH. \n   Beginning File System Initialization \n");
    
    bootLoadingAnimationRender* bootRender = new bootLoadingAnimationRender(myDesktop.getButtonSheet(),*textLabel,7,5);

    bootLoadingUpdateComponent* bootUpdate = new bootLoadingUpdateComponent(*bootRender,0.1f);

    loading.addComponent(bootRender);
    loading.addComponent(bootUpdate);
    loading.addComponent(textLabel);
    bootWindow->addEntity(loading);
    
    myDesktop.addWindow(bootWindow);
}



void runEndDesktop(ppc::Desktop& myDesktop) {

    Window* endWindow = new Window(1800,1000,sf::Color(30,32,33));
    
    Entity ending;
    
    endingAnimationRender* endRender = new endingAnimationRender(myDesktop.getButtonSheet());
    endAnimationUpdateComponent* endUpdate = new endAnimationUpdateComponent(*endRender, 0.1f);
    
    ending.addComponent(endRender);
    ending.addComponent(endUpdate);
    endWindow->addEntity(ending);
    
    myDesktop.addWindow(endWindow);
}


void runPlayerDesktop(ppc::Desktop& myDesktop) {

	createPlayerDesktop(myDesktop, *myDesktop.getDesktopWindow(), 
		myDesktop.getInputHandler(), myDesktop.getIconSheet(), myDesktop.getButtonSheet());

}


void runTargetDesktop(ppc::Desktop& myDesktop) {
	createTeacherDesktop(myDesktop, *myDesktop.getDesktopWindow(),
		myDesktop.getInputHandler(), myDesktop.getIconSheet(), myDesktop.getButtonSheet());

}

int main(int argc, char** argv) {

    DBG_INIT();
	//Scans Debug Flags
	Debug::scanOpts(argc, argv);
	DEBUGF("ac", argc);

	World::initFontMap();

	//Dont touch these comments please.
	
	ifstream ifs1("Saves/playerDesktop.ini", std::ifstream::in);
	Desktop testDesktop;
	ifs1 >> testDesktop;
	
	bool BootToTitleCard = false; 
    // Create the main sf::window
    sf::RenderWindow screen(sf::VideoMode(1000, 800), "SFML window");

	//Dont touch these comments please.
	//World::setGameScreen(screen);
	//World::setCurrDesktop(testDesktop);
	//runPlayerDesktop(testDesktop);
	//World::runCurrDesktop();

	
	AudioQueue audiotest(5);
	audiotest.addBgm("SoundTrack_Extraction.ogg");
	audiotest.playBgm();
	
	///////////// Load Spritesheets/Textures/Background Images ////////
	sf::Sprite playerWallpaper;
	sf::Sprite teacherWallpaper;
	sf::Texture playerWallpaperTexture;
	sf::Texture teacherWallpaperTexture;
	playerWallpaperTexture.loadFromFile(resourcePath() + "Wallpaper.png");
	teacherWallpaperTexture.loadFromFile(resourcePath() + "Teacher_Wallpaper.png");

	playerWallpaper.setTexture(playerWallpaperTexture);
	teacherWallpaper.setTexture(teacherWallpaperTexture);

	playerWallpaper.setScale(0.7f, 0.7f);
	playerWallpaper.setPosition(0, 0);

    sf::Image buttonSheet;
	buttonSheet.loadFromFile(resourcePath() + "Windows_UI.png");
    sf::Image pixelSheet;
    pixelSheet.loadFromFile(resourcePath() + "Pixel_Title.png");
    sf::Image iconSheet;
    iconSheet.loadFromFile(resourcePath() + "Icon_Sheet.png");
	sf::Image teacherIconSheet;
	teacherIconSheet.loadFromFile(resourcePath() + "Teacher_Icon_Sheet.png");
	///////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////
	//Assuming Builders Should Eventually Go Here
	/////////////////////////////////////////////
	//Placeholder stuff for now.

	//runBootDesktop
	ppc::NodeState bootState;
	Window* bootWindow = new Window(1800, 1000, sf::Color(0, 0, 0));
	Desktop* bootDesktop = new Desktop(bootWindow, bootState);

	bootDesktop->setIconSheet(iconSheet);
	bootDesktop->setButtonSheet(buttonSheet);

	bootDesktop->setBackgrond(playerWallpaper);

	//runPlayerDesktop
	ppc::NodeState playerState;
	playerState.setUp();
	Window* playerDesktopWindow = new Window(1800, 1000, sf::Color(0, 0, 0));


	Desktop* playerDesktop = new Desktop(playerDesktopWindow, playerState);
	playerDesktop->setIconSheet(iconSheet);
	playerDesktop->setButtonSheet(buttonSheet);
	playerDesktop->setBackgrond(playerWallpaper);

	//runTargetDesktop
	ppc::NodeState targetState;
	targetState.setUp();
	Window* targetDesktopWindow = new Window(1800, 1000, sf::Color(0, 0, 0));

	Desktop* targetDesktop = new Desktop(targetDesktopWindow, targetState);
	targetDesktop->setIconSheet(iconSheet);
	targetDesktop->setButtonSheet(buttonSheet);
	targetDesktop->setBackgrond(teacherWallpaper);

	//runEndDesktop
	ppc::NodeState endState;
	Window* endWindow = new Window(1800, 1000, sf::Color(0, 0, 0));

	Desktop* endDesktop = new Desktop(endWindow, endState);
	endDesktop->setIconSheet(iconSheet);
	endDesktop->setButtonSheet(pixelSheet);
	endDesktop->setBackgrond(playerWallpaper);

   
	/////////////////////////////////////////////
	//Assuming Builders End Here
	/////////////////////////////////////////////

    World::setGameScreen(screen);

    Logger::startTimer("bootDesktop");
    
	//Main Loops for each Desktops
	World::setCurrDesktop(*bootDesktop);
	runBootDesktop(*bootDesktop);
    while (World::runDesktop(*bootDesktop)) {}
	delete bootDesktop;

    Logger::endTimer("bootDesktop");
    Logger::startTimer("playerDesktop");

	World::setCurrDesktop(*playerDesktop);
	runPlayerDesktop(*playerDesktop);
	while (World::runDesktop(*playerDesktop)) {}
	delete playerDesktop;

    Logger::endTimer("playerDesktop");
    Logger::startTimer("targetDesktop");

	World::setCurrDesktop(*targetDesktop);
	runTargetDesktop(*targetDesktop);
	while (World::runDesktop(*targetDesktop)) {}
	delete targetDesktop;

    Logger::endTimer("targetDesktop");
    Logger::startTimer("endDesktop");

	World::setCurrDesktop(*endDesktop);
	runEndDesktop(*endDesktop);
    while (World::runDesktop(*endDesktop)) {}
    delete endDesktop;

    Logger::endTimer("endDesktop");

    Logger::exportParcels();
	

    return EXIT_SUCCESS;
}



