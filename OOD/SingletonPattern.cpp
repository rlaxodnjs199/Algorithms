#include <iostream>
#include <string>
class ConfigSetting {
  static ConfigSetting* mInstance;
  int mBrightness;
  int mWidth;
  int mHeight;
  ConfigSetting() : mWidth(386), mHeight(486), mBrightness(10) {}
public:
  static ConfigSetting* getInstance() {
    if (mInstance == nullptr) {
      mInstance = new ConfigSetting;
    }
    return mInstance;
  }
  void setWidth(int width) {mWidth = width;}
  int getWidth() {return mWidth;}
};

ConfigSetting* ConfigSetting::mInstance;
int main() {
  ConfigSetting* setting = ConfigSetting::getInstance();
  std::cout << setting->getWidth << std::endl;
}