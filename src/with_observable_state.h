#ifndef WITH_OBSERVABLE_STATE_H
#define WITH_OBSERVABLE_STATE_H

#include <boost/signals2.hpp>

namespace hangman {

class with_observable_state {
 public:
  boost::signals2::signal<void()> state_changed;
  virtual void notify_state_changed() { state_changed(); }
  virtual ~with_observable_state() {}
};
}

#endif  // WITH_OBSERVABLE_STATE_H
