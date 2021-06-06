// --- CMAKE generated variables for your plugin

#include "pluginstructures.h"

#ifndef _plugindescription_h
#define _plugindescription_h

#define QUOTE(name) #name
#define STR(macro) QUOTE(macro)
#define AU_COCOA_VIEWFACTORY_STRING STR(AU_COCOA_VIEWFACTORY_NAME)
#define AU_COCOA_VIEW_STRING STR(AU_COCOA_VIEW_NAME)

// --- AU Plugin Cocoa View Names (flat namespace) 
#define AU_COCOA_VIEWFACTORY_NAME AUCocoaViewFactory_173B0A18B32239969104E4AD6E65C748
#define AU_COCOA_VIEW_NAME AUCocoaView_173B0A18B32239969104E4AD6E65C748

// --- BUNDLE IDs (MacOS Only) 
const char* kAAXBundleID = "developer.aax.yagrud.bundleID";
const char* kAUBundleID = "developer.au.yagrud.bundleID";
const char* kVST3BundleID = "developer.vst3.yagrud.bundleID";

// --- Plugin Names 
const char* kPluginName = "yaGRUd";
const char* kShortPluginName = "yaGRUd";
const char* kAUBundleName = "yaGRUd_AU";

// --- Plugin Type 
const pluginType kPluginType = pluginType::kFXPlugin;

// --- VST3 UUID 
const char* kVSTFUID = "{173b0a18-b322-3996-9104-e4ad6e65c748}";

// --- 4-char codes 
const int32_t kFourCharCode = 'yGRU';
const int32_t kAAXProductID = 'yGRU';
const int32_t kManufacturerID = 'ASPK';

// --- Vendor information 
const char* kVendorName = "My Company";
const char* kVendorURL = "www.myplugins.com";
const char* kVendorEmail = "support@myplugins.com";

// --- Plugin Options 
const bool kWantSidechain = false;
const uint32_t kLatencyInSamples = 0;
const double kTailTimeMsec = 0.000000;
const bool kVSTInfiniteTail = false;
const bool kVSTSAA = false;
const uint32_t kVST3SAAGranularity = 1;
const uint32_t kAAXCategory = 0;

#endif
