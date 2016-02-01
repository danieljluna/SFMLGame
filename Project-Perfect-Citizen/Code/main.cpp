//Used to get XCODE working/////////////////////////////////

#ifdef WINDOWS_MARKER
    #define resourcePath() string()
#else
    #include "ResourcePath.hpp"
#endif

///////////////////////////////////////////////////////////

#include <iostream>

#include <SFML/Main.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Engine/testRenderSprite.h"
#include "Engine/testRotateSprite.h"
<<<<<<< HEAD
#include "Engine/subject.h"
#include "Engine/TestSubject.h"
#include "Engine/TestObserver.h"
#include "Engine/debug.h"
#include "Library/json/json.h"
#include <fstream>
=======
#include "Engine/TestSubject.h"
#include "Engine/TestObserver.h"
#include "Engine/debug.h"
#include "Engine/entity.h"
#include "Engine/Window.h"

using namespace ppc;

>>>>>>> experimental

//Note that this is placeholder for now
int main(int argc, char** argv) {
	//Scans Debug Flags
	Debug::scanOpts(argc, argv);
	//Example of using the debugger macro
	DEBUGF("ac", argc);

    // Create the main sf::window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    //Define a Sprite
    sf::Sprite S;
    sf::Texture T;
    if (!(T.loadFromFile(resourcePath() + "Resources/kappa.png"))) {
        //Test for failure
        cerr << "COULD NOT LOAD KAPPA.PNG\n";
        std::system("PAUSE");
        return -1;
    };
    S.setTexture(T);
    S.setPosition(300, 300);
    S.setScale(0.2f, 0.2f);


    //Create A TestRenderSprite
    TestRenderSprite testRenderSpr(resourcePath() + "Resources/kappa.png");

    //Create A TestRotateSprite
	testRotateSprite testSprCmpnt;
    
    //Put that Component into an Entity
    Entity testEntity;
    testEntity.addComponent(&testRenderSpr);

    //Create ppc::Window
    Window kappaBlack(200, 200);
    //Add testEntity to ppc::Window
    kappaBlack.addEntity(testEntity);

<<<<<<< HEAD
	//Add the component to it
	testRotateSprite test(S, 1);
    // Start the game loop
	sf::Clock deltaTime; //define deltaTime
	sf::Time dt;
    //////////JSON EXAMPLE//////////////////////////////////////////////
    Json::Reader reader;
    Json::Value value;
    // read from file, why can I just use the name dummy.json?
    ifstream doc(resourcePath() + "dummy.json", ifstream::binary);
    if (reader.parse(doc, value)){
        //outputting whole dummy doc
        cout << value << endl;
        //output value acquanted with my-encoding
        string out = value[ "my-encoding" ].asString();
        cout << out << endl;
        // create Json Array object from my-plug-ins
        const Json::Value arrayObj = value[ "my-plug-ins" ];
        for (int i = 0; i < arrayObj.size(); i++){
            //output each arrayObj
            cout << arrayObj[i].asString();
            if (i != arrayObj.size() - 1) { cout << endl; }
        }
    }
    cout << endl;
    //create json array from my-indent
    const Json::Value indentArray = value["my-indent"];
    //can make returned value int, bool, string, etc.
    cout << indentArray.get("length", "Not found").asInt() << endl;
    cout << indentArray.get("use_space", "Not found").asBool() << endl;
    string temp = value.get("Try to find me", "Not found" ).asString();
    cout << temp << endl;
    ////////////////////////////////////////////////////////////////////
=======
////Start the game loop
    //Used to keep track time
	sf::Clock deltaTime;
    sf::Time framePeriod = sf::milliseconds(1000.0f / 30.f);
>>>>>>> experimental
    while (window.isOpen()) {
        //Process sf::events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (deltaTime.getElapsedTime() > framePeriod) {
            // Clear screen
            window.clear(sf::Color::White);

            //Draw Objects
            window.draw(testRenderSpr);
            window.draw(S);
            
            //Update kappaBlack
            sf::Time dt = deltaTime.restart();
            kappaBlack.update(dt);

            //Draw kappaBlack ppc::Window
            kappaBlack.refresh();
            window.draw(kappaBlack);

            //Display final Window
            window.display();
        }
    }
    return EXIT_SUCCESS;
}
