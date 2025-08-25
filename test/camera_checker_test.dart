import 'package:flutter_test/flutter_test.dart';
import 'package:camera_checker/camera_checker_platform_interface.dart';
import 'package:camera_checker/camera_checker_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockCameraCheckerPlatform
    with MockPlatformInterfaceMixin
    implements CameraCheckerPlatform {
  @override
  Future<bool> isCameraAvailable() => Future.value(true);
}

void main() {
  final CameraCheckerPlatform initialPlatform = CameraCheckerPlatform.instance;

  test('$MethodChannelCameraChecker is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelCameraChecker>());
  });
}
