# Wallpaper Launcher介绍  :mushroom:
当我们使用Wallpaper时，一般都不会在steam上计算时长，因为开机自启动不通过steam启动，当我们想要在创意工坊下载时，Wallpaper才被计算入时长，被真正用``Steam``打开  
所以我开发了一款由Qt6.7编写的Wallpaper Launcher，它开机时自动将Wallpaper使用Steam打开，即使没有打开Steam，它也可以由Steam打开  
这个程序可以解放双手，对于那些不想要SAM作弊器，Steam++等工具破解成就,时长的玩家来说，这个程序可以放心使用，它``不``使用``任何``的``外挂``程序，所以绝``不会``被判定为``作弊``  
# 原理  :earth_asia:
当我们在中国大陆时，想要获取外区游戏需要``输入命令``来直接到达Steam商城页面，比如Apex和一些小黄油，基于这个原理，我测试了``open``,``exe``,``run``这个命令，其中``run``可以通过Steam直接打开软件  
所以你下载源代码时，同样可以改成GTA5 Launcher，CS2 Launcher等等  
# 方法  :question:
## 直接使用 :trollface:
1.使用Qt6.7打开项目(Qt6版本以上均可以，点击打开项目，选CMakeLists.txt)  
2.编译文件，打开并使用Wallpaper Launcher  
##  切换游戏/软件  :rage4:
1.使用Qt6.7打开项目(Qt6版本以上均可以，点击打开项目，选CMakeLists.txt) :heart_eyes_cat:  
2.打开``main.cpp``文件,在最下方找到运行代码字样(一串数字431960) :scream_cat:  
3.在网页打开Steam，找到你的游戏，比如Wallpaper的网页网址:``https://store.steampowered.com/app/431960/Wallpaper_Engine/``  :exclamation:  
4.找到网址中app\之后，\游戏名之前的一串数字  :exclamation:  
5.在代码中更改 :exclamation:  
# 预览代码和UI  

![40873777_image](https://github.com/user-attachments/assets/55eab6e0-a7f1-43f7-97b5-97300d28e22b)

![40941447 699999996_image](https://github.com/user-attachments/assets/daeccb48-92c5-4559-a44c-8bcb56296170)

![image](https://github.com/user-attachments/assets/f2f4e6fe-5a6e-4bfe-8338-dab3a68e8250)

# 鸣谢
### 我炙热的青春时光 :blush:
### 我的大脑和身体器官，熬夜陪伴我写代码 :stuck_out_tongue_winking_eye:
# 条件
### 必须是Qt6及以上的版本，Qt6以下的版本需要修改后使用 :grin:
### Qt6直接编译出来的程序无法在Windows7上使用，需要进一步修改编译 :hushed:
### 保证在启动项中有此程序 :sunglasses:
# 问题
### 在Issues中报告 :blue_heart:
### 在Gmail中报告 :green_heart:
### 在Twitter中报告 :heartpulse:
