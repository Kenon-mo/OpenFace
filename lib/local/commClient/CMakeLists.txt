add_library(commClient 
    src/CommClient.cxx include/CommClient.hxx
)

add_library( OpenFace::commClient ALIAS commClient)

target_include_directories(commClient PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include/OpenFace>)

install (TARGETS commClient EXPORT OpenFaceTargets LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install (FILES ${HEADERS} DESTINATION include/OpenFace)