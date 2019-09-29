---
title: "C++ 約数列挙"
date: 2019-09-29T15:13:17+09:00
lastmod: 2019-09-29T15:13:17+09:00
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
約数の列挙
<!--more-->

## 計算量
$\mathcal{O}(\sqrt{N})$

## テンプレート
{{< file "includes/divisor.cpp" >}}

## 利用例
```sh
% g++ -std=gnu++1y -O2 divisor.cpp -o run
% time ./run
divisors of 36 is ...
1
2
3
4
6
9
12
18
36
divisors of 999985999949 is ...
1
999983
1000003
999985999949
./run  0.01s user 0.00s system 82% cpu 0.019 total
```
