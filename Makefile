BUILD = ../../.build/sighol56_default.uf2
TARGET = /mnt/RPI-RP2

build:
	rm -f $(BUILD)
	qmk compile -km default -kb sighol56
	@[[ -f "$(BUILD)" ]] || bash -c "echo build did not produce build target; exit 1"

flash: build
	bash -c 'while [[ ! -f $(TARGET)/INDEX.HTM ]]; do printf "Waiting...\n"; sleep 1; done; printf "Mounted...\n"; sleep 2'
	cp $(BUILD) $(TARGET)

.PHONY: build flash
