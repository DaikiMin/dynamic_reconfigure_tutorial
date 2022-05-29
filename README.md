# Dynamic Reconfigure Tutorial

動的にパラメータを変更できるrqt_reconfigureのチュートリアル

## rqt_reconfigureとは?
Dynamic Reconfigureパッケージを使うことで、プログラム実行中でも、変更することができます。

## Getting started

rqt_reconfigureが使えるようになっていること

※ROSをdesktopfullで入れた場合はすでにインストールされているはず

心配な方は…
```
$ sudo apt install ros-$ROS_DISTRO-rqt-reconfigure
```

でインストールしてください

## 下準備
1. cfgファイルの制作
1. 実行フラグの設定
1. CmakeFileを設定

## cfgファイルの制作
本パッケージのcfgディレクトリに、`○○○.cfg`として生成してください
## 実行フラグの設定
```
 $ roscd rqt_reconfigure_tutorial/cfg
 $ chmod a+x sample.cfg
```

## Cmakeファイルの設定
```
# パッケージの依存を追加
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  dynamic_reconfigure　#この行を追加
)
```

```
# configファイルを追加
generate_dynamic_reconfigure_options(
  cfg/sample.cfg
)
```

## How to use
### rosrunで起動する場合
- パラメータを変更される側
```
$ rosrun rqt_reconfigure_tutorial reconfigure_node
```
- GUIでパラメータを変更
```
$ rosrun rqt_reconfigure rqt_reconfigure
```

### roslaunchで起動する場合
```bash
$ roslaunch rqt_reconfigure_tutorial reconfigure_node.launch
```
- [reconfigure_node.launch)](launch/reconfigure_node.launch)

  #### 初期値をrosparamで変更
  cfgファイルの初期値は、node起動時のrosparamで更新可能です。
  - [sample.yaml](param/sample.yaml)

## reference
「ROS講座28 Dynamic Reconfigureを使う」
> https://qiita.com/srs/items/3adcc5898955a6aa1631
