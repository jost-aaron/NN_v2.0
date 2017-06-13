clear
echo "---Compiling---"
#echo "--------------"
make

# Check to see if the compilation was sucessful
if [ $? -eq 0 ]; then
  #echo "--------------"
  echo "---Cleaning object files---"
  #echo "--------------"
  make clean
  #echo "--------------"
  echo "---Running---"
  #echo "--------------"
  ./output

fi
