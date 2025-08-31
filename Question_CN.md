## <font color=red size=6> 针对一些常见问题，尝试给出一些回答 </font>
* 我的游戏比较特殊，使用你的打包方案无法出现悬浮窗<br>

windows平台使用apkeasytool反编译游戏官方apk（推荐,注意更新apktool插件）

在反编译后的文件夹内找到	
`AndroidManifest.xml`:	
	在文件尾部找到`</application>`，直接替换成以下代码
 ```
	<service android:name="com.android.support.Launcher" android:enabled="true" android:exported="false" android:stopWithTask="true"/>
    </application>
	<uses-permission android:name="android.permission.SYSTEM_ALERT_WINDOW"/>
```
	
`UnityPlayerActivity.smali`：
	位于`com/unity3d/player/`目录内，对所有服生效，对所有安卓版本生效，不可同时修改`CoreComponentFactory.smali`
	打开并找到`<init>`方法
 ```
	.method public constructor <init>()V
    .locals 0   <--这一行无论什么内容都不管，在它的下一行插入以下代码
    invoke-static {}, Lcom/android/support/Main;->Start()V
```

	
先观察游戏存在哪些架构的库，对应的lib放进去就行了，不一定需要全部放入

`smali_classes4`这个文件夹的命名也需要变通，B服存在3个`smali`文件夹（也就是拥有3个`dex`），所以我命名为3+1=4<br>
4399服存在7个`smali`文件夹，需要将我的文件夹命名为`smali_classes8`，修改后可以避免可能出现的打包错误。<br>其他服同理
<br>
* 运行游戏时没有出现悬浮图标<br>
     在首次运行游戏时，如果游戏没有悬浮权限，会自动打开一个设置窗口(如果没有弹窗则代表打包错误)，你需要同意碧蓝航线的悬浮权限<br>

     
https://github.com/user-attachments/assets/c6169108-c6db-4233-a17d-d925bad2da2c



* 悬浮图标太大了，影响到我alas挂机了<br>
2.8将提供悬浮图标记忆位置和自由修改悬浮图标大小


https://github.com/user-attachments/assets/304ef842-c457-4543-ad8d-a01389a86a3a



* 一直卡在更新界面，无法进入游戏<br>
    可以尝试清空游戏所有数据<br>
    

https://github.com/user-attachments/assets/7dfd7ec6-3424-489b-b7cc-07c9d3776a6d



* 在游戏过程中可能会出现卡loading<br>
    这个不清楚具体原因，先关闭`移除状态`，这个功能可能卡loading，可能是游戏自身原因，也可能是注入的lua代码原因，当前无法解决<br><br>
* 我将武器伤害拉满后，有些敌人会将我秒杀<br>
  武器伤害是单独加持在武器上的功能，如果敌方持有武器，就会出现这种情况。可以开启`移除装备`、`移除技能`、`虚弱`来避免<br><br>
* 我将装填时间拉满，但装填速度并没有发生变化<br>
  装填时间越高，你的装填速度就越慢。正确的做法是让装填时间的值越小越好，如果这个值等于0，视为功能关闭<br><br>
* 每次开启游戏都要进行一次功能选择，能不能自动保存之前的选择<br>
  在功能窗口右上角，自己点进去开启<br><br>
* 能不能像其他mod那样增加只对我方生效的倍攻倍防<br>
  mod是基于lua c api来制作的，如果你能提供对应的源码，那就一定能添加



