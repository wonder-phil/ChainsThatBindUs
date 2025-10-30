FROM eclipse-mosquitto:2.0
USER root
RUN apk add --no-cache python3 py3-pip \
  && python3 -m venv /opt/venv \
  && /opt/venv/bin/pip install --upgrade pip
# Make the venv the default Python
ENV PATH="/opt/venv/bin:${PATH}"
WORKDIR /app
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt
COPY *.py .
RUN chown -R mosquitto:mosquitto /app
USER mosquitto
EXPOSE 1883 9001
