# 18级计科卓越班Git代码提交教程

## 新建一个文件夹用于保存本地代码仓库，鼠标右键单击Git Bash Here  

![1.png](https://i.loli.net/2020/11/22/IC5R8riKjv2Es7e.png)

## 克隆我们的远程代码仓库  
```
git clone https://github.com/PredominantClass2018/ZY18LeetCode.git
```

![2.png](https://i.loli.net/2020/11/22/L8ZQ43pfSWXbigr.png)  

可以看到我们当前文件夹内只有一个**.git**文件*(开启隐藏文件可见，才能看到)*和**README.md**文件。  
那是因为我们的**master**分支只有这两个文件。在该位置再次使用`Git Bush Here`  
使用`git branch`命令看到，当前只有一个`master`分支。  

![3.png](https://i.loli.net/2020/11/22/DLgwFzhZH2VYx87.png)

## 关联我们当前需要控制的分支(以Week1分支为例子)
```
git checkout -b Week1 origin/Week1
```
使用`git branch`命令可以看到，我们当前切换到了Week1分支。并且本地代码库中出现了Week1文件夹。  

![4.png](https://i.loli.net/2020/11/22/dwVBCeYPF4LvONs.png)

## 打开Week1文件夹，建立自己的代码文件，命名规则为XX(序号)_XXX(小写姓名拼音首字母).X(代码后缀)。修改后保存退出。  
## 
![5.png](https://i.loli.net/2020/11/22/NZY5vB7emStQask.png)

## 返回`ZY18LeetCode`文件所在目录，鼠标右键单击`Git Bush Here`。
大家提交的时候记得注释，注释记得备注自己的姓名拼写。
```
git add .
git commit -m "修正_sgq"
```

![6.png](https://i.loli.net/2020/11/22/UNTIsYtBk8AH2uW.png)

## 将本地代码部署到远端
大家一定要注意的是，当前分支是Week1那么命令就是
```
git push origin Week1
```
如果当前分支是Week2则命令为
```
git push origin Week2
```

![7.png](https://i.loli.net/2020/11/22/feSb9mQ4Wyi8RKs.png)

## 完成！