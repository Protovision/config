require('vis')
vis.events.subscribe(vis.events.WIN_OPEN , function(window)
	vis:command('set escdelay 0')
	vis:command('set tabwidth 8')
	vis:command('set autoindent')
	vis:command('set number')
	vis:command('set colorcolumn 73')
end)

