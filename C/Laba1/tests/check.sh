#!/bin/bash
DATE=`date +%Y-%m-%d-%H-%M-%S`

#colors for print
RED=`tput setaf 1`
NC=`tput sgr0`
YELLOW=`tput setaf 3`

mkdir $DATE
#  |tee -a  $DATE/report.txt  create file with stdout and print stdout to console

cd ..
make -i test  > /dev/null 2>&1 

echo ' '
echo "	${YELLOW} Start unit testing ${NC}"
make -i moduletest
./moduletest
echo  "	${YELLOW} End unit testing ${NC}"
cd tests
echo "	${YELLOW} Start functional testing ${NC}"
ls | grep '^out' | while read line
do	
	mv out* $DATE/ > /dev/null 2>&1 
	diff -q $DATE/$line answers/$line  >/dev/null
	if [[ $? == "0" ]]
	then
  		echo "Test with file "$line" pass"  |tee -a  $DATE/report.txt
	else
 		echo "Test with file "$line" ${RED} FAILED${NC}"  
		echo diff $DATE/$line answers/$line |tee -a  $DATE/report.txt
        	diff $DATE/$line answers/$line |tee -a  $DATE/report.txt

	fi
done


