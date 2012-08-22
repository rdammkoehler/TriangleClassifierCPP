rm *.o
rm TestTriangleClassifier
g++ $(gtest-config --cppflags --cxxflags) -o Triangle.o -c Triangle.cpp 
g++ $(gtest-config --cppflags --cxxflags) -o Classifier.o -c Classifier.cpp 
g++ $(gtest-config --cppflags --cxxflags) -o TestTriangleClassifier.o -c TestTriangleClassifier.cpp 
g++ $(gtest-config --ldflags --libs) -o TestTriangleClassifier TestTriangleClassifier.o Classifier.o
./TestTriangleClassifier
