# memory

    sudo dd if=/dev/zero of=/var/swap.img bs=1024k count=100
    sudo mkswap /var/swap.img
    sudo swapon /var/swap.img
