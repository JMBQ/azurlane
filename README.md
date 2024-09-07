# Azurlane
I've refactored the code logic to fix the crashing issue <br>

Perseus was crashing for the simple reason that it may try to get luafunc and do a hook before the il2cpp engine is loaded, so I just had to call the corresponding api for il2cpp and wait for it to finish loading before performing those operations. <br>

# How to use
open `com\unity3d\player\UnityPlayerActivity.smali`

`.method protected onCreate(Landroid/os/Bundle;)V` <br>
`    .locals 2` <br>
<br>
Just insert the following code here  <br>
<br>
`const-string v0, "JMBQ"`  <br>
`invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V` <br>
<br>
Actually my library doesn't need context support, if you know which methods will be loaded first after the game starts, you can also load my library in that method with the same effect


# Config
Settings can be found inside JMBQ.ini, located within the game's external files directory (/sdcard/Android/data/{package-name}/files/).

If you're unsure of your region's package name, just look it up. All of them include "AzurLane" though.

Enabling the Skins mod gives you all skins in-game as if you had bought them. They are persistent between restarts.

# Credits
* [Egoistically/Perseus](https://github.com/Egoistically/Perseus)
