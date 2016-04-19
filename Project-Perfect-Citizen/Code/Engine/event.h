#pragma once
//Programmed by Andy
#include <SFML/Graphics.hpp>

namespace ppc {
	//This is the event struct. You can add events here
	//if you need them. Nothing here is final except
	//the template. 

	class Event
	{
	public:
        Event(sf::Event ev);

        operator sf::Event&();


		struct Buttons {
			bool isPushed;
			bool isReleased;
			bool isHovered;
		};

		struct Transformations {
			sf::Vector2f newPos;
		};

		struct Scrollbar {
			float start;
			float end;
		};

		enum EventTypes
		{
			ButtonType,
			TransformationType,
			ScrollbarType,
			sfEventType,
			EmotionType,
			Count
		};

		EventTypes type;

		union {
			Buttons buttons;
			Transformations transformations;
			Scrollbar scrollbar;
            sf::Event sfEvent;
		};
	};
} //end of ppc namespace
