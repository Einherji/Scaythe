workspace "Scaythe"
    configurations {
        "Debug",
        "Release",
        "Dist"
    }

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
        "source/**.h",
        "source/**.c"
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

project "ScaytheEditor"
    location "ScaytheEditor"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "source/**.h",
        "source/**.c"
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