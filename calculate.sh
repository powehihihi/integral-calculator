#!/bin/bash
RF="./rewrite-function"
I="./integral"
logs="./logs/logs.txt"
echo "logs will be available in $logs "
if [ -f $logs ]
then
  rm $logs
fi 
touch ./logs/logs.txt
cd build
make > ../$logs

if [ $# -eq 2 ]
then
  $I $1 $2
elif [ $# -eq 3 ]
then
  $RF $3 
  make > ../$logs
  $I $1 $2 
elif [ $# -eq 4 ]
then
  $RF $4
  make > ../$logs
  $I $1 $2 $3
else

  echo "Usage: a b (eps) \"F(x)\""
  echo "eps is not required"
fi 

cd ..
