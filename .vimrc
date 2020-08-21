"costomize
"set mouse=a  "使能鼠标
set showcmd "显示命令
set ruler  "显示标尺
set showmatch "高亮显示适配括号

set nu  "显示行号
syntax on "句法高亮
syntax enable 
colorscheme desert

" Indent
set smartindent
set cindent
set autoindent

" TagList
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1

" WinManager
let g:winManagerWindowLayout='FileExplorer|TagList'
nmap wm :WMToggle<cr>

" Omnicompletion
set nocp
filetype plugin indent on
set completeopt=longest,menu

nmap <C-\>s :cs find s <C-R>=expand("<cword>")<CR><CR>
nmap <C-\>g :cs find g <C-R>=expand("<cword>")<CR><CR>
nmap <C-\>c :cs find c <C-R>=expand("<cword>")<CR><CR>
nmap <C-\>t :cs find t <C-R>=expand("<cword>")<CR><CR>
nmap <C-\>e :cs find e <C-R>=expand("<cword>")<CR><CR>
nmap <C-\>f :cs find f <C-R>=expand("<cfile>")<CR><CR>
nmap <C-\>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
nmap <C-\>d :cs find d <C-R>=expand("<cword>")<CR><CR>

nmap <leader>w :w!<cr>
nmap <leader>f :find<cr>


autocmd BufNewFile *.[ch],*.hpp,*.cpp exec ":call SetTitle()"
func SetTitle() 
	if &filetype == 'c'
		call setline(1,"#include <stdio.h>")
		call append(line("."),"")
		call append(line(".")+1,"int main(int argc, char **argv)")
		call append(line(".")+2,"{")
		call append(line(".")+3,"")
		call append(line(".")+4,"")
		call append(line(".")+5,"")
		call append(line(".")+6,"	return 0")
		call append(line(".")+7,"}")
	endif
endfunc
