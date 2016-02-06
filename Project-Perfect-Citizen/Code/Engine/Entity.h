#ifndef ENTITY_H
#define ENTITY_H

#include <cstddef>
#include <SFML/Graphics/Transformable.hpp>
#include <string>

typedef std::string msgType;

namespace ppc {

class Component;


//TODO: Finish Entity Interface
///////////////////////////////////////////////////////////////////////
/// @brief Uses a collection of Components to define a Entity.
/// @author Daniel Luna
/// @details The Entity is a minimally intrusive class that holds 
///     together the real powerhouses: the Components. The Entity is 
///     not designed to anything other than group Components 
///     considered to be part of the same Entity. The only member
///     data in Entity should be data used by a vast majority of 
///     Components. Furthermore, an Entity takes responsibility for
///     the destruction of its Components.
///////////////////////////////////////////////////////////////////////
class Entity {
public:

  /////////////////////////////////////////////////////////////////////
  // Constructors & Destructor
  /////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////
    /// @brief Default Constructor
    /// @details Creates an Empty Entity
    ///////////////////////////////////////////////////////////////////
    Entity();

    //No Copy Constructor
    Entity(const Entity& other) = delete;

    ///////////////////////////////////////////////////////////////////
    /// @brief Destructor
    ///////////////////////////////////////////////////////////////////
    ~Entity();


  /////////////////////////////////////////////////////////////////////
  // Getters
  /////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////
    /// @brief Returns the number of Components in this Entity.
    /// 
    /// @return Returns the number of Components in this Entity.
    ///////////////////////////////////////////////////////////////////
    size_t cmpntCount();
  
    ///////////////////////////////////////////////////////////////////
    /// @brief Returns the Component (or lack thereof) at the specified
    ///     index in this Entity.
    /// @pre (0 < index < cmpntCount())
    ///
    /// @param index The index to return
    /// @return  Returns a pointer to the Component with the given
    ///     index in this Entity.
    ///////////////////////////////////////////////////////////////////
    Component* getComponent(size_t index);
    
    ///////////////////////////////////////////////////////////////////
    /// @brief Returns the index of the Component in this Entity.
    /// 
    /// @param cmpnt The Component to get the index of.
    /// @return Returns the index of cmpnt in this Entity. If cmpnt is
    ///     not part of this Entity, returns -1.
    ///////////////////////////////////////////////////////////////////
    int getIndex(Component* cmpnt);

    
  /////////////////////////////////////////////////////////////////////
  // Component Manipulation
  /////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////
    /// @brief Adds a Component to the Entity
    /// @details If the Component is already in the Entity, there will
    ///     be multiple copies of that entity in the array. Undefined
    ///     behavior will ensue.
    ///
    /// @param cmpnt Pointer to the Component you wish to add.
    /// @return The index of the added Component. A return of -1 
    ///     implies the Component was not found.
    ///////////////////////////////////////////////////////////////////
    int addComponent(Component* cmpnt);

    ///////////////////////////////////////////////////////////////////
    /// @brief Removes the Component at the specified address from the
    ///     Entity.
    /// @details If the Component specified is not in the Entity, the
    ///     function does nothing.
    /// @post The Component pointed to by cmpnt will not be part of the
    ///     Entity.
    ///
    /// @param cmpnt A pointer to the Entity
    ///////////////////////////////////////////////////////////////////
    void removeComponent(Component* cmpnt);

    ///////////////////////////////////////////////////////////////////
    /// @brief Removes the Component with the specified index from the
    ///     Entity.
    /// @details If there is no Component at the given index for this
    ///     Entity, nothing happens.
    /// @pre (0 < index < cmpntCount())
    /// @post getComponent(index) = nullptr
    /// 
    /// @param index The index of the desired Component you would like
    ///     to remove.
    ///////////////////////////////////////////////////////////////////
    void removeComponent(size_t index);
    
    
  /////////////////////////////////////////////////////////////////////
  // Message System
  /////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////
    /// @brief Broadcasts a message to each Component in the Entity
    /// @todo Create a union or enum specifically for this messaging
    ///     system.
    ///
    /// @param message Denotes the message to send.
    ///////////////////////////////////////////////////////////////////
    void broadcastMessage(msgType message);


  /////////////////////////////////////////////////////////////////////
  // Static Variables
  /////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////
    /// @brief Holds the max amount of Components per Entity
    ///////////////////////////////////////////////////////////////////
    static const size_t maxComponentCount = 10;

private:
    
    //Stores a collection of pointers to Components
    Component* components_[maxComponentCount];

    //Current Component Count
    size_t componentCount_;


};


};      //End namespace ppc


#endif  //ENTITY_H
