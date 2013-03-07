akenQueue.o CourseTaken.o CourseTaughtQueue.o CourseTaught.o WorkExperienceQueue.o WorkExperience.o
	g++ -o cutaes main.o mainmenu.o Student.o Application.o studentmenu.o applicationUI.o adminmenu.o summarypending.o CourseTakenQueue.o CourseTaken.o CourseTaughtQueue.o CourseTaught.o WorkExperienceQueue.o WorkExperience.o `pkg-config gtkmm-3.0 --cflags --libs`

main.o:	main.cpp mainmenu.h
	g++ -c main.cpp `pkg-config gtkmm-3.0 --cflags --libs`

mainmenu.o:	mainmenu.cpp mainmenu.h
	ainmenu.cpp `pkg-config gtkmm-3.0 --cflags --libs`

Application.o: Application.cpp Application.h
	g++ -c Application.cpp
	
Student.o: Student.cpp Student.h Application.h
	g++ -c Student.cpp

studentmenu.o:	studentmenu.cpp studentmenu.h
	g++ -c studentmenu.cpp `pkg-config gtkmm-3.0 --cflags --libs`

applicationUI.o:	applicationUI.cpp applicationUI.h Student.h CourseTakenQueue.h CourseTaughtQueue.h WorkExperienceQueue.h
	g++ -c applicationUI.cpp `pkg-config gtkmm-3.0 --cflags --libs`

adminmenu.o:	adminmenu.cpp adminmenu.h
	g++ -c adminmenu.cpp `pkg-config gtkmm-3.0 --cflags --libs`

summarypending.o:	summarypending.cpp summarypending.h
	g++ -c summarypending.cpp `pkg-config gtkmm-3.0 --cflags --libs`
	
CourseTakenQueue.o:	CourseTakenQueue.cpp CourseTakenQueue.h
	g++ -c CourseTakenQueue.cpp 

CourseTaken.o:	CourseTaken.cpp CourseTaken.h
	g++ -c CourseTaken.cpp 

CourseTaughtQueue.o:	CourseTaughtQueue.cpp CourseTaughtQueue.h
	g++ -c CourseTaughtQueue.cpp 

CourseTaught.o:	CourseTaught.cpp CourseTaught.h
	g++ -c CourseTaught.cpp 
	
WorkExperienceQueue.o:	WorkExperienceQueue.cpp WorkExperienceQueue.h
	g++ -c WorkExperienceQueue.cpp 

WorkExperience.o:	WorkExperience.cpp WorkExperience.h
	g++ -c WorkExperience.cpp 
	
clean:
	rm -f *.o mainMenu cutaes
