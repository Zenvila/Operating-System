all:
	gcc -o pmms pmms.c

run: all
	chmod +x pmms-monitor.sh
	./pmms-monitor.sh

clean:
	rm -f pmms pmms.log
