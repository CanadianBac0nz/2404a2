Testing
Team Carmack4Prez

Instructions and comments:
	-	uses gtkmm-3.0
	-	compile with "make"
	-	execute with "./cutaes"
	-	navigate using the menu buttons
	
	-	to create a new application select Student->Create an application
		select a course from the pulldown and enter information into the fields
		click submit when the information has been entered
		Optionally an applicant can enter relevant courses taken, relevant courses taught as a TA
		and relevant work experience. When the fields have been filled hitting add will add it to
		the application.

	-	each application is stored separately in the /applications/ folder under their application number.
		this does mean that there is duplicated information when more than one application is made by a student
		this is done to limit complexity in our file structure

	-	Note that the "responsibilities" field is not labelled correctly and is the box that sits above the
		the error box at the bottom of the window. Text written to this box will be taken as responsibilities
		associated with the job added.
	-	view pending summary allows the admin to view a list of pending applications
		the scrollbox is fixed at an incorrect size but will show all the applications.

	-	saving a list of pending applications will create a file in the /summaries/ folder that
		uses the course code as its name.

		the field at the bottom will update with error messages for invalid/incomplete fields
		exit the application using the exit button in the main menu
	-	to create a 
		
	-	certain functionality not required in assignment 2 have buttons in the menus
		however their handlers have not been implemented eg."Edit an application"
		
	-	the program requires three text files, applicationCounter.txt and applications.txt, temp.txt
		it will update all of these text files when an application is accepted
	
	-	there is a memory leak of around 1.5 MB upon exit after creating a single application entry
