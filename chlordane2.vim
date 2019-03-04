" Name: chlordane2.vim
" Description: Modified from the original chlordane.vim to support 256 color terminals
" Maintainer: Mark Swoope
" Last Change: 2019-02-19
" Revision: 1.0


" vim:set ts=8 sts=2 sw=2 tw=0:
" Name: chlordane.vim
" Maintainer:	Kojo Sugita
" Last Change:  2008-11-22
" Revision: 1.2

set background=dark
hi clear
if exists("syntax_on")
  syntax reset
endif
let g:colors_name = 'chlordane2'

hi Cursor	ctermfg=22 guifg=#3a553a ctermbg=114 guibg=#77dd88
hi lCursor	ctermfg=22 guifg=#3a553a ctermbg=114 guibg=#77dd88
hi CursorLine	ctermbg=0 guibg=#000000 gui=underline
hi CursorIM	ctermfg=22 guifg=#3a553a ctermbg=114 guibg=#77dd88
hi Directory	ctermfg=114 guifg=#77dd88 ctermbg=0 guibg=#000000 gui=bold
hi DiffAdd	ctermfg=114 guifg=#77dd88 ctermbg=22 guibg=#3a553a gui=none
hi DiffChange	ctermfg=114 guifg=#77dd88 ctermbg=22 guibg=#3a553a gui=none
hi DiffDelete	ctermfg=22 guifg=#223322 ctermbg=22 guibg=#223322 gui=none
hi DiffText	ctermfg=114 guifg=#77dd88 ctermbg=65 guibg=#448844 gui=bold
hi ErrorMsg	ctermfg=12 guifg=#ee1111 ctermbg=0 guibg=#000000
hi VertSplit	ctermfg=22 guifg=#223322 ctermbg=22 guibg=#223322
hi Folded	ctermfg=71 guifg=#55af66 ctermbg=0 guibg=#000000
hi FoldColumn	ctermfg=65 guifg=#557755 ctermbg=22 guibg=#102010
hi IncSearch	ctermfg=22 guifg=#3a553a ctermbg=114 guibg=#77dd88 gui=none
hi LineNr	ctermfg=65 guifg=#446644 ctermbg=0 guibg=#000000 gui=none
hi ModeMsg	ctermfg=71 guifg=#55af66 ctermbg=0 guibg=#000000
hi MoreMsg	ctermfg=71 guifg=#55af66 ctermbg=0 guibg=#000000
hi Normal	ctermfg=71 guifg=#55af66 ctermbg=0 guibg=#000000
hi Question	ctermfg=71 guifg=#55af66 ctermbg=0 guibg=#000000
hi Search	ctermfg=22 guifg=#223322 ctermbg=71 guibg=#55af66 gui=none
hi NonText	ctermfg=241 guifg=#606060 ctermbg=none guibg=none
hi SpecialKey	ctermfg=22 guifg=#707070
"\n, \0, %d, %s, etc...
hi Special	ctermfg=71 guifg=#55af66 ctermbg=23 guibg=#223333 gui=bold
" status line
hi StatusLine	ctermfg=65 guifg=#88ee99 ctermbg=0 guibg=#447f55 gui=bold
hi StatusLineNC term=bold cterm=bold,underline ctermfg=green ctermbg=Black
hi StatusLineNC term=bold gui=bold,underline ctermfg=22 guifg=#3a553a  guibg=Black
hi Title	ctermfg=114 guifg=#77dd88 ctermbg=22 guibg=#223322 gui=bold
hi Visual	ctermfg=0  guifg=#000000 ctermbg=28 guibg=#448844 gui=none
hi VisualNOS	ctermfg=71 guifg=#55af66 ctermbg=0 guibg=#000000
hi WarningMsg	ctermfg=114 guifg=#77dd88 ctermbg=0 guibg=#000000
hi WildMenu	ctermfg=22 guifg=#3a553a ctermbg=114 guibg=#77dd88
hi Number	ctermfg=114 guifg=#77dd88 ctermbg=238 guibg=#354535
hi Char		ctermfg=114 guifg=#77dd88 ctermbg=238 guibg=#354535
hi String	ctermfg=114 guifg=#77dd88 ctermbg=238 guibg=#354535
hi Boolean	ctermfg=114 guifg=#77dd88 ctermbg=238 guibg=#354535
hi Comment	ctermfg=65 guifg=#446644
hi Constant	ctermfg=114 guifg=#88ee99 gui=none
hi Identifier	ctermfg=114 guifg=#77dd88
hi Statement	ctermfg=114 guifg=#88ee99 gui=none

"Procedure name
hi Function     ctermfg=114 guifg=#77dd88

"Define, def
hi PreProc	ctermfg=114 guifg=#77dd88 gui=bold
hi Type		ctermfg=114 guifg=#77dd88 gui=bold
hi Underlined	ctermfg=114 guifg=#77dd88 gui=underline
hi Error	ctermfg=12 guifg=#ee1111 ctermbg=0 guibg=#000000
hi Todo		ctermfg=22 guifg=#223322 ctermbg=71 guibg=#55af66 gui=none
hi SignColumn   ctermbg=0 guibg=#000000

if version >= 700
  " Pmenu
  hi Pmenu	ctermfg=235 guibg=#222222
  hi PmenuSel	ctermbg=22 guibg=#3a553a ctermfg=114 guifg=#77dd88
  hi PmenuSbar	ctermbg=235 guibg=#222222

  " Tab
  hi TabLine	  ctermfg=22 guifg=#3a553a guibg=black gui=bold
  hi TabLineFill  ctermfg=0 guifg=black ctermbg=0 guibg=black gui=bold
  hi TabLineSel	  ctermfg=114 guifg=#88ee99 ctermbg=65 guibg=#447f55 gui=bold
endif

hi ColorColumn ctermbg=238 guibg=#354535
hi MatchParen cterm=bold ctermfg=0 guifg=#000000 ctermbg=227 guibg=#ffff5f

