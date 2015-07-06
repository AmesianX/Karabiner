#ifndef VIRTUALKEY_VK_MOUSEKEY_HPP
#define VIRTUALKEY_VK_MOUSEKEY_HPP

namespace org_pqrs_Karabiner {
namespace VirtualKey {
class VK_MOUSEKEY final {
public:
  static void initialize(IOWorkLoop& workloop);
  static void terminate(void);
  static void reset(void);

  static bool handle(const Params_KeyboardEventCallBack& params, AutogenId autogenId, PhysicalEventType physicalEventType);
  static bool isKeyLikeModifier(KeyCode keycode);

private:
  static void fire_timer_callback(OSObject* notuse_owner, IOTimerEventSource* notuse_sender);

  static bool handle_button(const Params_KeyboardEventCallBack& params, AutogenId autogenId, PhysicalEventType physicalEventType);
  static bool handle_move(const Params_KeyboardEventCallBack& params, AutogenId autogenId, PhysicalEventType physicalEventType);
  static bool handle_fixeddistancemove(const Params_KeyboardEventCallBack& params, AutogenId autogenId, PhysicalEventType physicalEventType);
  static bool handle_fixeddistancescroll(const Params_KeyboardEventCallBack& params, AutogenId autogenId, PhysicalEventType physicalEventType);
  static bool handle_lock_button(const Params_KeyboardEventCallBack& params, AutogenId autogenId, PhysicalEventType physicalEventType);
  static PointingButton getPointingButton(KeyCode keycode);
  static PointingButton getPointingButtonFromLockKey(KeyCode keycode);

  static int dx_;
  static int dy_;
  static int scale_;
  static bool highspeed_;
  static bool scrollmode_;
  static AutogenId currentAutogenId_;
  static PhysicalEventType lastPhysicalEventType_;
  static TimerWrapper fire_timer_;
};
}
}

#endif
