#pragma once
#include <sstream>
#include "event.h"

namespace cppfx
{

    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float xx, float yy) :
            x(xx), y(yy) {}

        inline float getX() const { return x; }
        inline float getY() const { return y; }

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << x << ", " << y;
            return ss.str();
        } 

        EVENT_CLASS_TYPE(MouseMoved);
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
        
    private:
        float x, y;
    };


    class MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float x, float y) :
            xOffset(x), yOffset(y) {}

        inline float getXOffset() const { return xOffset; }
        inline float getYOffset() const { return yOffset; }

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << getXOffset() << ", " << getYOffset();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled);
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

    private:
        float xOffset, yOffset;
    };

    class MouseButtonEvent : public Event
    {
    public:

        inline int getMouseButton() const { return button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

    protected:
        MouseButtonEvent(int but) :
            button(but) {}
    
        int button;
    };


    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button) :
            MouseButtonEvent(button) {}

        std::string toString() const override 
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << button; 
            return ss.str();
        }
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button) :
            MouseButtonEvent(button) {}

        std::string toString() const override 
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << button; 
            return ss.str();
        }
    };

} // namespace cppfx

