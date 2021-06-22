# easy operation

> plugs: EasyMotion use 先导键\\

[[	跳转到代码块的开头去(但要求代码块中'{'必须单独占一行)
- gD	跳转到局部变量的定义处

# 移动光标（普通模式下）

    _/$ {/} f+ % zz/zt/zb */#

- h  j  k  l 
- ctr+f(b,d,u) (翻页)
- 行： 0 _ (行首)  ^(移动到本行的第一个不是 blank 字符)   $(行尾)   g_ （移动到本行最后一个不是 blank 字符的位置） 
- ( 上一个句子，  ) 下一个句子
- { 上一段， } 下一段 
- 词： w （下一个单词的开头） e (结尾)  b（上头）/ge W E B(广义单词，空格)
- 行内查找： f  nf（第n个） F（反向查找）nF  t （移动光标至字符的前一个字符）nt /T

  > ; 和, 当使用 f, F, t ,T, 关键字指定字符跳转的时候，使用 ；可以快速跳转到下一个指定的字符，, 是跳到前一个指定的字符

- % 匹配括号移动，包括 ( , { , [ 光标on it.
- 全文: gg G nG （n行的行首）
- 页: H M L zt (把当前行移动到当前屏幕的最上方) zz (中间) zb (尾部???)
- \*（或g*) 和 # 匹配光标当前所在的单词，移动光标到下一个（或者上一个）匹配的单词（ * 是下一个，# 是上一个）
 
# 返回回撤

- 光标返回： ctr+o(ctr+i反)   /‘’

> ^M 是 Ctrl + v + m 打出来的（按下这三个键，VIM 会显示成 ^M ）,^M 代表快捷键是Ctrl + m ,
# 编辑

- 进入插入模式： i  a  I  A  s(删除字符后进入)
- delete: x
- o O(行插入)
- 行合并： J
- r(替换一个)  R(依次替换)  c(删除字符后插入，cc（一行, 会保持前一行的缩进）！！！)  C(到尾) 

  > cw   (use :help text-objects)
  > ciw  ci(  ci" ci(  ci" 
  > caw ...

-  d(dd  ndd d4l db dW) y p/P

    >yi"  yi(   d/c...(也可） （ ‘’内的内容）
    >yf...

- 撤销： u  ctr+r（反撤销）
- ~: 将光标下的字母改变大小写(n~)
- g~\~: 改变当前行字母的大小写
- gUU 将当前行的字母改成大写 gUw(词)  guu 小写 guw

# 插入模式

- ctr+p/n:补全

# 替换

- :s/zempty/handsome/g  (行zempty替换成 handsome) (no g, replace next)
- :%s/zempty/handsome/g  (全文)
- :n1,n2s/zempty/handsome/g   (n1 到 n2行)

- i 表示大小写不敏感查找，I 表示大小写敏感：
- :%s/zempty/handsome/i  替换掉所有行第一个出现 zempty (不区分大小写) 为 handsome 。
- :%s/zempty/handsome/gi  替换掉所有行出现 zempty (不区分大小写) 为 handsome 
- c 表示需要确认，例如全局查找"zempty"替换为"handsome"并且需要确认： - :%s/zempty/handsome/gc

# 搜索: 

- /(front): n(next) N(before)
- ?(back)
- set hlsearch set incsearch(未输入完就跳转)
- :noh (no hlsearch)

1. 跨文件
- :grep
- :vimgrep what *.c then, :cn, :cp, the :copen will open all
2. ack 
- ack.vim
- :ack --file what


# 宏录制

- q键, 按一个a（字母随意）,表示该宏注册为 a, than do operation, 最后按下q键完成
- do again: @a  (n@a)

# Mark

- mx	设置书签,x只能是a-z的26个字母 a-zA-Z 是创建标记的名字，小写字母用来创建单个文件的标记，大些字母用来创建文件之间的标记。
- \`x	跳转到书签处("\`"是1左边的键) \`撇号通常用来定位到之前光标所在的位置 ‘单引号通常用来定位到标记所在的行
- :marks 显示所有的标记
- :delmarks 删除指定的标记
- :delmarks! 删除所有标记（大些字母的标记除外)

# 可视模式

- 当操作的文本光标在 “”，‘’ ，（），{} ，[]（双引号，单引号，小括号，大括号，中括号）,可以通过 va"选中 ”“ 内的所有内容包括双引号 ，vi" 选中 "" 内的所有内容，不包括 "" 
- v/V
- :normal command (ps: isome)
- ctr+v  no need


# 命令模式

- . 该命令是重复上一个操作的命令 (n.)
- shift+k: can find a function in man
- :ab email kickcodeman@gmail.com, ab 是关键字 ,该命令执行后，然后切换到编辑模式下,输入 email 会把输入的 email 自动替换成 kickcodeman@gmail.com。这个命令主要是处理频繁输入同样的长串字符串
- :Set spell (拼写检查)

>ctr+x+s 匹配词
>z= 在词处显示提示词
:
注释:s#^#//#g
删除空行
在命令模式下输入 g/^$/d，前面 g 命令是扩展到全局，中间是匹配空行，后面 d 命令是执行删除动作。用替换也可以实现，键入 %s#^\n##g，意思是把所有以换行开头的行全部替换为空。类似地，如果要把多个空行转换为一个可以输入 g/^\n$/d 或者 %s#^\n$##g
- :color (default)

## 引用
- :!  :后面紧跟着!，!后面紧跟着 linux 命令（command指操作 Linux 系统的一系列命令，如创建文件，新建文件夹，查询文件的属性的等
- 保存: `:w !sudo tee % ` 

# 注释

- "
