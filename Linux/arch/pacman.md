
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

```
