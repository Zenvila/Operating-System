# Dockerfile
FROM ubuntu:latest
COPY table.sh /table.sh
RUN chmod +x /table.sh
CMD ["/table.sh"]

