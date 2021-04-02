import glob
import git
import re
with open('ttt') as f:
    problem_nums = f.readlines()

bare_repo = git.Repo.init("/root/leetcode-cpp/", bare=False)

for line in problem_nums:
    num = line.strip()
    m = re.match('^[0-9]+\s*$', line)
    if not m:
        continue
    file_prefix = '0' * (4 - len(num)) + num
    #print(num, glob.glob(file_prefix + '*.h'))
    try:
        bare_repo.index.add("src/" + glob.glob(file_prefix + '*.h')[0])
    except Exception as e:
        print(str(e))
        pass
