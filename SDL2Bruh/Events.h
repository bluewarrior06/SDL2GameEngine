#pragma once

#include <vector>

namespace Events
{
	class Event
	{
	public:
		virtual void Invoke();
		~Event();
	private:
		std::vector<Event*>* root_event;
	};

	class RootEvent
	{
	public:
		friend class Events::Event;

		std::vector<Event*>* events;

		RootEvent();
		~RootEvent();

		void AddEvent(Event* e);
		void Invoke();

	};

}
