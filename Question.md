## <font color=red size=6> Attempting to provide answers to some common questions </font>
* My game is rather unique, and your packaging solution won't enable the floating window. <br>
    First, decompile the game and locate the `<application` tag in AndroidManifest.xml.<br>
```
<application android:allowBackup="false" android:appComponentFactory="androidx.core.app.CoreComponentFactory" android:extractNativeLibs="true" android:icon="@mipmap/app_icon" android:label="@string/app_name" android:name="com.manjuu.azurlane.App" android:requestLegacyExternalStorage="true" android:resizeableActivity="true" android:supportsPictureInPicture="true" android:supportsRtl="true" android:theme="@style/LauncherAzurlane" android:usesCleartextTraffic="true">
```
If this line contains `android:appComponentFactory`, go directly to the path it points to and modify the `init` method.<br>
If it doesn't exist, go directly to the path specified by `android:name` and modify the `init` method (based on the code above, this points to `com/manjuu/azurlane/App.smali`).<br>

The naming convention for the `smali_classes4` folder also requires flexibility. The Bili server contains three `smali` folders (meaning it has three `dex` files), so I named it 3+1=4.<br>
The 4399 server contains seven `smali` folders. To avoid potential packaging errors, rename my folder to `smali_classes8`.<br>The same applies to other servers. If you don't understand, just ask others in other groups for the package.
<br><br><br>
* The floating icon did not appear when running the game. <br>
     When launching the game for the first time, if the game lacks overlay permissions, a settings window will automatically open (if no pop-up appears, it indicates a packaging error). You must grant Azur Lane overlay permissions.<br>


     https://github.com/user-attachments/assets/c6169108-c6db-4233-a17d-d925bad2da2c


     <br><br><br>
* The floating icon is too big, affecting my ability to leave the game running in the background. <br>


    https://github.com/user-attachments/assets/304ef842-c457-4543-ad8d-a01389a86a3a

  
    <br><br><br>
* It keeps getting stuck on the update screen and won't let me enter the game.<br>
    You can try clearing all game data. If clearing the data and re-downloading still prevents you from entering the game, you'll need to seek help from others. There are many possible reasons.<br>

    
    https://github.com/user-attachments/assets/7dfd7ec6-3424-489b-b7cc-07c9d3776a6d

  
    <br><br><br>
* <font color=gray size=5>The game may experience loading delays during gameplay. </font><br>
    The exact cause is unclear. First, disable the removal status. This feature may be stuck on loading (scheduled for removal in 2.8). If this doesn't resolve the issue, there is no solution.<br><br>

* After maxing out my weapon damage, some enemies can one-shot me.<br>
  Weapon damage is a function applied exclusively to weapons. This effect occurs when enemies wield weapons. You can enable `Remove Equipment`, `Remove Skills`, or `Weak` to prevent it.<br><br>
* I extended the reload time to its maximum, but the reload speed remained unchanged.<br>
  The higher the reload time, the slower your reload speed becomes. The correct approach is to keep the reload time value as low as possible. If this value equals 0, the function is considered disabled.<br><br>
* Can the previous selection be saved automatically so that I don't have to choose features every time I launch the game?<br>
  In the upper-right corner of the function window, click to enable it yourself.<br><br>
* Can you add multi-attack and multi-defense effects that only affect our side, similar to other mods?<br>
    Mods are created using the Lua C API. If you can provide the corresponding source code, it will definitely be possible to add this feature.<br>



