FROM alpine:latest

RUN apk add python3 py3-pip
RUN python -m venv /app/venv
RUN /app/venv/bin/pip install discord.py

WORKDIR /app

ADD src ./

CMD /app/venv/bin/python bot.py
