# Change this to set a different Project file name
project.name = "AppRTCMobile"

# Replace this with your class prefix for Objective-C files.
project.class_prefix = "ARD"

# By default Xcake defaults to creating the standard Debug and Release
# configurations, uncomment these lines to add your own.
#
#debug_configuration :Staging
#debug_configuration :Debug
#release_configuration :Release

# Change these to the platform you wish to support (ios, osx) and the
# version of that platform (8.0, 9.0, 10.10, 10.11)
#
application_for :ios, 9.0 do |target|

    #Update these with the details of your app
    target.name = "AppRTCMobile"
    target.all_configurations.each { |c| c.product_bundle_identifier = "com.github.piasy.AppRTCMobile" }

    target.all_configurations.each { |c| c.supported_devices = :iphone_only}

    # all files under `AppRTCMobile` are added, do not use `include_files` again,
    # otherwise, it will raise `duplicate symbol` error

    target.exclude_files << "AppRTCMobile/tests/*.*"
    target.exclude_files << "AppRTCMobile/mac/*.*"

    target.include_files << "WebRTC.framework"

    target.all_configurations.each do |c|
      c.settings["INFOPLIST_FILE"] = "AppRTCMobile/ios/Info.plist"
      c.settings["ENABLE_BITCODE"] = "NO"

      c.settings["OTHER_LDFLAGS"] = "$(inherited) -licucore"
    end

    # Uncomment to define your own preprocessor macros
    #
    #target.all_configurations.each { |c| c.preprocessor_definitions["API_ENDPOINT"] = "https://example.org".to_obj_c}

    # Comment to remove Unit Tests for your app
    #

    # Uncomment to create a Watch App for your application.
    #
    #watch_app_for target, 2.0
end
