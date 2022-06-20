cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        include/typedefs.h
        include/Client.h
        include/Address.h
        include/Rent.h
        include/Personal.h
        include/Group.h
        include/Table.h
        include/RentObject.h
        include/Hall.h
        include/repositories/StorageContainer.h
        include/repositories/ClientRepository.h
        include/repositories/RentObjectRepository.h
        include/repositories/RentRepository.h
        include/exceptions/ClientExceptions.h
        include/exceptions/RentExceptions.h
        include/exceptions/RentObjectExceptions.h
        include/managers/ClientManager.h
        include/exceptions/ManagersExceptions.h
        include/managers/RentObjectManager.h
        include/managers/RentManager.h

        src/Client.cpp
        src/Address.cpp
        src/Rent.cpp
        src/Personal.cpp
        src/Group.cpp
        src/Table.cpp
        src/RentObject.cpp
        src/Hall.cpp
        src/repositories/StorageContainer.cpp
        src/repositories/ClientRepository.cpp
        src/repositories/RentObjectRepository.cpp
        src/repositories/RentRepository.cpp
        src/exceptions/ClientExceptions.cpp
        src/exceptions/RentExceptions.cpp
        src/exceptions/RentObjectExceptions.cpp
        src/managers/ClientManager.cpp
        src/exceptions/ManagersExceptions.cpp
        src/managers/RentObjectManager.cpp
        src/managers/RentManager.cpp)
#Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

enable_testing() # dodane wcześniej w punkcie 2
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
        test/master.cpp
        test/AddressTest.cpp
        test/ClientTest.cpp
        test/RentObjectTest.cpp
        test/RentTest.cpp) # tu w przyszłości będą dodawane pliki źródłowe testów

add_executable (LibraryTest ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (LibraryTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose)