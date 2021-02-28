workspace "ChernoEngine"
	architecture "x86"
	
	configurations
	{
		"Debug", "Release", "Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "ChernoEngine"
	location "ChernoEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "pch.h"
	pchsource "ChernoEngine/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
	    "%{prj.name}/src",
		"%{prj.name}/vendor/includes"
	}
	
	libdirs
	{
		"%{prj.name}/vendor/libs"
	}
	
	links
	{
		"SDL2main",
		"SDL2", 
		"opengl32.lib"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"CE_PLATFORM_WINDOWS",
			"CE_BUILD_DLL",
			"CE_ENABLE_ASSERTS"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}
		
	filter "configurations:Debug"
		defines "CE_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "CE_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "CE_DIST"
		optimize "On"
	
project "Sandbox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"ChernoEngine/vendor/includes",
		"ChernoEngine/src"
	}
	
	links
	{
		"ChernoEngine"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"CE_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "CE_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "CE_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "CE_DIST"
		optimize "On"