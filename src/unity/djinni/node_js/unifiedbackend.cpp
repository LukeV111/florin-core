// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni

#include <napi.h>

#include "NJSILibraryController.hpp"
#include "NJSIWalletController.hpp"
#include "NJSIWalletListener.hpp"
#include "NJSMonitorListener.hpp"
#include "NJSILibraryListener.hpp"
#include "NJSIRpcController.hpp"
#include "NJSIRpcListener.hpp"
#include "NJSIP2pNetworkController.hpp"
#include "NJSIP2pNetworkListener.hpp"
#include "NJSIAccountsController.hpp"
#include "NJSIAccountsListener.hpp"
#include "NJSIGenerationController.hpp"
#include "NJSIGenerationListener.hpp"


Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
    NJSILibraryController::Init(env, exports);
    NJSIWalletController::Init(env, exports);
    NJSIWalletListener::Init(env, exports);
    NJSMonitorListener::Init(env, exports);
    NJSILibraryListener::Init(env, exports);
    NJSIRpcController::Init(env, exports);
    NJSIRpcListener::Init(env, exports);
    NJSIP2pNetworkController::Init(env, exports);
    NJSIP2pNetworkListener::Init(env, exports);
    NJSIAccountsController::Init(env, exports);
    NJSIAccountsListener::Init(env, exports);
    NJSIGenerationController::Init(env, exports);
    NJSIGenerationListener::Init(env, exports);
    return exports;
}
NODE_API_MODULE(unifiedbackend,InitAll);
