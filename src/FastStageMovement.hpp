



void mod_fastStageMovement(lua_State *instance, bool flag) {
    lua_State *L = lua_newthread(instance);
    double value = flag ? 0.0 : 0.5;

    luaReplaceAttribute<double>(L, obf("ChapterConst.ShipStepDuration"), value);
    luaReplaceAttribute<double>(L, obf("ChapterConst.ShipStepQuickPlayScale"), value);

    LOGI("ChapterFastStage flag:%s  value:%f", flag ? "true" : "false", value);
}
