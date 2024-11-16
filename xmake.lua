set_project("test")

set_xmakever("2.6.0")


target("test")
    set_kind("binary")  
    add_files("src/*.c")
    add_files("src/**/*.c") 
    if is_os("windows") then
        add_syslinks("winhttp", "user32") 
    end