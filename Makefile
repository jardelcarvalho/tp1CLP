all:
	gcc imperativo/main/main.c -o imperativo/main/main
	ghc funcional/main/main.hs -ifuncional/cauda -ifuncional/comum -o funcional/main/main
	gcc funcional/main/medias.c -o funcional/main/medias 
	find -name "*.java" > orientado_objetos/src.txt
	javac @orientado_objetos/src.txt
	gcc orientado_objetos/main/mili.c -o orientado_objetos/main/mili
	@echo compilacao concluida

run:
	./imperativo/main/main
	./funcional/main/main
	./funcional/main/medias 5
	java -cp orientado_objetos/ main.main
	./orientado_objetos/main/mili
	rm -rf resultados/medias_java_temp.csv
	@echo execucao concluida, dados em ./resultados

clean:
	rm -rf funcional/cauda/*.hi funcional/cauda/*.o funcional/comum/*.hi funcional/comum/*.o funcional/main/*.o
	rm -rf imperativo/main/*.o
	rm -rf resultados/*.csv
	rm -rf funcional/main/*.o funcional/main/*.hi
	rm -rf orientado_objetos/recursivo/*.class
	rm -rf orientado_objetos/main/*.class
	rm -rf orientado_objetos/sequencial/*.class
	@echo remocao concluida