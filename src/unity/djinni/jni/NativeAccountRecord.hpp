// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#pragma once

#include "account_record.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class NativeAccountRecord final {
public:
    using CppType = ::AccountRecord;
    using JniType = jobject;

    using Boxed = NativeAccountRecord;

    ~NativeAccountRecord();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeAccountRecord();
    friend ::djinni::JniClass<NativeAccountRecord>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/florin/jniunifiedbackend/AccountRecord") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;ZLjava/util/ArrayList;)V") };
    const jfieldID field_mUUID { ::djinni::jniGetFieldID(clazz.get(), "mUUID", "Ljava/lang/String;") };
    const jfieldID field_mLabel { ::djinni::jniGetFieldID(clazz.get(), "mLabel", "Ljava/lang/String;") };
    const jfieldID field_mState { ::djinni::jniGetFieldID(clazz.get(), "mState", "Ljava/lang/String;") };
    const jfieldID field_mType { ::djinni::jniGetFieldID(clazz.get(), "mType", "Ljava/lang/String;") };
    const jfieldID field_mIsHD { ::djinni::jniGetFieldID(clazz.get(), "mIsHD", "Z") };
    const jfieldID field_mAccountLinks { ::djinni::jniGetFieldID(clazz.get(), "mAccountLinks", "Ljava/util/ArrayList;") };
};

}  // namespace djinni_generated
