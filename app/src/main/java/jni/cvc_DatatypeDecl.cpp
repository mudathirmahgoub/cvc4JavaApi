#include "cvc_DatatypeDecl.h"

#include "cvc4/api/cvc4cpp.h"

using namespace CVC4::api;

/*
 * Class:     cvc_DatatypeDecl
 * Method:    deletePointer
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_cvc_DatatypeDecl_deletePointer(JNIEnv*,
                                                           jobject,
                                                           jlong pointer)
{
  delete ((DatatypeDecl*)pointer);
}

/*
 * Class:     cvc_DatatypeDecl
 * Method:    toString
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cvc_DatatypeDecl_toString(JNIEnv* env,
                                                         jobject,
                                                         jlong pointer)
{
  DatatypeDecl* datatypeDecl = (DatatypeDecl*)pointer;
  return env->NewStringUTF(datatypeDecl->toString().c_str());
}

/*
 * Class:     cvc_DatatypeDecl
 * Method:    addConstructor
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_cvc_DatatypeDecl_addConstructor(
    JNIEnv* env, jobject, jlong pointer, jlong datatypeConstructorDeclPointer)
{
  try
  {
    DatatypeDecl* datatypeDecl = (DatatypeDecl*)pointer;
    DatatypeConstructorDecl* decl =
        (DatatypeConstructorDecl*)datatypeConstructorDeclPointer;
    datatypeDecl->addConstructor(*decl);
  }
  catch (const CVC4ApiException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiException");
    env->ThrowNew(exceptionClass, e.what());
  }
}