# 移动光标（普通模式下）

    - h  j  k  l 
    - ctr+f(b,d,u) (翻页)
    - 行： 0  ^ (移动到本行的第一个不是 blank 字符)   $    g_ （移动到本行最后一个不是 blank 字符的位置） 
    - ( 上一个句子，  ) 下一个句子
    - { 段首， } 段尾
    - 词： w （下一个单词的开头） e (结尾)  b（上）
    - 行内查找： f  nf（第n个） F（反向查找）nF  t （移动光标至字符的前一个字符）nt /T
    
      > ; 和, 当使用 f, F, t ,T, 关键字指定字符跳转的时候，使用 ；可以快速跳转到下一个指定的字符，, 是跳到前一个指定的字符
    
    - 全文: gg G nG （n行的行首）
    - 页: H M L zt (把当前行移动到当前屏幕的最上方) zz (中间) zb (尾部)
    - % 匹配括号移动，包括 ( , { , [ 需要把光标先移动到括号上
    - *（或g*) 和 # 匹配光标当前所在的单词，移动光标到下一个（或者上一个）匹配的单词（ * 是下一个，# 是上一个）
 
 
## 返回回撤


    - 光标返回： ctr+o(ctr+i反)   /‘’

    
    
# 编辑

    - 进入插入模式： i  a  I  A  s(删除字符后进入)
    - o O(行插入)
    - 行合并： J
    - r(替换一个)  R(依次替换)  x  c(删除字符后插入，cc（一行）)     
    
      > cw
      > ciw  ci(  ci" 
      > ci(  ci" 
    
    -  d(dd  ndd) y p/P
    
        >yi"  yi(   d/c...(也可） （ ‘’内的内容）
        >yf...
    
    - 撤销： u  ctr+r（反撤销）
    - ~ 将光标下的字母改变大小写 n~
    - g~~ 改变当前行字母的大小写
    - gUU 将当前行的字母改成大写 gUw(词)  guu 小写 guw

  
     
## 插入模式
    
    - ctr+p/n:补全
    

 
## 替换


    - :s/zempty/handsome/g  (行zempty替换成 handsome) (no g, replace next)
    - :%s/zempty/handsome/g  (全文)
    - :n1,n2s/zempty/handsome/g   (n1 到 n2行)
    - :s/zempty/handsome  作用于当前行，从光标处开始查找替换，仅仅替换第一次匹配 zempty 的地方为handsome 。
    - :%s/zempty/handsome  替换掉文件中所有行第一次出现 zempty 的地方为 handsome 。
    - i 表示大小写不敏感查找，I 表示大小写敏感：
    - :%s/zempty/handsome/i  替换掉所有行第一个出现 zempty (不区分大小写) 为 handsome 。
    - :%s/zempty/handsome/gi  替换掉所有行出现 zempty (不区分大小写) 为 handsome 
    - c 表示需要确认，例如全局查找"zempty"替换为"handsome"并且需要确认： - :%s/zempty/handsome/gc
     

## 宏录制

    先将光标移动到第一行，在普通模式下按下 q 键（宏录制是 q 键启动的),在按一个 a （字母随意）,表示该宏注册为 a ，按下 I 在行首插入一个 tab 键，按下jj或者 <ESC>退出编辑模式,按下 j 将光标移动到下一行行首，最后按下 q 键完成录制操作（宏录制是 q 键结束的）。
    上述的例子，在正常模式下，按 @a执行宏录制的一系列动作，将会在第二行执行插入 tab 。
    @a是对上一次宏使用的重复操作。n@aa就会执行 n 次一系列的动作。使用宏录制可以一次执行一系列的操作，可以针对一些重复度较高的操作进行宏录制。
    
    
    
## Mark
    
    - mx
    - '/\`x
        m 是创建标记的关键字
    a-zA-Z 是创建标记的名字，小写字母用来创建单个文件的标记，大些字母用来创建文件之间的标记。
    \` 撇号通常用来定位到之前光标所在的位置
    ‘ 单引号通常用来定位到标记所在的行
    :marks 显示所有的标记
    :delmarks 删除指定的标记
    :delmarks! 删除所有标记（大些字母的标记除外
    
    
    

             
   
    
    
## 可视模式
        
    当操作的文本光标在 “”，‘’ ，（），{} ，[（双引号，单引号，小括号，大括号，中括号）
    当中的时候,可以通过 va"选中 ”“ 内的所有内容包括双引号 ，vi" 选中 "" 内的所有内容，不包括 ""。va,vi 会快速选择区域，va 后面会紧跟一个区域结束标志，a 会选中结束符标志，i 就不会。例子如下：
    
    "hello world [VIM is so strong],{we all can master vim skill}"
    
    假设当前光标定位在上面的文本 M 处：
    va] 操作将会选中以下文本（加粗部分）：
    “hello world [VIM is so strong],{we all can master vim skill}“
    vi] 操作将会选中如下的区域，没有包含 []：
    
    - v  V
    - : normal command (ps: isome)
    
    	>ctr+v  no need
        
    打开文件:gf 
    >:ls
    >:bn
    >
    当打开多个文件的时候可以输入 :bn 和 :bp 进行上一个文件或者下一个文件的切换。
    
    
    
    
    
## 命令模式
             
        
    . 该命令是重复上一个操作的命令 (n.)
    
    shift+k: can find a function in man
    
    搜索: / n(next) N(before)
    
    
    
    ^M 是 Ctrl + v + m 打出来的（按下这三个键，VIM 会显示成 ^M ）,^M 代表快捷键是Ctrl + m ,
    
    :ab email kickcodeman@gmail.com
    : 后面的 ab 是关键字 ,该命令执行后，然后切换到编辑模式下,输入 email 会把输入的 email 自动替换成 kickcodeman@gmail.com。
    这个命令主要是处理频繁输入同样的长串字符串
    
    
    :Set spell (拼写检查)
    >ctr+x+s 匹配词
    >z= 在词处显示提示词
    
    :
    注释:s#^#//#g
    删除空行
    
    在命令模式下输入 g/^$/d，前面 g 命令是扩展到全局，中间是匹配空行，后面 d 命令是执行删除动作。用替换也可以实现，键入 %s#^\n##g，意思是把所有以换行开头的行全部替换为空。类似地，如果要把多个空行转换为一个可以输入 g/^\n$/d 或者 %s#^\n$##g
     
    
    
    # 
    
    :color (default)
    
    
    
    
## 引用
    
    - :!
    : 后面紧跟着 ! ，! 后面紧跟着 linux 命令（ command 指操作 Linux 系统的一系列命令，如创建文件，新建文件夹，查询文件的属性的等
    保存: `:w !sudo tee % ` 
    :{作用范围}s/{目标}/{替换}/{替换的标志}
    
    
    
    
## 注释
    
## buffer
    
    
    ## Tab
    :tabnew  web
    使用 ：tabnew 创建一个名字叫 web 的 tab ,当然名字也可以没有，这样会创建一个没有名字的 tab
    :tabc
    关闭当前的 tab
        :tabn
    切换到下一个 tab
    :tabp 
    切换到上一个 tab
    :tabs 
    查看一共有几个 tab
    gt 
    这个是一个快捷键在正常模式下按下键盘上的 g 和 t 就会自动切换 tab
    1gt
    这是上一个命令的拓展，按下数字键（1，2，3，4……）和 gt ,将切换到相应顺序的 tab, tab 的序号默认从 1 开始，上面的命令将会切换到第一个 tab 。
    :tabe
    >+/-tabnext
    
    
##分屏
    
    
    : vsplit/split sp/vsp 
    >ctr+w+l/H 光标
    >:vertical resize+/-
    
    左右分屏如下操作：
    vim -On file1 file2 ... filen
    上下分屏如下操作：
    vim -on file1 file2 ... filen
    
    Ctrl + w s
    上面这个命令将会上下分割当前打开的文件。
    :sp file
    上面的这个命令将会上下分割当前文件和新打开的 file 。
    Ctrl +w v
    上面的这个命令将会左右分割当前的文件
    :vsp file
    上面的这个命令将会左右分割当前打开的文件和新打开的文件 file 。
    Ctrl + w H
    
    将当前的分屏移动到左边
    
    Ctrl + w L
        
    将当前的分屏移动到右边
    Ctrl + w c
    
    上面这个命令是关闭当前的分屏
    
    
    
    Ctrl + w q
    
    上面的这个命令也是关闭当前的分屏，如果是最后一个分屏将会退出 VIM
    
    
    ## 配置：
    
    
    
    ## Register
    
        ayy 表示的是复制当前行内容到 a 寄存器当中
    “ap 表示的是从 a 寄存器当中取出内容
    :reg
    该命令会列出所有的寄存器
    
    :reg a
    会查看 a 寄存器里寄存的内容
    “” 两个双引号就是一个无名寄存器，通常我们复制黏贴的时候都会自动启用这个寄存器。
    
    
    
