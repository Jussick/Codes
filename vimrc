set nu
set relativenumber
set sw=4
set ts=4  " 设置Tab为4个空格
set ai
" F5开启/关闭相对行号
map <silent> <F5> :set relativenumber!<cr>
" F6开启/关闭左侧树形目录
map <silent> <F6> :NERDTreeToggle<cr>
" F7开启/关闭paste模式
map <silent> <F7> :set paste!<cr>
" F8显示/取消行号
nnoremap <silent> <F8> :set nu!<CR>
" F9显示/关闭Tlist
" map <silent> <F9> :TlistToggle<cr>
map <silent> <F9> :TagbarToggle<cr>
" F2开启markdown预览
nmap <silent> <F2> <Plug>MarkdownPreview        
imap <silent> <F2> <Plug>MarkdownPreview        
" F3关闭markdown预览
nmap <silent> <F3> <Plug>StopMarkdownPreview    
imap <silent> <F3> <Plug>StopMarkdownPreview    
" visual模式下ctrl+c复制内容到系统剪切板
vnoremap <c-c> "+y
" normal模式下ctrl+j黏贴内容到vim
nnoremap <c-,> "*p 
" Ctrl+h 进入全剧查找模式
map <c-h> :Ack<space>
set showmatch
set ignorecase
set hlsearch
set incsearch
set title
set laststatus=2
set backspace=2 "使backspace生效
set shortmess=atI " 干掉乌干达儿童
" 解决卡顿
set re=1
set ttyfast
set lazyredraw
" 解决完毕？

" 开始设置大括号自动匹配
set smartindent
set tabstop=4
set shiftwidth=4
set expandtab
"imap { {}<ESC>i<CR><ESC>V<O 
" imap是映射按键，把{映射为{}<ESC>i<CR><ESC>V<O
" 设置完毕

" $HOME/.cargo/bin:
" let $PATH='/usr/bin:/usr/local/bin:/bin:/usr/sbin:/sbin'
" set mouse=a

function! CurDir()
        let curdir = substitute(getcwd(), $HOME, "~", "g")
        return curdir
endfunction
set statusline=[%n]\ %f%m%r%h\ \|\ \ pwd:\ %{CurDir()}\ \ \|%=\|\ %l,%c\ %p%%\ \|\ ascii=%b,hex=%b%{((&fenc==\"\")?\"\":\"\ \|\ \".&fenc)}\ \|\ %{$USER}\ @\ %{hostname()}\


" set statusline=%F\ [%{&fenc}\ %{&ff}\ L%l/%L\ C%c]\ %=%{strftime('%Y-%m-%d\ %H:%M')}
set ruler


autocmd InsertEnter * se cul    " 自动命令：进入insert模式后执行se cul
autocmd InsertLeave * se nocul
syntax enable
syntax on
syntax sync fromstart
" set redrawtime 10000



if getfsize("vimscript") > 0
    source vimscript
endif
" set tags+=/Users/edwardlu/mine/keyou/trunk/tags
" set tags+=/Users/edwardlu/Downloads/redis/redis-unstable/src/tags
" set tags+=/Users/edwardlu/mine/gitCodes/12306/tags
" set tags+=/Users/edwardlu/mine/Codes/unpv13e/tags
" set tags+=/Users/edwardlu/mine/gitCodes/Tiny-WebServer/tags
" set tags+=/Users/edwardlu/mine/gitCodes/protobuf-master/tags
" set tags+=/Users/edwardlu/mine/gosuncn/phoenix2.0/tags
" set tags+=/Users/edwardlu/mine/gitCodes/FlowChar/src/tags
map <c-]> g<c-]>
set autochdir


""" 简要帮助文档
""" :PluginList       - 列出所有已配置的插件
""" :PluginInstall    - 安装插件,追加 `!` 用以更新或使用 :PluginUpdate
""" :PluginSearch foo - 搜索 foo ; 追加 `!` 清除本地缓存
""" :PluginClean      - 清除未使用插件,需要确认; 追加 `!` 自动批准移除未使用插件

set nocompatible              " be iMproved, required
 
" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')
 
" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
Bundle 'altercation/vim-colors-solarized'
Bundle 'sickill/vim-monokai' 
Plugin 'vim-scripts/OmniCppComplete'
Plugin 'scrooloose/nerdtree' 
Plugin 'taglist.vim'
Plugin 'Valloric/YouCompleteMe'
Plugin 'tpope/vim-sensible'
Plugin 'junegunn/seoul256.vim'
Plugin 'iamcco/mathjax-support-for-mkdp'
Plugin 'iamcco/markdown-preview.vim'
Plugin 'jiangmiao/auto-pairs'
Plugin 'tpope/vim-surround'
Plugin 'scrooloose/nerdcommenter'
Bundle 'majutsushi/tagbar'
" Plugin 'joeytwiddle/sexy_scroller.vim'
Plugin 'junegunn/vim-easy-align'
" Plugin 'itchyny/lightline.vim'
Plugin 'vifm/vifm.vim' 
Plugin 'vimwiki/vimwiki'
Plugin 'ap/vim-css-color'
Plugin 'mileszs/ack.vim'
 
" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required, 忽视插件改变缩进
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

" TListToggle配置
let Tlist_Exit_OnlyWindow = 1  " 如果只有一个buffer，kill窗口也kill掉buffer
let Tlist_Use_Right_Window=1
let Tlist_File_Fold_Auto_Close=1
let Tlist_Auto_Open=0

" tagbar配置
let g:tagbar_ctags_bin='/usr/local/bin/ctags'  " 设置ctags所在路径
let g:tagbar_width=30
let g:tagbar_autoclose = 0
let g:tagbar_sort = 0
let g:tagbar_autoopen = 1
autocmd BufReadPost *.cpp,*.c,*.h,*.hpp,*.cc,*.cxx  call tagbar#autoopen()

" ack配置
let g:ackprg = 'ag --nogroup --nocolor --column'

" nerd Commenter配置
let mapleader=","  "把<leader>的对应按键改为','，默认为\
let g:NERDSpaceDelims = 1

" vim-easy-align配置
" Start interactive EasyAlign in visual mode (e.g. vipga)
xmap ga <Plug>(EasyAlign)
" Start interactive EasyAlign for a motion/text object (e.g. gaip)
nmap ga <Plug>(EasyAlign)
" vim-easy-align配置结束

" vifm配置
map <leader>vv :Vifm<CR>
map <leader>vs :VsplitVifm<CR>
map <leader>sp :SplitVifm<CR>
map <leader>dv :DiffVifm<CR>
map <leader>tv :TabVifm<CR>
let g:vifm_embed_term = 0

" vimwiki配置
let g:vimwiki_list = [{'path': '~/vimwiki/',
                      \ 'syntax': 'markdown', 'ext': '.md'} ]
map <leader>wk :VimwikiIndex<CR>

" Youcompleteme
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
	call append(5, '#        Author: luhg - luhengguang@gosuncn.com')
	call append(6, '#   Description: ---')
	call append(7, '#        Create: '.strftime("%Y-%m-%d %H:%M:%S"))
	call append(8, '#**********************************************/')
endif

if expand("%:e") == 'cpp'
    call append(9, '#include <iostream>')
    " call append(10, 'using namespace std;')
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

