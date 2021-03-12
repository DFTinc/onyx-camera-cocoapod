#
# Be sure to run `pod lib lint OnyxCamera.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name                    = 'OnyxCamera'
  s.version                 = '7.0.0'
  s.summary                 = 'Onyx SDK CocoaPod for iOS.'
  s.description             = 'Onyx software development kit for iOS distributed via CocoaPods'
  s.homepage                = 'https://github.com/DFTinc/onyx-camera-cocoapod'
  s.license                 = { :type => 'custom', :file => 'LICENSE' }
  s.author                  = { 'mjwheatley' => 'mwheatley@diamondfortress.com', 'Jaroslav84' => 'yzheleznov@diamondfortress.com' }
  s.source                  = { :git => 'https://github.com/DFTinc/onyx-camera-cocoapod.git', :tag => s.version.to_s }
  s.ios.deployment_target   = '9.0'
  s.requires_arc            = true
  s.xcconfig                = { 'FRAMEWORK_SEARCH_PATHS' => '$(inherited)', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.pod_target_xcconfig     = { 'ENABLE_BITCODE' => 'NO', 'OTHER_LDFLAGS' => '-lObjC', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.resource_bundles        = { 'OnyxCamera' => ['OnyxCamera/Assets/*.*'] }
  s.ios.vendored_frameworks = 'OnyxCamera/Frameworks/*.framework'
  s.frameworks              = 'CoreMedia', 'AVFoundation', 'AssetsLibrary'
  s.dependency                'OpenCV', '3.4.5'
  s.dependency                'TensorFlowLiteObjC'
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
end
