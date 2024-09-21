DESTDIR=/usr/local/bin
name=backlight



all:main.c
	gcc $^ -o ${name}

install:all
	install -m 755 -t ${DESTDIR} ${name}

clear:
	rm ${name}

uninstall:
	rm ${DESTDIR}/${name}
