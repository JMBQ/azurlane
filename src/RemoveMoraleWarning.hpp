


int cosumeEnergyHook(lua_State *L){
    lua_getglobal(L, STR("Ship"));
    lua_getfield(L,-1,STR("old_cosumeEnergy"));
    lua_remove(L, -2);
    lua_pushvalue(L,1);
    if (RemoveEnergy){
        lua_pushnumber(L, 0);
    } else {
        lua_pushvalue(L, 2);
    }
    lua_pcall(L,2,0,0);

    return 0;
}


int getEnergyHook(lua_State *L){
    lua_getglobal(L, STR("Ship"));
    lua_getfield(L,-1,STR("old_getEnergy"));
    lua_remove(L, -2);
    lua_pushvalue(L,1);
    lua_pcall(L,1,1,0);
    if (RemoveEnergy){
        lua_pop(L, 1);
        lua_pushnumber(L, 150);
    }
    return 1;
}


void mod_energy(lua_State *instance) {
    lua_State *L = lua_newthread(instance);
    luaHookFunc(L, obf("Ship.cosumeEnergy"), cosumeEnergyHook, obf("old_"));
    luaHookFunc(L, obf("Ship.getEnergy"), getEnergyHook, obf("old_"));
    LOGI("mod_energy");
}
