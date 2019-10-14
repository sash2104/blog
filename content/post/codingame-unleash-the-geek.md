---
title: "Unleash the Geek 参加記"
date: 2019-10-14T17:00:00+09:00
lastmod: 2019-10-14T17:00:00+09:00
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

CodinGameで10/5-14の10日間開催されたコンテスト    
(https://www.codingame.com/contests/unleash-the-geek-amadeus)  
雰囲気はhttps://www.codingame.com/replay/416371651 のような感じ
<!--more-->


## 結果
世界??位/2162人、日本?位/62人、Legendリーグ

## 使う用語 (括弧内が定義もしくは公式の用語)
- 基本用語
  - 地雷 (trap)
  - 鉱石 (ore)
  - 鉱脈 (vine)
  - レーダー (radar)
  - 本部 (headquarter)
  - アイテム (item, 地雷 or レーダー or 鉱石)
  - ロボット (robot)
- 戦略
  - 資源効率型 (鉱石の回収効率を高めて勝つ戦略)
  - 地雷型 (地雷を埋めて、敵が地雷を踏むか複数の敵を巻き込みながら自爆して数の有利を取って勝つ)
  - 複合型 (資源効率型と地雷型の複合)
- その他
  - 自爆 (わざと地雷を踏んで敵を道連れにすること)
  - 相打ち (自爆した際に敵味方の同数のロボットが死ぬこと)
  - 地雷偽装 (x=0でWAITかレーダー取得することで、相手から見ると地雷取得と区別がつかない状態にすること)
  - 食べ残し (地雷偽装したロボットが掘った場所の鉱石回収を後回しにすること)

## 最終的に提出したもの

### アルゴリズム概要
- 戦略は大きく分けて、資源効率型、地雷型、複合型の三つ位？自分はルールベースの資源効率型を採用した
  - レーダーを駆使して回収効率を高める
  - レーダーは見えている鉱石の数が多くなければ取得する
  - A: レーダーを置いた場所のみ食べ残し
  - 自分からは地雷は使わない
  - B: 敵が地雷を埋めた可能性のある場所を覚えておき相打ちか死ぬ敵の数が多くなりうる場合に地雷を踏む
  - C: 本部の近くで自爆を狙ってそうな敵がいる場合避ける

### アルゴリズム詳細
- レーダーを駆使して回収効率を高める
  - 初手は、x=8 (中心) に一番近いロボットがレーダーを取得し、(5, robot.y) にレーダーを置く
  - それ以外は、本部に近くて
- レーダーは見えている鉱石の数が多くなければ取得する
  - レーダー取得分資源回収効率は落ちるが、鉱石回収しながら見えている範囲を増やせるのと地雷偽装の効果があるのの利点が上回りそうだったので採用
- レーダーを置いた場所のみ食べ残し
  - 敵視点では地雷の可能性もあり、回収されないとの仮定から採用。Goldリーグでは役に立ったが、Legendだと地雷型の戦略が少ないこともあり無視してくる敵も多そうだったので有効だったかは微妙
- 自分からは地雷は使わない 
  - 資源効率を重視したかったのと、下手に使うと相手に逆用されてしまいそうだったため
- 敵が地雷を埋めた可能性のある場所を覚えておき相打ちか死ぬ敵の数が多くなりうる場合に地雷を踏む 
  - Gold Bossがやっていたもの。地雷型には資源効率で勝ってるはずなので相打ちでもよい、踏んだ場所に埋まっていたのがレーダーでも敵のレーダーを壊せるのでよい、食べ残し戦略に対するカウンターにもなる、ので損がなかった印象
- 本部の近くで自爆を狙ってそうな敵がいる場合避ける
  - Goldで、x=1に地雷を並べて自爆、をやる敵が多かったため
  - 下記の条件を満たした場合、自分の二体目以降のロボットは地雷を避ける
    - x = 1に隣接した場所でWAITしている敵がいる or x = 1で地雷が埋まってそうな場所に1ターンで到達できる敵がいる
    - 1ターン後に、x=1の地雷に対する自爆で味方のロボット複数体が死ぬ可能性がある
  - 地雷を避ける処理は、x <= 3までで地雷が埋まっている可能性のある場所は連鎖するものとして地雷で死にうる範囲を計算した
- その他
  - D: 自分のレーダーが破壊された場合にも、過去の情報を使って破壊された範囲を復元する
  - E: 1ターン目はレーダーを取得したロボット以外も全ロボットWAIT。地雷偽装の効果を狙った。上位でやってる人が多かったので真似した
  - x <= 3 で敵が掘った場所には地雷のみが埋まっていると仮定した


## 感想
- 初legend！ずっと目標にしていて初めて達成できたのでとても嬉しい
- ルールベースしか思いつかなかったが、焼きなましとかChokudaiサーチとかも使えるようになりたい

## 補足
### 各リーグ毎にやったこと
- wood -> bronze
  - 各ロボットごとに、「x方向に1マス隣に移動し掘り、鉱石を回収できたら本部に戻る」を繰り返す
- bronze -> silver
  - レーダー使って少し効率よく資源を回収する
- silver -> gold
  - レーダーの配置と資源回収をある程度最適化
- gold -> legend
  - 上記までで、最終日前日時点でgold500位、全体550位くらい
  - レーダーの配置や資源回収効率をさらに高めてgold100位台
  - アルゴリズム概要のA、B、とアルゴリズム詳細->その他->Dをやってgold10位くらい
  - アルゴリズム概要のCをやってgold2位 -> しばらく待ったらlegend
- legend
  - レーダーの配置をより最適化
  - アルゴリズム詳細->その他->E (1ターン目WAIT) を追加
  - 見えている鉱石がなくなったら、近くのまだ掘られていない場所を掘る処理を追加

### 他の人との比較
- 足りてなさそうで影響大きそうなもの
  - 初手数ターンで、相手が固まりそうな場所を狙って動いて自爆
    - legendの上位層がとてもうまくやっていた印象
- 他に足りてなさそうなもの
  - x=1付近以外での自爆回避。資源効率をあまり損なわずにやる良い方法が思いつかず断念


## リンク
### 他の参加者の情報
- https://www.codingame.com/forum/t/unleash-the-geek-feedback-strategies/133878
