workspace "premakeExample"
	location "prj"
	language "C++"
	architecture "x64"
	configurations {"Debug","Release"}
	filter {"configurations:Debug"}
		symbols "On"
	filter {"configurations:Release"}
		optimize "On"
	filter {}
	
	targetdir ("build/target/%{prj.name}/%{cfg.longname}")
	objdir ("build/obj/%{prj.name}/%{cfg.longname}")
	
	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} \"../bin/\"")
	}
	
function includeGLFW()
	includedirs "3rd/glfw/include"
end
	
function linkGLFW()
	libdirs "3rd/glfw/lib-vc2019"
	links "glfw3dll"
end

project "ExampleDll"
	kind "SharedLib"
	files "src/ExampleDll/**"
	includeGLFW()
	linkGLFW()
	
function useExampleDLL()
	includedirs "src/ExampleDll"
	links "ExampleDll"
end

project "App"
	kind "ConsoleApp"
	files "src/App/**"
	useExampleDLL()
	filter "system:windows"
		links {"OpenGL32"}
	
function includeCatch()
	includedirs "3rd/Catch/Include"
	defines "CATCH_CPP11_OR_GREATER"
end

project "UnitTests"
	kind "ConsoleApp"
	files "src/UnitTests/**"
	includeCatch()
	useExampleDLL()
	