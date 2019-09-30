---
title: "C++ 素因数分解"
date: 2019-09-29T12:15:51+09:00
lastmod: 2019-09-29T12:15:51+09:00
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

エラトステネスの篩で素数列挙した後に素因数分解
<!--more-->

## 計算量
$\mathcal{O}(\sqrt{N})$

## テンプレート
{{< file "includes/prime-factorization.cpp" >}}

## 利用例
```sh
% g++ -std=gnu++1y -O2 prime-factorization.cpp -o run
% time ./run
prime factors of 40180 is ...
2 2
5 1
7 2
41 1

prime factors of 999966000289 is ...
999983 2
./run  0.01s user 0.00s system 87% cpu 0.015 total
```
