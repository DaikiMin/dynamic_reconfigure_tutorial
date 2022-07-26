# Dynamic Reconfigure Tutorial

Dynamic Reconfigureのチュートリアル
rqt_reconfigureパッケージを使うことで、プログラム実行中でも、パラメータ変更することができます。

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
  - [Sample.cfg](cfg/Sample.cfg)

### cfgファイルの書き方
```
 gen.add("name",int_t,0,"An Integer parameter",50,0,100)
```
gen.addでパラメータを追加していきます。パラメータの意味はそれぞれ以下のようになっています。
- パラメータ名(`name`)
- 型(`int_t/double_t/str_t/bool_tの`どれか)
- level(`dynamicRecongigureがコールバック時にこの値を返すらしい？`)
- 説明(`An Integer parameter`)
- 初期値(`50`)
- 最小値(`0`)
- 最大値(`100`)

↓のようにするとプルダウンでの変更もできます
```
 size_enum = gen.enum([ gen.const("Small", int_t, 0, "A small constant"),
                  gen.const("Medium", int_t, 1, "A medium constant"),
                  gen.const("Large", int_t, 2, "A large constant"),
                  gen.const("ExtraLarge", int_t, 3, "An extra large constant") ],
                  "An enum to set size")
 gen.add("size", int_t, 0, "A size parameter which is edited via an enum", 1, 0, 3, edit_method=size_enum)
```

最終行では第2引数はパッケージ名、第3第3引数はこのファイル名から拡張子を除いた物にすること
```
 exit(gen.generate(PACKAGE, "dynamic_reconfigure_tutorial", "Sample"))
```

## 実行フラグの設定
```
 $ roscd dynamic_reconfigure_tutorial/cfg
 $ chmod a+x Sample.cfg
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
  cfg/Sample.cfg
)
```

## How to use
### rosrunで起動する場合
- パラメータを変更される側
```
$ rosrun dynamic_reconfigure_tutorial reconfigure_node
```
- GUIでパラメータを変更
```
$ rosrun rqt_reconfigure rqt_reconfigure
```

### roslaunchで起動する場合
```bash
$ roslaunch dynamic_reconfigure_tutorial reconfigure_node.launch
```
- [reconfigure_node.launch](launch/reconfigure_node.launch)

  #### 初期値をrosparamで変更
  cfgファイルの初期値は、node起動時のrosparamで更新可能です。
  - [sample.yaml](param/sample.yaml)

## reference
「ROS講座28 Dynamic Reconfigureを使う」
> https://qiita.com/srs/items/3adcc5898955a6aa1631
