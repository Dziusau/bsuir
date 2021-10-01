#pragma once
#include "Teacher.h"
#include "Student.h"
#include "Question.h"
#include "Test.h"
#include "Authorization.h"
#include <memory>

class Menu {
public:
	unique_ptr<Teacher> teacher;
	unique_ptr<Student> student;

	Menu(Teacher teacher) {
		unique_ptr<Teacher> temp(new Teacher(teacher));
		this->teacher.swap(temp);
	}
	Menu(Student student) {
		unique_ptr<Student> temp(new Student(student));
		this->student.swap(temp);
	}

	void menu_teacher();
	void teacher_addQuest();
	void teacher_viewQuest();
	void teacher_deleteQuest(Test<int>&, Test<string>&, int);
	void teacher_editQuest(Question<string>&);
	void teacher_editQuest(Question<int>&);
	void teacher_viewStud(int);
	void teacher_searchStud(string);
	void teacher_edit(char);
	void teacher_deleteTeach();

	void menu_student();
	void student_passTest();
	void student_edit(char);
};