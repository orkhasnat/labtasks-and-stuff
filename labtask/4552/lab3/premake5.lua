-- premake5.lua
workspace "Lab3"
   configurations { "Debug", "Release" }
   
   project "TransformationAndAnimation"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   architecture "x64"
   targetname "GenerateFrames"
   targetdir "bin/%{cfg.buildcfg}"

   includedirs {
        "./src",
        "./src/include",
        "./src/include/stb"
    }

   files { "**.h", "**.hpp", "**.cpp", "**.cc", "**.cx", "**.c" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "Speed"