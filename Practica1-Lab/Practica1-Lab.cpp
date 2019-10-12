#include <iostream>
#include <iomanip> /* Contiene prototipos de función para manipuladores de flujo que
dan formato a flujos de datos. Permitirá formatear y organizar
la salida de datos. */
#include <vector>
#include <string>

//C indica que es una clase
//refijo m_ indica que es un atributo miembro

using namespace std;
class Persona // Clase Base Persona
{
protected:
	char nombre[40];
	int edad;
public:
	// Funciones Miembro
	Persona() { }; // constructor por defecto
	virtual void leerdatos();
	virtual void imprimirdatos();
};
// Declaración del Método para dar valor a los atributos de la clase Persona
void Persona::leerdatos()
{
	cout << "Digitar el Nombre : " << endl;
	cin >> nombre;
	cout << "Digitar la Edad: " << endl;
	cin >> edad;
}
// Método que despliega los valores de los atributos de una persona
void Persona::imprimirdatos()
{
	cout << endl << endl;
	cout << "----- Imprimir los Datos del Empleado -----" << endl;
	cout << "Nombre : " << nombre << endl;
	cout << "Edad : " << edad << " a";
	printf("%c", 164); // Para mostrar la letra "ñ"
	cout << "os" << endl;
}
/* Definición de la Clase Empleado como clase derivada de la clase Persona. Se utiliza
herencia pública */
class Empleado : public Persona
{
protected:
	float salarioanual;
	char cargo[60];
public:
	Empleado() { }; // constructor por defecto
	virtual void leeremp();
	virtual void imprimiremp();
};
// Declaración del Método para dar valor a los atributos de la clase Empleado
void Empleado::leeremp()
{
	Persona::leerdatos();
	cout << "Introducir Cargo:" << endl;
	cin >> cargo;
	cout << "Introducir Sueldo:" << endl;
	cin >> salarioanual;
}
// Método que despliega los valores de los atributos de un empleado
void Empleado::imprimiremp()
{
	Persona::imprimirdatos();
	cout << "Cargo del empleado: " << cargo << endl;
	cout << "Sueldo anual empleado: $ " << fixed << showpoint << setprecision(2)
		<< salarioanual << endl;
}

//CEstudiante class definition
class CEstudiante : public Persona
{
protected:
	//Students ID Numnber
	int m_id_number; 
	//Students highest grade obtained
	char m_highest_grade[40];
public:
	//contstructor
	CEstudiante() {}; 
	
	virtual void set_estudiante();
	
	virtual void get_estudiante();
};
//Sets CEstudiante class
void CEstudiante::set_estudiante() 
{
	Persona::leerdatos();
	cout << "Introducir numero de carnet:" << endl;
	cin >> m_id_number;
	cout << "Introducir grado de instruccion" << endl;
	cin >> m_highest_grade;
}
//Gets CEstudiante class
void CEstudiante::get_estudiante()
{
	Persona::imprimirdatos();
	cout << "Carnet del estudiante:" << m_highest_grade << endl;
	cout << "Grado de instruccion" << m_highest_grade << endl;
}

//CUniversitario class definition, inherits from CEstudiante
class CUniversitario : public CEstudiante 
{
	
	//TODO: add CUM, averiguar que es CUM
protected:
	char m_university_name[40];
	char m_major_name[40];
	vector<string> m_subjects;
	vector<float> m_grades;
	float m_promedio;
public:
	CUniversitario() {};
	virtual void get_promedio();
	virtual void set_subjects_and_grades();
	virtual void get_subjects_and_grades();
	virtual void set_CUniversitario();
	virtual void get_CUniversitario();

};

void CUniversitario::set_subjects_and_grades()
{
	int ite = 1;
	string subj= "";
	int nota=0;
	do {
		cout << "Ingrese una materia" << endl;
		cin >> subj;
		m_subjects.push_back(subj);
		cout << "Ingrese la nota de la materia:" << endl;
		cin >> nota;
		m_grades.push_back(nota);
		cout << "Desea ingresar mas materias y notas? SI[1], NO[0]" << endl;
		cin >> ite;
	} while (ite != 0);

}
void CUniversitario::get_subjects_and_grades()
{
	int ite = m_subjects.size() - 1;
	cout << "Materias y notas:" << endl;
	for (int i = 0; i <= ite; i++) {
		cout << m_subjects[i] << ": " << m_grades[i] << "." << endl;
	}
}
void CUniversitario::set_CUniversitario()
{
	CEstudiante::set_estudiante();
	cout << "Nombre de la universidad:" << endl;
	cin >> m_university_name;
	cout << "Nombre de la carrera" << endl;
	cin >> m_major_name;
	set_subjects_and_grades();
	get_promedio();
}
void CUniversitario::get_CUniversitario()
{
	CEstudiante::get_estudiante();
	cout << "Nombre de la universidad:" << m_university_name << endl;
	cout << "Nombre de la carrera" << m_major_name << endl;
	get_subjects_and_grades();
}
void CUniversitario::get_promedio() {
	int iter = this->m_grades.size() - 1;
	float grade=0;
	for (int it = 0; it <= iter; it++) { grade = +this->m_grades[it]; }
	this->m_promedio = grade / this->m_grades.size();


}

class CPasante : public Empleado, public CUniversitario
{
	//nombre del proyecto, total de horas (duraciónd e la pasantía), número de horas completadas.
protected:
	char m_project_name;
	int m_total_hours;
	int m_completed_hours;
public:
	CPasante() {};
	
	void get_CPasante_promedio();
	void set_CPasante();
	
	void get_CPasante();
};
//Sets the CPasante class
void CPasante::set_CPasante()
{
	Empleado::leeremp();
	CUniversitario::set_CUniversitario();
	cout << "Nombre del projecto:" << endl;
	cin >> m_project_name;
	cout << "Total de horas:" << endl;
	cin >> m_total_hours;
	cout << "Horas completadas: " << endl;
	cin >> m_completed_hours;
}
//Prints the CPasante class
void CPasante::get_CPasante()
{
	Empleado::imprimiremp();
	CUniversitario::get_CUniversitario();
	cout << "Nombre del projecto:" << m_project_name << endl;
	cout << "Total de horas:" << m_total_hours << endl;
	cout << "Horas completadas: " << m_completed_hours << endl;
}


int main()
{
	vector<CPasante> listaDePasantes;
	CPasante pasante;
	int ite = 1;
	do {
		cout << "Desdea agregar un pasante? SI[1], NO[0] " << endl;
		cin >> ite;
		pasante.set_CPasante();
		listaDePasantes.push_back(pasante);
	} while (ite != 0);
	system("pause>nul");
	return 0;
}