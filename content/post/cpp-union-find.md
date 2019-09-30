---
title: "C++ UnionFind"
date: 2019-06-25T23:28:14+09:00
lastmod: 2019-06-25T23:28:14+09:00
draft: false
keywords: []
description: ""
tags: ["データ構造"]
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
Union-Findのテンプレート
<!--more-->

## テンプレート
{{< file "includes/union-find.cpp" >}}

## 利用例
```sh
% g++ -std=gnu++1y -O2 union-find.cpp -o run
% ./run
0 -1 1
1 -4 4
2 1 4
3 1 4
4 1 4
2 and 4 is : 1 (1:same, 0:different)
0 and 3 is : 0 (1:same, 0:different)
```

## 参考
- http://www.prefield.com/algorithm/container/union_find.html
