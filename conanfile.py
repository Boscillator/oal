from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class oalRecipe(ConanFile):
    name = "oal"
    version = "0.1.0-dev"
    package_type = "library"

    # Optional metadata
    license = " MPL-2.0"
    author = "Frederick Buchanan <fred@buchanan.one>"
    url = "https://github.com/Boscillator/oal"
    description = "Open Aerospace Utilities. Unopinionated, open source and correct utilities for aerospace applications. Supports C++ and Python."
    topics = ("Aerospace", "Python")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*", "include/*"

    def config_options(self):
        if self.settings.os == "Windows":
            self.options.rm_safe("fPIC")

    def configure(self):
        if self.options.shared:
            self.options.rm_safe("fPIC")

    def layout(self):
        cmake_layout(self)
    
    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["oal"]

