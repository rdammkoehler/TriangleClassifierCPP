g++ $(gtest-config --cppflags --cxxflags) -o TestTriangleClassifier.o -c TestTriangleClassifier.cpp 
g++ $(gtest-config --ldflags --libs) -o TestTriangleClassifier TestTriangleClassifier.o

