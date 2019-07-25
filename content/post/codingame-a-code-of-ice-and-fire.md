---
title: "A Code of Ice & Fire 参加記"
date: 2019-06-01T13:34:22+09:00
lastmod: 2019-06-02T20:22:39+09:00
draft: false
keywords: []
description: ""
tags: []
categories: ["codingame"]
author: ""

# You can also close(false) or open(true) something for this content.
# P.S. comment can only be closed
comment: false
toc: false
autoCollapseToc: false
postMetaInFooter: false
hiddenFromHomePage: false
# You can also define another contentCopyright. e.g. contentCopyright: "This is another copyright."
contentCopyright: false
reward: false
mathjax: false
mathjaxEnableSingleDollar: false
mathjaxEnableAutoNumber: false

# You unlisted posts you might want not want the header or footer to show
hideHeaderAndFooter: false

# You can enable or disable out-of-date content warning for individual post.
# Comment this out to use the global config.
#enableOutdatedInfoWarning: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

## 概要
CodinGameで5/18-27の10日間開催されたコンテスト  
雰囲気はhttps://www.codingame.com/replay/391527675 のような感じ
<!--more-->


## 結果
世界83位/2160人、日本6位/71人、Goldリーグ


## 最終的に提出したもの

### アルゴリズム概要
- 下記を順に実行
 - unitのmove
 - A: 敵のHQにtrain連続で到達できるならやる
 - B: 敵の陣地をぶった斬れるならやる
 - C: towerの配置
 - D: unitのtrain

### アルゴリズム詳細
- unitのmove
  - unitのidが小さい順にmoveを決定
  - 各unitのmoveは動かない+上下左右4方向に動くの5つのうち評価関数のスコアが最も良いものを選択
  - 評価関数で考慮した要素は下記
      - move先のcellの種類 (敵のcell +10、inactiveな敵のcell +8、neutralなcell +5)
      - move先のunit/buildingの種類 (敵のHQ +∞、敵のtower +35、敵のunit `level*10`、敵のmine +5)
      - move先の位置 (敵のHQに近いほど+、中央に近いほど+)

- A: 敵のHQにtrain連続で到達できるならやる
  - 敵のHQから各cellについて、そのcellから敵のHQにtrain連続で到達するのにかかるコストをdijkstra法で計算
  - ただし、towerの破壊によるコストの変動は考えなかった

- B: 敵の陣地をぶった斬れるならやる
  - Aを実施していない場合のみ考慮する
  - 各行各列について、trainで占領することで敵の陣地をぶった斬れるcellの並び (断絶cell) と占領にかかるコスト (断絶コスト) を計算
  - 断絶cellのどれかに到達するための最小コストを計算 (到達コスト)
  - ぶった切った結果失われる敵の戦力 (`陣地*5+unitとbuildingのcostの和`) を計算
  - 断絶コスト+到達コストが現在のgoldより少ないものがみつかったら、`戦力/(断絶コスト+到達コスト)` が最も高いものを一つ選択

- C: towerの配置
  - A, Bを実施していない場合のみ考慮する
  - tower配置の候補となるcellは下記を全て満たす
      - 周囲8マスのどれかに敵の陣地がある
      - 周囲8マスのどれにも味方のtowerがない
  - 周囲8マスのどれかに敵の陣地があり、自分のtower場所のみをtowerを配置しうる場所とする
  - towerを配置しうる場所が見つかったら、towerの評価関数のスコアが最も良いものを選択
  - 評価関数で考慮した要素は下記
      - 周囲8マスにある味方の陣地の数
      - 周囲8マスにある味方のunit, buildingの数

- D: unitのtrain
  - A, B, Cを実施していない場合のみ考慮する
  - unitのtrainは、最初のターンのみlevel1を二体、それ以外は最大一体
  - unit配置の候補となるcellは敵の陣地かneutralなcellのみ
  - unitのtrainの評価関数のスコアが最も良いものを選択
  - 評価関数で考慮した要素は下記
      - trainするunitのlevel (`level*-100`、levelが低いunitが配置できるならそちらを優先させるため)
      - 敵のunitの上にtrainする場合、敵のunitと自分のHQとの近さ (近い敵ほど早く殺すため)
      - 周囲8マスにある自分の陣地以外のマスの数
      - 残りはunitのmoveの評価関数と同じ

## 感想
- CODE VS 4.0やPlatinum Riftでも思ったが、多数のunitを操作する系のものは何をやればいいのかよくわからない
- goldに余裕を持って到達できたのと、CodinGameのコンテストで初めて100位以内で終われたのは良かった
- 次こそlegendに...

## 補足
### 各リーグ毎にやったこと
- wood3 -> wood2, wood1
  - trainは敵の陣地かneutralなcellではじめに見つかった場所、gold>=20ならlevel1のunitを一体出す
  - moveは、敵の陣地かneutralが周囲にあればそこ、なければランダム
- wood1 -> bronze
  - 下記を追加
      - gold >= 100ならlevel2のunitをtrain
      - moveで、敵の陣地かneutralが周囲になければ敵のHQに近づく
- bronze -> silver, gold
  - trainとmoveの評価関数を用意しスコアが良いものを選択するよう修正
  - 敵のHQにtrain連続で到達できるならやる
- gold
  - 上記までで、最終日開始時点でgold220位、全体260位くらい
  - 敵の陣地をぶった斬れるならやるようにして、gold220 -> 130位くらい
  - towerの配置を行うようにして、gold130 -> 80位くらい
  - trainの評価関数のパラメータを調整して gold80 -> 40位くらい
      - 周囲8マスにある自分の陣地以外のマスを考慮
      - level2,3のunitを極力配置しないように

### 上位陣との比較
- 足りてなさそうで影響大きそうなもの
  - 敵の行動を考慮 (味方のHQにtrain連続で到達されてしまうなら守る)
  - ターンの経過とともにgoldの価値を上昇させる (trainを控えてgoldをためるようになるのでtrain連続の行動を取りやすくなる)
- 他に足りてなさそうなもの
  - unitのmoveを全unitで最適化、複数ターンで最適化 (unit毎に決めても最適に近い動きをするので影響少なめ)
  - 敵の陣地ぶった切りの改善 (上位陣と比べて、ぶった切り候補の列挙が甘い)
  - unitのtrainをターンに一体ではなく複数体行う

## リンク
### 他の参加者の情報
- https://www.codingame.com/forum/t/code-of-ice-fire/105722
- https://valgrowth.hatenablog.com/entry/2019/05/30/214003 (6位)
- https://github.com/morozec/CodeOfIceAndFire (29位)
