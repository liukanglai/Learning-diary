## 普通模式

- h  j  k  l
0 移动到行头
^ 移动到本行的第一个不是 blank 字符
$ 移动到行尾
g_ 移动到本行最后一个不是 blank 字符的位置
w 光标移动到下一个单词的开头
e 光标移动到下一个单词的结尾
fa 移动到本行下一个为 a 的字符处，fb 移动到下一个为 b 的字符处
nfa 移动到本行光标处开始的第 n 个 字符为 a 的地方（n 是 1，2，3，4 ... 数字）
Fa 同 fa 一样，光标移动方向同 fa 相反
nFa 同 nfa 类似，光标移动方向同 nfa相反
ta 移动光标至 a 字符的前一个字符
nta 移动到第二个 a 字符的前一个字符处
Ta 同 ta 移动光标方向相反
nTa 同 nta 移动光标方向相反
; 和, 当使用 f, F, t ,T, 关键字指定字符跳转的时候，使用 ；可以快速跳转到写一个指定的字符，, 是跳到前一个指定的字符
跨行移动光标
nG 光标定位到第 n 行的行首
gg 光标定位到第一行的行首
G 光标定位到最后一行的行首
H 光标定位到当前屏幕的第一行行首
M 光标移动到当前屏幕的中间
L 光标移动到当前屏幕的尾部
zt 把当前行移动到当前屏幕的最上方，也就是第一行
zz 把当前行移动到当前屏幕的中间
zb 把当前行移动到当前屏幕的尾部
% 匹配括号移动，包括 ( , { , [ 需要把光标先移动到括号上
* 和 # 匹配光标当前所在的单词，移动光标到下一个（或者上一个）匹配的单词（ * 是下一个，# 是上一个）

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

打开文件:gf 返回ctr+o
>:ls
>:bn
>
当打开多个文件的时候可以输入 :bn 和 :bp 进行上一个文件或者下一个文件的切换。

<C-w>

- i  a  I  A  s
- r  R  x  c  b/e/w  f/F 
  > cw
  > ciw  ci(  ci" 
  > ci(  ci" 

- G gg  d y p
    >yi"  yi(   d/c... 
    >yf...

- zz
- u  ctr+r

~ 将光标下的字母改变大小写
3~ 将光标位置开始的3个字母改变其大小写
g\~~ 改变当前行字母的大小写
gUU 将当前行的字母改成大写
guu 将当前行的字母全改成小写

3gUU 将从光标开始到下面3行字母改成大写
gUw 将光标下的单词改成大写。
guw 将光标下的单词改成小写

VIM 的重复命令

. 该命令是重复上一个操作的命令
n<command>重复某个命令 n 次

回到上次光标处：ctr+o(ctr+i反)    ‘’
shift+k: can find a function in man
搜索: /





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










## 插入模式

- ctr+p/n:补全





## 命令模式


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



## 配置：

.vim/vimrc


- 全局配置

 >"关闭vi兼容模式" set nocompatible (nocp)
 
 >"设置历史记录步数" set history=1000
 
 >"侦测文件类型" filetype on
 >"载入文件类型插件" filetype plugin on
 >"为特定文件类型载入相关缩进文件" filetype indent on
 >filetype plugin indent on (file style)

 >"当文件在外部被修改时，自动更新该文件"     set autoread

 >"激活鼠标的使用"
 >set mouse=a
 >set selection=exclusive
 >set selectmode=mouse,key

 >"保存全局变量" >set viminfo+=!

 >"带有如下符号的单词不要被换行分割" >set iskeyword+=_,$,@,%,#,-

 >"通过使用: commands命令，告诉我们文件的哪一行被改变过"  set report=0

 >"被分割的窗口间显示空白，便于阅读" >set fillchars=vert:\ ,stl:\ ,stlnc:\

 
- Vim 界面

>"增强模式中的命令行自动完成操作"
>set wildmenu
>
>"显示标尺"
>set ruler
>
>"设置命令行的高度"
>set cmdheight=1
>
>"显示行数"
>set nu
>
>"不要图形按钮"
>set go=
>
>"在执行宏命令时，不进行显示重绘；在宏命令执行完成后，一次性重绘，以便提高性能"
>set lz
>
>"使回格键（backspace）正常处理indent, eol, start等"
>set backspace=eol,start,indent
>
>"允许空格键和光标键跨越行边界"
>set whichwrap+=<,>,h,l
>
>"设置魔术"
>set magic
>
>"关闭遇到错误时的声音提示"
>"关闭错误信息响铃"
>set noerrorbells
>
>"关闭使用可视响铃代替呼叫"
>set novisualbell
>
>"高亮显示匹配的括号([{和}])"
>set showmatch
>
>"匹配括号高亮的时间（单位是十分之一秒）"
>set mat=2
>
>"光标移动到buffer的顶部和底部时保持3行距离"
>set scrolloff=3
>
>"搜索逐字符高亮"
>set hlsearch
>set incsearch
>
>"搜索时不区分大小写"
>"还可以使用简写（“:set ic”和“:set noic”）"
>set ignorecase
>
>"用浅色高亮显示当前行"
>autocmd InsertLeave * se nocul
>autocmd InsertEnter * se cul
>
>"输入的命令显示出来，看的清楚"
>set showcmd
>



- 字体和颜色
 
 >"自动开启语法高亮" syntax on/off
 
 >"设置字体" 
 >"set guifont=dejaVu\ Sans\ MONO\ 10
 >set guifont=Courier_New:h10:cANSI
 
 >"设置颜色" >"colorscheme desert
 
 >"高亮显示当前行"
 >set cursorline
 >hi cursorline guibg=#00ff00
 >hi CursorColumn guibg=#00ff00
 
 >"高亮显示普通txt文件（需要txt.vim脚本）"
 >au BufRead,BufNewFile *  setfiletype txt
 

- 代码折叠功能

>"激活折叠功能"
>set foldenable
>"set nofen（这个是关闭折叠功能）"
>
>"设置按照语法方式折叠（可简写set fdm=XX）"
>"有6种折叠方法：
>"manual   手工定义折叠"
>"indent   更多的缩进表示更高级别的折叠"
>"expr     用表达式来定义折叠"
>"syntax   用语法高亮来定义折叠"
>"diff     对没有更改的文本进行折叠"
>"marker   对文中的标志进行折叠"
>set foldmethod=manual
>"set fdl=0（这个是不选用任何折叠方法）"
>
>"设置折叠区域的宽度"
>"如果不为0，则在屏幕左侧显示一个折叠标识列
>"分别用“-”和“+”来表示打开和关闭的折叠
>set foldcolumn=0
>
>"设置折叠层数为3"
>setlocal foldlevel=3
>
>"设置为自动关闭折叠"
>set foldclose=all
>
>"用空格键来代替zo和zc快捷键实现开关折叠"
>"zo O-pen a fold (打开折叠)
>"zc C-lose a fold (关闭折叠)
>"zf F-old creation (创建折叠)
>"nnoremap <space> @=((foldclosed(line('.')) < 0) ? 'zc' : 'zo')<CR>


- 文字处理

>"使用空格来替换Tab"
>set expandtab

>"设置所有的Tab和缩进为4个空格"
>set tabstop=4

>"设定<<和>>命令移动时的宽度为4"
>set shiftwidth=4

>"使得按退格键时可以一次删除4个空格"
>set softtabstop=4
>set smarttab

>"缩进，自动缩进（继承前一行的缩进）"
>"set autoindent 命令打开自动缩进，是下面配置的缩写
>"可使用autoindent命令的简写，即“:set ai”和“:set noai”
>"还可以使用“:set ai sw=4”在一个命令中打开缩进并设置缩进级别
>set ai
>set cindent
>
>"智能缩进"
>set si
>
>"自动换行”
>set wrap
>
>"设置软宽度"
>set sw=4
>
>"行内替换"
>set gdefault




- 编码设置

>"设置编码"
>set encoding=utf-8
>set fencs=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936
>
>"设置文件编码"
>set fileencodings=utf-8
>
>"设置终端编码"
>set termencoding=utf-8
>
>"设置语言编码"
>set langmenu=zh_CN.UTF-8
>set helplang=cn
>
>"""""""""""""""""""""""""""""
>"""=>其他设置<="""
>"""""""""""""""""""""""""""""
>"开启新行时使用智能自动缩进"
>set smartindent
>set cin
>set showmatch
>
>"在处理未保存或只读文件的时候，弹出确认"
>set confirm
>
>"隐藏工具栏"
>set guioptions-=T
>
>"隐藏菜单栏"
>set guioptions-=m
>
>"置空错误铃声的终端代码"
>set vb t_vb=
>
>"显示状态栏（默认值为1，表示无法显示状态栏）"
>set laststatus=2
>
>"状态行显示的内容"
>set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}
>
>"粘贴不换行问题的解决方法"
>set pastetoggle=<F9>
>
>"设置背景颜色"
>set background=dark
>
>"文件类型自动检测，代码智能补全"
>set completeopt=longest,preview,menu
>
>"共享剪切板"
>set clipboard+=unnamed
>
>"从不备份"
>set nobackup
>set noswapfile
>
>"自动保存"
>set autowrite
>
>"显示中文帮助"
>if version >= 603
>        set helplang=cn
>            set encoding=utf-8
>endif
>
>"设置高亮相关项"
>highlight Search ctermbg=black ctermfg=white guifg=white guibg=black
>
>""""""""""""""""""""""""""""""""
>"""=>在shell脚本开头自动增加解释器以及作者等版权信息<="""
>""""""""""""""""""""""""""""""""
>"新建.py,.cc,.sh,.java文件，自动插入文件头"
autocmd BufNewFile *.py,*.cc,*.sh,*.java exec ":call SetTitle()"
"定义函数SetTitle，自动插入文件头"
func SetTitle()
    if expand ("%:e") == 'sh'
        call setline(1, "#!/bin/bash")
        call setline(2, "#Author:bert")
        call setline(3, "#Blog:https://blog.51cto.com/zpf666")
        call setline(4, "#Time:".strftime("%F %T"))
        call setline(5, "#Name:".expand("%"))
        call setline(6, "#Version:V1.0")
        call setline(7, "#Description:This is a production script.")
    endif
endfunc

- syntax on/off: highlight or not
- noremap(map:递归???): define a new command 
    >vsp/sp  leader+n/m
    >ctr+w+.. leader+h/j/k/l
    >&  leader+

- set nu/nonu: show the line number
  set relativenumber

- set cursorline: under line
- set showcmd:   
- set hlsearch: 
- set incsearch: 边输边高亮
- exec "nohlsearch": 打开时执行
- set ignorecase(ic/noic): 大小写
- set smartcase: 智能匹配
- set undofile: u的使用连贯
- set scrolloff=5: 最下行始终有5行
- let mapleader=" "   map <LEADER> $

- set autoindent


- set ci: c language indet 
  >set sw=8: wide

- set ts=8: tab wide
- set sm: () automatic matching
-
- set co

- set mouse=a(鼠标)
- set encoding=utf-8
- let &t_ut=''(配色不同term)

    tab:
- set expandtab 
- set tabstop=2
- set shiftwidth=2
- set softtabstop=2


- set backspace=indent,eol,start(退格键能换行)

    光标不同显示:
- let &t_SI = "\<Esc>]50;CursorShape=1\x7"
- let &t_SR = "\<Esc>]50;CursorShape=2\x7"
- let &t_EI = "\<Esc>]50;CursorShape=0\x7"

- set laststatus=2(底层状态栏=2)
- `au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif(光标文件打开时返回)`
- set undofile


let mapleader=" "
map <LEADER>0  $
map <LEADER>n  <C-f>
map <LEADER>m  <C-b>

set autoread
set clipboard=unnamed
set ruler
set smartindent
set si
set showcmd
set cin 
set showmatch
set ttimeoutlen=100

## 插件

- github  vim-plug
- curl

	call plug#begin('~/.vim/plugged')

	Plug ' ' (ps: vim-airline/vim-airline(此名从github栏中找)

	call plug#end()
- :PlugInstall 
- 删除Plug并: PlugClean 



```
Plug 'vim-airline/vim-airline'                                                   //        
Plug 'connorholyday/vim-snazzy'                                                //主题 

" File navigation
Plug 'scrooloose/nerdtree', { 'on': 'NERDTreeToggle' }   
Plug 'Xuyuanp/nerdtree-git-plugin'

"注释
NERD Commenter

"模糊查找文件
fzf
"查找包含某特定行或单词的文件
ack/ag


" Taglist
tagliat 
Plug 'majutsushi/tagbar', { 'on': 'TagbarOpenAutoClose' }                        //右显示函数列表

" Error checking
Plug 'w0rp/ale'

" Auto Complete
Plug 'Valloric/YouCompleteMe'                                                  //language

" Undo Tree
Plug 'mbbill/undotree/'                                                        //浏览文件修改历史 

" Other visual enhancement
Plug 'nathanaelkane/vim-indent-guides'
Plug 'itchyny/vim-cursorword'

" Git
Plug 'rhysd/conflict-marker.vim'
Plug 'tpope/vim-fugitive'
Plug 'mhinz/vim-signify'
Plug 'gisphm/vim-gitignore', { 'for': ['gitignore', 'vim-plug'] }

" git (右行显示; ~已更改  +已添加  -已删除
gitgutter


" HTML, CSS, JavaScript, PHP, JSON, etc.
Plug 'elzr/vim-json'
Plug 'hail2u/vim-css3-syntax'
Plug 'spf13/PIV', { 'for' :['php', 'vim-plug'] }
Plug 'gko/vim-coloresque', { 'for': ['vim-plug', 'php', 'html', 'javascript', 'css', 'less'] }
Plug 'pangloss/vim-javascript', { 'for' :['javascript', 'vim-plug'] }
Plug 'mattn/emmet-vim'

" Python
Plug 'vim-scripts/indentpython.vim'

" Markdown
Plug 'iamcco/markdown-preview.nvim', { 'do': { -> mkdp#util#install_sync() }, 'for' :['markdown', 'vim-plug'] }
vim-markdown
Plug 'dhruvasagar/vim-table-mode', { 'on': 'TableModeToggle' }
Plug 'vimwiki/vimwiki'

" Bookmarks
Plug 'kshenoy/vim-signature'

" Other useful utilities
Plug 'terryma/vim-multiple-cursors'
Plug 'junegunn/goyo.vim' " distraction free writing mode
Plug 'tpope/vim-surround' " type ysks' to wrap the word with '' or type cs'` to change 'word' to `word`
Plug 'godlygeek/tabular' " type ;Tabularize /= to align the =
Plug 'gcmt/wildfire.vim' " in Visual mode, type i' to select all text in '', or type i) i] i} ip
Plug 'scrooloose/nerdcommenter' " in <space>cc to comment a line

" Dependencies
Plug 'MarcWeber/vim-addon-mw-utils'
Plug 'kana/vim-textobj-user'
Plug 'fadein/vim-FIGlet'


call plug#end()

```

- YouCompleteMe
  >:echo has('python') || has('python3') if return 1,show right
  >下载clang:
  >>wget http://releases.llvm.org/3.9.0/clang+llvm-3.9.0-x86_64-linux-gnu-ubuntu-14.04.tar.xz
  >cd .vim/plugged/YouCompleteMe
  >sudo python3 install.py --clangd-completer



## 拼写



## 注释


## 宏录制

先将光标移动到第一行，在普通模式下按下 q 键（宏录制是 q 键启动的),在按一个 a （字母随意）,表示该宏注册为 a ，按下 I 在行首插入一个 tab 键，按下jj或者 <ESC>退出编辑模式,按下 j 将光标移动到下一行行首，最后按下 q 键完成录制操作（宏录制是 q 键结束的）。
上述的例子，在正常模式下，按 @a执行宏录制的一系列动作，将会在第二行执行插入 tab 。
@a是对上一次宏使用的重复操作。n@aa就会执行 n 次一系列的动作。使用宏录制可以一次执行一系列的操作，可以针对一些重复度较高的操作进行宏录制。





## 引用

- :!
: 后面紧跟着 ! ，! 后面紧跟着 linux 命令（ command 指操作 Linux 系统的一系列命令，如创建文件，新建文件夹，查询文件的属性的等
保存: `:w !sudo tee % ` 
:{作用范围}s/{目标}/{替换}/{替换的标志}

## 返回回撤

## buffer



## register



## 

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


## Register

ayy 表示的是复制当前行内容到 a 寄存器当中
“ap 表示的是从 a 寄存器当中取出内容
:reg
该命令会列出所有的寄存器

:reg a
会查看 a 寄存器里寄存的内容
“” 两个双引号就是一个无名寄存器，通常我们复制黏贴的时候都会自动启用这个寄存器。



## 替换


:s/zempty/handsome/g

将会把当前光标所在行的 zempty 替换成 handsome
:%s/zempty/handsome/g
将会把全文中的 zempty 替换成 handsome
:n1,n2s/zempty/handsome/g
这里的 n1 和 n2 值得是行号，将会替换掉 n1 到 n2 的所有 zempty 为 handsom
:s/zempty/handsome
作用于当前行，从光标处开始查找替换，仅仅替换第一次匹配 zempty 的地方为handsome 。
:%s/zempty/handsome
替换掉文件中所有行第一次出现 zempty 的地方为 handsome 。
i 表示大小写不敏感查找，I 表示大小写敏感：
:%s/zempty/handsome/i
替换掉所有行第一个出现 zempty (不区分大小写) 为 handsome 。
:%s/zempty/handsome/gi
替换掉所有行出现 zempty (不区分大小写) 为 handsome 

c 表示需要确认，例如全局查找"zempty"替换为"handsome"并且需要确认：
:%s/zempty/handsome/gc



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

