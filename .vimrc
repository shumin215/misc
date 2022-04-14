set nocompatible                " Use default vim
set number                      " line number
set ai                          " auto indent according to upper line
set si                          " smart indent according to if or for statment
set expandtab                   " space instead of tab key
set shiftwidth=4                " set shift is 4 blocks when using >>
set tabstop=4                   " one tab key is 4 blocks
set softtabstop=4               " set tab key is 4 blocks when using tab key
set smarttab                    " Enabling this will make the tab key (in insert mode) insert spaces or tabs to go to the next indent of the next tabstop
set ignorecase                  " When searching both small letter and capital word
set hlsearch                    " highlight when searching
set fileencodings=utf-8,euc-kr  " set file encoding type
set bs=indent,eol,start         " It's possible to use backspace key
set history=1000                " contains history of 1000 commands
set ruler                       " display coordinate of cursor at stateline
set title                       " Display title
set showmatch                   " Display match of parenthesis
set nowrap                      " Doesn't line change automatically
set wmnu                        " Display auto generated when using tab key
set cursorline                  " Make a cursorline
set cursorcolumn                " make a vertical cursor line
set sc                          " Display commands being completed
set wrap
"set paste                       " When pasting, eliminate indent, causes bad indent
"set mouse=a                     "'a' to all mode, n, v, i, c to Normal, Visual, Insert, Command mode
colorscheme darkblue
sy enable                       " Turn on syntax depend on file type
filetype plugin indent on       " Turns on 'detection', 'plugin', and 'indent'

" Set swap file path
set dir=~/.vim/temp
set bdir=~/.vim/temp

" Set 'E' to explore
command! E Explore

" Set specific tags 
" set tags+=[path for specific tags]

"------------------------- Change the window ---------------------------
nmap <C-h> <C-w>h
nmap <C-j> <C-w>j
nmap <C-k> <C-w>k
nmap <C-l> <C-w>l

""------------------------- Plugin -------------------------
set rtp+=~/.vim/bundle/auto-pairs
set rtp+=~/.vim/bundle/AutoComplPop
set rtp+=~/.vim/bundle/lightline
set rtp+=~/.vim/bundle/syntastic
set rtp+=~/.vim/bundle/gruvbox
set rtp+=~/.vim/bundle/nerdtree
set rtp+=~/.vim/bundle/ctrlp
set rtp+=~/.vim/bundle/vim-buftabline

"set rtp+=~/.vim/bundle/taglist
set rtp+=~/.vim/bundle/vim-easytags
set rtp+=~/.vim/bundle/vim-misc     " This is for vim-easytags

"------------------------------- AutoComplPop -------------------------
function! InsertTabWrapper()
    let col=col('.')-1
    if !col||getline('.')[col-1]!~'\k'
        return "\<TAB>"
    else
        if pumvisible()
            return "\<C-N>"
        else
            return "\<C-N>\<C-P>"
        end
    endif
endfunction
inoremap <TAB> <c-r>=InsertTabWrapper()<cr>
hi Pmenu ctermbg=blue
hi PmenuSel ctermbg=yellow ctermbg=black
hi PmenuSbar ctermbg=blue

"------------------------------- Lightline -------------------------
set laststatus=2
let g:lightline = {
            \ 'colorscheme': 'wombat',
            \ 'active': {
            \   'left': [ [ 'mode', 'paste' ],
            \             [ 'cocstatus', 'readonly', 'filename', 'modified' ] ]
            \ },
            \ 'component_function': {
            \   'cocstatus': 'coc#status'
            \ },
            \ }

"------------------------------- Syntastic -------------------------
" Usage: Syntax check
" reference: https://vimawesome.com/plugin/syntastic
" let g:syntastic_python_checkers = [ 'pep8' ]    " This is for python comments that is detected as invalid syntax
let g:syntastic_python_checkers = ['pylint']
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0

"------------------------------- Syntastic -------------------------
" a: create new file
" m: move the file
" d: delete the file
" c: copy the file
nmap <C-o> :NERDTreeToggle<CR>

"------------------------------- Ctrlp -------------------------
" Usage: Ctrl + p
let g:ctrlp_custom_ignore = {
            \ 'dir': '\.git$\|public$\|log$\|tmp$\|vendor$',
            \ 'file': '\v\.(exe|so|dll)$'
            \ }

"------------------------------- Buffer command -------------------------
map ,1 :b!1<CR>
map ,2 :b!2<CR>
map ,3 :b!3<CR>
map ,4 :b!4<CR>
map ,5 :b!5<CR>
map ,6 :b!6<CR>
map ,7 :b!7<CR>
map ,8 :b!8<CR>
map ,9 :b!9<CR>
map ,0 :b!10<CR>
map ,w :bw<CR>
map ,n :bn<CR>

"------------------------------- easytags -------------------------
let g:easytags_async=1 
let g:easytags_auto_highlight = 0 
let g:easytags_include_members = 1 
let g:easytags_dynamic_files = 1

"------------------------------- Cscope -------------------------
set csprg=/usr/bin/cscope
set csto=0 
set cst
set nocsverb
if filereadable("./cscope.out")
    cs add cscope.out
else
    cs add ~/.tags/cscope.out
endif
set csverb
func! Css()
    let css = expand("<cword>")
    "new
    exe "cs find s ".css
    if getline(1) == " "
        exe "q!"
    endif
endfunc
nmap ,css :call Css()<cr>
func! Csc()
    let csc = expand("<cword>")
    "new
    exe "cs find c ".csc
    if getline(1) == " "
        exe "q!"
    endif
endfunc
nmap ,csc :call Csc()<cr>
func! Csd()
    let csd = expand("<cword>")
    "new
    exe "cs find d ".csd
    if getline(1) == " "
        exe "q!"
    endif
endfunc
nmap ,csd :call Csd()<cr>
func! Csg()
    let csg = expand("<cword>")
    "new
    exe "cs find g ".csg
    if getline(1) == " "
        exe "q!"
    endif
endfunc
nmap ,csg :call Csg()<cr>
func! Cssn()
    let css = expand("<cword>")
    new
    exe "cs find s ".css
    if getline(1) == " "
        exe "q!"
    endif
endfunc
nmap ,cssn :call Cssn()<cr>
func! Cscn()
    let csc = expand("<cword>")
    new
    exe "cs find c ".csc
    if getline(1) == " "
        exe "q!"
    endif
endfunc
nmap ,cscn :call Cscn()<cr>
func! Csdn()
    let csd = expand("<cword>")
    new
    exe "cs find d ".csd
    if getline(1) == " "
        exe "q!"
    endif
endfunc
nmap ,csdn :call Csdn()<cr>
func! Csgn()
    let csg = expand("<cword>")
    new
    exe "cs find g ".csg
    if getline(1) == " "
        exe "q!"
    endif
endfunc
nmap ,csgn :call Csgn()<cr>
