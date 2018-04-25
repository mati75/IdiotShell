FROM debian:stretch 
ARG USER="user"
ARG PASS="dupa.8"
COPY src /root/src
RUN apt-get update && apt-get install --no-install-recommends -y build-essential openssh-server curl wget python3 && \
    mkdir -p /var/run/sshd && \
    cd /root/src && make && make install && \
    echo "/usr/local/bin/idiotshell" >> /etc/shells && \
    useradd -m -s /usr/local/bin/idiotshell $USER && \
    echo "${USER}:${PASS}" | chpasswd && \
    dpkg -i /root/src/ponysay_3.0.2-1_all.deb && \
    apt-get autoremove -y --purge build-essential && \
    rm -rf /root/src && \
    rm -rf /var/lib/apt/lists/* 
EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]
