workspace "ChernoEngine"
	architecture "x86"
	
	configurations
	{
		"Debug", "Release", "Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "ChernoEngine"
	location "ChernoEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "Pch.h"
	pchsource "ChernoEngine/src/Pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/src/**.cpp",
		"%{prj.name}/vendor/src/**.c"
	}
	
	includedirs
	{
	    "%{prj.name}/src",
		"%{prj.name}/vendor/includes",
		"%{prj.name}/vendor/includes/imgui"
	}
	
	libdirs
	{
		"%{prj.name}/vendor/libs"
	}
	
	links
	{
		"SDL2main",
		"SDL2"
	}
	
	filter "files:ChernoEngine/vendor/src/**.cpp or ChernoEngine/vendor/src/**.c"
		flags 
		{
			"NoPCH"
		}
	
	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"CE_PLATFORM_WINDOWS",
			"CE_BUILD_DLL",
			"CE_ENABLE_ASSERTS",
			"IMGUI_API=__declspec(dllexport)",
			"_CRT_SECURE_NO_WARNINGS"
		}
		
	filter "configurations:Debug"
		defines "CE_DEBUG"
		buildoptions "/MDd"
		symbols "on"
	
	filter "configurations:Release"
		defines "CE_RELEASE"
		buildoptions "/MD"
		optimize "on"
	
	filter "configurations:Dist"
		defines "CE_DIST"
		buildoptions "/MD"
		optimize "on"
	
project "Sandbox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
    staticruntime "on"
	
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
		systemversion "latest"
		
		defines
		{
			"CE_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "CE_DEBUG"
		buildoptions "/MDd"
		symbols "On"
	
	filter "configurations:Release"
		defines "CE_RELEASE"
		buildoptions "/MD"
		optimize "On"
	
	filter "configurations:Dist"
		defines "CE_DIST"
		buildoptions "/MD"
		optimize "On"