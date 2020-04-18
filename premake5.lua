solution "cppFX"
    architecture "x64"
    
    configurations 
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "cppFX"
    location "cppFX"
    kind "StaticLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "/home/uros/src/cppFX/cppFX/src/**.cpp",
        "/home/uros/src/cppFX/cppFX/src/**.h"
    }

    filter "configurations: Debug"
        defines "DEBUG"
        optimize "On"

    filter "configurations: Release"
        defines "RELEASE"
        optimize "On"

    configuration { "linux", "gmake" }
        linkoptions { "-lGL -lGLEW -lglut" }

    
project "sandbox"
    location "sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "/home/uros/src/cppFX/sandbox/sandboxApp.cpp"
    }

    links
    {
        "cppFX",
        "GL",
        "GLEW",
        "glut"
    }

    includedirs
    {
        "cppFX/include"
    }

    filter "configurations: Debug"
        defines "DEBUG"
        optimize "On"

    filter "configurations: Release"
        defines "RELEASE"
        optimize "On"