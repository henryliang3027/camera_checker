import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'camera_checker_platform_interface.dart';

/// An implementation of [CameraCheckerPlatform] that uses method channels.
class MethodChannelCameraChecker extends CameraCheckerPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('camera_checker');

  @override
  Future<bool> isCameraAvailable() async {
    final bool available =
        await methodChannel.invokeMethod<bool>('isCameraAvailable') ?? false;
    return available;
  }
}
