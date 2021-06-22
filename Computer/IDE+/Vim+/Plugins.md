# self

- mkidr -p ~/.vim/pack/plugins/start 总是需要加载的插件
- mkidr -p ~/.vim/pack/plugins/opt 手动加载的插件（use :packadd ..., to use）
> command ! -nargs=* Ack :packadd ack.vim | Ack <f-args> (:Ack to use)
> autcmd! filetype markdown packadd goyo.vim | Goyo (use in markdown)

- in vimrc: packloadall "加载   silent! helptags ALL “加载帮助文档，silent! 是为隐藏错误
- git clone ... ~/.vim/pack/plugins/start/file

## use git to manage plugins

- cd ~/.vim
- git init
- git submodule add https://github.com/scroooloose/nerdtree.git
pack/plugins/start/nerdtree
- git commit -am "Add NERDTree plugin"

update:
- git submodule update --recursive
- git commit -am "Update plugins"

delete
- git submodule deinit -f --pack/plugins/start/nerdtree
- rm -rf .git/modules/pack/plugins/start/nerdtree
- git rm -f pack/plugins/start/nerdtree

# Pathogen

# vim-plug

- github  vim-plug
- curl

        curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
            https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim 

        	call plug#begin('~/.vim/plugged')
        
        	Plug ' ' (ps: vim-airline/vim-airline(此名从github栏中找)
        
         " 延迟按需加载，使用到命令的时候再加载或者打开对应文件类型才加载
          Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' } " when use :NERDTreeToggle, the plug will start 
          Plug 'tpope/vim-fireplace', { 'for': 'clojure' }
        
          " 确定插件仓库中的分支或者 tag
          Plug 'rdnetto/YCM-Generator', { 'branch': 'stable' }
          Plug 'nsf/gocode', { 'tag': 'v.20150303', 'rtp': 'vim' }
        
        	call plug#end()

- :PlugInstall :PlugUpdate, but to update vim-plug, you need :PlugUpgrade, then reboot vim
- 删除Plug并: PlugClean 
- use Plug 'junegunn/vim-plug' to look up :help vim-plug
- use this: (to install vim-plug auto)

        if empty(glob('~/.vim/autoload/plug.vim'))
          silent ! `curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
            https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim 
          autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
        endif


# Vundle

- be same to vim-plug
- use :PluginSearch ... !!!you can find plugins, then put the cursor on it, push i, will try it, but not installed it, you need use plug '' to install it.

# Plug 

" theme
Plug 'vim-airline/vim-airline'
Plug 'connorholyday/vim-snazzy'

" File navigation
Plug 'scrooloose/nerdtree', { 'on': 'NERDTreeToggle' }
Plug 'Xuyuanp/nerdtree-git-plugin'

" 注释
" in <space>cc to comment a line
Plug 'scrooloose/nerdcommenter' 

" 模糊查找文件
fzf

" 查找包含某特定行或单词的文件
ack

" 键映射
vim-unimpaired

" Taglist
"右显示函数列表
Plug 'majutsushi/tagbar', { 'on': 'TagbarOpenAutoClose' }

vim-gutentags: 
- 工作原理：确定vim当前打开的文件是否需要自动生成tags标签，若需要则通过某种方式确定tag文件的路径，再基于tag标签文件完成函数跳转、结构体定义跳转等功能

        " gutentags搜索工程目录的标志，碰到这些文件/目录名就停止向上一级目录递归 "
        let g:gutentags_project_root = ['.root', '.svn', '.git', '.project']
        
        " 所生成的数据文件的名称 "
        let g:gutentags_ctags_tagfile = '.tags'
        
        " 将自动生成的 tags 文件全部放入 ~/.cache/tags 目录中，避免污染工程目录 "
        let s:vim_tags = expand('~/.cache/tags')
        let g:gutentags_cache_dir = s:vim_tags
        " 检测 ~/.cache/tags 不存在就新建 "
        if !isdirectory(s:vim_tags)
           silent! call mkdir(s:vim_tags, 'p')
        endif
        
        " 配置 ctags 的参数 "
        let g:gutentags_ctags_extra_args = ['--fields=+niazS', '--extra=+q']
        let g:gutentags_ctags_extra_args += ['--c++-kinds=+pxI']
        let g:gutentags_ctags_extra_args += ['--c-kinds=+px']

" Error checking
Plug 'w0rp/ale'

" Auto Complete
Plug 'Valloric/YouCompleteMe'

" Undo Tree
Plug 'mbbill/undotree/'

“缩进指南
Plug 'nathanaelkane/vim-indent-guides'

“相同字符串下划线
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

" 表格
Plug 'dhruvasagar/vim-table-mode', { 'on': 'TableModeToggle' }

" 格式
" for your own format"
Plug 'vimwiki/vimwiki'

" Bookmarks
Plug 'kshenoy/vim-signature'

" Other useful utilities
Plug 'terryma/vim-multiple-cursors'
" distraction free writing mode
Plug 'junegunn/goyo.vim' 

    " type ysks ' to wrap the word with '   ' or type cs'`   to change 'word' to `word`

Plug 'tpope/vim-surround' 

"line up text"
Plug 'godlygeek/tabular' " type ;Tabularize /= to align the =
Plug 'gcmt/wildfire.vim' " in Visual mode, type i' to select all text in '', or type i) i] i} ip


" Dependencies

Plug 'MarcWeber/vim-addon-mw-utils'
Plug 'kana/vim-textobj-user'
Plug 'fadein/vim-FIGlet'

call plug#end()



# YouCompleteMe
  >vim中输入:echo has('python') || has('python3')   - if return 1,show right
  > 
  > Install cmake python clang boost llvm-libs cmake
  >
  >>wget http://releases.llvm.org/3.9.0/clang+llvm-3.9.0-x86_64-linux-gnu-ubuntu-14.04.tar.xz
  >cd .vim/plugged/YouCompleteMe
  > 
  >sudo python3 install.py --clangd-completer (all)

        let g:ycm_min_num_identifier_candidate_chars = 2
        let g:ycm_semantic_triggers =  {
			                          \ 'c,cpp,python,java,go,erlang,perl': ['re!\w{2}'],
			                          \ 'cs,lua,javascript': ['re!\w{2}'],
			                          \ }
- 如果你和我一样想把它改成上面比较素雅的灰色的话，可以自己定义 highlight：https://jonasjacek.github.io/colors/(auto)

        highlight PMenu ctermfg=0 ctermbg=242 guifg=black guibg=darkgrey
        highlight PMenuSel ctermfg=242 ctermbg=8 guifg=darkgrey guibg=black

- 我不喜欢 YCM 自动弹出函数原型预览窗口，它搞乱我的布局，我有其他方法查看函数的原型，如果你和我一样想关闭该功能的话，增加两行配置：

        set completeopt=menu,menuone
        let g:ycm_add_preview_to_completeopt = 0

- YCM默认会显示诊断信息，语言标注出来你代码问题, 屏蔽: 这样你可以用其他插件来完成自动/非自动代码静态检查

        let g:ycm_show_diagnostics_ui = 0
- 最后建议设置一下：g:ycm_filetype_whitelist 这个白名单，避免编辑白名单外的文件类型时 YCM也在那分析半天，比如你打开个 1MB 的 TXT 文件，YCM还要再那里空跑半天就傻了：

        let g:ycm_filetype_whitelist = { 
        			\ "c":1,
        			\ "cpp":1, 
        			\ "objc":1,
        			\ "sh":1,
        			\ "zsh":1,
        			\ "zimbu":1,
        			\ }

# termdebug

默认情况下需手动加载 termdebug 插件：
:packadd termdebug
g++ -g helloworld.cpp -o helloworld
现在，我们在 Vim 中启动 termdebug 来调试这个程序：

:Termdebug helloworld
我们可以通过 <Ctrl-W> 按键切换不同窗口。

调试程序
我们既可以在 GDB 窗口中调试，也可以在源码窗口中调试

在源码窗口中的调试指令：

 :Run [args]        运行程序，可带参数 [args]，或沿用上一次运行的参数
 :Arguments {args}  设置下一次运行所用参数

 :Break     在当前行加断点
 :Clear     删除当前行的一个断点

 :Step      = gdb "step" 
 :Over      = gdb "next"
 :Finish    = gdb "finish"
 :Continue  = gdb "continue"
 :Stop      中断程序
 
 如果觉得手动输入调试指令太麻烦，可以在个人的 .vimrc 文件中自定义 keymap 来执行这些命令，如用 <F9> 来添加断点：

nnoremap <F9> :Break<CR>

- 在 Vim 窗口中输入 :h terminal-debug 阅读详细的帮助文档。

# neocomplete
# deoplete.nvim / youcompleteme???
 pip install -U msgpack-python
You can enable Python3 interface with pip:
pip3 install --user pynvim
- for vim-plug:
if has('nvim')
  Plug 'Shougo/deoplete.nvim', { 'do': ':UpdateRemotePlugins' }
else
  Plug 'Shougo/deoplete.nvim'
  Plug 'roxma/nvim-yarp'
  Plug 'roxma/vim-hug-neovim-rpc'
endif
let g:deoplete#enable_at_startup = 1


# analysis

1. start time
    - vim --startuptime startuptime.log 记录行为到文件中
    - 第三列为启动时间。

2. 特定行为的分析(ps: CtrlP)
    - 从github下载python，vim仓库
    - do :CtrlP
