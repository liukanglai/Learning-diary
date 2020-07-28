# proxy 

-方法一：（推荐使用）
为什么说这个方法推荐使用呢？因为他只作用于当前终端中，不会影响环境，而且命令比较简单
在终端中直接运行：

export http_proxy=http://proxyAddress:port
如果你是SSR,并且走的http的代理端口是12333，想执行wget或者curl来下载国外的东西，可以使用如下命令：

export http_proxy=http://127.0.0.1:12333
如果是https那么就经过如下命令：

export https_proxy=http://127.0.0.1:12333
方法二 ：
这个办法的好处是把代理服务器永久保存了，下次就可以直接用了
把代理服务器地址写入shell配置文件.bashrc或者.zshrc 直接在.bashrc或者.zshrc添加下面内容

export http_proxy="http://localhost:port"
export https_proxy="http://localhost:port"
或者走socket5协议（ss,ssr）的话，代理端口是1080

export http_proxy="socks5://127.0.0.1:1080"
export https_proxy="socks5://127.0.0.1:1080"
或者干脆直接设置ALL_PROXY

export ALL_PROXY=socks5://127.0.0.1:1080
最后在执行如下命令应用设置

source ~/.bashrc
或者通过设置alias简写来简化操作，每次要用的时候输入setproxy，不用了就unsetproxy。

 alias setproxy="export ALL_PROXY=socks5://127.0.0.1:1080" alias unsetproxy="unset ALL_PROXY"
方法三:
改相应工具的配置，比如apt的配置

sudo vim /etc/apt/apt.conf
在文件末尾加入下面这行

Acquire::http::Proxy "http://proxyAddress:port"
重点来了！！如果说经常使用git对于其他方面都不是经常使用，可以直接配置git的命令。
使用ss/ssr来加快git的速度
直接输入这个命令就好了

git config --global http.proxy 'socks5://127.0.0.1:1080' 
git config --global https.proxy 'socks5://127.0.0.1:1080'


	        Reply    28
hello100   2019-05-20 14:55:11 +08:00
`git config --global http.proxy 代理地址`
`git config --global https.proxy 代理地址`
这种方法是不会起作用的，因为很多 repo 用的是 SSL 的地址，SSL 的地址不会使用 http 和 https 的 proxy。
真正的解决方法是使用 SSL 的 proxyCommand
在你的.ssh/config 中加入这么一行：
···
Host github.com
Hostname github.com
User XXXX
IdentityFile /home/XXXX/.ssh/id_rsa
ProxyCommand /bin/nc -X5 -x 172.0.0.2:1080 %h %p
···

最后一行会让 git 使用 172.0.0.2:1080 地址的 socket5 代理。我的 linux 跑在 VM 里，这个地址是我 windows 上的 s-s 的地址。

服务器端 supervisord 建立了一个 socat 转发到 github.com 的服务：
socat tcp-l:61222,fork,reuseaddr tcp:github.com:22

客户端 ssh/.config:
Host my.github.com
HostName <服务器域名或者 IP>
Port 61222
客户端再克隆的时候，github.com 上面的地址例如： git@github.com:updateing/lede-source.git
克隆的时候在 @前面加上 my 就可以从镜像克隆，不加则是官方地址克隆。

方法跟楼上 hello100 基本雷同
