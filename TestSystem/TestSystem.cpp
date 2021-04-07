#include <iostream>
#include <list>
using namespace std;

class User;
template <typename T> class Student;
template <typename T> class Question;

class User 
{
    int key;
    string login;
    string password;

public:
    User(int key) :key(key), login(""), password("") {};

    int getKey() { return key; }
    string getLogin() { return login; }
    string getPassword() { return password; }

    void setLogin(string login) { this->login = login; }
    void setPassword(string password) { this->password = password; }
};

template <typename T>
class Student :User 
{
public:
    Student() :User(0) {};

    void answer(Question<T>, T);
};

template <typename T>
class Teacher :User 
{
public:
    Teacher() :User(1) {};

    void newQuestion(list<Question<T>>);
};

template <typename T>
class Question 
{
    string question;
    T answer;
    bool isRight;

public:
    Question() :question(""), answer(T()), isRight(false) {};

    int setQuestion(int, string);
    int setAnswer(int, T);
    bool checkAnswer(T);
    
    void write2file();

};

template<typename T>
int Question<T>::setQuestion(int key, string question) 
{
    if (key) 
    {
        this->question = question;
        return 1;
    }
    else return 0;
}

template<typename T>
int Question<T>::setAnswer(int key, T answer)
{
    if (key)
    {
        this->answer = answer;
        return 1;
    }
    else return 0;
}

template<typename T>
bool Question<T>::checkAnswer(T answer)
{
    return isRight = (this->answer == answer) ? true : false;
}

template <typename T>
void Student<T>::answer(Question<T> question, T answer)
{
    if (question.checkAnswer(answer)) cout << "Correct answer" << endl;
    else cout << "Uncorrect answer" << endl;
}

template<typename T>
void Teacher<T>::newQuestion(list<Question<T>> questions)
{
    Question<T> question;
    cout << "Enter the question: ";
    string str;
    cin >> str;
    question.setQuestion(this->getKey(), str);
    cout << endl << "Enter answer: ";
    T answer;
    cin >> answer;
    question.setAnswer(this->getKey(), answer);
    questions.push_back(question);
}

int main()
{
    list<Question<int>> questions;
    Teacher<int> teacher;
    teacher.newQuestion(questions);

    Student<int> student;
    student.answer(questions.back(), 1);

}