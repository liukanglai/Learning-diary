let mapleader=" "
map <LEADER>0  $
map <LEADER>f  <C-f>
map <LEADER>b  <C-b>
map <LEADER>p  <C-p>
map <LEADER>w  <C-w>
syntax on
exec "nohlsearch"
set smartcase
set ci
set sm
let &t_ut=''
let &t_SI = "\<Esc>]50;CursorShape=1\x7"
let &t_SR = "\<Esc>]50;CursorShape=2\x7"
let &t_EI = "\<Esc>]50;CursorShape=0\x7"
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
set whichwrap+=<,>,h,l
"高亮显示匹配的括号([{和}])"
set showmatch
"光标移动到buffer的顶部和底部时保持3行距离"
set scrolloff=5
highlight Search ctermbg=black ctermfg=white guifg=white guibg=black
set hlsearch
set incsearch
set showcmd
"开启新行时使用智能自动缩进"
"set smartindent
"set cin
"set showmatch
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