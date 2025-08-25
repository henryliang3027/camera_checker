# Camera Checker Flutter Plugin

這個套件專為 Windows 平台而設計，使用 C++ 調用 Windows Media Foundation API 來偵測系統中是否有可用的攝像頭設備。

## 快速開始

### 1. 安裝套件

在您的 Flutter 專案中的 `pubspec.yaml` 檔案中添加：

方法一：使用 Git Repository

```yaml
camera_checker:
  git:
    url: https://github.com/your-repo/camera_checker.git # git repository 路徑
    ref: main
```

方法二：使用本地端路徑

```yaml
camera_checker:
  path: /path/to/camera_checker # 本地端路徑
```

然後執行：

```bash
flutter pub get
```

### 2. 基本使用示例

```dart
import 'package:camera_checker/camera_checker.dart';

// 創建 CameraChecker 實例
final cameraChecker = CameraChecker();

// 檢查攝像頭是否可用
Future<void> checkCamera() async {
  try {
    bool? isAvailable = await cameraChecker.isCameraAvailable();
    if (isAvailable == true) {
      print('攝像頭可用');
      // 執行需要攝像頭的功能
    } else {
      print('攝像頭不可用');
      // 顯示錯誤訊息或禁用攝像頭相關功能
    }
  } catch (e) {
    print('檢查攝像頭狀態時發生錯誤: $e');
  }
}
```

完整使用範例請參考：`example/lib/main.dart`

## API 函數說明

### CameraChecker 類別

#### 實例方法

**`Future<bool?> isCameraAvailable()`**

- **功能**：檢測 Windows 系統中是否有可用的攝像頭設備
- **回傳**：
  - `true` - 系統中有可用的攝像頭設備
  - `false` - 系統中沒有攝像頭設備或設備不可用

## 平台支援

目前僅支援 Windows 平台：

- **Windows 7** 及以上版本，內建 **Windows Media Foundation** 函式庫
