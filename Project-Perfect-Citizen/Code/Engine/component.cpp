#include "component.h"
#include "entity.h"

using namespace ppc;

///////////////////////////////////////////////////////////////////////
// AT ALL TIMES A COMPONENT - 
//  - With a non-nullptr value for entity will be in the components 
//      array of the specified entity.
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
// Constructors & Destructor
///////////////////////////////////////////////////////////////////////

Component::Component() {
    entity = nullptr;
}




Component::Component(const Component& other) {
    entity = nullptr;
}




Component::Component(Component&& other) {
    entity = other.entity;
    if (entity != nullptr) {
        entity->removeComponent(&other);
        entity->addComponent(this);
    }
}




Component::~Component() {
    if (entity != nullptr) {
        entity->removeComponent(this);
        entity = nullptr;
    }
}




///////////////////////////////////////////////////////////////////////
// Getters
///////////////////////////////////////////////////////////////////////

Entity* Component::getEntity() {
    return entity;
}


