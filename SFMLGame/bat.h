#ifndef BAT_H
#define BAT_H

#include <SFML/Graphics/Sprite.hpp>

#include "helios_baseobj.h"

namespace Pong {

class Bat : public Helios::SprObj {
public:
  /////////////////////////////////////////////////////////////////////
  /// Constructors and Destructors:
  /////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////
    /// \breif Default Constructor.
    ///
    ///////////////////////////////////////////////////////////////////
    Bat::Bat();


  /////////////////////////////////////////////////////////////////////
  /// Step and Frame Functions:
  /////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////
    /// \breif Function called by the Room this object is active in to
    /// update this object for the next frame.
    ///
    ///////////////////////////////////////////////////////////////////
    virtual void Update();

private:
  //Private Functions
    
    //Draw
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states);


  //Static Private Members

    //Holds the object Sprite
    static sf::Texture spr_paddle;

  //Private Members

};


}   //namespace Pong


#endif //BAT_H
