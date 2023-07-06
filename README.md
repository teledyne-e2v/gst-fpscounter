# gst-fpscounter

# Version 1.0

# About

A Gstreamer plugin to display the FPS of the pipeline

# Dependencies

The following libraries are required for this plugin:
- v4l-utils
- libv4l-dev
- libgstreamer1.0-dev
- libgstreamer-plugins-base1.0-dev
- gcc
- meson 
- ninja

### Debian based system (Jetson): 

```
sudo apt install v4l-utils libv4l-dev libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev meson 
```

### Yocto based system (IMX): 

Teledyne provide a bbappend file which provides all packages needed :
https://github.com/teledyne-e2v/Yocto-files

##### Note : You can also compile them on your installed distribution but it will take a long time to compile (Do it only if you miss one or two packages)


# Compilation

## Ubuntu (Jetson)
First you must make sure that your device's clock is correctly setup.
Otherwise the compilation will fail.

In the **gst-fpscounter** folder do:

```
meson build
ninja -C build
sudo ninja -C build install
```


## Yocto (IMX)
First you must make sure that your device's clock is correctly setup.
Otherwise the compilation will fail.

In the **gst-fpscounter** folder do:

```
meson build
ninja -C build install
```


# Installation test

To test if the plugin has been correctly install, do:
```
export GST_PLUGIN_PATH=/usr/local/lib/gstreamer-1.0/
gst-inspect-1.0 fpscounter
```

If the plugin failed to install the following message will be displayed: "No such element or plugin 'fpscounter'"

# Uninstall
```
sudo rm /usr/local/lib/gstreamer-1.0/libgstfpscounter.*
```
# Usage

By default the plugin is installed in /usr/local/lib/gstreamer-1.0. 
It is then required to tell gstreamer where to find it with the command:
```
export GST_PLUGIN_PATH=/usr/local/lib/gstreamer-1.0/
```
The plugin can be used in any gstreamer pipeline by adding ```fpscounter```, the name of the plugin.

## Pipeline examples:

### Simple example:
```
gst-launch-1.0 v4l2src ! fpscounter ! 'video/x-raw,width=1920,height=1080,format=GRAY8' ! capssetter join=false caps="video/x-bayer,format=rggb"  ! bayer2rgb ! nvvidconv ! 'video/x-raw(memory:NVMM)' ! nv3dsink sync=0
```


#### Note : You can use the plugin without debayer or with another (only if the debayer is after in the pipeline)

# Plugin parameters

- timestamp           : 
    - Flags: readable, writable
    - Type: Boolean
    - Default: false
    - Description: Measure the time between each frame         
- framerate           : 
    - Flags: readable
    - Type: Integer
    - Range: 0 - 1000 
    - Default: 0 
    - Description: Indicate the framerate

- silent              : 
    - flags: writable
    - Type: Boolean. 
    - Default: false 
    - Description: Control the std output
