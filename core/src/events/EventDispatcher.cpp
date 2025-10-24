#include "EventDispatcher.h"

std::unordered_map<EventType, EventDispatcher::Handler, EnumClassHash> EventDispatcher::m_observers{};