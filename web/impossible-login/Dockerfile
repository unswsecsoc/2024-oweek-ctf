FROM alpine:latest

RUN apk add python3 py3-pip
RUN python -m venv /app/venv
RUN /app/venv/bin/pip install quart

WORKDIR /app

ADD src ./

EXPOSE 9999

CMD /app/venv/bin/python server.py 9999
