#include "Events.h"

Events::Event::~Event()
{
	
}

Events::RootEvent::RootEvent() { this->events = new std::vector<Event*>(); }
Events::RootEvent::~RootEvent()
{
	
	this->events->clear();
	delete this->events;
}
void Events::RootEvent::AddEvent(Event* e)
{
	
	this->events->push_back(e);
}

void Events::RootEvent::Invoke()
{
	for (int i = 0; i < this->events->size(); i++)
	{
		if (this->events->at(i) != nullptr)
		{
			this->events->at(i)->Invoke();
		}
	}
}

