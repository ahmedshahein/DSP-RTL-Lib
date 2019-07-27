git add -n . .gitignore

git status
git add .
git commit -m "commutator.v line23 added 1 to overcome linting warning."
git pull origin master
git push origin master

git rm -r filt_fir filt_mac filt_ppd filt_ppi filt_cic filt_cici sgen_cordic sgen_nco
git add .drl_src_code .drl_param


git ls-tree -d origin/master:.drl_src_code/filt_cicd/
