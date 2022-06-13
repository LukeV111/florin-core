// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#include "NJSIAccountsController.hpp"
using namespace std;

void NJSIAccountsController::setListener(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 1)
    {
        Napi::Error::New(env, "NJSIAccountsController::setListener needs 1 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types
    std::shared_ptr<NJSIAccountsListener> arg_0(std::shared_ptr<NJSIAccountsListener>{}, NJSIAccountsListener::Unwrap(info[0].As<Napi::Object>()));

    try
    {
        IAccountsController::setListener(arg_0);
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return;
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return;
    }
}
Napi::Value NJSIAccountsController::listAccounts(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        Napi::Error::New(env, "NJSIAccountsController::listAccounts needs 0 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types

    try
    {
        auto result = IAccountsController::listAccounts();

        //Wrap result in node object
        auto arg_0 = Napi::Array::New(env);
        for(size_t arg_0_id = 0; arg_0_id < result.size(); arg_0_id++)
        {
            auto arg_0_elem = Napi::Object::New(env);
            auto arg_0_elem_1 = Napi::String::New(env, result[arg_0_id].UUID);
            arg_0_elem.Set("UUID", arg_0_elem_1);
            auto arg_0_elem_2 = Napi::String::New(env, result[arg_0_id].label);
            arg_0_elem.Set("label", arg_0_elem_2);
            auto arg_0_elem_3 = Napi::String::New(env, result[arg_0_id].state);
            arg_0_elem.Set("state", arg_0_elem_3);
            auto arg_0_elem_4 = Napi::String::New(env, result[arg_0_id].type);
            arg_0_elem.Set("type", arg_0_elem_4);
            auto arg_0_elem_5 = Napi::Value::From(env, result[arg_0_id].isHD);
            arg_0_elem.Set("isHD", arg_0_elem_5);
            auto arg_0_elem_6 = Napi::Array::New(env);
            for(size_t arg_0_elem_6_id = 0; arg_0_elem_6_id < result[arg_0_id].accountLinks.size(); arg_0_elem_6_id++)
            {
                auto arg_0_elem_6_elem = Napi::String::New(env, result[arg_0_id].accountLinks[arg_0_elem_6_id]);
                arg_0_elem_6.Set((int)arg_0_elem_6_id,arg_0_elem_6_elem);
            }

            arg_0_elem.Set("accountLinks", arg_0_elem_6);

            arg_0.Set((int)arg_0_id,arg_0_elem);
        }


        return arg_0;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::setActiveAccount(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 1)
    {
        Napi::Error::New(env, "NJSIAccountsController::setActiveAccount needs 1 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types
    std::string arg_0 = info[0].As<Napi::String>();

    try
    {
        auto result = IAccountsController::setActiveAccount(arg_0);

        //Wrap result in node object
        auto arg_1 = Napi::Value::From(env, result);

        return arg_1;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::getActiveAccount(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        Napi::Error::New(env, "NJSIAccountsController::getActiveAccount needs 0 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types

    try
    {
        auto result = IAccountsController::getActiveAccount();

        //Wrap result in node object
        auto arg_0 = Napi::String::New(env, result);

        return arg_0;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::createAccount(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 2)
    {
        Napi::Error::New(env, "NJSIAccountsController::createAccount needs 2 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types
    std::string arg_0 = info[0].As<Napi::String>();
    std::string arg_1 = info[1].As<Napi::String>();

    try
    {
        auto result = IAccountsController::createAccount(arg_0,arg_1);

        //Wrap result in node object
        auto arg_2 = Napi::String::New(env, result);

        return arg_2;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::getAccountName(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 1)
    {
        Napi::Error::New(env, "NJSIAccountsController::getAccountName needs 1 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types
    std::string arg_0 = info[0].As<Napi::String>();

    try
    {
        auto result = IAccountsController::getAccountName(arg_0);

        //Wrap result in node object
        auto arg_1 = Napi::String::New(env, result);

        return arg_1;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::renameAccount(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 2)
    {
        Napi::Error::New(env, "NJSIAccountsController::renameAccount needs 2 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types
    std::string arg_0 = info[0].As<Napi::String>();
    std::string arg_1 = info[1].As<Napi::String>();

    try
    {
        auto result = IAccountsController::renameAccount(arg_0,arg_1);

        //Wrap result in node object
        auto arg_2 = Napi::Value::From(env, result);

        return arg_2;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::deleteAccount(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 1)
    {
        Napi::Error::New(env, "NJSIAccountsController::deleteAccount needs 1 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types
    std::string arg_0 = info[0].As<Napi::String>();

    try
    {
        auto result = IAccountsController::deleteAccount(arg_0);

        //Wrap result in node object
        auto arg_1 = Napi::Value::From(env, result);

        return arg_1;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::purgeAccount(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 1)
    {
        Napi::Error::New(env, "NJSIAccountsController::purgeAccount needs 1 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types
    std::string arg_0 = info[0].As<Napi::String>();

    try
    {
        auto result = IAccountsController::purgeAccount(arg_0);

        //Wrap result in node object
        auto arg_1 = Napi::Value::From(env, result);

        return arg_1;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::getAccountLinkURI(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 1)
    {
        Napi::Error::New(env, "NJSIAccountsController::getAccountLinkURI needs 1 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types
    std::string arg_0 = info[0].As<Napi::String>();

    try
    {
        auto result = IAccountsController::getAccountLinkURI(arg_0);

        //Wrap result in node object
        auto arg_1 = Napi::String::New(env, result);

        return arg_1;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::getWitnessKeyURI(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 1)
    {
        Napi::Error::New(env, "NJSIAccountsController::getWitnessKeyURI needs 1 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types
    std::string arg_0 = info[0].As<Napi::String>();

    try
    {
        auto result = IAccountsController::getWitnessKeyURI(arg_0);

        //Wrap result in node object
        auto arg_1 = Napi::String::New(env, result);

        return arg_1;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::createAccountFromWitnessKeyURI(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 2)
    {
        Napi::Error::New(env, "NJSIAccountsController::createAccountFromWitnessKeyURI needs 2 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types
    std::string arg_0 = info[0].As<Napi::String>();
    std::string arg_1 = info[1].As<Napi::String>();

    try
    {
        auto result = IAccountsController::createAccountFromWitnessKeyURI(arg_0,arg_1);

        //Wrap result in node object
        auto arg_2 = Napi::String::New(env, result);

        return arg_2;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::getReceiveAddress(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 1)
    {
        Napi::Error::New(env, "NJSIAccountsController::getReceiveAddress needs 1 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types
    std::string arg_0 = info[0].As<Napi::String>();

    try
    {
        auto result = IAccountsController::getReceiveAddress(arg_0);

        //Wrap result in node object
        auto arg_1 = Napi::String::New(env, result);

        return arg_1;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::getTransactionHistory(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 1)
    {
        Napi::Error::New(env, "NJSIAccountsController::getTransactionHistory needs 1 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types
    std::string arg_0 = info[0].As<Napi::String>();

    try
    {
        auto result = IAccountsController::getTransactionHistory(arg_0);

        //Wrap result in node object
        auto arg_1 = Napi::Array::New(env);
        for(size_t arg_1_id = 0; arg_1_id < result.size(); arg_1_id++)
        {
            auto arg_1_elem = Napi::Object::New(env);
            auto arg_1_elem_1 = Napi::String::New(env, result[arg_1_id].txHash);
            arg_1_elem.Set("txHash", arg_1_elem_1);
            auto arg_1_elem_2 = Napi::Value::From(env, result[arg_1_id].timeStamp);
            arg_1_elem.Set("timeStamp", arg_1_elem_2);
            auto arg_1_elem_3 = Napi::Value::From(env, result[arg_1_id].amount);
            arg_1_elem.Set("amount", arg_1_elem_3);
            auto arg_1_elem_4 = Napi::Value::From(env, result[arg_1_id].fee);
            arg_1_elem.Set("fee", arg_1_elem_4);
            auto arg_1_elem_5 = Napi::Value::From(env, (int)result[arg_1_id].status);
            arg_1_elem.Set("status", arg_1_elem_5);
            auto arg_1_elem_6 = Napi::Value::From(env, result[arg_1_id].height);
            arg_1_elem.Set("height", arg_1_elem_6);
            auto arg_1_elem_7 = Napi::Value::From(env, result[arg_1_id].blockTime);
            arg_1_elem.Set("blockTime", arg_1_elem_7);
            auto arg_1_elem_8 = Napi::Value::From(env, result[arg_1_id].depth);
            arg_1_elem.Set("depth", arg_1_elem_8);
            auto arg_1_elem_9 = Napi::Array::New(env);
            for(size_t arg_1_elem_9_id = 0; arg_1_elem_9_id < result[arg_1_id].inputs.size(); arg_1_elem_9_id++)
            {
                auto arg_1_elem_9_elem = Napi::Object::New(env);
                auto arg_1_elem_9_elem_1 = Napi::String::New(env, result[arg_1_id].inputs[arg_1_elem_9_id].address);
                arg_1_elem_9_elem.Set("address", arg_1_elem_9_elem_1);
                auto arg_1_elem_9_elem_2 = Napi::String::New(env, result[arg_1_id].inputs[arg_1_elem_9_id].label);
                arg_1_elem_9_elem.Set("label", arg_1_elem_9_elem_2);
                auto arg_1_elem_9_elem_3 = Napi::String::New(env, result[arg_1_id].inputs[arg_1_elem_9_id].desc);
                arg_1_elem_9_elem.Set("desc", arg_1_elem_9_elem_3);
                auto arg_1_elem_9_elem_4 = Napi::Value::From(env, result[arg_1_id].inputs[arg_1_elem_9_id].isMine);
                arg_1_elem_9_elem.Set("isMine", arg_1_elem_9_elem_4);

                arg_1_elem_9.Set((int)arg_1_elem_9_id,arg_1_elem_9_elem);
            }

            arg_1_elem.Set("inputs", arg_1_elem_9);
            auto arg_1_elem_10 = Napi::Array::New(env);
            for(size_t arg_1_elem_10_id = 0; arg_1_elem_10_id < result[arg_1_id].outputs.size(); arg_1_elem_10_id++)
            {
                auto arg_1_elem_10_elem = Napi::Object::New(env);
                auto arg_1_elem_10_elem_1 = Napi::Value::From(env, result[arg_1_id].outputs[arg_1_elem_10_id].amount);
                arg_1_elem_10_elem.Set("amount", arg_1_elem_10_elem_1);
                auto arg_1_elem_10_elem_2 = Napi::String::New(env, result[arg_1_id].outputs[arg_1_elem_10_id].address);
                arg_1_elem_10_elem.Set("address", arg_1_elem_10_elem_2);
                auto arg_1_elem_10_elem_3 = Napi::String::New(env, result[arg_1_id].outputs[arg_1_elem_10_id].label);
                arg_1_elem_10_elem.Set("label", arg_1_elem_10_elem_3);
                auto arg_1_elem_10_elem_4 = Napi::String::New(env, result[arg_1_id].outputs[arg_1_elem_10_id].desc);
                arg_1_elem_10_elem.Set("desc", arg_1_elem_10_elem_4);
                auto arg_1_elem_10_elem_5 = Napi::Value::From(env, result[arg_1_id].outputs[arg_1_elem_10_id].isMine);
                arg_1_elem_10_elem.Set("isMine", arg_1_elem_10_elem_5);

                arg_1_elem_10.Set((int)arg_1_elem_10_id,arg_1_elem_10_elem);
            }

            arg_1_elem.Set("outputs", arg_1_elem_10);

            arg_1.Set((int)arg_1_id,arg_1_elem);
        }


        return arg_1;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::getMutationHistory(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 1)
    {
        Napi::Error::New(env, "NJSIAccountsController::getMutationHistory needs 1 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types
    std::string arg_0 = info[0].As<Napi::String>();

    try
    {
        auto result = IAccountsController::getMutationHistory(arg_0);

        //Wrap result in node object
        auto arg_1 = Napi::Array::New(env);
        for(size_t arg_1_id = 0; arg_1_id < result.size(); arg_1_id++)
        {
            auto arg_1_elem = Napi::Object::New(env);
            auto arg_1_elem_1 = Napi::Value::From(env, result[arg_1_id].change);
            arg_1_elem.Set("change", arg_1_elem_1);
            auto arg_1_elem_2 = Napi::Value::From(env, result[arg_1_id].timestamp);
            arg_1_elem.Set("timestamp", arg_1_elem_2);
            auto arg_1_elem_3 = Napi::String::New(env, result[arg_1_id].txHash);
            arg_1_elem.Set("txHash", arg_1_elem_3);
            auto arg_1_elem_4 = Napi::String::New(env, result[arg_1_id].recipient_addresses);
            arg_1_elem.Set("recipient_addresses", arg_1_elem_4);
            auto arg_1_elem_5 = Napi::Value::From(env, (int)result[arg_1_id].status);
            arg_1_elem.Set("status", arg_1_elem_5);
            auto arg_1_elem_6 = Napi::Value::From(env, result[arg_1_id].depth);
            arg_1_elem.Set("depth", arg_1_elem_6);

            arg_1.Set((int)arg_1_id,arg_1_elem);
        }


        return arg_1;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::getActiveAccountBalance(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        Napi::Error::New(env, "NJSIAccountsController::getActiveAccountBalance needs 0 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types

    try
    {
        auto result = IAccountsController::getActiveAccountBalance();

        //Wrap result in node object
        auto arg_0 = Napi::Object::New(env);
        auto arg_0_1 = Napi::Value::From(env, result.availableIncludingLocked);
        arg_0.Set("availableIncludingLocked", arg_0_1);
        auto arg_0_2 = Napi::Value::From(env, result.availableExcludingLocked);
        arg_0.Set("availableExcludingLocked", arg_0_2);
        auto arg_0_3 = Napi::Value::From(env, result.availableLocked);
        arg_0.Set("availableLocked", arg_0_3);
        auto arg_0_4 = Napi::Value::From(env, result.unconfirmedIncludingLocked);
        arg_0.Set("unconfirmedIncludingLocked", arg_0_4);
        auto arg_0_5 = Napi::Value::From(env, result.unconfirmedExcludingLocked);
        arg_0.Set("unconfirmedExcludingLocked", arg_0_5);
        auto arg_0_6 = Napi::Value::From(env, result.unconfirmedLocked);
        arg_0.Set("unconfirmedLocked", arg_0_6);
        auto arg_0_7 = Napi::Value::From(env, result.immatureIncludingLocked);
        arg_0.Set("immatureIncludingLocked", arg_0_7);
        auto arg_0_8 = Napi::Value::From(env, result.immatureExcludingLocked);
        arg_0.Set("immatureExcludingLocked", arg_0_8);
        auto arg_0_9 = Napi::Value::From(env, result.immatureLocked);
        arg_0.Set("immatureLocked", arg_0_9);
        auto arg_0_10 = Napi::Value::From(env, result.totalLocked);
        arg_0.Set("totalLocked", arg_0_10);


        return arg_0;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::getAccountBalance(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 1)
    {
        Napi::Error::New(env, "NJSIAccountsController::getAccountBalance needs 1 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types
    std::string arg_0 = info[0].As<Napi::String>();

    try
    {
        auto result = IAccountsController::getAccountBalance(arg_0);

        //Wrap result in node object
        auto arg_1 = Napi::Object::New(env);
        auto arg_1_1 = Napi::Value::From(env, result.availableIncludingLocked);
        arg_1.Set("availableIncludingLocked", arg_1_1);
        auto arg_1_2 = Napi::Value::From(env, result.availableExcludingLocked);
        arg_1.Set("availableExcludingLocked", arg_1_2);
        auto arg_1_3 = Napi::Value::From(env, result.availableLocked);
        arg_1.Set("availableLocked", arg_1_3);
        auto arg_1_4 = Napi::Value::From(env, result.unconfirmedIncludingLocked);
        arg_1.Set("unconfirmedIncludingLocked", arg_1_4);
        auto arg_1_5 = Napi::Value::From(env, result.unconfirmedExcludingLocked);
        arg_1.Set("unconfirmedExcludingLocked", arg_1_5);
        auto arg_1_6 = Napi::Value::From(env, result.unconfirmedLocked);
        arg_1.Set("unconfirmedLocked", arg_1_6);
        auto arg_1_7 = Napi::Value::From(env, result.immatureIncludingLocked);
        arg_1.Set("immatureIncludingLocked", arg_1_7);
        auto arg_1_8 = Napi::Value::From(env, result.immatureExcludingLocked);
        arg_1.Set("immatureExcludingLocked", arg_1_8);
        auto arg_1_9 = Napi::Value::From(env, result.immatureLocked);
        arg_1.Set("immatureLocked", arg_1_9);
        auto arg_1_10 = Napi::Value::From(env, result.totalLocked);
        arg_1.Set("totalLocked", arg_1_10);


        return arg_1;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::getAllAccountBalances(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        Napi::Error::New(env, "NJSIAccountsController::getAllAccountBalances needs 0 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types

    try
    {
        auto result = IAccountsController::getAllAccountBalances();

        //Wrap result in node object
        auto arg_0 = Napi::Object::New(env);
        for(auto const& arg_0_elem : result)
        {
            auto arg_0_first = Napi::String::New(env, arg_0_elem.first);
            auto arg_0_second = Napi::Object::New(env);
            auto arg_0_second_1 = Napi::Value::From(env, arg_0_elem.second.availableIncludingLocked);
            arg_0_second.Set("availableIncludingLocked", arg_0_second_1);
            auto arg_0_second_2 = Napi::Value::From(env, arg_0_elem.second.availableExcludingLocked);
            arg_0_second.Set("availableExcludingLocked", arg_0_second_2);
            auto arg_0_second_3 = Napi::Value::From(env, arg_0_elem.second.availableLocked);
            arg_0_second.Set("availableLocked", arg_0_second_3);
            auto arg_0_second_4 = Napi::Value::From(env, arg_0_elem.second.unconfirmedIncludingLocked);
            arg_0_second.Set("unconfirmedIncludingLocked", arg_0_second_4);
            auto arg_0_second_5 = Napi::Value::From(env, arg_0_elem.second.unconfirmedExcludingLocked);
            arg_0_second.Set("unconfirmedExcludingLocked", arg_0_second_5);
            auto arg_0_second_6 = Napi::Value::From(env, arg_0_elem.second.unconfirmedLocked);
            arg_0_second.Set("unconfirmedLocked", arg_0_second_6);
            auto arg_0_second_7 = Napi::Value::From(env, arg_0_elem.second.immatureIncludingLocked);
            arg_0_second.Set("immatureIncludingLocked", arg_0_second_7);
            auto arg_0_second_8 = Napi::Value::From(env, arg_0_elem.second.immatureExcludingLocked);
            arg_0_second.Set("immatureExcludingLocked", arg_0_second_8);
            auto arg_0_second_9 = Napi::Value::From(env, arg_0_elem.second.immatureLocked);
            arg_0_second.Set("immatureLocked", arg_0_second_9);
            auto arg_0_second_10 = Napi::Value::From(env, arg_0_elem.second.totalLocked);
            arg_0_second.Set("totalLocked", arg_0_second_10);

            arg_0.Set(arg_0_first, arg_0_second);
        }


        return arg_0;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::addAccountLink(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 2)
    {
        Napi::Error::New(env, "NJSIAccountsController::addAccountLink needs 2 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types
    std::string arg_0 = info[0].As<Napi::String>();
    std::string arg_1 = info[1].As<Napi::String>();

    try
    {
        auto result = IAccountsController::addAccountLink(arg_0,arg_1);

        //Wrap result in node object
        auto arg_2 = Napi::Value::From(env, result);

        return arg_2;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::removeAccountLink(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 2)
    {
        Napi::Error::New(env, "NJSIAccountsController::removeAccountLink needs 2 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types
    std::string arg_0 = info[0].As<Napi::String>();
    std::string arg_1 = info[1].As<Napi::String>();

    try
    {
        auto result = IAccountsController::removeAccountLink(arg_0,arg_1);

        //Wrap result in node object
        auto arg_2 = Napi::Value::From(env, result);

        return arg_2;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}
Napi::Value NJSIAccountsController::listAccountLinks(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();


    //Check if method called with right number of arguments
    if(info.Length() != 1)
    {
        Napi::Error::New(env, "NJSIAccountsController::listAccountLinks needs 1 arguments").ThrowAsJavaScriptException();
    }

    //Check if parameters have correct types
    std::string arg_0 = info[0].As<Napi::String>();

    try
    {
        auto result = IAccountsController::listAccountLinks(arg_0);

        //Wrap result in node object
        auto arg_1 = Napi::Array::New(env);
        for(size_t arg_1_id = 0; arg_1_id < result.size(); arg_1_id++)
        {
            auto arg_1_elem = Napi::String::New(env, result[arg_1_id]);
            arg_1.Set((int)arg_1_id,arg_1_elem);
        }


        return arg_1;
    }
    catch (std::exception& e)
    {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    catch (...)
    {
        Napi::Error::New(env, "core exception thrown").ThrowAsJavaScriptException();
        return Napi::Value();
    }
}

Napi::FunctionReference NJSIAccountsController::constructor;

Napi::Object NJSIAccountsController::Init(Napi::Env env, Napi::Object exports) {

    // Hook all method callbacks
    Napi::Function func = DefineClass(env, "NJSIAccountsController", {
    InstanceMethod("setListener", &NJSIAccountsController::setListener),
    InstanceMethod("listAccounts", &NJSIAccountsController::listAccounts),
    InstanceMethod("setActiveAccount", &NJSIAccountsController::setActiveAccount),
    InstanceMethod("getActiveAccount", &NJSIAccountsController::getActiveAccount),
    InstanceMethod("createAccount", &NJSIAccountsController::createAccount),
    InstanceMethod("getAccountName", &NJSIAccountsController::getAccountName),
    InstanceMethod("renameAccount", &NJSIAccountsController::renameAccount),
    InstanceMethod("deleteAccount", &NJSIAccountsController::deleteAccount),
    InstanceMethod("purgeAccount", &NJSIAccountsController::purgeAccount),
    InstanceMethod("getAccountLinkURI", &NJSIAccountsController::getAccountLinkURI),
    InstanceMethod("getWitnessKeyURI", &NJSIAccountsController::getWitnessKeyURI),
    InstanceMethod("createAccountFromWitnessKeyURI", &NJSIAccountsController::createAccountFromWitnessKeyURI),
    InstanceMethod("getReceiveAddress", &NJSIAccountsController::getReceiveAddress),
    InstanceMethod("getTransactionHistory", &NJSIAccountsController::getTransactionHistory),
    InstanceMethod("getMutationHistory", &NJSIAccountsController::getMutationHistory),
    InstanceMethod("getActiveAccountBalance", &NJSIAccountsController::getActiveAccountBalance),
    InstanceMethod("getAccountBalance", &NJSIAccountsController::getAccountBalance),
    InstanceMethod("getAllAccountBalances", &NJSIAccountsController::getAllAccountBalances),
    InstanceMethod("addAccountLink", &NJSIAccountsController::addAccountLink),
    InstanceMethod("removeAccountLink", &NJSIAccountsController::removeAccountLink),
    InstanceMethod("listAccountLinks", &NJSIAccountsController::listAccountLinks),
    });
    // Create a peristent reference to the class constructor. This will allow a function called on a class prototype and a function called on instance of a class to be distinguished from each other.
    constructor = Napi::Persistent(func);
    // Call the SuppressDestruct() method on the static data prevent the calling to this destructor to reset the reference when the environment is no longer available.
    constructor.SuppressDestruct();
    exports.Set("NJSIAccountsController", func);
    return exports;
}
