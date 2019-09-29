---
title: "C++ ユークリッドの互除法"
date: 2019-09-29T11:43:32+09:00
lastmod: 2019-09-29T11:43:32+09:00
draft: false
keywords: []
description: ""
tags: ["整数"]
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
ユークリッドの互除法を用いた最小公倍数と最大公約数
<!--more-->

## テンプレート
{{< file "includes/euclidean-algorithm.cpp" >}}

## 利用例
```sh
% g++ -std=gnu++1y -O2 euclidian-algorithm.cpp -o run
% ./run
ok
```
