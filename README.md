# rqt_reconfigure_tutorial

動的にパラメータを変更できるrqt_reconfigureのチュートリアル

## Getting started
※カメラキャリブレーションを済ませていること
※AzureKinectに対応しました（2021/08/19）

## Install dependent package
```
$ sudo apt install ros-melodic-visp-auto-tracker

```
## How to use 
- for azure kinect
```
$ roslaunch qr_to_distance azure_kinect.launch
```
- for usb camera
```
$ roslaunch qr_to_distance demo.launch
```

## Integrate with your tools
QRコードからmap基準のTFを送信します。


