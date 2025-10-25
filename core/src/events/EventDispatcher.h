#pragma once

#include "Event.h"

#include <functional>
#include <unordered_map>

namespace Core {

  // Hash for enum class (so we can use unordered_map<EventType,...>)
  struct EnumClassHash {
    template <class T>
    std::size_t operator()(T e) const noexcept {
      using U = std::underlying_type_t<T>;
      return std::hash<U>{}(static_cast<U>(e));
    }
  };

  class EventDispatcher
  {
  public:
    using Handler = std::function<void(const Event&)>;

    template<class T, class F>
    void subscribe(F&& func)
    {
      // normalize callable to std::function<void(const T&)>
      std::function<void(const T&)> typed = std::forward<F>(func);

      Handler erased = [f = std::move(typed)](const Event& e) {
        if (const T* p = dynamic_cast<const T*>(&e))
          f(*p);
        };

      const EventType type = T::getStaticType();

      m_observers[type] = std::move(erased);
    }

    static void emit(const Event& e) {
      EventType type = e.getType();
      if (!m_observers.contains(type)) return;
      m_observers.at(type)(e);
    }

    template <class T, class... Args>
    static void makeAndEmit(Args&&... args) {
      T ev(std::forward<Args>(args)...);
      emit(ev);
    }
  private:
    static std::unordered_map<EventType, Handler, EnumClassHash> m_observers;
  };

}