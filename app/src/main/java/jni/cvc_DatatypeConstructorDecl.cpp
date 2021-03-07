#include "cvc_DatatypeConstructorDecl.h"

#include "cvc4/api/cvc4cpp.h"

using namespace CVC4::api;

/*
 * Class:     cvc_DatatypeConstructorDecl
 * Method:    deletePointer
 * Signature: (J)V
 */
JNIEXPORT void JNICALL
Java_cvc_DatatypeConstructorDecl_deletePointer(JNIEnv*, jobject, jlong pointer)
{
  std::cout << "Deleting DatatypeConstructorDecl: "
            << ((DatatypeConstructorDecl*)pointer)->toString() << std::endl;
  delete ((DatatypeConstructorDecl*)pointer);
}

/*
 * Class:     cvc_DatatypeConstructorDecl
 * Method:    toString
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_cvc_DatatypeConstructorDecl_toString(JNIEnv* env, jobject, jlong pointer)
{
  DatatypeConstructorDecl* decl = (DatatypeConstructorDecl*)pointer;
  return env->NewStringUTF(decl->toString().c_str());
}

/*
 * Class:     cvc_DatatypeConstructorDecl
 * Method:    addSelector
 * Signature: (JLjava/lang/String;J)V
 */
JNIEXPORT void JNICALL Java_cvc_DatatypeConstructorDecl_addSelector(
    JNIEnv* env, jobject, jlong pointer, jstring jName, jlong sortPointer)
{
  try
  {
    DatatypeConstructorDecl* decl = (DatatypeConstructorDecl*)pointer;
    const char* cName = env->GetStringUTFChars(jName, nullptr);
    Sort* sort = (Sort*)sortPointer;
    decl->addSelector(std::string(cName), *sort);
  }
  catch (const CVC4ApiException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiException");
    env->ThrowNew(exceptionClass, e.what());
  }
}
