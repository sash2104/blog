---
title: "A Code of Ice & Fire 参加記"
date: 2019-06-01T13:34:22+09:00
lastmod: 2019-06-02T20:22:39+09:00
draft: true
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

# 概要
CodinGameで5/18-27の10日間開催されたコンテスト  
雰囲気はhttps://www.codingame.com/replay/391527675 のような感じ


# 結果
世界83位/2160、日本6位/71、Goldリーグ


# 最終的に提出したもの

## アルゴリズム概要
- 下記を順に実行
 - unitのmove
 - 敵のHQにtrain連続で到達できるならやる
 - 敵の陣地をぶった斬れるならやる
 - towerの配置
 - unitのtrain

## アルゴリズム詳細
### unitのmove
- unitのidが小さい順にmoveを決定
- 各unitのmoveは動かない+上下左右4方向に動くの5つのうち評価関数のスコアが最も良いものを選択
- 評価関数で考慮した要素は下記
  - move先のcellの種類 (敵のcell +10、inactiveな敵のcell +8、neutralなcell +5)
  - move先のunit/buildingの種類 (敵のHQ +∞、敵のtower +35、敵のunit `level*10`、敵のmine +5)
  - move先の位置 (敵のHQに近いほど+、中央に近いほど+)

### 敵のHQにtrain連続で到達できるならやる

# 補足
## 各リーグを突破するのにやったこと
## 上位陣との比較

# リンク
## 他の参加者の情報
- https://www.codingame.com/forum/t/code-of-ice-fire/105722
- https://valgrowth.hatenablog.com/entry/2019/05/30/214003 (6位)
- https://github.com/morozec/CodeOfIceAndFire (29位)
