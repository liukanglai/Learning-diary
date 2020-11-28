
## tags: pacman

```

- 列出已安装包 -Q
- 查看包是否安装 -Q name
- 查看已安装包信息 -Qi name
- 列出已安装包所有文件 -QI name
- 查找某个文件属于哪个包 -Qo /…
- 查询包组 -Sg
- 查询包组所包含软件包 -Sg name
- 搜索相关包 -Ss name
- 从数据库中搜索信息 -Si name
- 仅同步源 -Sy
- 更新系统 -Su
- 同步源并更新系统 -Syu
- 同后安装包 -Sy name
- 从本地数据库中获取信息并安装 -S name
- 强制安装 -Sf name
- 删除 -R name
- 强制删除被依赖包 -Rd name
- 删除包及依赖其的包 -Rc name
- 删除包及其依赖的包 -Rsc name
- 清理/var/cache/pacman/pkg目录下的旧包 -Sc
- 清除所有下载的包和数据库 -Scc
- 安装下载的包（有时候需要降级包的时候就用这个
- cd /var/cache/pacman/pkg
-U name-5.2.12-1-x86_64.pkg.tar.xz 
- 升级时不升级包 -Su –ignore name
- sudo pacman -Scc: 清除软件包


清理安装包缓存
使用

Shell
1
sudo pacman -Scc
不仅会删除未安装或旧版本的包文件缓存，也会将安装着的包的包文件缓存也一并删除。这部分是最占空间的，我大概有7-8G。

清理孤立的软件包
使用

Shell
1
sudo pacman -Rns $(pacman -Qtdq)
就可以删除孤立的软件包。什么是孤立的软件包呢？比如我想要吃西餐，我需要买刀叉。刀叉即西餐的一个依赖，西餐依赖于刀叉。如果我再也不想要吃西餐了，那么已经买来的刀叉也没用了。这个刀叉即孤立的软件包。既然用不上了，那么可以删掉。我大概清理了2-3G。

清理日志
使用

Shell
1
journalctl --vacuum-size=50M
可以限制日志记录大小在50M，我使用一年没清理过，日志记录大概在2G左右。设置了固定大小为50M后，多的日志就会被删掉。




作者: 杨宇昊
链接: https://qsctech-sange.github.io/arch-linux-clean.html#%E6%B8%85%E7%90%86%E5%AE%89%E8%A3%85%E5%8C%85%E7%BC%93%E5%AD%98
来源: 三个技术小站
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

```
