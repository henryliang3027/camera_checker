#include "camera_checker_plugin.h"

// This must be included before many other Windows headers.
#include <windows.h>
#include <mfapi.h>
#include <mfidl.h>
#include <mfobjects.h>
#include <mfreadwrite.h>

// For getPlatformVersion; remove unless needed for your plugin implementation.
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <sstream>

#pragma comment(lib, "mfplat.lib")
#pragma comment(lib, "mf.lib")

namespace camera_checker
{

  // static
  void CameraCheckerPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarWindows *registrar)
  {
    auto channel =
        std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
            registrar->messenger(), "camera_checker",
            &flutter::StandardMethodCodec::GetInstance());

    auto plugin = std::make_unique<CameraCheckerPlugin>();

    channel->SetMethodCallHandler(
        [plugin_pointer = plugin.get()](const auto &call, auto result)
        {
          plugin_pointer->HandleMethodCall(call, std::move(result));
        });

    registrar->AddPlugin(std::move(plugin));
  }

  CameraCheckerPlugin::CameraCheckerPlugin() {}

  CameraCheckerPlugin::~CameraCheckerPlugin() {}

  void CameraCheckerPlugin::HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result)
  {
    if (method_call.method_name().compare("getPlatformVersion") == 0)
    {
      std::ostringstream version_stream;
      version_stream << "Windows ";
      if (IsWindows10OrGreater())
      {
        version_stream << "10+";
      }
      else if (IsWindows8OrGreater())
      {
        version_stream << "8";
      }
      else if (IsWindows7OrGreater())
      {
        version_stream << "7";
      }
      result->Success(flutter::EncodableValue(version_stream.str()));
    }
    else if (method_call.method_name().compare("isCameraAvailable") == 0)
    {
      HRESULT hr = MFStartup(MF_VERSION);
      if (FAILED(hr))
      {
        result->Error("MF_STARTUP_FAILED", "Failed to initialize Media Foundation.");
        return;
      }

      IMFAttributes *pAttributes = NULL;
      hr = MFCreateAttributes(&pAttributes, 1);
      if (SUCCEEDED(hr))
      {
        hr = pAttributes->SetGUID(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE,
                                  MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID);
        if (SUCCEEDED(hr))
        {
          IMFActivate **ppDevices = NULL;
          UINT32 count = 0;
          hr = MFEnumDeviceSources(pAttributes, &ppDevices, &count);
          pAttributes->Release();

          if (SUCCEEDED(hr) && count > 0)
          {
            result->Success(flutter::EncodableValue(true));
            for (UINT32 i = 0; i < count; i++)
            {
              ppDevices[i]->Release();
            }
            CoTaskMemFree(ppDevices);
            MFShutdown();
            return;
          }
        }
        pAttributes->Release();
      }
      MFShutdown();
      result->Success(flutter::EncodableValue(false));
    }
    else
    {
      result->NotImplemented();
    }
  }

} // namespace camera_checker
