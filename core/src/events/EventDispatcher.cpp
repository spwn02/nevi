#include "EventDispatcher.h"

namespace Core {

  std::unordered_map<EventType, EventDispatcher::Handler, EnumClassHash> EventDispatcher::m_observers{};

}