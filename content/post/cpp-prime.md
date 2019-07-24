---
title: "C++ 素数列挙"
date: 2019-07-24T23:25:17+09:00
lastmod: 2019-07-24T23:25:17+09:00
draft: false
keywords: ["素数"]
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
エラトステネスの篩による素数の列挙

## テンプレート
{{< file "includes/prime.cpp" >}}

## 利用例
```sh
% g++ -std=gnu++1y -O2 prime.cpp -o prime
% ./prime
2
3
5
7
```
<!--more-->
