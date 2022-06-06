cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        include/typedefs.h
        include/Client.h
        include/Address.h

        src/Client.cpp
        src/Address.cpp src/Rent.cpp include/Rent.h src/Personal.cpp include/Personal.h src/Group.cpp include/Group.h src/Table.cpp include/Table.h src/RentObject.cpp include/RentObject.h src/Hall.cpp include/Hall.h src/repositories/StorageContainer.cpp include/repositories/StorageContainer.h src/repositories/ClientRepository.cpp include/repositories/ClientRepository.h src/repositories/AddressRepository.cpp include/repositories/AddressRepository.h src/repositories/RentObjectRepository.cpp include/repositories/RentObjectRepository.h src/repositories/RentRepository.cpp include/repositories/RentRepository.h)
#Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)
