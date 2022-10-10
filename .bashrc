# .bashrc

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

LS_OPTIONS="--classify --color=never --format=long --hide-control-chars --human-readable --no-group --quoting-style=shell-always --reverse --sort=time --time-style=long-iso"
LS_FILTER="tail -n +2 | tr -s ' ' | cut -d ' ' -f 5-"
alias c='clear'
alias l="ls $LS_OPTIONS | $LS_FILTER"
alias la="ls --all --almost-all $LS_OPTIONS| $LS_FILTER"
alias st='st &>/dev/null &'
alias less='less --RAW-CONTROL-CHARS'
alias tree='tree -FC --noreport'
alias halt='sudo shutdown -P now'
alias poweroff='sudo shutdown -P now'
alias reboot='sudo shutdown -r now'
alias update='sudo xbps-install --sync --update --verbose'
alias uninstall='sudo xbps-remove --force --clean-cache --remove-orphans --recursive'
alias lat2eng='dict -d fd-lat-eng'
alias eng2lat='dict -d fd-eng-lat'
PS1='\W \$ '
