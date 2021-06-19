#

- sudo gunzip ***.gz
- chmod +x clash***
- ./clash -d .

- wget (-P /opt/clash/) -O config.yaml [你的订阅链接]
- config.yaml


# shellclash

- source ~/.bashrc &> /dev/null

启动脚本：clash

启动clash服务：$clashdir/start.sh start

停止clash服务：$clashdir/start.sh stop

重启clash服务：$clashdir/start.sh restart

更新订阅文件：$clashdir/start.sh getyaml

# arch

- pacman -S clash / or clash-premium-bin
- run clash
- ~/.config/clash: yaml

- delete: /usr/lib/systemd/system/clash@.service and  /usr/lib/systemd/user/clash@.service

- autostart:https://github.com/Dreamacro/clash/wiki/clash-as-a-daemon

        [Unit]
        Description=Clash daemon, A rule-based proxy in Go.
        After=network.target
        
        [Service]
        Type=simple
        Restart=always
        ExecStart=/usr/local/bin/clash -d /etc/clash // need change
        
        [Install]
        WantedBy=multi-user.target

- Launch clashd on system startup with:
$ systemctl enable clash
- Launch clashd immediately with:
$ systemctl start clash
- Check the health and logs of Clash with:
$ systemctl status clash
$ journalctl -xe

