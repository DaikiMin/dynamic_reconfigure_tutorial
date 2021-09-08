## cfgファイルに書くパラメータについて
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
```

```
 gen.add("size", int_t, 0, "A size parameter which is edited via an enum", 1, 0, 3, edit_method=size_enum)
```

最終行では第2引数はパッケージ名、第3第3引数はこのファイル名から拡張子を除いた物にすること
```
 exit(gen.generate(PACKAGE, "rqt_reconfigure_tutorial", "sample"))
```
