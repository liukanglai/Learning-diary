# command

    init    add .     config --global    commit -m ""     remote add origin    push


- git init:在当前目录生成
- git status:查看状态
- git add (file): . 代表所有,  准备提交
- git diff: 查看改动
- git reset: 返回
- git config --global user.name/email ""
- git commit -m "description": if no -m, it will a vi,then you can write it
- git commit -a : add+commit,but 未追踪file no
- git config --global core.editor vim
- vim .gitignore:write a file name --还没有追踪的file
- git rm --cached "....": 停止追踪
- git branch ...
- git checkout ...: 切换branch
- git merge ...: 合并branch
- git branch -d ...: del  -D 强制
- git remote add origin https://
- git push --set-upstream origin master
- git config credential.helper store




- git clone http
- git pull : 下载更新 






# git 

"歌易特"

> 2005年4月3日，开始开发Git
>
> 2005年4月6日，项目发布
>
> 2005年4月7日，Git就可以作为自身的版本控制工具了
>
> 2005年4月18日，发生第一个多分支合并
>
> 2005年4月29日，Git的性能就已经达到了Linus的预期
>
> 2005年6月16日，Linux核心2.6.12发布，那时Git已经在维护Linux核心的源代码了

- 备份
- 重提交
- 差异比较
- 下载


## 安装

1. 包管理器

    - git/git-core
    - git-doc: 文档    git help -w "command"  web查看 实际上即使不安装Git文档，也可以使用man手册查看Git帮助
    - git-svn 
    - git-email
    - gitk
    -


2. 源代码

    - http://git-scm.com/ 下载 tar.bz2/...
    - Install 文件

            tar -jxvf git-1.7.3.5.tar.bz2
            cd git-1.7.3.5/
            make prefix=/usr/local all
            sudo make prefix=/usr/local install


3. clone

    - git clone git://git.kernel.org/pub/scm/git/git.git
    - cd git
    - 更新: git pull
    - 执行清理工作，避免前一次编译的遗留文件造成影响,丢弃本地对Git代码的改动。

            git clean -fdx
            git reset --hard

    - 查看Git的里程碑，选择最新的版本进行安装。例如v1.7.3.5。

            git tag
            ...
            v1.7.3.5

    - 检出该版本的代码。

            git checkout v1.7.3.5

    - 执行安装。例如安装到/usr/local目录下。

            make prefix=/usr/local all doc info
            sudo make prefix=/usr/local install \
            install-doc install-html install-info


4. command-completion (包管理器，已配置，如以源码编译)


    - 将Git源码包中的命令补齐脚本复制到bash-completion对应的目录中。

            cp contrib/completion/git-completion.bash \
            /etc/bash_completion.d/

    - 重新加载自动补齐脚本，使之在当前shell中生效。

            . /etc/bash_completion

    - 在终端开启时加载，在本地配置文件~/.bash_profile或全局文件/etc/bashrc文件中添加

            if [ -f /etc/bash_completion ]; then
            . /etc/bash_completion
            fi


5. chinese (可在提交说明中使用，但若用非UTF-8字符集，则需设置。用来命名文件、目录或引用，只有在使用UTF-8字符集的环境下才可)

[Git](http://www.worldhello.net/gotgit/01-meet-git/035-install-on-linux.html)


# github

## search

- in:name ...
- in:readme ...
- in:description
- stars:>...
- forks:>...
- language:...
- pushed:>2020-09-
-
