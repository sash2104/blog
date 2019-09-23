---
title: "C++ スライド最小値"
date: 2019-09-23T11:53:50+09:00
lastmod: 2019-09-23T11:53:50+09:00
draft: true
keywords: []
description: ""
tags: []
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
スライド最小値

<!--more-->

## 計算量
$\mathcal{O}(N)$

## テンプレート
{{< file "includes/slide-min.cpp" >}}

## 利用例
```sh
% g++ -std=gnu++1y -O2 slide-min.cpp -o slide-min
% ./slide-min
1 3 5 4 2
[0,2] id = 0, value = 1
[1,3] id = 0, value = 1
[2,4] id = 4, value = 2
```

## 参考リンク
- http://statmodeling.hatenablog.com/entry/ant-book-slide-min
- https://tubo28.me/compprog/algorithm/slide-min/
