## <font color=red size=6> Attempting to provide answers to some common questions </font>
* <font color=gray size=5>My game is rather unique, and your packaging solution won't enable the floating window. </font><br>
    First, decompile the game and locate the `<application` tag in AndroidManifest.xml.<br>
```
<application android:allowBackup="false" android:appComponentFactory="androidx.core.app.CoreComponentFactory" android:extractNativeLibs="true" android:icon="@mipmap/app_icon" android:label="@string/app_name" android:name="com.manjuu.azurlane.App" android:requestLegacyExternalStorage="true" android:resizeableActivity="true" android:supportsPictureInPicture="true" android:supportsRtl="true" android:theme="@style/LauncherAzurlane" android:usesCleartextTraffic="true">
```
If this line contains `android:appComponentFactory`, go directly to the path it points to and modify the `init` method.<br>
If it doesn't exist, go directly to the path specified by `android:name` and modify the `init` method (based on the code above, this points to `com/manjuu/azurlane/App.smali`).<br>

The naming convention for the `smali_classes4` folder also requires flexibility. The Bili server contains three `smali` folders (meaning it has three `dex` files), so I named it 3+1=4.<br>
The 4399 server contains seven `smali` folders. To avoid potential packaging errors, rename my folder to `smali_classes8`.<br>The same applies to other servers. If you don't understand, just ask others in other groups for the package.
<br><br><br>
* <font color=gray size=5>The floating icon did not appear when running the game. </font><br>
     When launching the game for the first time, if the game lacks overlay permissions, a settings window will automatically open (if no pop-up appears, it indicates a packaging error). You must grant Azur Lane overlay permissions.<br>
     <video src="res/float_permission.mp4" controls></video>
     <br><br><br>
* <font color=gray size=5>The floating icon is too big, affecting my ability to leave the game running in the background. </font><br>
    <video src="res/float_icon_size.mp4" controls></video>
    <br><br><br>
* <font color=gray size=5>It keeps getting stuck on the update screen and won't let me enter the game. </font><br>
    You can try clearing all game data.<br>
    <video src="res/data.mp4" controls></video>
    <br><br><br>
* <font color=gray size=5>The game may experience loading delays during gameplay. </font><br>
    * The exact cause is unclear; it could be due to the game itself or the injected Lua code. This issue cannot be resolved at present.
