#include "Header.h"


Employee::Employee(const char* Full_name_, const char* company_, const char* job_title_, int salary_, int experience_) {
	this->Full_name = new char[strlen(Full_name_) + 1];
	strcpy(this->Full_name, Full_name_);
	this->company = new char[strlen(company_) + 1];
	strcpy(this->company, company_);
	this->job_title = new char[strlen(job_title_) + 1];
	strcpy(this->job_title, job_title_);
	salary = salary_;
	experience = experience_;
}

Employee::Employee(const Employee* obj) {

	this->Full_name = new char[strlen(obj->Full_name) + 1];
	strcpy(this->Full_name, obj->Full_name);
	this->company = new char[strlen(obj->company) + 1];
	strcpy(this->company, obj->company);
	this->job_title = new char[strlen(obj->job_title) + 1];
	strcpy(this->job_title, obj->job_title);
	salary = obj->salary;
	experience = obj->experience;

}

Employee::~Employee() {

	if (Full_name != nullptr) {
		delete[] Full_name;
		Full_name = nullptr;
	}
	if (company != nullptr) {
		delete[] company;
		company = nullptr;
	}
	if (job_title != nullptr) {
		delete[] job_title;
		job_title = nullptr;
	}
}

void Employee::Input() {

	if (Full_name != nullptr) delete[] Full_name;
	if (company != nullptr) delete[] company;
	if (job_title != nullptr) delete[] job_title;


	char* str = new char[100];

	cout << "Введите Фамилию" << endl;
	cin >> str;
	Full_name = new char[strlen(str) + 1];
	strcpy(Full_name, str);

	cout << "Компанию" << endl;
	cin >> str;
	company = new char[strlen(str) + 1];
	strcpy(company, str);

	cout << "Должность" << endl;
	cin >> str;
	job_title = new char[strlen(str) + 1];
	strcpy(job_title, str);

	cout << "Зарплату" << endl;
	cin >> salary;
	cout << "Опыт" << endl;
	cin >> experience;
}

void Employee::Output() const {
	cout << "ФИО:" << Full_name << endl;
	cout << "предприятие: " << company << endl;
	cout << "должность: " << salary << endl;
	cout << "зарплата: " << experience << endl;
	cout << "стаж: " << job_title << endl;
}


Self_Employeed::Self_Employeed(int duration_work, const char* Full_name_, const char* company_, const char* job_title_, \
	int salary_, int experience_) : Employee(Full_name_, company_, job_title_, salary_, experience_) {

	this->duration_work = duration_work;
}

Self_Employeed::~Self_Employeed() { };

void Self_Employeed::Input() {

	Employee::Input();

	cout << "Введите время работы" << endl;
	cin >> duration_work;
}

void Self_Employeed::Output() const {
	Employee::Output();
	cout << "Вреия работы: " << duration_work << endl;
}


Businessman::Businessman(const char* business, int duration_work, const char* Full_name_, const char* company_, const char* job_title_, \
	int salary_, int experience_) : Self_Employeed(duration_work, Full_name_, company_, job_title_, salary_, experience_) {

	this->business = new char[strlen(business) + 1];
	strcpy(this->business, business);
}


Businessman::~Businessman() {
	if (business != nullptr) {
		delete[] business;
		business = nullptr;
	}
}


void Businessman::Input() {

	if (business != nullptr) delete[] business;

	Self_Employeed::Input();

	char* str = new char[100];
	cout << "Введите бизнес" << endl;
	cin >> str;
	business = new char[strlen(str) + 1];
	strcpy(business, str);
}

void Businessman::Output() const {
	Self_Employeed::Output();
	cout << "Бизнес: " << business << endl;
}


int Businessman::operator || (const char* str) {

	int count = min(strlen(str), strlen(business));

	if (count < 2) throw("error symbol\n");

	return strncmp(str + 1, business + 1, count - 1);
}
int Businessman::operator || (const Businessman* obj) {
	return *this || obj->get_business();
}


void Businessman::operator - (const char* str) {

	if (str == nullptr || business == nullptr || strlen(business) < 2) throw("error symbol\n");

	char* tmp = business;
	business = new char[strlen(str) + strlen(tmp) + 1]{ '\0' };
	business[0] = tmp[0];
	strcat(business, str);
	strcat(business, tmp + 1);

	if (tmp != nullptr) delete[] tmp;
}
void Businessman::operator - (const Businessman* obj) {
	return *this - obj->get_business();
}


Translator::Translator(const char* language, const char* Full_name_, const char* company_, const char* job_title_, \
	int salary_, int experience_) : Employee(Full_name_, company_, job_title_, salary_, experience_) {

	this->language = new char[strlen(language) + 1];
	strcpy(this->language, language);
}

Translator::~Translator() {
	if (language != nullptr) {
		delete[] language;
		language = nullptr;
	}
};

void Translator::Input() {

	Employee::Input();

	char* str = new char[100];
	cout << "Введите язык" << endl;
	cin >> str;
	language = new char[strlen(str) + 1];
	strcpy(language, str);

}

void Translator::Output() const {
	Employee::Output();
	cout << "Язык: " << language << endl;
}