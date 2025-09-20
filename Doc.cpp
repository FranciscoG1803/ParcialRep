/*5. Structs básicos
Crea un struct Estudiante que almacene: nombre, edad y promedio.
    - Pide al usuario los datos de 3 estudiantes.
    - Imprime cuál tiene el mejor promedio.*/

#include <iostream>
#include <string>

using namespace std;

int cantidad_estudiantes = 3;

struct Estudiante
{
    string nombre;
    int edad = 0;
    float promedio = 0;
};

Estudiante IngresarEstudiante(){
    Estudiante e;
    cin.ignore();

    cout<<"\n----------------------------------------\n";
    cout<<"Ingrese el nombre del estudiante: ";
    getline(cin, e.nombre);

    cout<<"Ingrese la edad del estudiante: ";
    cin>>e.edad;

    cout<<"Ingrese el promedio del estudiante: ";
    cin>>e.promedio;

    return e;
}

void MostrarEstudiantes(Estudiante &e){
    cout<<"\n----------------------------------------\n";
    cout<<"Nombre del estudiante: "<<e.nombre<<endl;
    cout<<"Edad del estudiante: "<<e.edad<<endl;
    cout<<"Promedio del estudiante: "<<e.promedio<<endl;
}

int main(){

    Estudiante e[cantidad_estudiantes];
    int opcion = 0;
    int total_estudiante = 0;

    do
    {
        cout<<"\n----------------------------------------\n";
        cout<<"1. Ingresar estudiante\n";
        cout<<"2. Mostrar estudiantes\n";
        cout<<"1. Promedio mas alto\n";
        cout<<"4. Salir del programa\n";
        cout<<"Eliga la opcion: ";
        cin>>opcion;

        switch (opcion)
        {
        case 1:
            if (total_estudiante < cantidad_estudiantes)
            {
                e[total_estudiante] = IngresarEstudiante();
                total_estudiante++;
            }
            
            else{
                cout<<"\nLimite de estudiantes registrados, alcanzados";
            }
            
            break;
        
        case 2:
            if (total_estudiante == 0)
            {
                cout<<"\nNo se ha registrado ningun estudiante";
            }

            else{
                for (int i = 0; i < total_estudiante; i++)
                {
                    MostrarEstudiantes(e[i]);
                }
                
            }
            
            break;

        case 3:
            /* code */
            break;

        case 4:
            /* code */
            break;

        default:
            break;
        }
    } while (opcion != 4);
    
    
    return 0;
}