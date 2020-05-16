###############################################################################
#	Configuration
###############################################################################

TEMPLATE_INSTALL_HOME_DIR = "$(HOME)/.config/templateGen/"
TEMPLATE_INSTALL_DIR =      "$(TEMPLATE_INSTALL_HOME_DIR)templates/"

.PHONY: all
run: all
	@echo "" > /dev/null

.PHONY: install
install:
	@mkdir -p ${TEMPLATE_INSTALL_HOME_DIR}
	@cp -avr templateGen "$(HOME)/.local/bin/"
	@cp -avr templates   ${TEMPLATE_INSTALL_DIR}

.PHONY: uninstall
uninstall:
	rm -rf "$(HOME)/.local/bin/templateGen"
	rm -rf ${TEMPLATE_INSTALL_HOME_DIR}
