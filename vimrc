set nu
set sw=4
set ts=4
set ai
let Tlist_Exit_OnlyWindow=1
let Tlist_Use_Right_Window=1
let Tlist_File_Fold_Auto_Close=1
" F6开启/关闭左侧树形目录
map <silent> <F6> :NERDTreeToggle<cr>
" F7开启/关闭paste模式
map <silent> <F7> :set paste!<cr>
" F8显示/取消行号
nnoremap <silent> <F8> :set nu!<CR>
" F9显示/关闭Tlist
map <silent> <F9> :TlistToggle<cr>
let Tlist_Auto_Open=1
set showmatch
set smartindent
set ignorecase
set hlsearch
set incsearch
set title
" $HOME/.cargo/bin:
" let $PATH='/usr/bin:/usr/local/bin:/bin:/usr/sbin:/sbin'
" set mouse=a

autocmd InsertLeave * se nocul
autocmd InsertEnter * se cul
syntax enable
syntax on

set tags+=/Users/edwardlu/mine/keyou/trunk/tags
set tags+=/Users/edwardlu/Downloads/redis/redis-unstable/src/tags
set tags+=/Users/edwardlu/mine/gitCodes/12306/tags
set tags+=/Users/edwardlu/mine/Codes/unpv13e/tags
set tags+=/Users/edwardlu/mine/gitCodes/Tiny-WebServer/tags
set tags+=/Users/edwardlu/mine/gitCodes/protobuf-master/tags
map <c-]> g<c-]>
set autochdir


""set nocompatible              " 去除VI一致性,必须
""filetype off                  " 必须
""" 设置包括vundle和初始化相关的runtime path
""set rtp+=~/.vim/bundle/Vundle.vim
""call vundle#begin()
""Bundle 'altercation/vim-colors-solarized'
""Plugin 'vim-scripts/OmniCppComplete'
""Plugin 'Valloric/YouCompleteMe'
""call vundle#end()
""
""filetype plugin indent on    " 必须 加载vim自带和插件相应的语法和文件类型相关脚本
""" 忽视插件改变缩进,可以使用以下替代:
"""filetype plugin on
"""
""" 简要帮助文档
""" :PluginList       - 列出所有已配置的插件
""" :PluginInstall    - 安装插件,追加 `!` 用以更新或使用 :PluginUpdate
""" :PluginSearch foo - 搜索 foo ; 追加 `!` 清除本地缓存
""" :PluginClean      - 清除未使用插件,需要确认; 追加 `!` 自动批准移除未使用插件
"""
""" 查阅 :h vundle 获取更多细节和wiki以及FAQ
""" 将你自己对非插件片段放在这行之后
""
""let g:ycm_server_keep_logfiles = 1
""let g:ycm_server_log_level = 'debug'

set nocompatible              " be iMproved, required
 
" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')
 
" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
 
" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
"Plugin 'tpope/vim-fugitive'
" plugin from http://vim-scripts.org/vim/scripts.html
" Plugin 'L9'
" Git plugin not hosted on GitHub
"Plugin 'git://git.wincent.com/command-t.git'
" git repos on your local machine (i.e. when working on your own plugin)
"Plugin 'file:///home/gmarik/path/to/plugin'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
"Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Install L9 and avoid a Naming conflict if you've already installed a
" different version somewhere else.
" Plugin 'ascenator/L9', {'name': 'newL9'}
Bundle 'altercation/vim-colors-solarized'
Bundle 'sickill/vim-monokai' 
Plugin 'vim-scripts/OmniCppComplete'
Plugin 'scrooloose/nerdtree' 
Plugin 'taglist.vim'
Plugin 'Valloric/YouCompleteMe'
 
" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line
 
colorscheme monokai
" start solarized theme config
" colorscheme solarized
let g:solarized_termtrans = 1
let g:solarized_termcolors=256
if has('gui_running')
    set background=light
else
    set background=dark
endif
" end solarized theme config
 
let g:ycm_global_ycm_extra_conf='~/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'

" 1秒后关闭结构体提示预览窗
let g:ycm_autoclose_preview_window_after_insertion = 1
let g:ycm_autoclose_preview_window_after_completion = 1
" 关闭YCM语法检查
let g:ycm_enable_diagnostic_signs = 0
let g:ycm_enable_diagnostic_highlighting = 0
" 自动触发语义补全
let g:ycm_semantic_triggers =  {
  \   'c' : ['->', '.'],
  \   'objc' : ['->', '.', 're!\[[_a-zA-Z]+\w*\s', 're!^\s*[^\W\d]\w*\s',
  \             're!\[.*\]\s'],
  \   'ocaml' : ['.', '#'],
  \   'cpp,objcpp' : ['->', '.', '::'],
  \   'perl' : ['->'],
  \   'php' : ['->', '::'],
  \   'cs,java,javascript,typescript,d,python,perl6,scala,vb,elixir,go' : ['.'],
  \   'ruby' : ['.', '::'],
  \   'lua' : ['.', ':'],
  \   'erlang' : [':'],
  \ }
let g:ycm_semantic_triggers =  {
			\ 'c,cpp,python,java,go,erlang,perl': ['re!\w{2}'],
			\ 'cs,lua,javascript': ['re!\w{2}'],
			\ }
" 关闭函数原形预览
set completeopt=menu,menuone
" set completeopt-=preview
let g:ycm_add_preview_to_completeopt = 0


set backspace=2
" 光标停留上一次打开位置
au BufReadPost * if line("'\"") > 0|if line("'\"") <= line("$")|exe("norm '\"")|else|exe "norm $"|endif|endif

if has("multi_byte")
    set fileencodings=utf-8,ucs-bom,cp936,cp1250,big5,euc-jp,euc-kr,latin1
else
    echoerr "Sorry, this version of (g)vim was not compiled with multi_byte"
endif

 "SET Comment START
 "添加头注释

autocmd BufNewFile *.php,*.js,*.cpp,*.c,*.py,*.java exec ":call SetComment()" |normal 10Go
func SetComment()
if expand("%:e") == 'php'
    call setline(1, "<?php")
elseif expand("%:e") == 'js'
    call setline(1, '//JavaScript file')
elseif expand("%:e") == 'cpp'
    call setline(1, '//C++ file')
elseif expand("%:e") == 'c'
    call setline(1, '//C file')
elseif expand("%:e") == 'java'
    call setline(1, '//java file')
elseif expand("%:e") == 'py'
    call setline(1, '# Python file')
    call setline(2, '#!/usr/local/bin/python3')
    call setline(3, '# -*- coding:utf-8 -*')
endif

if expand("%:e") != 'py'
	call append(1, '/***********************************************')
	call append(2, '#')
	call append(3, '#      Filename: '.expand("%"))
	call append(4, '#')
	call append(5, '#        Author: luhg - luhg@keyou.cn')
	call append(6, '#   Description: ---')
	call append(7, '#        Create: '.strftime("%Y-%m-%d %H:%M:%S"))
	call append(8, '#**********************************************/')
endif

if expand("%:e") == 'cpp'
    call append(9, '#include <iostream>')
    call append(10, 'using namespace std;')
elseif expand("%:e") == 'c'
    call append(9, '#include <stdio.h>')
elseif expand("%:e") == 'java'
	call append(10, '}')
	call append(11, 'public class '.expand("%").expand(" {"))
	call append(12, '}')
" elseif expand("%:e") == 'py'
" 	 call append(2, '#!/usr/local/bin/python3')
" 	 call append(3, '# -*- coding:utf-8 -*')
endif
endfunc
" map <F2> :call SetComment()<CR>:10<CR>o

"SET Comment END

 " 添加函数注释开始
 "autocmd BufNewFile *.php,*.js,*.cpp exec ":call SetComment2()" |normal line('.')Go
 func SetComment2()
 call append(line('.'), '/***********************************************')
 call append(line('.')+1, '#      函数名称:')
 call append(line('.')+2, '#')
 call append(line('.')+3, '#   Description:')
 call append(line('.')+4, '#     parameter:')
 call append(line('.')+5, '#   returnValue:')
 call append(line('.')+6, '#   	 Author: luhg')
 call append(line('.')+7, '#        Create: '.strftime("%Y-%m-%d %H:%M:%S"))
 call append(line('.')+8, '#**********************************************/')
endfunc
map <F1> :call SetComment2()<CR>

" 函数注释END
