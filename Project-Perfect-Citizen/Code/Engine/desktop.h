//desktop.h
// Nader Sleem

#pragma once

#include <vector>
#include <map>
#include <SFML/Graphics/Drawable.hpp>

namespace sf {
    class Event;
    class Sprite;
    class Time;
	class Image;
};

//temporary typedefs for classes/types not defined yet
typedef int OSStyle;


namespace ppc {

	class WindowInterface;
	class NodeState;
	class InputHandler;

///////////////////////////////////////////////////////////////////////
///@brief Manages a series of Windows, an associated file tree and
/// OS style.
///@details Desktops drawn on the screen will also have their
/// containing Windows drawn and managed on the screen. In 
/// addition, each Desktop has its own unique FileTree and
/// OS style.
///@author Nader Sleem
///@todo Deal with minimization.
///////////////////////////////////////////////////////////////////////
	class Desktop : public sf::Drawable {

///////////////////////////////////////////////////////////////////////
// PRIVATE FIELDS
///////////////////////////////////////////////////////////////////////
	private:
///////////////////////////////////////////////////////////////////////
///@brief The OS style of this Desktop
///////////////////////////////////////////////////////////////////////
		OSStyle* style_;

///////////////////////////////////////////////////////////////////////
///@brief The sprite sheet for a Desktop's Icons
///////////////////////////////////////////////////////////////////////
		sf::Image* iconSheet;

///////////////////////////////////////////////////////////////////////
///@brief The sprite sheet for a Desktop's Icons
///////////////////////////////////////////////////////////////////////
		sf::Image* buttonSheet;

///////////////////////////////////////////////////////////////////////
///@brief The FileTree structure of this Desktop
///////////////////////////////////////////////////////////////////////
		NodeState* nodeState_;

///////////////////////////////////////////////////////////////////////
///@brief The Window that represents the Desktop itself. Should contain
/// all the icons and buttons, and other windows of the Desktop.
///@details This window is special, in that it cannot be deleted from
/// from a Desktop. desktopWindow_ is a part of all the windows kept 
/// track by windows_. desktopWindow is ALWAYS in the back of the
/// window_ vector, even when it is focused. 
///////////////////////////////////////////////////////////////////////
		WindowInterface* desktopWindow_;

///////////////////////////////////////////////////////////////////////
///@brief The Window that is focused
///////////////////////////////////////////////////////////////////////
		WindowInterface* focused_;

///////////////////////////////////////////////////////////////////////
///@brief The container of all WindowInterfaces/Windows
///////////////////////////////////////////////////////////////////////
		std::vector<WindowInterface*> windows_;


		//maps strings to function pointers of functions that take in 
		// Node* and return WindowInterface*
		//map<string, (WindowInterface*) (Node*)> extensionMap_;

///////////////////////////////////////////////////////////////////////
///@brief Draws the Desktop & all its Windows.
///
///@param in target The object that is to be drawn on.
///@param in states Used to manipulate draw calls.
///////////////////////////////////////////////////////////////////////
		virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

///////////////////////////////////////////////////////////////////////
///@brief A helper function that checks if the mouse is within a
/// window.
///////////////////////////////////////////////////////////////////////
		bool isMouseCollision(WindowInterface*, sf::Vector2i);


///////////////////////////////////////////////////////////////////////
//PUBLIC FIELD
///////////////////////////////////////////////////////////////////////
	public:

///////////////////////////////////////////////////////////////////////
// CTORs & DTOR
///////////////////////////////////////////////////////////////////////
		
		//No default CTor
		Desktop() = delete;
///////////////////////////////////////////////////////////////////////
///@brief Desktop Constructor.
///@details Creates a Desktop with a given FileTree and width and 
/// height for the size of the desktopWindow_, which holds the icons &
/// buttons for the Desktop. The Ctor also intitalizes the
/// Input Handle for the Desktop. 
///@param bkgndWin The Window representing the Window for the Desktop
/// background, which can hold icons/entities.
///@param n The NodeState object to be associated with the Desktop.
///@todo Add param for OSStyle?.
///////////////////////////////////////////////////////////////////////
		Desktop(WindowInterface& bkgndWin, NodeState& n);

		
///////////////////////////////////////////////////////////////////////
///@brief Copy Ctor
///////////////////////////////////////////////////////////////////////
		Desktop(const Desktop& other);

///////////////////////////////////////////////////////////////////////
///@brief The virtual Dtor
///////////////////////////////////////////////////////////////////////
		virtual ~Desktop();

///////////////////////////////////////////////////////////////////////
///@brief Adds a new Window to the Desktop.
///@details When a new Window is added to the Desktop, it is 
/// automatically focused on.
///@param wi A WindowInterface* which points to the Window to be added.
/// If the pointer is nullptr, nothing happens.
///@post Desktop contains 1 more Window.
///////////////////////////////////////////////////////////////////////
		virtual void addWindow(WindowInterface*);


        ///////////////////////////////////////////////////////////////////////
        ///@brief Brings the desired Window into focus.
        ///@details To be called when a specificed Window should be 
        /// drawn above all others. The Window is then moved to the
        /// front of the Window container, ahead of all other Windows,
        /// but the ordering of the remaining Windows is kept.
        /// @param wi A WindowInterface* which points to the Window that
        /// is to be focused on.
        ///@return Returns True if the Window successfuly focused. Returns
        /// False if the argument was nullptr, the Desktop's Window, or if
        /// the argument is not a Window in the Desktop.
        ///////////////////////////////////////////////////////////////////////
        bool focusWindow(WindowInterface*);

        bool isWindow(WindowInterface*);

///////////////////////////////////////////////////////////////////////
///@brief Removes a Window from the Desktop.
///@details After a window is closed, the desktopWindow is the new 
/// focused.
///@param wi  A WindowInterface* which points to the Window to be 
/// deleted. If the pointer is nullptr, nothing happens.
///@post Desktop contains 1 less Window.
///////////////////////////////////////////////////////////////////////
		virtual void destroyWindow(WindowInterface*);

///////////////////////////////////////////////////////////////////////
///@brief Sets the icon spritesheet to the Desktop.
///@param sheet The spritesheet containing the icons for the Desktop.
///////////////////////////////////////////////////////////////////////
		virtual void setIconSheet(sf::Image& sheet);

///////////////////////////////////////////////////////////////////////
///@brief Gets the icon spritesheet to the Desktop.
///////////////////////////////////////////////////////////////////////
		virtual sf::Image* getIconSheet();

///////////////////////////////////////////////////////////////////////
///@brief Sets the icon spritesheet to the Desktop.
///@param sheet The spritesheet containing the icons for the Desktop.
///////////////////////////////////////////////////////////////////////
		virtual void setButtonSheet(sf::Image& sheet);

///////////////////////////////////////////////////////////////////////
///@brief Gets the icon spritesheet to the Desktop.
///////////////////////////////////////////////////////////////////////
		virtual sf::Image* getButtonSheet();

///////////////////////////////////////////////////////////////////////
///@brief Returns a reference of the NodeState in the Desktop.
///@return A reference to the NodeState in the Desktop
///////////////////////////////////////////////////////////////////////
		virtual NodeState& getNodeState();

///////////////////////////////////////////////////////////////////////
///@brief Returns a reference to the Input Handler of desktop window
///@return A reference to the InputHandler of desktopWindow_
///////////////////////////////////////////////////////////////////////
		virtual InputHandler& getInputHandler();

///////////////////////////////////////////////////////////////////////
///@brief Returns the pointer to the desktopWindow
///////////////////////////////////////////////////////////////////////
		virtual WindowInterface* getDesktopWindow();

///////////////////////////////////////////////////////////////////////
///@brief Adds a background render cmpnt to the given Window
///////////////////////////////////////////////////////////////////////
		virtual void addBackgroundCmpnt(WindowInterface*, sf::Sprite&);

///////////////////////////////////////////////////////////////////////
///@brief Reacts to Input for the focused Window.
///////////////////////////////////////////////////////////////////////
		virtual void registerInput(sf::Event ev);

///////////////////////////////////////////////////////////////////////
///@brief Updates all Windows and all objects in the Windows.
///@param deltaTime The time the object needs to catch up with.
///////////////////////////////////////////////////////////////////////
		virtual void update(sf::Time&);

///////////////////////////////////////////////////////////////////////
///@brief Refreshes all Windows of the Desktop, so they are ready
/// to be drawn again.
///@param states Used to manipulate draw.
///////////////////////////////////////////////////////////////////////
		virtual void refresh(sf::RenderStates states = sf::RenderStates());
			
	};
};