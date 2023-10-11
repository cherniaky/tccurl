FROM "jakubhricik/ubuntu-zap"

# WORKDIR /app

RUN apt-get install texinfo -y

# RUN wget http://download.savannah.gnu.org/releases/tinycc/tcc-0.9.27.tar.bz2 \
#     && tar -xvf tcc-0.9.27.tar.bz2 \
#     && cd tcc-0.9.27 \
#     && mkdir dist \
#     && ./configure --prefix=./dist/ \
#     && make \
#     && make install \
#     && cd .. \
#     && rm tcc-0.9.27.tar.bz2