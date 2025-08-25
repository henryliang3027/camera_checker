import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'camera_checker_method_channel.dart';

abstract class CameraCheckerPlatform extends PlatformInterface {
  /// Constructs a CameraCheckerPlatform.
  CameraCheckerPlatform() : super(token: _token);

  static final Object _token = Object();

  static CameraCheckerPlatform _instance = MethodChannelCameraChecker();

  /// The default instance of [CameraCheckerPlatform] to use.
  ///
  /// Defaults to [MethodChannelCameraChecker].
  static CameraCheckerPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [CameraCheckerPlatform] when
  /// they register themselves.
  static set instance(CameraCheckerPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<bool> isCameraAvailable() async {
    throw UnimplementedError('isCameraAvailable() has not been implemented.');
  }
}
