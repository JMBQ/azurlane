



extern bool AutoRepeat;


int GetMaxBattleCountHook(lua_State *L){
    lua_getglobal(L, STR("Chapter"));
    lua_getfield(L,-1,STR("old_GetMaxBattleCount"));
    lua_remove(L, -2);
    lua_pushvalue(L,1);
    lua_pcall(L,1,1,0);
    if (AutoRepeat){
        lua_pop(L, 1);
        lua_pushnumber(L,10);
    }
    return 1;
}

void mod_auto_repeat(lua_State *instance) {
    lua_State *L = lua_newthread(instance);
    luaHookFunc(L, obf("Chapter.GetMaxBattleCount"), GetMaxBattleCountHook, obf("old_"));
    LOGI("Repeat AutoRepeat:%s", AutoRepeat ? "true" : "false");
}