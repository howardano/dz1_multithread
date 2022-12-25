build:
	mkdir build && \
	cd build && \
	cmake .. && \
	make && \
	cd ../tests/integration && \
	python3 test_integr.py

go:
	cd build && \
	./main

test:
	cd build && \
	./test_realisation

