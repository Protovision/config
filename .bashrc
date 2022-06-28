# .bashrc

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

alias ls='ls -F --color=never --format=long --human-readable --reverse --sort=time'
alias less='less --RAW-CONTROL-CHARS'
alias tree='tree -FC --noreport'
alias halt='sudo halt'
alias reboot='sudo reboot'
alias poweroff='sudo poweroff'
alias shutdown='sudo shutdown'
alias lat2eng='dict -d fd-lat-eng'
alias eng2lat='dict -d fd-eng-lat'
PS1='\W \$ '
