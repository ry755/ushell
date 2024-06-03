APPLICATIONS = \
	desktop

OUTPUT_FILES = $(foreach app,$(APPLICATIONS),$(app)/$(app).app)

all: $(OUTPUT_FILES)

$(OUTPUT_FILES): %:
# extracts the application name from the target name
# e.g. desktop/desktop.app --> desktop desktop.app --> desktop
	cd $(word 1,$(subst /, ,$@)) && $(MAKE)

.PHONY: $(OUTPUT_FILES) clean
clean:
	for app in $(APPLICATIONS); do \
		(cd $$app && $(MAKE) clean); \
	done
