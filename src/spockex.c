#include <stdio.h>

#include "erl_nif.h"
#include "vulkan.h"

static ERL_NIF_TERM
info(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {

  VkApplicationInfo appInfo = {VK_NULL_HANDLE};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "name";
  appInfo.pEngineName = "name";
  appInfo.apiVersion = VK_MAKE_VERSION(1, 0 ,2);

  VkInstanceCreateInfo instanceCreateInfo = {VK_NULL_HANDLE};
  instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  instanceCreateInfo.pNext = VK_NULL_HANDLE;
  instanceCreateInfo.pApplicationInfo = &appInfo;

  VkInstance instance;
  VkResult result = vkCreateInstance(&instanceCreateInfo, VK_NULL_HANDLE, &instance);

  char result_code[15];
  sprintf(result_code, "%d", result);
  return enif_make_atom(env, result_code);
}

static ErlNifFunc funcs[] = {
  // erlang/elixir name, arity, pointer to native function, flags (see erlang documents for ErlNifFunc struct)
  { "info", 0, info, 0 }
};

static int
load(ErlNifEnv* env, void** priv, ERL_NIF_TERM info) {
  return 0;
}

static int
reload(ErlNifEnv* env, void** priv, ERL_NIF_TERM info) {
  return 0;
}

static int
upgrade(ErlNifEnv* env, void** priv, void** old_priv, ERL_NIF_TERM info) {
  return load(env, priv, info);
}

static void
unload(ErlNifEnv* env, void* priv) {
}

ERL_NIF_INIT(Elixir.Spockex, funcs, &load, &reload, &upgrade, &unload)
