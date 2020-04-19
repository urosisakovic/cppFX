#pragma once
#include "event.h"
#include <functional>

namespace cppfx
{

    class EventDispatcher
    {
        template<typename T>
        using eventFn = std::function<bool(T&)>;
    
    public:
        EventDispatcher(Event& e) :
            event(e) {}

        template<typename T>
        bool dispatch(eventFn<T> func)
        {
            if (event.getEventType() == T::getStaticType())
            {
                event.handled = func(*(T*)&event);
                return true;
            }
            return false;
        }


    private:
        Event& event;
    };

    inline std::ostream& operator<<(std::ostream& out, const Event& event)
	{
		return out << event.toString();
	}

} // namespace cppfx