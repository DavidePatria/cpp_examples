cmake_minimum_required(VERSION 3.24)

# Imposta il nome del progetto
project(EsempiCPlusPlus)

# Continua aggiungendo i tuoi programmi...
# Lista dei file sorgente
set(SOURCE_FILES
    command.cpp
    derived.cpp
    expected.cpp
    print.cpp
    unique_ptr.cpp
    observer.cpp
    type_erasure.cpp
    string_view.cpp
    reimpl_strategy.cpp
    span.cpp
)

# Opzioni di compilazione comuni
set(COMMON_FLAGS "-stdlib=libc++" "-std=c++23")
set(CMAKE_CXX_COMPILER "clang++")

# Ciclo per aggiungere eseguibili e impostare le opzioni di compilazione
foreach(SRC_FILE IN LISTS SOURCE_FILES)
    # Ottiene il nome del file senza il suffisso .cpp
    get_filename_component(TARGET_NAME ${SRC_FILE} NAME_WE)

    # Aggiunge l'eseguibile
    add_executable(${TARGET_NAME} examples/${SRC_FILE})

    # Imposta le opzioni di compilazione comuni
    target_compile_options(${TARGET_NAME} PRIVATE ${COMMON_FLAGS})
    target_link_options(${TARGET_NAME} PRIVATE -stdlib=libc++)
endforeach()

