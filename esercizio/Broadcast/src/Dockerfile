FROM gcc:latest as builder
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN gcc -o br -static broadcast.c

FROM alpine:latest as runtime
COPY --from=builder /usr/src/myapp/server /server
ENTRYPOINT ["./br"]