#pragma once
#include <sstream>
#include "event.h"


namespace cppfx
{
    
    class KeyEvent : public Event
    {
    public:
        inline int getKeyCode() const 
        {
            return keyCode;
        }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
        KeyEvent(int key) :
            keyCode(key) {}

        int keyCode;
    };


    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keyCode, int repeatCnt) :
            KeyEvent(keyCode), repeatCount(repeatCnt) {}

        inline int getRepeatCount() const { return repeatCount; }

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << keyCode << "( " << repeatCount << "repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)

    private:
        int repeatCount;
    };


    class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int keyCode)
            : KeyEvent(keyCode) {}

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << keyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased);
    };

} // namespace cppfx