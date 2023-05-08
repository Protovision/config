# .bashrc

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

PS1='\W \$ '

LS_OPTIONS="--classify --color=never --format=long --hide-control-chars --human-readable --no-group --quoting-style=shell-always --reverse --sort=time --time-style=long-iso"
LS_FILTER="tail -n +2 | tr -s ' ' | cut -d ' ' -f 5-"

alias go='cd'
alias list="ls $LS_OPTIONS | $LS_FILTER"
alias tree='tree -FC --noreport'
alias fork='st &>/dev/null &'
alias scroll='less --RAW-CONTROL-CHARS'
alias edit='vim'
alias erase='rm'
alias move='mv'
alias copy='cp'
alias play='mpv'
alias shutdown='sudo shutdown -P now'
alias restart='sudo shutdown -r now'
alias update='sudo xbps-install --sync --update --verbose'
alias uninstall='sudo xbps-remove --force --clean-cache --remove-orphans --recursive'
alias latin-english='dict -d fd-lat-eng'
alias english-latin='dict -d fd-eng-lat'
alias define='dict'

function view(){ mupdf "$@" &>/dev/null & }


