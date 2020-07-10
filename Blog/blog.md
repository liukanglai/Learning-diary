# install

1. node.js
2. cnpm
3. cnpm install -g hexo-cli


# config

- mkdir blog
- cd
- hexo init
- hexo s
- heso n "..."
 
    > cd 
    >
    > cd ../..

- hexo clean
- hexo g
- hexo d


# push

- github: liukanglai.github.io
- cnpm install --save hexo-deployer-git
- vim \_config.yml

    > 低部:deployment
    >
    > type: git
    >
    > repo: https://github.com/liukanglai/liukanglai.github.io.git
    >
    > branch: 

        ssh-keygen -t rsa -C <Email> # <Email>替换为git配置的用户邮箱
        cat ~/.ssh/id_rsa.pub # 查看public key，复制内容到ithub账户设置页
        ssh -T git@github.com # 测试ssh认证


- hexo d



# themes

- git clone ... themes/...
- vim \_config.yml
- theme: ...(修改)



# write

1. pages

    - post

      > hexo n ...

    - draft

      > hexo new draft ...
      >
      > hexo server --draft
      >

    - normal

      > hexo new page ...
      >
      > http://localhost:4000/.../


        vim _config.yml
        default_layout: ...
