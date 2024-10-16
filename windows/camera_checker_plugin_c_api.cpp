#include "include/camera_checker/camera_checker_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "camera_checker_plugin.h"

void CameraCheckerPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  camera_checker::CameraCheckerPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
