#include "notifier.h"
#include "libnotify_platform.h"
#include "example_service.h"

/* Displays a notification to the user with the current Platform. */
void Notifier::Notify(std::string title, std::string description, std::string icon) {
  _platform->Notify(title, description, icon);
}

/*
 * Starts up Centro by initializing a Platform and a Service.
 */
int main(int argc, char* argv[]) {
  LibnotifyPlatform * libnotifyPlatform = new LibnotifyPlatform;
  Platform * platform;
  platform = dynamic_cast<Platform*>(libnotifyPlatform);

  Notifier centroNotifier(platform);
  ExampleService service(&centroNotifier);
  service.Start();
}
