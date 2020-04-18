app:
	g++ cppFX/src/*.cpp cppFX/src/utility/*.cpp sandbox/sandboxApp.cpp -IcppFX/include -o app  -lGL -lGLEW -lglut