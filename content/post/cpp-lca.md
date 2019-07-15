---
title: "C++ LCA (最小共通祖先)"
date: 2019-07-15T17:20:07+09:00
lastmod: 2019-07-15T17:20:07+09:00
draft: false
keywords: ["lca", "最小共通祖先", "doubling"]
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
LCA (最小共通祖先) のdoublingによる実装

## テンプレート
{{< file "includes/lca.cpp" >}}

## 利用例
![img](/image/cpp-lca-graph.png "img")
```sh
% g++ -std=gnu++1y -O2 lca.cpp -o lca
% ./lca
lca of (2, 0) is 0
lca of (2, 3) is 1
lca of (2, 4) is 0
lca of (4, 5) is 4
```

## 参考リンク
- https://tubo28.me/compprog/algorithm/doubling-lca/

<!--more-->
