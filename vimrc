set nu
set relativenumber
set sw=4
set ts=4  " 设置Tab为4个空格
set ai
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
set smartindent
set tabstop=4
set shiftwidth=4
set expandtab
set statusline=%F\ [%{&fenc}\ %{&ff}\ L%l/%L\ C%c]\ %=%{strftime('%Y-%m-%d\ %H:%M')}
set statusline+=%{gutentags#statusline()}
set ruler

autocmd InsertEnter * se cul    " 自动命令：进入insert模式后执行se cul
autocmd InsertLeave * se nocul
syntax enable
syntax on
syntax sync fromstart
" set redrawtime 10000
set nocompatible              " be iMproved, required
set autochdir

" 函数名高亮
syn match cFunctions "\<[a-zA-Z_][a-zA-Z_0-9]*\>[^()]*)("me=e-2
syn match cFunctions "\<[a-zA-Z_][a-zA-Z_0-9]*\>\s*("me=e-1
hi cFunctions gui=NONE cterm=bold  ctermfg=blue

"===========================================================
" 快捷键设置
"===========================================================
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
" F3关闭markdown预览
nmap <silent> <F3> <Plug>StopMarkdownPreview    
imap <silent> <F3> <Plug>StopMarkdownPreview    
" visual模式下ctrl+c复制内容到系统剪切板
vnoremap <c-c> "+y
" normal模式下ctrl+j黏贴内容到vim
nnoremap <c-,> "*p 
" Ctrl+h 进入全剧查找模式
map <c-h> :Ack<space>
" c-j自动补全，当补全菜单打开时，ctrl+j,k上下选择
imap <expr> <c-j>      pumvisible()?"\<C-N>":"\<C-X><C-O>"
imap <expr> <c-k>      pumvisible()?"\<C-P>":"\<esc>"
map <c-]> g<c-]>
nmap <silent> <C-l> gt<cr>
nmap <silent> <C-h> gT<cr>


if getfsize("vimscript") > 0
    source vimscript
endif

"===========================================================
" ctags路径设置
"===========================================================
" set tags+=/Users/edwardlu/mine/keyou/trunk/tags
" set tags+=/Users/edwardlu/Downloads/redis/redis-unstable/src/tags
" set tags+=/Users/edwardlu/mine/gitCodes/12306/tags
" set tags+=/Users/edwardlu/mine/Codes/unpv13e/tags
" set tags+=/Users/edwardlu/mine/gitCodes/Tiny-WebServer/tags
" set tags+=/Users/edwardlu/mine/gitCodes/protobuf-master/tags
" set tags+=/Users/edwardlu/mine/gosuncn/phoenix2.0/tags
" set tags+=/Users/edwardlu/mine/gitCodes/FlowChar/src/tags
set tags+=/Users/edwardlu/mine/Codes/LeetCodes/tags
set tags+=/Users/edwardlu/mine/gitCodes/WebRTC_NS/tags
set tags+=/Users/edwardlu/mine/gosuncn/phoenix2.0/Module/platform/tags
set tags+=/Users/edwardlu/mine/joyy/Baichuan_DataUpload/receiver/tags

"===========================================================
" Vundle插件管理
"===========================================================

""" 简要帮助文档
""" :PluginList       - 列出所有已配置的插件
""" :PluginInstall    - 安装插件,追加 `!` 用以更新或使用 :PluginUpdate
""" :PluginSearch foo - 搜索 foo ; 追加 `!` 清除本地缓存
""" :PluginClean      - 清除未使用插件,需要确认; 追加 `!` 自动批准移除未使用插件
 
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
Plugin 'Valloric/YouCompleteMe'
Plugin 'tpope/vim-sensible'
Plugin 'junegunn/seoul256.vim'
Plugin 'iamcco/mathjax-support-for-mkdp'
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
Plugin 'ludovicchabant/vim-gutentags'
Plugin 'Yggdroot/LeaderF', { 'do': ':LeaderfInstallCExtension' }
" Vim状态栏插件，包括显示行号，列号，文件类型，文件名，以及Git状态
Plugin 'vim-airline/vim-airline'
" 配合vim-airline显示git branch用的
Plugin 'tpope/vim-fugitive'
" vim_airline主题
Plugin 'vim-airline/vim-airline-themes'
" 高亮当前单词添加下划线
Plugin 'itchyny/vim-cursorword'
" go相关插件
Plugin 'fatih/vim-go'
Plugin 'jstemmer/gotags'
Plugin 'dgryski/vim-godef'
 
" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required, 忽视插件改变缩进
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line
 
"===========================================================
" 主题设置
"===========================================================
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

"===========================================================
" TListToggle配置
"===========================================================
let Tlist_Exit_OnlyWindow = 1  " 如果只有一个buffer，kill窗口也kill掉buffer
let Tlist_Use_Right_Window=1
let Tlist_File_Fold_Auto_Close=1
let Tlist_Auto_Open=0

"===========================================================
" Tagbar配置
"===========================================================
let g:tagbar_ctags_bin='/usr/local/bin/ctags'  " 设置ctags所在路径
let g:tagbar_width=30
let g:tagbar_autoclose = 0
let g:tagbar_sort = 0
let g:tagbar_autoopen = 1
autocmd BufReadPost *.cpp,*.c,*.h,*.hpp,*.cc,*.cxx,*.go,*.lua  call tagbar#autoopen()

"===========================================================
" ack:配置
"===========================================================
let g:ackprg = 'ag --nogroup --nocolor --column'

"===========================================================
" nerd Commenter配置
"===========================================================
let mapleader=","  "把<leader>的对应按键改为','，默认为\
let g:NERDSpaceDelims = 1

"===========================================================
" vim-easy-align配置
"===========================================================
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

"===========================================================
" vimwiki配置
"===========================================================
let g:vimwiki_list = [{'path': '~/vimwiki/',
                      \ 'syntax': 'markdown', 'ext': '.md'} ]
map <leader>wk :VimwikiIndex<CR>

"===========================================================
" Youcompleteme配置
"===========================================================
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

"===========================================================
" gutentags配置（自动生成tags插件）
"===========================================================
" 开关
let g:gutentags_enabled = 1
" A list of project roots to generally ignore.
let g:gutentags_exclude_project_root = ['.notags']
" gutentags搜索工程目录的标志，碰到这些文件/目录名就停止向上一级目录递归 "
let g:gutentags_project_root = ['.root', '.svn', '.git', '.project']
" 所生成的数据文件的名称 "
let g:gutentags_ctags_tagfile = '.tags'
" 将自动生成的 tags 文件全部放入 ~/.cache/tags 目录中，避免污染工程目录 "
let s:vim_tags = expand('~/.cache/tags')
let g:gutentags_cache_dir = s:vim_tags
" 忽略目录
let g:gutentags_exclude_project_root = ['/home/edwardlu/mine/Codes']
" 检测 ~/.cache/tags 不存在就新建 "
if !isdirectory(s:vim_tags)
   silent! call mkdir(s:vim_tags, 'p')
endif

"===========================================================
" 配置 ctags 的参数
"===========================================================
let g:gutentags_ctags_extra_args = ['--fields=+niazS', '--extra=+q']
let g:gutentags_ctags_extra_args += ['--c++-kinds=+pxI']
let g:gutentags_ctags_extra_args += ['--c-kinds=+px']


"===========================================================
" 光标停留上一次打开位置
"===========================================================
au BufReadPost * if line("'\"") > 0|if line("'\"") <= line("$")|exe("norm '\"")|else|exe "norm $"|endif|endif
if has("multi_byte")
    set fileencodings=utf-8,ucs-bom,cp936,cp1250,big5,euc-jp,euc-kr,latin1
else
    echoerr "Sorry, this version of (g)vim was not compiled with multi_byte"
endif

"===========================================================
" SET Comment START 添加头注释
"===========================================================
autocmd BufNewFile *.php,*.js,*.cpp,*.c,*.py,*.java,*.sh exec ":call SetComment()" |normal 10Go
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
    elseif expand("%:e") == 'sh'
        call setline(1, '#!/bin/bash')
    endif

    if expand("%:e") != 'py' && expand("%:e") != 'sh'
        call append(1, '/***********************************************')
        call append(2, '#')
        call append(3, '#      Filename: '.expand("%"))
        call append(4, '#')
        call append(5, '#        Author: luhg - luhengguang@joyy.com')
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


"===========================================================
" 添加函数注释开始
"===========================================================
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


"===========================================================
" leaderF 配置
"===========================================================
let g:Lf_ShortcutF = '<c-p>'
let g:Lf_WorkingDirectoryMode = 'a'  " 把包含marker的目录当做根目录，就算当前打开的文件目录不是根目录
let g:Lf_RootMarkers = ['.git', '.svn', '.hg', '.project', '.root']  " 自定义根目录的markers
let g:Lf_DefaultExternalTool='rg'
let g:Lf_RecurseSubmodules = 1  " 寻找git子模块的文件
autocmd BufNewFile,BufRead X:/yourdir* let g:Lf_WildIgnore={'file':['*.vcproj', '*.vcxproj', 'tags', '*.java'],'dir':[]}  " 忽略的文件
let g:Lf_PreviewInPopup = 1
let g:Lf_WindowHeight = 0.30
let g:Lf_ShowDevIcons = 0  " 文件类型图标会显示错误，索性关闭
" let g:Lf_CacheDirectory = s:cachedir
let g:Lf_StlColorscheme = 'powerline'
let g:Lf_PreviewResult = {
        \ 'File': 0,
        \ 'Buffer': 0,
        \ 'Mru': 0,
        \ 'Tag': 0,
        \ 'BufTag': 1,
        \ 'Function': 1,
        \ 'Line': 1,
        \ 'Colorscheme': 0,
        \ 'Rg': 0,
        \ 'Gtags': 0
        \}
nmap <unique> <leader>f  <Plug>LeaderfRgPrompt
nmap <unique> <leader>fa <Plug>LeaderfRgCwordLiteralNoBoundary<CR>
nmap <unique> <leader>ff <Plug>LeaderfRgCwordLiteralBoundary<CR>
nmap <unique> <leader>fn <Plug>LeaderfRgCwordRegexNoBoundary<CR>
nmap <unique> <leader>fr <Plug>LeaderfRgCwordRegexBoundary<CR>

" 查找当前文件中的函数
nmap <unique> <leader>tt :LeaderfFunction<CR>
" 查找当前文件中的变量
nmap <unique> <leader>wr :LeaderfLine<CR>
" 查找buffer中的内容
nmap <unique> <leader>bb :LeaderfBuffer<CR>
" 列出最近使用的文件
nmap <unique> <leader>mm :LeaderfMru<CR>
" 快捷键	解释
" <leader>f 	将会在命令行显示 :Leaderf rg -e, 然后等待用户输入想要查询的正则表达式.
" <leader>fa	将会直接查询光标所在的词语或者visual模式下选中的词语, 但是没有边界. 没有边界的意思是说如果你查word, 包含abcwordxyz的行也会被搜到.
" <leader>ff	将会直接查询光标所在的词语,或者visual模式下选中的词语 但是有边界. 有边界的意思是说如果你查word, 包含abcwordxyz 的行不会被搜到, 只有包含类似abc word xyz字段的行才会被搜到.
" <leader>fn	将会直接把光标所在的词语或者visual模式下选中的词语作为正则表达式检索, 但是没有边界.
" <leader>fr	将会直接把光标所在的词语或者visual模式下选中的词语作为正则表达式检索, 但是有边界.

"==============================================================================
" vim-go 插件
"==============================================================================
let g:go_fmt_command = "goimports" " 格式化将默认的 gofmt 替换
let g:go_autodetect_gopath = 1
let g:go_list_type = "quickfix"
let g:go_version_warning = 1
let g:go_highlight_types = 1
let g:go_highlight_fields = 1
let g:go_highlight_functions = 1
let g:go_highlight_function_calls = 1
let g:go_highlight_operators = 1
let g:go_highlight_extra_types = 1
let g:go_highlight_methods = 1
let g:go_highlight_generate_tags = 1
let g:godef_split=2

"==============================================================================
" godef 配置
"==============================================================================
autocmd FileType go nnoremap <buffer> gd :call GodefUnderCursor()<cr>
autocmd FileType go nnoremap <buffer> <C-]> :call GodefUnderCursor()<cr>
let g:godef_same_file_in_same_window=1 """函数在同一个文件中时不需要打开新窗口
let g:godef_split=0 " 在光标下定义出打开新窗口
"==============================================================================
" vim-airline配置
"==============================================================================

let g:airline_theme='dark'
" let g:airline_theme='powerlineish'
" let g:airline_powerlineish_bg='dark'

" 打开tabline功能,方便查看Buffer和切换,省去了minibufexpl插件
let g:airline#extensions#tabline#enabled = 0
let g:airline#extensions#tabline#left_sep = ' '
let g:airline#extensions#tabline#left_alt_sep = '|'
let g:airline#extensions#tabline#buffer_nr_show = 1

" "这个是安装字体后 必须设置此项"
let g:airline_powerline_fonts = 1


" "设置切换Buffer快捷键"
" nnoremap <C-tab> :bn<CR>
" nnoremap <C-s-tab> :bp<CR>
" 关闭状态显示空白符号计数
let g:airline#extensions#whitespace#enabled = 0
let g:airline#extensions#whitespace#symbol = '!'
" " 设置consolas字体"前面已经设置过
" set guifont=Consolas\ for\ Powerline\ FixedD:h11
set guifont=Powerline_Consolas:h14:cANSI

" 开启git分支的展示
let g:airline#extensions#branch#enabled = 1

if !exists('g:airline_symbols')
  let g:airline_symbols = {}
endif
" old vim-powerline symbols
let g:airline_left_sep = '⮀'
let g:airline_left_alt_sep = '⮁'
let g:airline_right_sep = '⮂'
let g:airline_right_alt_sep = '⮂'
let g:airline_symbols.branch = '⭠'
