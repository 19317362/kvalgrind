#ifndef __IN_VMI_LINUX_EXT_H__
#define __IN_VMI_LINUX_EXT_H__

/*
 * DO NOT MODIFY. This file is automatically generated by scripts/apigen.py,
 * based on the <plugin>_int.h file in your plugin directory.
 */

#include <dlfcn.h>
#include "panda_plugin.h"

typedef int(*connect_guest_agent_t)(void);
static connect_guest_agent_t __connect_guest_agent = NULL;
static inline int connect_guest_agent(void);
static inline int connect_guest_agent(void){
    assert(__connect_guest_agent);
    return __connect_guest_agent();
}
typedef int64_t(*get_ksymbol_addr_t)(const char *ksymbol);
static get_ksymbol_addr_t __get_ksymbol_addr = NULL;
static inline int64_t get_ksymbol_addr(const char *ksymbol);
static inline int64_t get_ksymbol_addr(const char *ksymbol){
    assert(__get_ksymbol_addr);
    return __get_ksymbol_addr(ksymbol);
}
typedef int64_t(*get_kmod_addr_t)(const char *mod_name);
static get_kmod_addr_t __get_kmod_addr = NULL;
static inline int64_t get_kmod_addr(const char *mod_name);
static inline int64_t get_kmod_addr(const char *mod_name){
    assert(__get_kmod_addr);
    return __get_kmod_addr(mod_name);
}
typedef int64_t(*get_kmod_size_t)(const char *mod_name);
static get_kmod_size_t __get_kmod_size = NULL;
static inline int64_t get_kmod_size(const char *mod_name);
static inline int64_t get_kmod_size(const char *mod_name){
    assert(__get_kmod_size);
    return __get_kmod_size(mod_name);
}
typedef int64_t(*get_word_size_t)(void);
static get_word_size_t __get_word_size = NULL;
static inline int64_t get_word_size(void);
static inline int64_t get_word_size(void){
    assert(__get_word_size);
    return __get_word_size();
}
typedef void(*load_infos_t)(char *ksym, char *kinfo);
static load_infos_t __load_infos = NULL;
static inline void load_infos(char *ksym, char *kinfo);
static inline void load_infos(char *ksym, char *kinfo){
    assert(__load_infos);
    return __load_infos(ksym,kinfo);
}
#define API_PLUGIN_NAME "in_vmi_linux"
#define IMPORT_PPP(module, func_name) { \
 __##func_name = (func_name##_t) dlsym(module, #func_name); \
 char *err = dlerror(); \
 if (err) { \
    printf("Couldn't find %s function in library %s.\n", #func_name, API_PLUGIN_NAME); \
    printf("Error: %s\n", err); \
    return false; \
 } \
}
static inline bool init_in_vmi_linux_api(void);static inline bool init_in_vmi_linux_api(void){
    void *module = panda_get_plugin_by_name("panda_" API_PLUGIN_NAME ".so");
    if (!module) {
        printf("In trying to add plugin, couldn't load %s plugin\n", API_PLUGIN_NAME);
        return false;
    }
    dlerror();
IMPORT_PPP(module, connect_guest_agent)
IMPORT_PPP(module, get_ksymbol_addr)
IMPORT_PPP(module, get_kmod_addr)
IMPORT_PPP(module, get_kmod_size)
IMPORT_PPP(module, get_word_size)
IMPORT_PPP(module, load_infos)
return true;
}

#undef API_PLUGIN_NAME
#undef IMPORT_PPP

#endif
