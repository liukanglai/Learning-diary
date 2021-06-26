# 

> need \ to escape, except . and *
- `\(c\|p\)`arrot match carrot or parrot
- `\warrot\?` match all+arro(t) \w is all, t\? means optional
- `pa.\+ot` .\ means one or more character


# 

> :help ordinary-atom

    . 任意字符，不包括行尾
    ^ 行首
    $ 行尾
    \_ 任意字符，包含行尾
    \< 单词开始
    \> 单词结尾

    \s 一个空白符（space，tab）S
    \d 一个数字 D（非...）
    \w 一个单词字符（数字，字母，下划线） W
    \l 一个小写字符 L(除小写字母外的所有字符)
    \u 一个大写字符 U
    \a 一个字母字符 A

> :help character-classes

    [A-Z0-9]
    [,4abc] 只匹配, 4 a b c
    [^0-9A-Za-z] 所有非字符数字

    \| 或
    \(...\) grouping

- cat hunting mice to mice hunting cat: s/\(cat\) hunting \(mice\)/\2 hunting \1/

- 字符或字符区间后面接一个量词(quantifier，称为重数(multi)
- 贪婪匹配模式(greedy)：尽可能多地匹配字符
- 非贪婪匹配模式(non-greedy)：尽可能少的
        
        * 0个或多个, 贪婪
        \+ 1个或多个, 贪婪
        \{-} 0或多个，非贪婪
        \? \= 0或1个，贪婪
        \{n,m} n~m个，贪婪
        \{-n,m} n~m个，非贪婪

- \w\+ : 一个或多个字符
- a\{2,4} : 2~4个连续的a
- 对于foo2bar2, 使用\w\+2将匹配foo2bar2，而\w\{-}2匹配foo2

> :help multi

# magic

1. magic
- 大部分字符都要转义（. *除外），可\m set, ps: s/\mfoo/bar
2. nomagic (set nomagic, 可能会影响插件)
- 都需要转义, add \M
- /^.\*$查找任意行, nomagic:

        /\^\.\*\$

3. very magic
- 数字，字母，下划线以外都是特殊字符, add \v
