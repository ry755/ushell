APPLICATIONS = \
	desktop

OUTPUT_FILES = $(foreach app,$(APPLICATIONS),$(app)/$(app).bin)

all: $(OUTPUT_FILES)

$(OUTPUT_FILES): %:
	# extracts the application name from the target name
	# e.g. desktop/desktop.bin --> desktop desktop.bin --> desktop
	cd $(word 1,$(subst /, ,$@)) && $(MAKE)

.PHONY: $(OUTPUT_FILES) clean
clean:
	for app in $(APPLICATIONS); do \
		(cd $$app && $(MAKE) clean); \
	done
