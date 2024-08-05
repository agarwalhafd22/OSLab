echo "Enter Basic Pay"
read basic
echo "Enter TA"
read ta
basicTA=$(expr $basic + $ta)
tenB=`bc -l <<<$basic\*\0.1`
gross=`bc -l <<<$basicTA\+\$tenB`
echo $gross
