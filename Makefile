BUILD = ../../.build/sighol56_default.uf2
TARGET = /mnt/RPI-RP2

build:
	qmk compile -km default -kb sighol56

flash: build
	bash -c 'while [[ ! -f $(TARGET)/INDEX.HTM ]]; do printf "Waiting...\n"; sleep 1; done; printf "Mounted...\n"; sleep 2'
	cp $(BUILD) $(TARGET)

.PHONY: build flash
