#!/bin/bash

cacheVariable1="\"Content-Type:text/xml;charset=UTF-8"\"

websiteVariable="http://ota.bphone.bkav.com/service/update2"

entireURL="curl -X POST --header "$cacheVariable1" --data @test.xml "$websiteVariable""

output=$(eval $entireURL)

if [ -z "$output" ] ; then
  echo $output
else
  echo $output
fi

