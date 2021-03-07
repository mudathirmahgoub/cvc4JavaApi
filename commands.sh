#build/install/cvc4JavaApi/app/src/main/java
javac -h jni cvc/*.java -cp commons-lang3-3.11.jar
# get string representation for fields and class cvc/Pair
#build/install/cvc4JavaApi/app/src/main/java
javap -s -p cvc/Pair
# get signature of
javap -s -p java.lang.Long
# remove class files generated with javac -h
rm cvc/*.class