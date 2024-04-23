BUILD = ../../.build/sighol56_default.uf2
TARGET = /run/media/sighol/RPI-RP2

build:
	qmk compile -km default

flash: build
	bash -c '[[ -f $(BUILD) ]]'
	bash -c '[[ -d $(TARGET) ]]'
	cp $(BUILD) $(TARGET)

.PHONY: build flash
