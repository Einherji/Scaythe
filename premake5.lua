include("conanbuildinfo.premake.lua")

workspace "Scaythe"
    conan_basic_setup()
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

    startproject "ScaytheEditor"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ScaytheEngine"
    location "ScaytheEngine"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "%{prj.name}/source/**.h",
        "%{prj.name}/source/**.cpp"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .. "/ScaytheEditor")
    }

    filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

    filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

    filter "configurations:Dist"
        defines { "NDEBUG" }
        optimize "On"

    filter "system:windows"
        defines
        {
            "SCAYTHE_LIB",
            "SCAYTHE_SYS_WIN"
        }

    filter "system:not windows"
        defines
        {
            "SCAYTHE_LIB",
            "SCAYTHE_SYS_UNIX"
        }

project "ScaytheEditor"
    location "ScaytheEditor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "%{prj.name}/source/**.h",
        "%{prj.name}/source/**.cpp"
    }

    includedirs
    {
        "ScaytheEngine/source"
    }

    links
    {
        "ScaytheEngine"
    }

    filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

    filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

    filter "configurations:Dist"
        defines { "NDEBUG" }
        optimize "On"

    filter "system:windows"
        defines
        {
            "SCAYTHE_SYS_WIN"
        }

    filter "system:not windows"
        defines
        {
            "SCAYTHE_SYS_UNIX"
        }