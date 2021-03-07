#include "cvc_Term.h"

#include "cvc4/api/cvc4cpp.h"

using namespace CVC4::api;

/*
 * Class:     cvc_Term
 * Method:    deletePointer
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_cvc_Term_deletePointer(JNIEnv*,
                                                   jobject,
                                                   jlong pointer)
{
  std::cout << "Deleting Term: " << ((Term*)pointer)->toString() << std::endl;
  delete ((Term*)pointer);
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

/*
 * Class:     cvc_Term
 * Method:    eqTerm
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Term_eqTerm(JNIEnv* env,
                                             jobject,
                                             jlong termPointer,
                                             jlong tPointer)
{
  Term* term = (Term*)termPointer;
  Term* t = (Term*)tPointer;
  try
  {
    Term* ret = new Term(term->eqTerm(*t));
    return ((jlong)ret);
  }
  catch (const CVC4ApiException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiException");
    env->ThrowNew(exceptionClass, e.what());
  }

  // execution should never reach here
  return 0;
}

/*
 * Class:     cvc_Term
 * Method:    notTerm
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc_Term_notTerm(JNIEnv* env,
                                              jobject,
                                              jlong termPointer)
{
  Term* term = (Term*)termPointer;
  try
  {
    Term* ret = new Term(term->notTerm());
    return ((jlong)ret);
  }
  catch (const CVC4ApiException& e)
  {
    jclass exceptionClass = env->FindClass("cvc/CVCApiException");
    env->ThrowNew(exceptionClass, e.what());
  }
  // execution should never reach here
  return 0;
}