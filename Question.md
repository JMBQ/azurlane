## <font color=red size=6> Attempting to provide answers to some common questions </font>
* My game is rather unique, and your packaging solution won't enable the floating window. <br>
 
Assuming you have read Readme_EN.txt, The naming convention for the `smali_classes4` folder also requires flexibility. The Bili server contains three `smali` folders (meaning it has three `dex` files), so I named it 3+1=4.<br>
The 4399 server contains seven `smali` folders. To avoid potential packaging errors, rename my folder to `smali_classes8`.<br>The same applies to other servers. If you don't understand, just ask others in other groups for the package.
<br><br><br>
* The floating icon did not appear when running the game. <br>
     When launching the game for the first time, if the game lacks overlay permissions, a settings window will automatically open (if no pop-up appears, it indicates a packaging error). You must grant Azur Lane overlay permissions.<br>


     https://github.com/user-attachments/assets/c6169108-c6db-4233-a17d-d925bad2da2c


     <br><br><br>
* The floating icon is too big, affecting my ability to leave the game running in the background. <br>
    2.8 Provides floating icon position memory and allows free modification of floating icon size<br>

* It keeps getting stuck on the update screen and won't let me enter the game.<br>
    You can try clearing all game data. If clearing the data and re-downloading still prevents you from entering the game, you'll need to seek help from others. There are many possible reasons.<br>

    
    https://github.com/user-attachments/assets/7dfd7ec6-3424-489b-b7cc-07c9d3776a6d

  
    <br><br><br>
* <font color=gray size=5>The game may experience loading delays during gameplay. </font><br>
    The exact cause is unclear. First, disable the `removebuffs`. This feature may be stuck on loading (scheduled for removal in 2.8). If this doesn't resolve the issue, there is no solution.<br><br>

* After maxing out my weapon damage, some enemies can one-shot me.<br>
  2.8 Optimized.<br><br>
* I extended the reload time to its maximum, but the reload speed remained unchanged.<br>
  2.8 Optimized.<br><br>
* Can the previous selection be saved automatically so that I don't have to choose features every time I launch the game?<br>
  In the upper-right corner of the function window, click to enable it yourself.<br><br>
* Can you add the XXXXX feature like other mods do?<br>
    Mods are created using the Lua C API. If you can provide the corresponding source code, it will definitely be possible to add this feature.<br>




