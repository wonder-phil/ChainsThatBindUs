# Dockerfile — MQTT broker (Eclipse Mosquitto) FILE
FROM eclipse-mosquitto:2.0
COPY mosquitto.conf /mosquitto/config/mosquitto.conf
RUN mkdir -p /mosquitto/data /mosquitto/log \
  && chown -R mosquitto:mosquitto /mosquitto \
  && chmod 644 /mosquitto/config/mosquitto.conf
EXPOSE 1883 9001