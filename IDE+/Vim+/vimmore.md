# buffer

- :ls look files(:buffers, :files)
- :e file
- :bn(next)/bp(previous)/bd(delete)    b 1(or b1)   b name(partly)
-

# split

- :split(sp) file   vsplit(vs)
- ctr+w+hjkl 光标
- >:vertical resize+/-
- 左右分屏如下操作： vim -On file1 file2 ... filen
- 上下分屏如下操作： vim -on file1 file2 ... filen
- Ctrl + w s 上面这个命令将会上下分割当前打开的文件。
- Ctrl +w v 上面的这个命令将会左右分割当前的文件
- Ctrl + w c 关闭当前的分屏
- Ctrl + w q 关闭当前的分屏，如果是最后一个分屏将会退出 VIM
- Ctrl + w o 关闭所有其他
- :wqa(w,q,all)

- 关闭缓冲区，而不关窗口，in vimrc: command! Bd :bp | :sp | :bn | :bd, then use :Bd

# 窗口

- :help window-moving, :help window-resize
- c-w+HJKL: move the current window to ...
- c-w+r,x...
- 编号算了。。。

- c+w+=: all windows high and weigh same
- :resize(res) +-N...   :vertical resize(vert res) +-N...
- 

# Tab

- :tabnew  web 使用 ：tabnew 创建一个名字叫 web 的 tab ,当然名字也可以没有，这样会创建一个没有名字的 tab
- :tabc(close) 关闭当前的 tab
- :tabn 切换到下一个 tab /gt
- :tabp 切换到上一个 tab /gT
- :tabs 查看一共有几个 tab
- gt 这个是一个快捷键在正常模式下按下键盘上的 g 和 t 就会自动切换 tab
- 1gt 这是上一个命令的拓展，按下数字键（1，2，3，4……）和 gt ,将切换到相应顺序的 tab, tab 的序号默认从 1 开始，上面的命令将会切换到第一个 tab 。
- :tabe  >+/-tabnext
- tabmove N


# fold

- set foldmethod=indent(manual, expr（正则）, marker(文中的特殊标记如（{【), syntax, diff)
- zo: open fold
- zc: close
- za: open/close
- zR: open all
- zM: close all
- 

# filetree

1. Netrw: use :Ex
    - enter, -, D, R  :Vex(左右分割打开Netrw），:Sex, :Lex  :Ex(e) sftp://<domain>/<directory>/, :e scp://<domain>/<directory>/<file>
2. set wildmenu(启动增强的tab自动补全)，set wildmode=list:longest,full(允许的最长字符串)
    - :e, then use tab, can open file(shift+tab, turn)
3. NERDTree
    - :NERDTree
    - let NERDTreeShowBookmarks = 1
    - audocmd VimEnter * NERDTree "自动打开
4. Vinegar
    - 按ctr+P会进入文件选择，ctr+j,k上下，esc退出
    - ctr+f，b切换搜索模式，打开搜索模式 :CtrlPBuffer, :CtrlPMRU(最近使用), :CtrlPMixed（同时）
5. CtrP

# Register

- " 访问寄存器
- "ayy 表示的是复制当前行内容到 a 寄存器当中，如需附加，使用A
- “ap 表示的是从 a 寄存器当中取出内容
- :reg 该命令会列出所有的寄存器
- :reg a 会查看 a 寄存器里寄存的内容 (%当前文件名，#上次打开的文件名，.最后插入的文本，:最后的命令)
- “” 两个双引号就是一个无名寄存器，通常我们复制黏贴的时候都会自动启用这个寄存器。
- 0寄存器是最近一次的 （1，2, ...）

- *寄存器（macOS，windows的），+寄存器（linux默认的ctr+c，ctr+v）
- .vimrc: set clipboard=unamed  " 复制到**
- set clipboard=unnamedplus  " 复制到+
- set clipboard=unamed, unnamedplus  " 同时 

