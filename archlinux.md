#安装

## 启动

* 镜像u盘 (MD5… PGP…)

> 例:dd bs=4M if=/home/liukanglai/Downloads/archlinux-2020.04.01-x86_64.iso of=/dev/sda status=progress oflag=sync

* u盘启动 UEFI root@archiso~#

* 查看指南:ls 再打开

* 验证启动模式:ls /sys/firmware/efi/efivars 有输出即为UEFI

## 联网

* ip link –看网卡  `enp开头有线网卡 wlp无线网卡` (小技巧；手机usb共享网???)

> 看有无网: 命令 ping www.baidu.com 后显 ….ms 即有网

> enp开头有线网卡 wlp无线网卡 (手机usb共享网???)

### 无线

* ip link set .. up

iwlist .. scan | grep ESSID
wpa_passphrase 网络名 密码 > internet.conf
wpa_supplicant -c internet.conf -i 设备名 &
dhcpcd &

### 有线：systemctl enable dhcpcd

systemctl restart dhcpcd

wifi-menu 此命令垃圾…

如需web登录(Captive Portal): elinks http…

配置
时间同步: timedatectl set-ntp true
手动: timectl set-time “year-month-date h-minute-s”

检查:timedatectl status
安盘
查看硬盘: lsblk或fdisk -l
/dev/… nvme0n(高级)或sda…
新盘不同

分盘: cfdisk 进gpt 分后yes
格式	大小	目录	格式
fat32	300M	EFI	EFI system
ext4		home	linux filesystem()
ext4		/	linux filesystem
swap	linux swap
格式化: mkfs.ext4 /dev/..
mkfs.fat -F32
EFI: mkfs.vfat
交换空间: mkswap -f /…

打开swap:swapon /…

挂载:

/: mount /dev/.. /mnt
mkdir /mnt/boot
mkdir /mnt/boot/EFI
EFI: mount /dev/.. /mnt/boot/EFI
mkdir /mnt/home()
home: mount /dev/.. /mnt/home()

软件源:
vim /etc/pacman.d/mirrorlist
/## 阿里云:Server = https://mirrors.allyun.com/archlinux/$repo/os/$arch

刷新: pacman -syy

安装
pacstrap /mnt base linux linux-firmware vim e2fsprogs base-devel yay

#(netctl iw dialog wpa_supplicant wpa_actiond networkmanager wireless_tools )

进入chroot
生成fstab???

命令: 1.genfstab 2.genfstab -U /mnt >> /mnt/etc/fstab

检查:cat /mnt/etc/fstab

arch-chroot /mnt
基本设置
时区: In -s /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
设置时间标准UTC,并调整时间漂移? hwclock –systohc
本地化: vim /etc/locale.gen 去#号 en_US.UTF-8 UTF-8
locale-gen(生成)
vim /etc/locale.conf

LANG=en_US.UTF-8
LANG=zh_CN.UTF-8

设密码:passwd
vim /mnt/etc/hostname 编辑主机名称
vim /etc/hosts
文末加
127.0.0.1 localhost
::1 localhost

127.0.1.1 hostname.localdomain hostname

网络:pacman -S networkmanager iw wpa_supplicant dialog intel-ucode dhcpcd
安装启动加载器:
pacman -S efibootmgr dosfstoolls grub os-probe
grub-install –target=x86_64-efi –efi-directory=/boot/EFI –bootloader-id=grub –recheck
生成:grub-mkconfig -o /boot/grub/grub.cfg

重启:exit
killall wpa_supplicant dhcpcd
umount -R /mnt
reboot

##

systemctl enable dhcpcd
dhcpcd &

pacman -Syyu

安装bash-completion

systemctl enable NetworkManager

systemctl start NetworkManager

用户
useradd -m -g users -G wheel -s /bin/bash …(name)
passwd ..(name)
修改sudo权限:visudo
Uncomment to allow members of group wheel to execute any command
去%wheel前#

桌面
安装:

xorg xorg-server xorg-xinit
sddm sddm-kcm
plasma
kde-applications-meta (kde-base)
git
systemctl enable sddm

网络工具:net-tools networkmanager plasma-nm
systemctl enable NetworkManager

systemctl start sddm

vim /etc/pacman.conf 文末：
[multilib]去#
/#[custom]变：
[archlinuxcn]
SigLevel = Optional TrustAll
Server = https://mirrors.ustc.edu.cn/archlinuxcn/$arch

字体:

Google Noto Fonts 系列： noto-fonts noto-fonts-cjk noto-fonts-emoji
思源黑体：adobe-source-han-sans-otc-fonts
文泉驿：wqy-microhei wqy-zenhei
本地化: vim /etc/locale.gen 去#号 zh_CN.UTF-8 UTF-8
locale-gen(生成)

目录:
安装xdg-user-dirs
执行xdg-user-dirs-update

输入法：安装fcitx

fcitx-googlepinyin
fcitx-im (各环境下使用)
fcitx-configtool(配置)
vim ~/.xprofile

输入:
export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export XMODIFIERS=@im=fcitx

显卡
查看：lspci | grep VGA
英特尔：xf86-video-vesa
sudo pacman -S xf86-video-intel intel-media-driver vulkan-intel xf86-video-amdgpu xf86-video-ati mesa-vdpau vulkan-radeon
英伟达：nvidia nvidia-settings

声卡
alsa-utils

yay:

git clone https://aur.archlinux.org/yay.git
cd yay
makepkg -si
cd ..

* 触控板 yay -S kcm-pointing-devices-git

软件:

wegt curl ntfs-3g exfat-utils p7zip unzip unrar

deepin.com.qq.office

wewechat

tlp - 电池

chromium

Chromium 的用户资料在~/.config/chromium/Default

gimp

google-chrome Google Chrome 浏览
netease-cloud-music 网易云音乐
sublime-text-dev 代码编辑器
Flameshot 现代、快捷、轻便的截图工具
electron-ssr 好用的科学上网工具
proxychains-ng 终端内科学上网代理工具
redshift 显示屏色温调节工具
vlc 强大的多媒体播放工具
deadbeef 终极音频播放软件
telegram-desktop 客户端开源的加密聊天工具
liferea RSS 阅读器
qbittorrent 好用的 BT 下载工具
calibre 电子书转换、编辑、阅读工具
gthumb 图片浏览工具,可简单编辑图片,可清除照片元数据
libreoffice-fresh 必备的办公软件
peek 录制 GIF 动图
gimp 强大的图片编辑工具
inkscape 强大的矢量图形编辑软件
shotcut 强大的视频剪辑软件
fontforge 字体设计、编辑软件
audacity 简单的音频编辑软件
kid3 音频元数据编辑软件
aria2 强大的多线程下载工具
youtube-dl YouTube 视频下载工具
baidupcs-go-git 百度网盘下载工具
ncmdump-go 网易云音乐的 .ncm 格式转换工具
code Visual Studio Code

代理
v2ray
1.
yay -S v2ray
vim /etc/v2ray/config.json
systemctl enable v2ray.service
systemctl start v2ray.service
桌面setting,代理
2. 下载 -v2rayLui-v.zip
解压
终端进入文件,sudo ./install.sh
./v2rayLui

3. docker
docker search –filter=stars=5 v2ray
docker pull v2ray/offic
docker pull v2ray/official
Terminal
bash-completion
yay -S zsh
sudo chsh -s /bin/zsh username
yay -S oh-my-zsh-git
cp /usr/share/oh-my-zsh/zshrc ~/.zshrc

vim
dock
安装lattw-dock


___

## tags: pacman

```
列出已安装包 -Q
查看包是否安装 -Q name
查看已安装包信息 -Qi name
列出已安装包所有文件 -QI name
查找某个文件属于哪个包 -Qo /…
查询包组 -Sg
查询包组所包含软件包 -Sg name
搜索相关包 -Ss name
从数据库中搜索信息 -Si name
以下 su
仅同步源 -Sy
更新系统 -Su
同步源并更新系统 -Syu
同后安装包 -Sy name
从本地数据库中获取信息并安装 -S name
强制安装 -Sf name
删除 -R name
强制删除被依赖包 -Rd name
删除包及依赖其的包 -Rc name
删除包及其依赖的包 -Rsc name
清理/var/cache/pacman/pkg目录下的旧包 -Sc
清除所有下载的包和数据库 -Scc
安装下载的包（有时候需要降级包的时候就用这个
cd /var/cache/pacman/pkg
-U name-5.2.12-1-x86_64.pkg.tar.xz
升级时不升级包 -Su –ignore name
```

