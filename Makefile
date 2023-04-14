.PHONY: all
all: checks package
	:

.PHONY: checks
checks: lint test docs
	:

.PHONY: package
package:
	@./setup.py sdist

.PHONY: publish
publish: clean package
	@twine upload dist/*

.PHONY: lint
lint:
	@pylint templategen

.PHONY: clean
clean:
	@rm -rf MANIFEST
	@rm -rf dist
	@rm -rf *.egg-info
	@rm -rf .eggs
	@rm -rf .pytest_cache
	@rm -rf build
	@py3clean .
	@echo "Done"
