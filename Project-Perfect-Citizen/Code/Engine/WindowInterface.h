#ifndef WINDOW_INTERFACE_H
#define WINDOW_INTERFACE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Window/Event.hpp>

#include "inputComponent.h"
#include "updateComponent.h"
#include "renderComponent.h"
#include "entity.h"


namespace ppc {


///////////////////////////////////////////////////////////////////////
/// @brief Interface for all Window interactions.
/// @details Due to the relatively complicated Window hierarchy, this
///     class is needed to define the common interface between all 
///     classes in the hierarchy.
///////////////////////////////////////////////////////////////////////
class WindowInterface : public sf::Drawable, public sf::Transformable {
public:
  /////////////////////////////////////////////////////////////////////
  // Virtual Destructor
  /////////////////////////////////////////////////////////////////////

    virtual ~WindowInterface() {};


  /////////////////////////////////////////////////////////////////////
  // Setters
  /////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////
    /// @brief Sets the position of the Window
    ///////////////////////////////////////////////////////////////////
    virtual void setPosition(float x, float y) {};

    ///////////////////////////////////////////////////////////////////
    /// @brief Sets the size of the Window
    ///////////////////////////////////////////////////////////////////
    virtual void setSize(float x, float y) {};
    

  /////////////////////////////////////////////////////////////////////
  // Adding Entities and Components
  /////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////
    /// @brief Adds an Input Component to the Window.
    /// @details This function adds an Input Component to the Window.
    ///     Currently merely appends the Component.
    /// @todo Add functionality to assign Components order in the 
    ///     Vector
    ///
    /// @pre inputcmpnt != nullptr
    /// @param inputcmpnt A pointer to the InputComponent to add.
    ///////////////////////////////////////////////////////////////////
    virtual void addInputComponent(InputComponent* inputcmpnt) = 0;

    ///////////////////////////////////////////////////////////////////
    /// @brief Adds an Render Component to the Window.
    /// @details This function adds an Render Component to the Window.
    ///     Currently merely appends the Component.
    /// @todo Add functionality to assign Components order in the 
    ///     Vector
    ///
    /// @pre rendercmpnt != nullptr
    /// @param rendercmpnt A pointer to the RenderComponent to add.
    ///////////////////////////////////////////////////////////////////
    virtual void addRenderComponent(RenderComponent* rendercmpnt) = 0;

    ///////////////////////////////////////////////////////////////////
    /// @brief Adds an Update Component to the Window.
    /// @details This function adds an Update Component to the Window.
    ///     Currently merely appends the Component.
    /// @todo Add functionality to assign Components order in the 
    ///     Vector
    ///
    /// @pre updatecmpnt != nullptr
    /// @param updatecmpnt A pointer to the UpdateComponent to add.
    ///////////////////////////////////////////////////////////////////
    virtual void addUpdateComponent(UpdateComponent* updatecmpnt) = 0;

    ///////////////////////////////////////////////////////////////////
    /// @brief Adds an Entity to the Window
    /// @details More specifically, this adds the Components connected
    ///     to this Entity to the Window. Currently merely appends the 
    ///     Components.
    /// @todo Add functionality to assign Components order in the 
    ///     Vector
    ///
    /// @param entity The entity to add to the Window.
    ///////////////////////////////////////////////////////////////////
    virtual void addEntity(Entity& entity) = 0;


  /////////////////////////////////////////////////////////////////////
  // Update Functionality
  /////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////
    /// @brief Updates this, and all objects in the Window.
    ///////////////////////////////////////////////////////////////////
    virtual void update(sf::Time& deltaTime) = 0;

    ///////////////////////////////////////////////////////////////////
    /// @brief Reacts to Input for this, and all objects in the Window.
    ///////////////////////////////////////////////////////////////////
    virtual void registerInput(sf::Event&) = 0;


protected:

  /////////////////////////////////////////////////////////////////////
  // Constructors
  /////////////////////////////////////////////////////////////////////
    
    WindowInterface() {};

    WindowInterface(const WindowInterface&) {};


    ///////////////////////////////////////////////////////////////////
    /// @brief Draws this, and all objects in the Window.
    /// @details 
    ///
    /// @param target This is almost always going to be a 
    /// sf::renderWindow. 
    /// @param states This is used to dictate certain states that the 
    /// object can be rendered in. For now this can be safely "ignored"
    /// Just created a RenderStates object and shove it in there. 
    ///////////////////////////////////////////////////////////////////
    virtual void draw(sf::RenderTarget& target,
                      sf::RenderStates states) const override = 0;


};


};      //End namespace



#endif  //End WINDOW_INTERFACE_H