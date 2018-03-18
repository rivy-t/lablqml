.PHONY: all generator lib demo rundemo
all: lib generator

generator:
	dune build ppx/ppxext/ppx_qt.exe
lib:
	dune build lib/lablqml.a lib/dlllablqml_stubs.so

demo: all
	#PATH=`pwd`/_build/default/ppx/ppxext:$(PATH) bash -c "cd dune_test && ./configure"
	PATH=`pwd`/_build/default/ppx/ppxext:$(PATH) \
	dune build dune_test/ui/Root.qml \
     dune_test/moc_controller_c.cpp dune_test/program.exe

rundemo:
	PATH=`pwd`/_build/default/ppx/ppxext:$(PATH) \
	dune exec -- dune_test/program.exe

clean:
	$(RM) -r _build

uninstall:
	dune build @install
	dune uninstall

install:
	dune build @install
	dune install