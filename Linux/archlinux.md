# 安装

## 启动

* 镜像u盘 (MD5… PGP…)

> 例:dd bs=4M if=/home/liukanglai/Downloads/archlinux-2020.04.01-x86_64.iso of=/dev/sda status=progress oflag=sync

* u盘启动 UEFI `root@archiso~#`

# 查看指南:ls 

* 验证启动模式:ls /sys/firmware/efi/efivars 有输出即为UEFI

## 联网

* ip link –看网卡  `enp开头有线网卡 wlp无线网卡` 

    > 看有无网: 命令 ping www.baidu.com 后显 ….ms 即有网
    >     
    > enp开头有线网卡 wlp无线网卡 
    

(手机usb共享网,连接电脑)

### 无线

* ip link set .. up

- 扫描：iwlist .. scan | grep ESSID
- 连接：

    > wpa_passphrase 网络名 密码 > internet.conf
    > 
    > wpa_supplicant -c internet.conf -i 设备名 &

- 分配ip地址：dhcpcd &

- 如需web登录(Captive Portal): elinks http…

### 有线

- systemctl enable dhcpcd
- systemctl restart dhcpcd

## 配置

- 时间同步: timedatectl set-ntp true

    > 手动: timectl set-time “year-month-date h-minute-s”

- 检查:timedatectl status

## 安盘

- 查看硬盘: lsblk或fdisk -l

    > /dev/… nvme0n(高级)或sda… (新盘不同)

- 分盘: cfdisk 进gpt 分后yes

格式|大小|目录|格式
----|----|----|----
fat32|300M|EFI|EFI system
ext4| |/|linux filesystem
swap | |/|linux swap

- 格式化: 

    > /：mkfs.ext4 /dev/..
    >
    > EFI: mkfs.vfat或mkfs.fat -F32
    > 
    > swap: mkswap -f /…

- 打开swap：swapon /…
 
- 挂载:
 
    > /: mount /dev/..  /mnt
    > 
    > mkdir /mnt/boot
    > 
    > EFI: mount /dev/..  /mnt/boot
 
## 软件源

- vim /etc/pacman.d/mirrorlist 把China移到最前

```
 清华大学
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinux/$repo/os/$arch
## 163
Server = http://mirrors.163.com/archlinux/$repo/os/$arch
## aliyun
Server = http://mirrors.aliyun.com/archlinux/$repo/os/$arch
```
 
- 刷新: pacman -syy (-syu)
 
## 安装

- pacstrap /mnt base linux linux-firmware vim  base-devel man 

> linux中包含EFI文件！！！
 
## 进入chroot

- 生成fstab???
 
    > genfstab -L /mnt >> /mnt/etc/fstab
 
- 检查:cat /mnt/etc/fstab
 
- arch-chroot /mnt

## 基本设置

- 时区: In -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
- 设置时间标准UTC,并调整时间漂移 : hwclock –-systohc
- 本地化: 

    > vim /etc/locale.gen (去#号 en_US.UTF-8 UTF-8   zh_CN.UTF-8 UTF-8    zh_HK.UTF-8 UTF-8   zh_TW.UTF-8 UTF-8 )
    >     
    > locale-gen(生成)
    >  
    > vim /etc/locale.conf 输入： LANG=en_US.UTF-8
     
- vim /etc/hostname 编辑主机名称hostname
- vim /etc/hosts
 
- 文末加
- 127.0.0.1 localhost
- ::1 localhost
- 127.0.1.1 hostname.localdomain hostname
- 设密码:passwd

## 网络

pacman -S networkmanager iw wpa_supplicant dialog dhcpcd netctl 

## 安装启动加载器

- pacman -S efibootmgr  grub os-prober intel-ucode ntfs-3g
- grub-install -–target=x86_64-efi -–efi-directory=/boot –-bootloader-id=grub 
- 生成:grub-mkconfig -o /boot/grub/grub.cfg
 
## 重启:exit

- killall wpa_supplicant dhcpcd
- umount  /mnt/root
- umount  /mnt
- reboot
 
##
 
有线： dhcpcd
 
- wifi-menu 即可
- systemctl enable dhcpcd
- dhcpcd &
`连网可将iwlist换为iw` 
 
## 用户

- pacman -S sudo
- useradd -m -g users -G wheel -s /bin/bash …(name)
- passwd ..(name)
- 修改sudo权限:vim /etc/sudoers

    > ln -s /usr/bin/vim /usr/bin/vi  visudo

`Uncomment to allow members of group wheel to execute any command
 去%wheel前#`
 
## 源 

- vim /etc/pacman.conf 文末：
    
    > [multilib]去#
    
    > /#[custom]变：
    
    > [archlinuxcn]
- 只能加一个
    
```
[archlinuxcn]
# The Chinese Arch Linux communities packages.
# SigLevel = Optional TrustedOnly
SigLevel = Optional TrustAll
# 官方源
Server   = http://repo.archlinuxcn.org/$arch
# 163源
Server = http://mirrors.163.com/archlinux-cn/$arch
# 清华大学
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinuxcn/$arch
```
    
- 安装archlinuxcn-keyring
- pacman -Syu

## 字体:
 
- ttf-dejave ttf-liberation wqy-microhei ttf-wps-fonts
- 本地化:  vim /etc/locale.gen `去#号 zh_CN.UTF-8 UTF-8 `
- locale-gen(生成)
 
## 目录:

- 安装xdg-user-dirs
- 执行xdg-user-dirs-update
## 显卡

- 查看：lspci | grep VGA
- 英特尔：xf86-video-intel
- amd: xf86-video-ati
- 英伟达：nvidia nvidia-settings（非必要不装）

 [更多](https://wiki.archlinux.org/index.php/Xorg#Driver_installation) 

## 声卡

- alsa-utils


## 桌面

- 安装:
 
- xorg xorg-server xorg-xinit
- sddm sddm-kcm
- plasma
- 可选：kde-applications (kde-base)

> if you haven't install app,then a terminal needed(yakuake)
 
- 网络工具:net-tools plasma-nm network-manager-applet
- systemctl disable netctl
- systemctl enable NetworkManager
- systemctl enable sddm
- systemctl start sddm
 
 
## git 

## yay
 
- git clone https://aur.archlinux.org/yay.git
- cd yay
- makepkg -si
- 源：yay --aururl "https://aur.tuna.tsinghua.edu.cn" --save (https://aur.archlinux.org)

- 查看：yay -P -g(位于 ~/.config/yay/config.json) 

yay -Syu

 
## 输入法：安装fcitx
 
- kcm-fcitx

1. fcitx+fcitx-im+fcitx-sunpinyin(fcitx-qt5 fcitx-configtool)
2. 
    - sudo pacman -Rsn fcitx-im fcitx-configtool 
    - fcitx-lilydjwg-git fcitx-sogoupinyin(yay)

- For vim: vim-fcitx (set ttimeoutlen=100)

- vim /etc/profile
 
> 开头输入:

- export XMODIFIERS="@im=fcitx"
- export GTK_IM_MODULE="fcitx"
- export QT_IM_MODULE="fcitx" 



## 触控板 

- yay -S kcm-pointing-devices-git
- sudo pacman -S xf86-input-libinput
- sudo pacman -S xf86-input-synaptics  #触摸板驱动#
 
 
## 蓝牙耳机

- bluez bluez-utils bluez-firmware pulseaudio-bluetooth pavucontrol pulseaudio-alsa
 
``` 
bluez软件包提供蓝牙协议栈
bluez-utils软件包提供bluetoothctl工具
pulseaudio-bluetooth则为bluez提供了PulseAudio音频服务,若没有安装则蓝牙设备在配对完成后,连接会失败,提示
pavucontrol则提供了pulseaudio的图形化控制界面
pulseaudio-alsa(可选)则使pulseaudio和alsa协同使用，之后就可以用alsamixer来管理蓝牙音频
```

- systemctl enable bluetooth
- systemctl start bluetooth
- pulseaudio -k                   # 确保没有pulseaudio启动
- pulseaudio --start              # 启动pulseaudio服务

## 软件
 
- wget curl  exfat-utils p7zip unzip zip unrar

- install deepin-wine firstly.

    > deepin-wine-qq
    > 
    > deepin-wine-wechat
    > 
    > deepin-wine-tim
 
> 办公软件WPS安装软件和缺失字体：

> sudo pacman -S wps-office

> sudo pacman -S ttf-wps-fonts

> 如果你下载了国际版本缺失中文：

> sudo pacman -S wps-office-mui-zh-cn

> 然后右上角切换

   
- baidunetdisk-bin (yay)

- tlp - 电池
 
- chromium  (Chromium 的用户资料在~/.config/chromium/Default)

- qtcreator  ark cmake ctags electron

- flameshot  cheese  vlc  gwenview  gimp
 
- yakuake  ranger
- ark
- woeusb
 
- qv2ray
- electron-ssr

```
- openssh 远程连接工具
- deepin-screenshot  Flameshot 现代、快捷、轻便的截图工具
- SimpleScreenRecorder 轻量的录屏软件
- kdenlive shotcut 强大的视频剪辑软件
- netease-cloud-music 网易云音乐
- sublime-text-dev 代码编辑器
- proxychains-ng 终端内科学上网代理工具
- redshift 显示屏色温调节工具
- telegram-desktop 客户端开源的加密聊天工具
- liferea RSS 阅读器
- qbittorrent 好用的 BT 下载工具
- calibre 电子书转换、编辑、阅读工具
- gthumb 图片浏览工具,可简单编辑图片,可清除照片元数据
- libreoffice-fresh 必备的办公软件
- peek 录制 GIF 动图
- inkscape 强大的矢量图形编辑软件
- fontforge 字体设计、编辑软件
- audacity 简单的音频编辑软件
- kid3 音频元数据编辑软件
- aria2 强大的多线程下载工具
- youtube-dl YouTube 视频下载工具
- baidupcs-go-git 百度网盘下载工具
- ncmdump-go 网易云音乐的 .ncm 格式转换工具
- AppImageLauncher   .appimage文件的启动器 
```

## 系统时间与Windows兼容

```
sudo pacman -S ntpdate
sudo ntpdate time.windows.com
sudo hwclock --localtime --systohc

```

## 代理

#### 1.

- v2ray
- yay -S v2ray
- vim /etc/v2ray/config.json
- systemctl enable v2ray.service
- systemctl start v2ray.service


#### 2. 下载 -v2rayLui-v.zip

- 解压
- 终端进入文件,sudo ./install.sh
- ./v2rayLui
 
#### 3. docker

- docker search –filter=stars=5 v2ray
- docker pull v2ray/offic
- docker pull v2ray/official

## Terminal

- bash-completion
- yay -S zsh
- sudo chsh -s /bin/zsh username
- yay -S oh-my-zsh-git
- cp /usr/share/oh-my-zsh/zshrc ~/.zshrc

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


 
## vim

## deb安装

- yay -S debtap
- 也应该安装bash， binutils ，pkgfile 和 fakeroot 依赖包。
- 创建/更新 pkgfile 和 debtap 数据库。
- sudo debtap -u ..

转换deb包
debtap ***.deb
安装
sudo pacman -U <package-name>



## 美化

- 设置外观 layan
- 窗口管理-任务切换器-主窗口可视化切换
- 安装lattw-dock
  >布局/
- 终端,字体
  

___
 
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
