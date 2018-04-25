## IDIOT SHELL

### OLD WAY
Compile and set the binary as shell in 

`/etc/shells`

for any (l)user that makes your life miserable, disturbes your lazy evening or is simply too stupid to be given a real shell account.

Feel free to use and modify it to suit your needs best!

Put 'roll.sh' in /usr/local/bin/roll.sh

### DOCKERIZED
Simply build docker image with IdiotShell and openssh-server installed like this:

`docker build -t idiotshell .`

or optionally you can specify different username and password by using `--build-arg USER=example --build-arg PASS=strongpassword`
and run this container by executing:

`docker run -d -p <your_ssh_port>:22 idiotshell`

### Disclaimer(s)
Ponysay package used in this project can be found here: http://www.vcheng.org/ponysay/ 

##### Known problems
'roll.sh' doesn't work anymore, so we had to temporarily use something else instead.

======
### LICENCE
Licenced under Beerware!
