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






整理自 https://www.worldhello.net/

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


## Do


1. Git初始化

2.1.1. 创建版本库及第一次提交
2.1.2. 思考：为什么工作区下有一个.git目录？
2.1.3. 思考：git config命令参数的区别？
2.1.4. 思考：是谁完成的提交？
2.1.5. 思考：随意设置提交者姓名，是否太不安全？
2.1.6. 思考：命令别名是干什么的？
2.1.7. 备份本章的工作成果



2.2. Git暂存区
2.2.1. 修改不能直接提交？
2.2.2. 理解 Git 暂存区（stage）
2.2.3. Git Diff魔法
2.2.4. 不要使用git commit -a
2.2.5. 搁置问题，暂存状态



2.3. Git对象
2.3.1. Git对象库探秘
2.3.2. 问题：SHA1哈希值到底是什么，如何生成的？
2.3.3. 问题：为什么不用顺序的数字来表示提交？



2.4. Git重置
2.4.1. 分支游标master的探秘
2.4.2. 用reflog挽救错误的重置
2.4.3. 深入了解git reset命令



2.5. Git检出
2.5.1. HEAD的重置即检出
2.5.2. 挽救分离头指针
2.5.3. 深入了解git checkout命令



2.6. 恢复进度
2.6.1. 继续暂存区未完成的实践
2.6.2. 使用git stash
2.6.3. 探秘git stash



2.7. Git基本操作
2.7.1. 先来合个影
2.7.2. 删除文件
2.7.2.1. 本地删除不是真的删除
2.7.2.2. 执行git rm命令删除文件
2.7.2.3. 命令git add -u快速标记删除
2.7.3. 恢复删除的文件
2.7.4. 移动文件
2.7.5. 一个显示版本号的Hello World
2.7.6. 使用git add -i选择性添加
2.7.7. Hello world引发的新问题
2.7.8. 文件忽略
2.7.9. 文件归档



2.8. 历史穿梭
2.8.1. 图形工具：gitk
2.8.2. 图形工具：gitg
2.8.3. 图形工具：qgit
2.8.4. 命令行工具
2.8.4.1. 版本表示法：git rev-parse
2.8.4.2. 版本范围表示法：git rev-list
2.8.4.3. 浏览日志：git log
2.8.4.4. 差异比较：git diff
2.8.4.5. 文件追溯：git blame
2.8.4.6. 二分查找：git bisect
2.8.4.7. 获取历史版本



2.9. 改变历史
2.9.1. 悔棋
2.9.2. 多步悔棋
2.9.3. 回到未来
2.9.3.1. 时间旅行一
2.9.3.2. 时间旅行二
2.9.3.3. 时间旅行三
2.9.4. 丢弃历史
2.9.5. 反转提交



2.10. Git克隆
2.10.1. 鸡蛋不装在一个篮子里
2.10.2. 对等工作区
2.10.3. 克隆生成裸版本库
2.10.4. 创建生成裸版本库



2.11. Git库管理
2.11.1. 对象和引用哪里去了？
2.11.2. 暂存区操作引入的临时对象
2.11.3. 重置操作引入的对象
2.11.4. Git管家：git gc
2.11.5. Git管家的自动执行

































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
