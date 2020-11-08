#! /bin/bash

mkdir arduino

for f in $( find include src -type f); do
    cat $f | sed -E 's/#include <(.+)>/#include "\1"/g' > "arduino/$(echo $f | cut -d'/' -f 2- | sed -E 's/\//_/g')"
done

cd arduino
zip ../OSGB36.zip *
cd ..
rm -rf arduino