#!/bin/bash

#colors for print
RED=`tput setaf 1`
NC=`tput sgr0`
YELLOW=`tput setaf 3`
GREEN=`tput setaf 2`

DATE=`date +%Y-%m-%d-%H-%M-%S`

mkdir tests/$DATE
OUTFOLDER=tests/$DATE
REPORT=$OUTFOLDER/report.txt

#  |tee -a  $REPORT  create file with stdout and print stdout to console



echo "	${YELLOW} Start functional testing ${NC}"			|tee -a  $REPORT



ls tests | grep '^test' | while read line
do
	#echo $line
	./Tisd1.exe< tests/$line >>$OUTFOLDER/'out'$line 
done


ls $OUTFOLDER | grep '^out' | while read line
do
	diff -q $OUTFOLDER/$line tests/answers/$line  >/dev/null
	if [[ $? == "0" ]]
	then
  		echo "Test with file "$line" ${GREEN}pass ${NC}"  			|tee -a  $REPORT
	else
 		echo "Test with file "$line" ${RED} FAILED ${NC}"	|tee -a  $REPORT
		echo diff $OUTFOLDER/$line tests/answers/$line 		|tee -a  $REPORT
        	diff $OUTFOLDER/$line tests/answers/$line  		|tee -a  $REPORT

	fi
done

echo "  ${YELLOW} End functional testing ${NC}"                       	|tee -a  $REPORT

