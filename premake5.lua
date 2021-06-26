workspace "Manifold"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"




------------------- Manifold Game Engine Core (SharedLib) -----------------------
---------------------------------------------------------------------------------
project "Manifold"
    location "Manifold"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir ("bin-obj/" ..outputdir.."/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    } 

    filter "system:linux"
        cppdialect "gnu++17"
        staticruntime "On"
        systemversion "latest"

    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "MF_PLATFORM_WINDOWS",
            "MF_BUILD_DLL"
        }

    filter "configurations:Debug"
        defines "MF_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "MF_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "MF_DIST"
        symbols "On"
-------------------------------------------------------------------------------------





--------------------- Sandbox application project (Executable) ----------------------
-------------------------------------------------------------------------------------
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir ("bin-obj/" ..outputdir.."/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "Manifold/vendor/spdlog/include",
        "Manifold/src/"
    }

    links
    {
        "Manifold"
    }




    filter "system:linux"
        cppdialect "gnu++17"
        staticruntime "On"
        systemversion "latest"

    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "MF_PLATFORM_WINDOWS",
            "MF_BUILD_DLL"
        }

    filter "configurations:Debug"
        defines "MF_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "MF_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "MF_DIST"
        symbols "On"
-------------------------------------------------------------------------------