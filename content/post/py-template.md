---
title: "Python Template"
date: 2019-07-01T22:17:39+09:00
lastmod: 2019-07-01T22:17:39+09:00
draft: false
keywords: []
description: ""
tags: []
categories: ["py"]
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
C++のmacroを使った下記のデバッグ出力のようなことをpythonでもやる
```cpp
#ifdef DEBUG
printf(...)
#endif
```

{{< file "py/debug-template.py" >}}

## 利用例

```py:sample.py
# sample.py
dprint("Hello", "world!", sep=',')
```

```bash
# 何も出力されない
% python3 sample.py

# -Oをつけるとdprintの内容が出力される
% python3 -O sample.py
Hello,world!
```
<!--more-->
