#!/bin/bash

MSG=$(git log --oneline -1)
set -e

rm -rf output_prod
sculpin generate --env=prod

git stash
git checkout gh-pages

rsync -a -v output_prod/ ./
rm -rf output_*

git add *
git commit -m "$MSG"
git push origin gh-pages

git checkout master
git stash pop
