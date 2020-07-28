
~/.vim/vimrc

# 全局配置


- 关闭vi兼容模式 set nocompatible (nocp)
- 设置历史记录步数: set history=1000

"开启相关插件"

"侦测文件类型"
filetype on
"载入文件类型插件"
filetype plugin on
"为特定文件类型载入相关缩进文件"
filetype indent on

"当文件在外部被修改时，自动更新该文件"
set autoread

"激活鼠标的使用"
set mouse=a
set selection=exclusive
set selectmode=mouse,key

"保存全局变量"
set viminfo+=!

"带有如下符号的单词不要被换行分割"
set iskeyword+=_,$,@,%,#,-

"通过使用: commands命令，告诉我们文件的哪一行被改变过"
set report=0

"被分割的窗口间显示空白，便于阅读"
set fillchars=vert:\ ,stl:\ ,stlnc:\



# 字体和颜色

"自动开启语法高亮"
syntax enable


"设置字体"
"set guifont=dejaVu\ Sans\ MONO\ 10
set guifont=Courier_New:h10:cANSI

"设置颜色"
"colorscheme desert

"高亮显示当前行"
set cursorline
hi cursorline guibg=#00ff00
hi CursorColumn guibg=#00ff00

"高亮显示普通txt文件（需要txt.vim脚本）"
au BufRead,BufNewFile *  setfiletype txt

"""""""""""""""""""""""""""""""
"""=>代码折叠功能<="""
"""""""""""""""""""""""""""""""
"激活折叠功能"
set foldenable
"set nofen（这个是关闭折叠功能）"

"设置按照语法方式折叠（可简写set fdm=XX）"
"有6种折叠方法：
"manual   手工定义折叠"
"indent   更多的缩进表示更高级别的折叠"
"expr     用表达式来定义折叠"
"syntax   用语法高亮来定义折叠"
"diff     对没有更改的文本进行折叠"
"marker   对文中的标志进行折叠"
set foldmethod=manual
"set fdl=0（这个是不选用任何折叠方法）"

"设置折叠区域的宽度"
"如果不为0，则在屏幕左侧显示一个折叠标识列
"分别用“-”和“+”来表示打开和关闭的折叠
set foldcolumn=0

"设置折叠层数为3"
setlocal foldlevel=3

"设置为自动关闭折叠"
set foldclose=all

"用空格键来代替zo和zc快捷键实现开关折叠"
"zo O-pen a fold (打开折叠)
"zc C-lose a fold (关闭折叠)
"zf F-old creation (创建折叠)
"nnoremap <space> @=((foldclosed(line('.')) < 0) ? 'zc' : 'zo')<CR>

"""""""""""""""""""""""""""""""""""
"""=>文字处理<="""
"""""""""""""""""""""""""""""""""""
"使用空格来替换Tab"
set expandtab

"设置所有的Tab和缩进为4个空格"
set tabstop=4

"设定<<和>>命令移动时的宽度为4"
set shiftwidth=4

"使得按退格键时可以一次删除4个空格"
set softtabstop=4
set smarttab

"缩进，自动缩进（继承前一行的缩进）"
"set autoindent 命令打开自动缩进，是下面配置的缩写
"可使用autoindent命令的简写，即“:set ai”和“:set noai”
"还可以使用“:set ai sw=4”在一个命令中打开缩进并设置缩进级别
set ai
set cindent

"智能缩进"
set si

"自动换行”
set wrap

"设置软宽度"
set sw=4

"行内替换"
set gdefault

""""""""""""""""""""""""""""""""""
"""=>Vim 界面<="""
""""""""""""""""""""""""""""""""""
"增强模式中的命令行自动完成操作"
set wildmenu

"显示标尺"
set ruler

"设置命令行的高度"
set cmdheight=1

"显示行数"
set nu

"不要图形按钮"
set go=

"在执行宏命令时，不进行显示重绘；在宏命令执行完成后，一次性重绘，以便提高性能"
set lz

"使回格键（backspace）正常处理indent, eol, start等"
set backspace=eol,start,indent

"允许空格键和光标键跨越行边界"
set whichwrap+=<,>,h,l

"设置魔术"
set magic

"关闭遇到错误时的声音提示"
"关闭错误信息响铃"
set noerrorbells

"关闭使用可视响铃代替呼叫"
set novisualbell

"高亮显示匹配的括号([{和}])"
set showmatch

"匹配括号高亮的时间（单位是十分之一秒）"
set mat=2

"光标移动到buffer的顶部和底部时保持3行距离"
set scrolloff=3

"搜索逐字符高亮"
set hlsearch
set incsearch

"搜索时不区分大小写"
"还可以使用简写（“:set ic”和“:set noic”）"
set ignorecase

"用浅色高亮显示当前行"
autocmd InsertLeave * se nocul
autocmd InsertEnter * se cul

"输入的命令显示出来，看的清楚"
set showcmd

""""""""""""""""""""""""""""""""""""
"""=>编码设置<="""
""""""""""""""""""""""""""""""""""""
"设置编码"
set encoding=utf-8
set fencs=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936

"设置文件编码"
set fileencodings=utf-8

"设置终端编码"
set termencoding=utf-8

"设置语言编码"
set langmenu=zh_CN.UTF-8
set helplang=cn

"""""""""""""""""""""""""""""
"""=>其他设置<="""
"""""""""""""""""""""""""""""
"开启新行时使用智能自动缩进"
set smartindent
set cin
set showmatch

"在处理未保存或只读文件的时候，弹出确认"
set confirm

"隐藏工具栏"
set guioptions-=T

"隐藏菜单栏"
set guioptions-=m

"置空错误铃声的终端代码"
set vb t_vb=

"显示状态栏（默认值为1，表示无法显示状态栏）"
set laststatus=2

"状态行显示的内容"
set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}

"粘贴不换行问题的解决方法"
set pastetoggle=<F9>

"设置背景颜色"
set background=dark

"文件类型自动检测，代码智能补全"
set completeopt=longest,preview,menu

"共享剪切板"
set clipboard+=unnamed

"从不备份"
set nobackup
set noswapfile

"自动保存"
set autowrite

"显示中文帮助"
if version >= 603
        set helplang=cn
            set encoding=utf-8
endif

"设置高亮相关项"
highlight Search ctermbg=black ctermfg=white guifg=white guibg=black

""""""""""""""""""""""""""""""""
"""=>在shell脚本开头自动增加解释器以及作者等版权信息<="""
""""""""""""""""""""""""""""""""
"新建.py,.cc,.sh,.java文件，自动插入文件头"
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




## 插件

- github  vim-plug
- curl

`curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
    https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim 
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
  >vim中输入:echo has('python') || has('python3')   - if return 1,show right
  > 
  >下载clang  cmake:
  >>wget http://releases.llvm.org/3.9.0/clang+llvm-3.9.0-x86_64-linux-gnu-ubuntu-14.04.tar.xz
  >cd .vim/plugged/YouCompleteMe
  > 
  >sudo python3 install.py --clangd-completer




# Mine


let mapleader=" "
map <LEADER>0  $
map <LEADER>f  <C-f>
map <LEADER>b  <C-b>
map <LEADER>p  <C-p>
map <LEADER>w  <C-w>
noremap tn :NERDTree<CR>
noremap tt :Tagbar<CR>
noremap tr :source %<CR>
noremap tm :MarkdownPreview<CR>

set nu
syntax on
exec "nohlsearch"
set nofoldenable
set smartcase
set ci
set sm

"光标不同显示
let &t_ut=''
let &t_SI = "\<Esc>]50;CursorShape=1\x7"
let &t_SR = "\<Esc>]50;CursorShape=2\x7"
let &t_EI = "\<Esc>]50;CursorShape=0\x7"
set expandtab
set tabstop=2
set shiftwidth=4
set softtabstop=2
set laststatus=2
set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}

au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif

set clipboard=unnamed
set si
set ttimeoutlen=100
filetype on
filetype plugin on
filetype indent on
filetype plugin indent on 
set autoread

"通过使用: commands命令，告诉我们文件的哪一行被改变过"
set report=0

"被分割的窗口间显示空白，便于阅读"
set fillchars=vert:\ ,stl:\ ,stlnc:\
set smarttab
set autoindent

"自动换行”
set wrap

"增强模式中的命令行自动完成操作"
set wildmenu

"显示标尺"
set ruler

"使回格键（backspace）正常处理indent, eol, start等"
set backspace=eol,start,indent

"允许空格键和光标键跨越行边界"
"set whichwrap+=<,>,h,l

"高亮显示匹配的括号([{和}])"
set showmatch

"光标移动到buffer的顶部和底部时保持3行距离"
set scrolloff=5
highlight Search ctermbg=black ctermfg=white guifg=white guibg=black
set hlsearch
set incsearch
set ignorecase

"用浅色高亮显示当前行"
"竖
set nocursorcolumn 
"横
set cursorline
autocmd InsertLeave * se cul
autocmd InsertEnter * se nocul

"highlight CursorLine   cterm=NONE ctermbg=black ctermfg=green guibg=NONE guifg=NONE
"highlight CursorColumn cterm=NONE ctermbg=black ctermfg=green guibg=NONE guifg=NONE

"cterm 表示为原生vim设置样式，设置为NONE表示可以自定义设置。
"ctermbg 设置终端vim的背景色
"ctermfg 设置终端vim的前景色
"guibg 和 guifg 分别是设置gvim的背景色和前景色

set showcmd
"开启新行时使用智能自动缩进"
set smartindent
set cin
set showmatch
"文件类型自动检测，代码智能补全"
set completeopt=longest,preview,menu

set encoding=utf-8
set fencs=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936
"设置文件编码"
set fileencodings=utf-8
"设置终端编码"
set termencoding=utf-8
"设置语言编码"
set langmenu=zh_CN.UTF-8
set helplang=cn
"显示中文帮助"
if version >= 603
        set helplang=cn
            set encoding=utf-8
endif




autocmd BufNewFile *.py,*.cc,*.sh,*.java exec ":call SetTitle()"
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



call plug#begin('~/.vim/plugged')

Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'

" ()color
Plug 'luochen1990/rainbow'

" search
Plug 'mileszs/ack.vim'  
Plug 'ctrlpvim/ctrlp.vim'


" File navigation
Plug 'preservim/nerdtree'

" Taglist
Plug 'majutsushi/tagbar', { 'on': 'TagbarOpenAutoClose' }                    


" Error checking
Plug 'w0rp/ale'

" Auto Complete
Plug 'Valloric/YouCompleteMe'                                                 
Plug 'raimondi/delimitmate'

" Undo Tree 修改历史
Plug 'mbbill/undotree/'                                                        

" Other visual enhancement
Plug 'nathanaelkane/vim-indent-guides'
Plug 'itchyny/vim-cursorword'

" Git
Plug 'rhysd/conflict-marker.vim'
Plug 'tpope/vim-fugitive'
Plug 'mhinz/vim-signify'
Plug 'gisphm/vim-gitignore', { 'for': ['gitignore', 'vim-plug'] }


" Markdown
Plug 'iamcco/markdown-preview.nvim', { 'do': { -> mkdp#util#install_sync() }, 'for' :['markdown', 'vim-plug'] }
" 补全
Plug 'dhruvasagar/vim-table-mode', { 'on': 'TableModeToggle' }  
" 格式
Plug 'plasticboy/vim-markdown'

Plug 'vimwiki/vimwiki'


call plug#end()

let g:rainbow_active = 1 "0 if you want to enable it later via :RainbowToggle

let g:rainbow_conf = {
	\	'guifgs': ['royalblue3', 'darkorange3', 'seagreen3', 'firebrick'],
	\	'ctermfgs': ['lightblue', 'lightyellow', 'lightcyan', 'lightmagenta'],
	\	'operators': '_,_',
	\	'parentheses': ['start=/(/ end=/)/ fold', 'start=/\[/ end=/\]/ fold', 'start=/{/ end=/}/ fold'],
	\	'separately': {
	\		'*': {},
	\		'tex': {
	\			'parentheses': ['start=/(/ end=/)/', 'start=/\[/ end=/\]/'],
	\		},
	\		'lisp': {
	\			'guifgs': ['royalblue3', 'darkorange3', 'seagreen3', 'firebrick', 'darkorchid3'],
	\		},
	\		'vim': {
	\			'parentheses': ['start=/(/ end=/)/', 'start=/\[/ end=/\]/', 'start=/{/ end=/}/ fold', 'start=/(/ end=/)/ containedin=vimFuncBody', 'start=/\[/ end=/\]/ containedin=vimFuncBody', 'start=/{/ end=/}/ fold containedin=vimFuncBody'],
	\		},
	\		'html': {
	\			'parentheses': ['start=/\v\<((area|base|br|col|embed|hr|img|input|keygen|link|menuitem|meta|param|source|track|wbr)[ >])@!\z([-_:a-zA-Z0-9]+)(\s+[-_:a-zA-Z0-9]+(\=("[^"]*"|'."'".'[^'."'".']*'."'".'|[^ '."'".'"><=`]*))?)*\>/ end=#</\z1># fold'],
	\		},
	\		'css': 0,
	\	}
	\}

"autocmd vimenter * NERDTree

let g:airline_theme='luna'
if !exists('g:airline_symbols')
  let g:airline_symbols = {}
endif

  " powerline symbols
  let g:airline_left_sep = ''
  let g:airline_left_alt_sep = ''
  let g:airline_right_sep = ''
  let g:airline_right_alt_sep = ''
  let g:airline_symbols.branch = ''
  let g:airline_symbols.readonly = ''
  let g:airline_symbols.linenr = '☰'
  let g:airline_symbols.maxlinenr = ''
  let g:airline_symbols.dirty='⚡'



