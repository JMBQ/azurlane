

#include <map>


int get_reload(const std::map<int, int> &list, int key) {
    auto it = list.find(key);
    if (it != list.end()) {
        return it->second;
    } else {
        return 1000;  // Return 1000 if key is not found
    }
}


void mod_weapons(lua_State *instance, int ratio = 1) {
    struct timespec old{}, now{};
    static bool init = false;
    static std::map<int, int> weapon_list;
    
    clock_gettime(CLOCK_MONOTONIC, &old);

    lua_State *L = lua_newthread(instance);
    lua_getglobal(L, STR("pg"));
    lua_getfield(L, -1, STR("weapon_property"));
    std::vector<int> weapons = getTableIds(L);

    for (int weaponId: weapons) {
        lua_pushnumber(L, weaponId);
        lua_gettable(L, -2);
        if (!init) {
            lua_getfield(L, -1, STR("reload_max"));
            int reloadMax = (int) lua_tonumber(L, -1);
            weapon_list.insert(std::make_pair(weaponId, reloadMax));
            lua_pop(L, 1);
        }

        int value = get_reload(weapon_list, weaponId);

        if (ratio > 1) {
            int value1 = (int) (value / ratio);
            if (value1 == 0) {
                value1 = 1;
            }
            replaceAttributeN(L, STR("reload_max"), value1);
        } else {
            replaceAttributeN(L, STR("reload_max"), value);
        }

        lua_pop(L, 1);
    }
    init = true;

    lua_pop(L, 2);

    clock_gettime(CLOCK_MONOTONIC, &now);
    LOGI("Weapons: %ld ms ratio:%d",
         (now.tv_sec - old.tv_sec) * 1000 + (now.tv_nsec - old.tv_nsec) / 1000000, ratio);
}