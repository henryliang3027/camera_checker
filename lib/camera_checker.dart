import 'camera_checker_platform_interface.dart';

class CameraChecker {
  Future<bool?> isCameraAvailable() {
    return CameraCheckerPlatform.instance.isCameraAvailable();
  }
}
