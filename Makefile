.PHONY: check-format
check-format:
	find . -iname "*.cpp" -or -iname "*.hpp" | xargs clang-format -i --dry-run -style=file

.PHONY: format
format:
	find . -iname "*.cpp" -or -iname "*.hpp" | xargs clang-format -i -style=file