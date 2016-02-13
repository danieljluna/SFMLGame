//desktop.h
// Nader Sleem

#pragma once

#include <vector>
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

#include "Window.h"
#include "NodeState.h"
#include "BaseFileType.h"

//temporary typedefs for classes/types not defined yet
typedef int OSStyle;


namespace ppc {
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
///@brief Brings the desired Window into focus.
///@details To be called when a specificed Window should be 
/// drawn above all others. The Window is then moved to the
/// front of the Window container, ahead of all other Windows,
/// but the ordering of the remaining Windows is kept.
/// @param wi A WindowInterface* which points to the Window that
/// is to be focused on.
///////////////////////////////////////////////////////////////////////
		void focusWindow(WindowInterface*);

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
		bool isMouseCollision(WindowInterface*, sf::Vector2f);


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
/// buttons for the Desktop.
///@param ft The FileTree object to be associated with the Desktop.
///@param w Width of the desktopWindow_
///@param h Height of the desktopWindow_
///@todo Add param for OSStyle?.
///////////////////////////////////////////////////////////////////////
		Desktop(size_t w, size_t h, NodeState& n);

		
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
///@brief Removes a Window from the Desktop.
///@details After a window is closed, the desktopWindow is the new 
/// focused.
///@param wi  A WindowInterface* which points to the Window to be 
/// deleted. If the pointer is nullptr, nothing happens.
///@post Desktop contains 1 less Window.
///////////////////////////////////////////////////////////////////////
		virtual void destroyWindow(WindowInterface*);

///////////////////////////////////////////////////////////////////////
///@brief Sets the Desktop to the given OS style.
///@param oss The style the Desktop is to be associated with.
///////////////////////////////////////////////////////////////////////
		virtual void setStyle(OSStyle*);

///////////////////////////////////////////////////////////////////////
///@brief Return a reference to desktopWindow
///////////////////////////////////////////////////////////////////////
		virtual WindowInterface& getDesktopWindow();

///////////////////////////////////////////////////////////////////////
///@brief Returns the root of the NodeState in the Desktop.
///////////////////////////////////////////////////////////////////////
		virtual NodeState& getNodeState();

///////////////////////////////////////////////////////////////////////
///@brief Reacts to Input for the focused Window.
///////////////////////////////////////////////////////////////////////
		virtual void registerInput(sf::Event& ev);

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