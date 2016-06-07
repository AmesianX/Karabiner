#import "AppDelegate.h"
#import "PreferencesClient.h"
#import "PreferencesWindowController.h"

@interface AppDelegate ()

@property(weak) IBOutlet PreferencesClient* preferencesClient;
@property(weak) IBOutlet PreferencesWindowController* preferencesWindowController;

@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification*)aNotification {
  [[NSApplication sharedApplication] disableRelaunchOnLogin];

  [self.preferencesClient load];

  [self.preferencesWindowController setup];
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)theApplication {
  return YES;
}

- (BOOL)applicationShouldHandleReopen:(NSApplication*)theApplication hasVisibleWindows:(BOOL)flag {
  [self.preferencesWindowController show];
  return YES;
}

@end
