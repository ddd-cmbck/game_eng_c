#! /bin/bash
# Build script for rebuilding everething

set echo on

echo "Building everething..."

pushd engine
source build.sh
popd


ERRORLEVEL=$?
if [ ERRORLEVEL -ne 0 ]
then
echo "Error:"$ERRORLEVEL && exit
fi


pushd testbed
source build.sh
popd
ERRORLEVEL=$?
if [ $ERRORLEVEL -ne 0 ]
then
echo "Error:"$ERRORLEVEL && exit
fi

echo "All assemblies built successfully"