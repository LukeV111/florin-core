// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#include "NativeIGenerationController.hpp"  // my header
#include "Marshal.hpp"
#include "NativeIGenerationListener.hpp"

namespace djinni_generated {

NativeIGenerationController::NativeIGenerationController() : ::djinni::JniInterface<::IGenerationController, NativeIGenerationController>("com/novocurrency/jniunifiedbackend/IGenerationController$CppProxy") {}

NativeIGenerationController::~NativeIGenerationController() = default;


CJNIEXPORT void JNICALL Java_com_novocurrency_jniunifiedbackend_IGenerationController_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::IGenerationController>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_novocurrency_jniunifiedbackend_IGenerationController_00024CppProxy_setListener(JNIEnv* jniEnv, jobject /*this*/, jobject j_generationListener)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        ::IGenerationController::setListener(::djinni_generated::NativeIGenerationListener::toCpp(jniEnv, j_generationListener));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jboolean JNICALL Java_com_novocurrency_jniunifiedbackend_IGenerationController_00024CppProxy_startGeneration(JNIEnv* jniEnv, jobject /*this*/, jint j_numThreads, jstring j_memoryLimit)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::IGenerationController::startGeneration(::djinni::I32::toCpp(jniEnv, j_numThreads),
                                                          ::djinni::String::toCpp(jniEnv, j_memoryLimit));
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jboolean JNICALL Java_com_novocurrency_jniunifiedbackend_IGenerationController_00024CppProxy_stopGeneration(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::IGenerationController::stopGeneration();
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_com_novocurrency_jniunifiedbackend_IGenerationController_00024CppProxy_getGenerationAddress(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::IGenerationController::getGenerationAddress();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_com_novocurrency_jniunifiedbackend_IGenerationController_00024CppProxy_getGenerationOverrideAddress(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::IGenerationController::getGenerationOverrideAddress();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jboolean JNICALL Java_com_novocurrency_jniunifiedbackend_IGenerationController_00024CppProxy_setGenerationOverrideAddress(JNIEnv* jniEnv, jobject /*this*/, jstring j_overrideAddress)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::IGenerationController::setGenerationOverrideAddress(::djinni::String::toCpp(jniEnv, j_overrideAddress));
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
