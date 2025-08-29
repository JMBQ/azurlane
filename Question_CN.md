## <font color=red size=6> 针对一些常见问题，尝试给出一些回答 </font>
* <font color=gray size=5>我的游戏比较特殊，使用你的打包方案无法出现悬浮窗 </font><br>
    先反编译游戏，在AndroidManifest.xml里查找`<application`<br>
```
<application android:allowBackup="false" android:appComponentFactory="androidx.core.app.CoreComponentFactory" android:extractNativeLibs="true" android:icon="@mipmap/app_icon" android:label="@string/app_name" android:name="com.manjuu.azurlane.App" android:requestLegacyExternalStorage="true" android:resizeableActivity="true" android:supportsPictureInPicture="true" android:supportsRtl="true" android:theme="@style/LauncherAzurlane" android:usesCleartextTraffic="true">
```
如果这一行内容里存在`android:appComponentFactory`，那直接去它指向的路径修改`init`方法。<br>
如果不存在，那直接去`android:name`指向的路径修改`init`方法(根据上方代码内容得知指向的是com/manjuu/azurlane/App.smali)。<br>

`smali_classes4`这个文件夹的命名也需要变通，B服存在3个`smali`文件夹（也就是拥有3个`dex`），所以我命名为3+1=4<br>
4399服存在7个`smali`文件夹，需要将我的文件夹命名为`smali_classes8`，修改后可以避免可能出现的打包错误。<br>其他服同理，如果你看不懂，直接找其他人其他群拿包
<br>
* <font color=gray size=5>运行游戏时没有出现悬浮图标 </font><br>
     在首次运行游戏时，如果游戏没有悬浮权限，会自动打开一个设置窗口(如果没有弹窗则代表打包错误)，你需要同意碧蓝航线的悬浮权限<br>

     
https://github.com/user-attachments/assets/c6169108-c6db-4233-a17d-d925bad2da2c


     <br>
* <font color=gray size=5>悬浮图标太大了，影响到我alas挂机了 </font><br>


https://github.com/user-attachments/assets/304ef842-c457-4543-ad8d-a01389a86a3a


    <br>
* <font color=gray size=5>一直卡在更新界面，无法进入游戏 </font><br>
    可以尝试清空游戏所有数据<br>
    

https://github.com/user-attachments/assets/7dfd7ec6-3424-489b-b7cc-07c9d3776a6d


    <br>
* <font color=gray size=5>在游戏过程中可能会出现卡loading </font><br>
    * 这个不清楚具体原因，可能是游戏自身原因，也可能是注入的lua代码原因，当前无法解决

