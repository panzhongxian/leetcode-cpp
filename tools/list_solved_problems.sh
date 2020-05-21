bazel query //... 2> /dev/null | awk -F ":" '{print $2}' | grep -P "\d{4}_" |sed "s/_test$//g"| sort -n

