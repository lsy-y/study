<https://www.liaoxuefeng.com/wiki/896043488029600/896067074338496>

我就是在这个网站学习的git和github，讲的很清楚，很适合什么都不懂的小白

# Git简介



# 远程仓库

第1步：创建SSH Key。
在用户主目录下，看看有没有.ssh目录，

![1582800489341](assets/1582800489341.png)

如果有，再看看这个目录下有没有id_rsa和id_rsa.pub这两个文件，如果已经有了，可直接跳到下一步。如果没有，打开Shell（Windows下打开Git Bash），创建SSH Key：

```
$ ssh-keygen -t rsa -C "youremail@example.com"
```
你需要把邮件地址换成你自己的邮件地址，然后一路回车，使用默认值即可，由于这个Key也不是用于军事目的，所以也无需设置密码。
如果一切顺利的话，可以在用户主目录里找到.ssh目录，里面有id_rsa和id_rsa.pub两个文件，这两个就是SSH Key的秘钥对，id_rsa是私钥，不能泄露出去，id_rsa.pub是公钥，可以放心地告诉任何人。
第2步：登陆GitHub，打开“Account settings”，“SSH Keys”页面：
![1582800023383](assets/1582800023383.png)
然后，点“Add SSH Key”，填上任意Title，在Key文本框里粘贴id_rsa.pub文件的内容：
![1582800230655](assets/1582800230655.png)
在github上新建一个new repository

![1582801015957](assets/1582801015957.png)


## 连接远程仓库
```
$ git remote add gitlab git@xxx.com
例  $ git remote add origin git@github.com:lsy-y/study.git
```
gitlab是远程仓库在本地的名称！
git@xxx.com可以直接从github上复制

如何取消远程仓库连接

```
$ git remote -v           查看现在的连接
```

```
$ git remote rm gitlab     取消链接//gitlab是远程仓库在本地的名称
```
连接成功后,可以直接推上去了
```
$ git push -u origin master
```
