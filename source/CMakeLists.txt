file(GLOB SOURCES *.h *.cpp)

add_executable(StockSimulation ${SOURCES})
target_link_libraries(StockSimulation pthread)
install(TARGETS StockSimulation RUNTIME DESTINATION bin)
