#
# Be sure to run `pod lib lint ESLiveCloud.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ESLiveCloud'
  s.version          = '0.0.1'
  s.summary          = 'ESLiveCloud SDK.'

  s.homepage         = 'https://github.com/zhugexiaobo/ESLiveCloud'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'zhugexiaobo' => 'zhugexiaobo@gmail.com' }
  s.source           = { :git => 'https://github.com/zhugexiaobo/ESLiveCloud.git', :tag => s.version.to_s }
  
  s.ios.deployment_target = '9.0'

  s.vendored_frameworks = 'ESLiveCloud/ESLive-iOS.framework'
  s.resources           = 'ESLiveCloud/ESLive-iOS.bundle'
  s.frameworks          = "VideoToolbox", "AudioToolbox", "AVFoundation", "CoreData", "CoreMedia", "CFNetwork", "WebKit", "SystemConfiguration", "MobileCoreServices", "Foundation", "UIKit"
  s.libraries           = "c++", "z"
  s.static_framework    = true

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
