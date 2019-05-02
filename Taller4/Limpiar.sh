SCRIPT=`realpath $0`
SCRIPTPATH=`dirname $SCRIPT`

echo -e '\e[44m>> Limpiando SAXPY serial <<\e[49m '
rm -rf $SCRIPTPATH/Ejercicio1/Serial/libs
rm -rf $SCRIPTPATH/Ejercicio1/Serial/obj

echo -e '\e[44m>> Limpiando SAXPY Paralelo << \e[49m'
rm -rf $SCRIPTPATH/Ejercicio1/Paralelo/libs
rm -rf $SCRIPTPATH/Ejercicio1/Paralelo/obj

echo -e '\e[44m>> Limpiando IntegralesAproximacion <<\e[49m'
rm -rf $SCRIPTPATH/Ejercicio2/libs
rm -rf $SCRIPTPATH/Ejercicio2/obj

echo -e '\e[33m> Completado <\e[39m'
