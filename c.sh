git config --global user.name 'David Valor'
git config --global user.email 'davidvalorwork@gmail.com'
git config credential.helper 'store --file ~/.credentialopencvpractice'
git add .
git commit -am "$1"
git push
