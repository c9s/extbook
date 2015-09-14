#!/bin/bash

if [ $# -ne 1 ]; then
    echo "usage: ./publish.sh \"commit message\""
    exit 1;
fi

set -e

rm -rf output_prod
sculpin generate --env=prod

git stash
git checkout gh-pages

rsync -a --update -v output_prod/ ./
rm -rf output_*

git add *
git commit -m "$1"
git push origin gh-pages

git checkout master
git stash pop
