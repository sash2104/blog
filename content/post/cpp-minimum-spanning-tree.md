---
title: "C++ 最小全域木 (クラスカル法)"
date: 2019-09-26T23:16:01+09:00
lastmod: 2019-09-26T23:16:01+09:00
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

クラスカル法による最小全域木
<!--more-->

## テンプレート
{{< file "includes/minimum-spanning-tree.cpp" >}}

## 利用例
```sh
% cat 1.in
6 9
0 1 1
0 2 3
1 2 1
1 3 7
2 4 1
1 4 3
3 4 1
3 5 1
4 5 6
% g++ -std=gnu++1y -O2 minimum-spanning-tree.cpp -o run
% ./run < 1.in
5
```

## 参考リンク
- http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
