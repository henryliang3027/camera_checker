#ifndef FLUTTER_PLUGIN_CAMERA_CHECKER_PLUGIN_H_
#define FLUTTER_PLUGIN_CAMERA_CHECKER_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace camera_checker {

class CameraCheckerPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  CameraCheckerPlugin();

  virtual ~CameraCheckerPlugin();

  // Disallow copy and assign.
  CameraCheckerPlugin(const CameraCheckerPlugin&) = delete;
  CameraCheckerPlugin& operator=(const CameraCheckerPlugin&) = delete;

  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace camera_checker

#endif  // FLUTTER_PLUGIN_CAMERA_CHECKER_PLUGIN_H_
