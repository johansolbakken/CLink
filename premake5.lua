-- Premake.lua
workspace "CLink"
    architecture "x64"
    startproject "CLink"
    configurations { 
        "Debug", 
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
--IncludeDir["imgui"] = "Hazel/vendor/imgui"

--[[
    CLink PROJECT
]]
project "CLink"
    location "CLink"
	kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"
    
    -- Intermediate and target dirs
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files { "%{prj.name}/src/**.cpp", "%{prj.name}/src/**.hpp", "%{prj.name}/src/**.h", "%{prj.name}/src/**.mm"  }

	includedirs { 
        "%{prj.name}/src"
    }

	filter "configurations:Debug"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines { "NDEBUG" }
        runtime "Release"
        optimize "On"

    filter "system:macosx"
        systemversion "10.15"

        links {
            "Cocoa.framework",
            "IOKit.framework",
            "CoreFoundation.framework"
        }
