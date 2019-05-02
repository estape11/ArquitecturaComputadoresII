SCRIPT=`realpath $0`
SCRIPTPATH=`dirname $SCRIPT`

echo -e '\e[44m>> Compilando SAXPY serial <<\e[49m '
cd $SCRIPTPATH/Ejercicio1/Serial/jni
/opt/android-ndk-r19c/ndk-build

echo -e '\e[44m>> Compilando SAXPY Paralelo << \e[49m'
cd $SCRIPTPATH/Ejercicio1/Paralelo/jni
/opt/android-ndk-r19c/ndk-build

echo -e '\e[44m>> Compilando IntegralesAproximacion <<\e[49m'
cd $SCRIPTPATH/Ejercicio2/jni
/opt/android-ndk-r19c/ndk-build

echo -e '\e[33m> Completado <\e[39m'
