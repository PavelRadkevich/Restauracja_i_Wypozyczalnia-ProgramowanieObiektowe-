cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        include/typedefs.h
        include/Client.h
        include/Address.h

        src/Client.cpp
        src/Address.cpp src/Rent.cpp include/Rent.h src/Personal.cpp include/Personal.h src/Group.cpp include/Group.h src/Table.cpp include/Table.h src/RentObject.cpp include/RentObject.h src/Hall.cpp include/Hall.h src/repositories/StorageContainer.cpp include/repositories/StorageContainer.h src/repositories/ClientRepository.cpp include/repositories/ClientRepository.h src/repositories/RentObjectRepository.cpp include/repositories/RentObjectRepository.h src/repositories/RentRepository.cpp include/repositories/RentRepository.h src/exceptions/ClientExceptions.cpp include/exceptions/ClientExceptions.h src/exceptions/RentExceptions.cpp include/exceptions/RentExceptions.h src/exceptions/RentObjectExceptions.cpp include/exceptions/RentObjectExceptions.h src/managers/ClientManager.cpp include/managers/ClientManager.h src/exceptions/ManagersExceptions.cpp include/exceptions/ManagersExceptions.h src/managers/RentObjectManager.cpp include/managers/RentObjectManager.h src/managers/RentManager.cpp include/managers/RentManager.h)
#Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)
