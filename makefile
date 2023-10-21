VPATH := src
BUILDDIR := build
OBJSDIR := $(BUILDDIR)/objs
OBJS := $(patsubst src/%.cpp, $(OBJSDIR)/%.o, $(wildcard src/*.cpp))

$(OBJSDIR)/%.o: %.cpp %.h
	g++ -c $< -o $(OBJSDIR)/$(@F)

$(OBJSDIR)/%.o: %.cpp
	g++ -c $< -o $(OBJSDIR)/$(@F)

all: main

main: $(OBJS)
	g++ $(wildcard $(OBJSDIR)/*.o) -o $(BUILDDIR)/main

$(OBJS): | $(OBJSDIR)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

.PHONY: clean
.PHONY: cleanwrong

clean:
	rm -r $(OBJSDIR)

full-clean:
	rm -r $(BUILDDIR)

