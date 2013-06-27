JFLAGS = -classpath Jama-1.0.3.jar -d markovroulette_classes
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	MarkovRoulette.java

default: classes

classes: $(CLASSES:.java=.class)

jar:
	jar cvfm MarkovRoulette.jar manifest.txt -C markovroulette_classes/ .

test:
	java -jar MarkovRoulette.jar 30 10 60 10

clean:
	${RM} markovroulette_classes/*.class