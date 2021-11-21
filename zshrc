# If you come from bash you might have to change your $PATH.
# export PATH=$HOME/bin:/usr/local/bin:$PATH

# Path to your oh-my-zsh installation.
export ZSH=$HOME/.oh-my-zsh

# Set name of the theme to load --- if set to "random", it will
# load a random theme each time oh-my-zsh is loaded, in which case,
# to know which specific one was loaded, run: echo $RANDOM_THEME
# See https://github.com/robbyrussell/oh-my-zsh/wiki/Themes
ZSH_THEME="robbyrussell"
# ZSH_THEME="ys"

# Set list of themes to pick from when loading at random
# Setting this variable when ZSH_THEME=random will cause zsh to load
# a theme from this variable instead of looking in ~/.oh-my-zsh/themes/
# If set to an empty array, this variable will have no effect.
# ZSH_THEME_RANDOM_CANDIDATES=( "robbyrussell" "agnoster" )

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion.
# Case-sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment the following line to disable bi-weekly auto-update checks.
# DISABLE_AUTO_UPDATE="true"

# Uncomment the following line to change how often to auto-update (in days).
# export UPDATE_ZSH_DAYS=13

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
# ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# You can set one of the optional three formats:
# "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# or set a custom format using the strftime function format specifications,
# see 'man strftime' for details.
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load?
# Standard plugins can be found in ~/.oh-my-zsh/plugins/*
# Custom plugins may be added to ~/.oh-my-zsh/custom/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(
  git
)

source $ZSH/oh-my-zsh.sh

# User configuration

# export MANPATH="/usr/local/man:$MANPATH"

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='mvim'
# fi

# Compilation flags
# export ARCHFLAGS="-arch x86_64"

# ssh
# export SSH_KEY_PATH="~/.ssh/rsa_id"

# Set personal aliases, overriding those provided by oh-my-zsh libs,
# plugins, and themes. Aliases can be placed here, though oh-my-zsh
# users are encouraged to define aliases within the ZSH_CUSTOM folder.
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"
PATH="/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/games/bin"

# command
alias proxy='export all_proxy=socks5://127.0.0.1:1080'
alias unproxy='unset all_proxy'
alias subl=\''/Applications/Sublime Text.app/Contents/SharedSupport/bin/subl'\'
alias md=\''/Applications/Typora.app/Contents/MacOS/Typora'\'
alias mw='open -a MWeb'
alias ..='cd ..'
alias ..2='cd ../..'
alias ..3='cd ../../..'
alias ..4='cd ../../../..'
alias ,,='cd ..'
alias ,,2='cd ../..'
alias ,,3='cd ../../..'
alias ,,4='cd ../../../..'
alias py=python3
#alias cp='cp -i'
alias g++='g++ -std=c++11 -g'
alias tt='tldr' # better man
alias cdp="cd ~/mine/gosuncn/PHEONIX2.0"
alias cdc="cd ~/mine/Codes"
alias cds="cd ~/mine/joyy/projects/s2s"
alias cdl="cd ~/mine/joyy/projects/Baichuan_DataUpload/log-collection"
alias cdm="cd /Users/edwardlu/mine/gosuncn/phoenix2.0/Protocol/Msg"
alias gdb="gdb -q"
alias giticdiff="git icdiff"
alias gitlog="git log --pretty=format:'%h (%cd) : %s' --graph --date=short"
alias rmswp="rm -f .*.swp"


# proxy list
# export http_proxy="http://127.0.0.1:1080"
# export https_proxy="https://127.0.0.1:1080"

export NVM_DIR="/Users/edwardlu/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && . "$NVM_DIR/nvm.sh"  # This loads nvm

# JAVA Path
export JAVA_HOME=$(/usr/libexec/java_home)

# maven path
export M2_HOME=/Users/edwardlu/apache-maven-3.6.0
export PATH=$PATH:$M2_HOME/bin

# scons Path
export MYSCONS=/Users/edwardlu/Downloads/scons-2.1.0
export SCONS_LIB_DIR=$MYSCONS/engine
export HOMEBREW_BOTTLE_DOMAIN=https://mirrors.aliyun.com/homebrew/homebrew-bottles

# ffmpeg path
export PATH=/usr/local/ffmpeg/bin:$PATH

[[ -s "$HOME/.xmake/profile" ]] && source "$HOME/.xmake/profile" # load xmake profile

. /Users/edwardlu/Downloads/gitCodes/z-master/z.sh

# 解决终端中文乱码
export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8

# go related
export GOROOT=/usr/local/bin
export GOPATH=/Users/edwardlu/go
export PATH=$PATH:$GOPATH/bin:$GOROOT
