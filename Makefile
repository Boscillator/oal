.PHONY: default
default:
	echo "Usage: make [check-format|format|configure|build|test]"

.PHONY: check-format
check-format:
	find . -iname "*.cpp" -or -iname "*.hpp" | xargs clang-format -i --dry-run -style=file

.PHONY: format
format:
	find . -iname "*.cpp" -or -iname "*.hpp" | xargs clang-format -i -style=file

.PHONY: configure
configure:
	cmake --preset development

.PHONY: build
build:
	cmake --build --preset development

.PHONY: test
test:
	cd build && ctest
