#include "CommonData.hpp"
#include "Config.hpp"
#include "IOLogWrapper.hpp"
#include "UserClient_kext.hpp"

namespace org_pqrs_Karabiner {
AbsoluteTime CommonData::current_ts_;
KeyboardType CommonData::current_keyboardType_;
DeviceIdentifier CommonData::current_deviceIdentifier_;
BridgeWorkSpaceData CommonData::current_workspacedata_;
Vector_WorkspaceAppId CommonData::current_workspaceAppIds_;
Vector_WorkspaceInputSourceId CommonData::current_workspaceInputSourceIds_;
Vector_WorkspaceInputSourceDetailId CommonData::current_workspaceInputSourceDetailIds_;
WorkspaceUIElementRoleId CommonData::current_workspaceUIElementRoleId_;
Vector_WorkspaceWindowNameId CommonData::current_workspaceWindowNameIds_;

LastPressedPhysicalKey CommonData::current_lastpressedphysicalkey_;
char CommonData::statusmessage_[BRIDGE_USERCLIENT_STATUS_MESSAGE__END__][BRIDGE_USERCLIENT_STATUS_MESSAGE_MAXLEN];

bool CommonData::initialize(void) {
  for (int i = 0; i < BRIDGE_USERCLIENT_STATUS_MESSAGE__END__; ++i) {
    statusmessage_[i][0] = '\0';
  }

  return true;
}

void CommonData::terminate(void) {}

void CommonData::clear_statusmessage(int index) {
  if (index <= BRIDGE_USERCLIENT_STATUS_MESSAGE_NONE) return;
  if (index >= BRIDGE_USERCLIENT_STATUS_MESSAGE__END__) return;

  statusmessage_[index][0] = '\0';
}

void CommonData::append_statusmessage(int index, const char* message) {
  if (index <= BRIDGE_USERCLIENT_STATUS_MESSAGE_NONE) return;
  if (index >= BRIDGE_USERCLIENT_STATUS_MESSAGE__END__) return;

  strlcat(statusmessage_[index], message, sizeof(statusmessage_[index]));
}

void CommonData::send_notification_statusmessage(int index) {
  if (index <= BRIDGE_USERCLIENT_STATUS_MESSAGE_NONE) return;
  if (index >= BRIDGE_USERCLIENT_STATUS_MESSAGE__END__) return;

  org_pqrs_driver_Karabiner_UserClient_kext::send_notification_to_userspace(BRIDGE_USERCLIENT_NOTIFICATION_TYPE_STATUS_MESSAGE_UPDATED, index);
}

const char* CommonData::get_statusmessage(int index) {
  if (index <= BRIDGE_USERCLIENT_STATUS_MESSAGE_NONE) return nullptr;
  if (index >= BRIDGE_USERCLIENT_STATUS_MESSAGE__END__) return nullptr;

  return statusmessage_[index];
}
}
