#include "cvc_Term.h"

#include "cvc4/api/cvc4cpp.h"

using namespace CVC4::api;

/*
 * Class:     cvc_Term
 * Method:    deleteTerm
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_cvc_Term_deleteTerm(JNIEnv*,
                                                 jobject,
                                                 jlong termPointer)
{
  delete ((Term*)termPointer);
}

/*
 * Class:     cvc_Term
 * Method:    toString
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cvc_Term_toString(JNIEnv* env,
                                                  jobject,
                                                  jlong termPointer)
{
  Term* term = (Term*)termPointer;
  return env->NewStringUTF(term->toString().c_str());
}