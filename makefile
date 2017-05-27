vpath %.h include
vpath %.c src
vpath %.o obj
vpath main bin

CC = gcc
CFLAGS = -g -Wall -Wextra
IFLAGS = -Iinclude
LDLIBS = -L /usr/X11R6/lib -lX11
ALL = all
GENLAB = genlab
CHEMIN = chemin
OBJFILES = obj/genlab.o obj/labyrinth.o obj/matrice.o obj/ensemble.o obj/graph.o obj/parsing.o
OBJCHEMIN = obj/chemin.o obj/labyrinth.o obj/matrice.o obj/ensemble.o obj/graph.o obj/parsing.o
OPATH = obj
CPATH = src
BPATH = bin

$(ALL) : $(GENLAB) $(CHEMIN)

$(GENLAB) : $(OBJFILES)
	$(CC) -o $@ $^ $(LDLIBS)
	mv $@ $(BPATH)

$(CHEMIN) : $(OBJCHEMIN)
	$(CC) -o $@ $^ $(LDLIBS)
	mv $@ $(BPATH)
	
$(OPATH)/%.o : $(CPATH)/%.c
	$(CC) $(CFLAGS) -c $< $(IFLAGS) -o $@


exedoc :
	doxygen doxyfile

gendoc :
	doxygen -g doxyfile
	echo "RECURSIVE = YES" >> doxyfile
	echo "EXTRACT_ALL = YES" >> doxyfile
	echo "GENERATE_LATEX = NO" >> doxyfile
	echo "PROJECT_NAME = "Labyrinthe_Jean-Romain_Luttringer_et_Cyrille_Muller"" >> doxyfile
	
clean : 
	rm -r $(OPATH)/* $(BPATH)/* *.txt html doxyfile

# DO NOT DELETE

src/chemin.o: /usr/include/stdio.h /usr/include/features.h
src/chemin.o: /usr/include/stdc-predef.h /usr/include/libio.h
src/chemin.o: /usr/include/_G_config.h /usr/include/wchar.h
src/chemin.o: /usr/include/stdlib.h /usr/include/alloca.h
src/chemin.o: /usr/include/unistd.h /usr/include/getopt.h include/matrice.h
src/chemin.o: include/ensemble.h /usr/include/time.h include/graph.h
src/chemin.o: include/labyrinth.h include/parsing.h
src/ensemble.o: include/ensemble.h /usr/include/stdio.h
src/ensemble.o: /usr/include/features.h /usr/include/stdc-predef.h
src/ensemble.o: /usr/include/libio.h /usr/include/_G_config.h
src/ensemble.o: /usr/include/wchar.h /usr/include/stdlib.h
src/ensemble.o: /usr/include/alloca.h /usr/include/time.h
src/genlab.o: /usr/include/stdio.h /usr/include/features.h
src/genlab.o: /usr/include/stdc-predef.h /usr/include/libio.h
src/genlab.o: /usr/include/_G_config.h /usr/include/wchar.h
src/genlab.o: /usr/include/stdlib.h /usr/include/alloca.h
src/genlab.o: /usr/include/unistd.h /usr/include/getopt.h include/matrice.h
src/genlab.o: include/ensemble.h /usr/include/time.h include/labyrinth.h
src/genlab.o: include/graph.h include/parsing.h
src/labyrinth.o: /usr/include/stdio.h /usr/include/features.h
src/labyrinth.o: /usr/include/stdc-predef.h /usr/include/libio.h
src/labyrinth.o: /usr/include/_G_config.h /usr/include/wchar.h
src/labyrinth.o: /usr/include/stdlib.h /usr/include/alloca.h
src/labyrinth.o: /usr/include/unistd.h /usr/include/getopt.h
src/labyrinth.o: include/matrice.h include/ensemble.h /usr/include/time.h
src/labyrinth.o: include/labyrinth.h include/graph.h
src/matrice.o: /usr/include/stdio.h /usr/include/features.h
src/matrice.o: /usr/include/stdc-predef.h /usr/include/libio.h
src/matrice.o: /usr/include/_G_config.h /usr/include/wchar.h
src/matrice.o: /usr/include/stdlib.h /usr/include/alloca.h include/matrice.h
