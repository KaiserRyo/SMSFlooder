# Auto-generated by IDE. Any changes made by user will be lost!
BASEDIR =  $$quote($$_PRO_FILE_PWD_)

device {
    CONFIG(debug, debug|release) {
        SOURCES +=  $$quote($$BASEDIR/src/Settings.cpp) \
                 $$quote($$BASEDIR/src/applicationui.cpp) \
                 $$quote($$BASEDIR/src/main.cpp)

        HEADERS +=  $$quote($$BASEDIR/src/Settings.hpp) \
                 $$quote($$BASEDIR/src/applicationui.hpp)
    }

    CONFIG(release, debug|release) {
        SOURCES +=  $$quote($$BASEDIR/src/Settings.cpp) \
                 $$quote($$BASEDIR/src/applicationui.cpp) \
                 $$quote($$BASEDIR/src/main.cpp)

        HEADERS +=  $$quote($$BASEDIR/src/Settings.hpp) \
                 $$quote($$BASEDIR/src/applicationui.hpp)
    }
}

simulator {
    CONFIG(debug, debug|release) {
        SOURCES +=  $$quote($$BASEDIR/src/Settings.cpp) \
                 $$quote($$BASEDIR/src/applicationui.cpp) \
                 $$quote($$BASEDIR/src/main.cpp)

        HEADERS +=  $$quote($$BASEDIR/src/Settings.hpp) \
                 $$quote($$BASEDIR/src/applicationui.hpp)
    }
}

INCLUDEPATH +=  $$quote($$BASEDIR/src)

CONFIG += precompile_header

PRECOMPILED_HEADER =  $$quote($$BASEDIR/precompiled.h)

lupdate_inclusion {
    SOURCES +=  $$quote($$BASEDIR/../src/*.c) \
             $$quote($$BASEDIR/../src/*.c++) \
             $$quote($$BASEDIR/../src/*.cc) \
             $$quote($$BASEDIR/../src/*.cpp) \
             $$quote($$BASEDIR/../src/*.cxx) \
             $$quote($$BASEDIR/../assets/*.qml) \
             $$quote($$BASEDIR/../assets/*.js) \
             $$quote($$BASEDIR/../assets/*.qs) \
             $$quote($$BASEDIR/../assets/VisualStyle.bright/*.qml) \
             $$quote($$BASEDIR/../assets/VisualStyle.bright/*.js) \
             $$quote($$BASEDIR/../assets/VisualStyle.bright/*.qs) \
             $$quote($$BASEDIR/../assets/VisualStyle.bright/images/*.qml) \
             $$quote($$BASEDIR/../assets/VisualStyle.bright/images/*.js) \
             $$quote($$BASEDIR/../assets/VisualStyle.bright/images/*.qs) \
             $$quote($$BASEDIR/../assets/VisualStyle.dark/*.qml) \
             $$quote($$BASEDIR/../assets/VisualStyle.dark/*.js) \
             $$quote($$BASEDIR/../assets/VisualStyle.dark/*.qs) \
             $$quote($$BASEDIR/../assets/VisualStyle.dark/images/*.qml) \
             $$quote($$BASEDIR/../assets/VisualStyle.dark/images/*.js) \
             $$quote($$BASEDIR/../assets/VisualStyle.dark/images/*.qs) \
             $$quote($$BASEDIR/../assets/images/*.qml) \
             $$quote($$BASEDIR/../assets/images/*.js) \
             $$quote($$BASEDIR/../assets/images/*.qs) \
             $$quote($$BASEDIR/../assets/sheets/*.qml) \
             $$quote($$BASEDIR/../assets/sheets/*.js) \
             $$quote($$BASEDIR/../assets/sheets/*.qs)

    HEADERS +=  $$quote($$BASEDIR/../src/*.h) \
             $$quote($$BASEDIR/../src/*.h++) \
             $$quote($$BASEDIR/../src/*.hh) \
             $$quote($$BASEDIR/../src/*.hpp) \
             $$quote($$BASEDIR/../src/*.hxx)
}

TRANSLATIONS =  $$quote($${TARGET}.ts)
