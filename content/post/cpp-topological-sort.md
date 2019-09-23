---
title: "C++ トポロジカルソート"
date: 2019-09-23T20:55:44+09:00
lastmod: 2019-09-23T20:55:44+09:00
draft: false
keywords: []
description: ""
tags: ["graph"]
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
トポロジカルソートを求めるのと、ついでに閉路がない (DAG) かの判定をする
<!--more-->

## テンプレート
{{< file "includes/topological-sort.cpp" >}}

## 利用例
![img](/image/cpp-topological-sort-2.png "img")
```sh
% g++ -std=gnu++1y -O2 topological-sort.cpp -o run
% cat 1.in
5 4
0 4
1 4
1 2
4 3
% ./run < 1.in
This graph is DAG
1 2 0 4 3
```

![img](/image/cpp-topological-sort-1.png "img")
```sh
% cat 2.in
4 4
0 1
1 2
2 3
3 1
% ./run < 2.in
This graph is not DAG
0
```

## 参考リンク
- https://ferin-tech.hatenablog.com/entry/2017/01/24/184750
