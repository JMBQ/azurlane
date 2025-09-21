



int hookBMWABSetActive(lua_State *L) {
    // get old SetActive function and call it with the same arguments, but with
    // arg2 set to false instead, such that battleship bullet time is not activated
    lua_getglobal(L, STR("ys"));
    lua_getfield(L, -1, STR("Battle"));
    lua_remove(L, -2);
    lua_getfield(L, -1, STR("BattleManualWeaponAutoBot"));
    lua_remove(L, -2);
    lua_getfield(L, -1, STR("old_SetActive"));
    lua_remove(L, -2);
    lua_pushvalue(L, 1);
    lua_pushvalue(L, 2);
    if (RemoveBBAnimation) {
        lua_pushboolean(L, 0);
    } else {
        lua_pushvalue(L, 3);
    }
    lua_pcall(L, 3, 0, 0);

    return 0;
}

void mod_BBanimation(lua_State *instance) {
    lua_State *L = lua_newthread(instance);
    luaHookFunc(L, obf("ys.Battle.BattleManualWeaponAutoBot.SetActive"),
                hookBMWABSetActive, obf("old_"));
    LOGI("mod_BBanimation");
}