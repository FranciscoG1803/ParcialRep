/*
Sistema para gestionar información de Universidad. 

Cada Universidad tiene: 
    Nombre de la universidad (string) 
    Dirección (string) 
    Un arreglo de 5 estructuras anidadas que representen las Facultades de la universidad. 

Cada Facultad tiene: 
    Número de facultad (int) 
    Nombre de la carrera principal (string) 
    Número de estudiantes inscritos (int) 

Menú 

- Solicitar datos: Permitir ingresar la información de la universidad y sus facultades. 

- Imprimir información: Mostrar los datos registrados de la universidad y sus facultades. 

- Calcular total de estudiantes: Sumar todos los estudiantes de las facultades. 

- Buscar carrera: Ingresar el nombre de una carrera y verificar si existe en alguna facultad. 

- Salir del programa 
*/

#include <iostream>

using namespace std;

const int cantidad_facultades = 5;

struct Facultades
{
    int numero_facultad;
    string nombre_carrera;
    int estudiantes_inscritos;
};

struct Universidades
{
    string nombre_universidad;
    string direccion;
    Facultades facultades[cantidad_facultades];
};

Universidades RegistrarUniversidad(){
    Universidades u;
    cin.ignore();

    cout<<"\n-----Agregar Universidad-----"<<endl<<endl;
        cout<<"Ingrese el nombre de la universidad: ";
        getline(cin, u.nombre_universidad);
        
        cout<<"Ingrese la direccion de la universidad: ";
        getline(cin, u.direccion);

        cout<<"Ingrese las facultades de la universidad: ";
        for (int i = 0; i < cantidad_facultades; i++)
        {
            cout<<"\nIngrese el numero de la facultad: ";
            cin>>u.facultades[i].numero_facultad;
            cin.ignore();
            
            cout<<"Ingrese la carrera principal de la facultad: ";
            getline(cin, u.facultades[i].nombre_carrera);

            cout<<"Ingrese el numero de estudiantes de la facultad: ";
            cin>>u.facultades[i].estudiantes_inscritos;
            cin.ignore();
        }

    return u;
}

void MostrarUniversidades(Universidades &u){    
    cout<<"\n-----Lista de Universidades-----"<<endl<<endl;
    cout<<"Nombre de la universidad: "<<u.nombre_universidad<<endl;
    cout<<"Direccion de la universidad: "<<u.nombre_universidad<<endl;

    for (int i = 0; i < cantidad_facultades; i++)
    {
        cout<<"Num de la facultad: "<<u.facultades[i].numero_facultad<<endl;
        cout<<"Nombre de la Carrera: "<<u.facultades[i].nombre_carrera<<endl;
        cout<<"Num de estudiantes inscritos: "<<u.facultades[i].estudiantes_inscritos<<endl;
    }
}

void TotalEstudiantes(Universidades &u){    
    int total_estudiantes = 0;

    cout<<"\n-----Total de Estudiantes por Universidad-----"<<endl<<endl;
    cout<<"Nombre de la universidad: "<<u.nombre_universidad<<endl;
    for (int i = 0; i < cantidad_facultades; i++)
    {
        total_estudiantes += u.facultades[i].estudiantes_inscritos;
    }
    cout<<"Total de estudiantes: "<<total_estudiantes<<endl;
}

void BuscarFacultad(Universidades &u, string nombre_facultad){ 

    bool facultad_encontrada = false;
    int indice_facultad = 0;
    
    for (int i = 0; i < cantidad_facultades; i++)
    {
        if (nombre_facultad == u.facultades[i].nombre_carrera)
        {
            facultad_encontrada = true;
            indice_facultad = i;
        }
    }
    
    if (facultad_encontrada == true)
    {
        cout<<"\n-----Lista de Universidades-----"<<endl<<endl;
        cout<<"Nombre de la universidad: "<<u.nombre_universidad<<endl;
        cout<<"Direccion de la universidad: "<<u.nombre_universidad<<endl;

        cout<<"\nNum de la facultad: "<<u.facultades[indice_facultad].numero_facultad<<endl;
        cout<<"Nombre de la Carrera: "<<u.facultades[indice_facultad].nombre_carrera<<endl;
        cout<<"Num de estudiantes inscritos: "<<u.facultades[indice_facultad].estudiantes_inscritos<<endl;
    }

    else{
        cout<<"No se encontro ninguna facultad "<<endl;
    }
}

int main(){
    int cantidad_universidades = 3;
    int opciones = 0;
    int total_universidades = 0;
    
    Universidades u[cantidad_universidades];

    do
    {
      cout<<"\n-----Sistema de Gestionamiento de Universidades-----"<<endl<<endl;
        cout<<"1. Registrar universidad"<<endl;
        cout<<"2. Mostrar los datos de las universidades"<<endl;
        cout<<"3. Calcular total de estudiantes por facultad"<<endl;
        cout<<"4. Buscar carrera"<<endl;
        cout<<"5. Salir del programa"<<endl<<endl;
        cout<<"Que desea realizar: ";
        cin>>opciones;

        switch (opciones)
        {
        case 1:
            if (total_universidades < cantidad_universidades)
            {
                u[total_universidades] = RegistrarUniversidad();
                total_universidades++;
            }

            else {
                cout<<"Cantidad maxima de universidades registrada\n"<<endl;
            }
            
            break;
        
        case 2:
            if (total_universidades == 0)
            {
                cout<<"No existen universidades registradas\n"<<endl;
            }
            
            else{
                for (int i = 0; i < total_universidades; i++)
                {
                    MostrarUniversidades(u[i]);
                }
            }
            break;

        case 3:
            if (total_universidades == 0)
            {
                cout<<"No existen universidades registradas\n"<<endl;
            }
            
            else{
                for (int i = 0; i < total_universidades; i++)
                {
                    TotalEstudiantes(u[i]);
                }
            }
            break;

        case 4:
            if (total_universidades == 0)
            {
                cout<<"No existen universidades registradas\n"<<endl;
            }
            
            else{
                string nombre_facultad;

                cout<<"\nIngrese el nombre de la facultad que desea buscar: ";
                cin>>nombre_facultad;
                for (int i = 0; i < total_universidades; i++)
                {
                    BuscarFacultad(u[i], nombre_facultad);
                }
            }
            break;

        case 5:
            cout<<"Saliendo del programa..."<<endl;
            break;

        default:
            break;
        }

    } while (opciones != 5);
    
}