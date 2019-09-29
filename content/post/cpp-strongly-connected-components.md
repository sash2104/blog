---
title: "C++ 強連結成分分解"
date: 2019-09-29T22:10:14+09:00
lastmod: 2019-09-29T22:10:14+09:00
draft: false
keywords: []
description: ""
tags: ["グラフ"]
categories: ["c++"]
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
mathjax: true
mathjaxEnableSingleDollar: true
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
強連結成分分解。深さ優先探索を二回行う
<!--more-->

## 計算量
$\mathcal{O}(V+E)$

## テンプレート
{{< file "includes/strongly-connected-components.cpp" >}}

## 利用例
![img](/image/cpp-strongly-connected-components.png "img")  
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
```sh
% cat 1.in
5 6
0 1
1 0
1 2
2 4
4 3
3 2
4
0 1
0 3
2 3
3 4
% g++ -std=gnu++1y -O2 strongly-connected-components.cpp -o run
% ./run < 1.in
1
0
1
1
```

## 参考
- https://mathtrain.jp/kyorenketsu
- https://ei1333.github.io/luzhiled/snippets/graph/strongly-connected-components.html
