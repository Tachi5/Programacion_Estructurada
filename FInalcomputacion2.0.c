#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct noPatologicos{
	char alimentacion[150];
	char vacunas[20];
	char banio[30];
	char estudios[50];
};

struct aPatologicos{
	char enfermedades[100];
	char tabaquismo[50];
	char alcoholismo[50];
	char quirurgicos[100];
};

struct aHeredofamiliares{
	char DM[40];
	char HAS[40];
	char cancer[40];
	char renales[40];
};

struct signosV{
	int fc;
	int fr;
	float temp;
	int taS;
	int taD;
	float peso;
	float altura;
};
struct pacientes{
	char fecha[20];
	int folio;
	char nombres[60];
	char apellidoP[20];
	char apellidoM[20];
	char exp[5];
	int edad;
	char direccion[100];
	char sexo;
	char escolaridad[30];
	char ocupacion[30];
	char alergias[30];
	char pActual[500];
	struct noPatologicos APNP;
	struct aPatologicos APP;
	struct aHeredofamiliares AHF;
	char PEPA[500];
	struct signosV signos;
	char EF[1500];
	char dx[200];
	char tx[500];
}paciente[20];

struct notas{
	int folioN;
	int registroExp;
	char fechaN[20];
	char padecimientoN[100];
	char PEPAN[500];
	char EFN[1500];
	char diagnosticoN[200];
	char tratamientoN[500];
}pacienteN[20];

struct reportes{
	char fecha[20];
	int consultas;
	int inyecciones;
	int TA;
	int gananciaDia;
}reporte[20];

/*void datosPrueba(){
strcpy(paciente[1].nombres,"Aldo");
strcpy(paciente[1].apellidoP,"Arellano");
strcpy(paciente[1].apellidoM,"Romero");
strcpy(paciente[1].exp,"3333");
paciente[1].folio=1234;
paciente[1].edad=30;
strcpy(paciente[1].fecha,"9 junio 2018");
strcpy(paciente[1].direccion,"bahia #23");
paciente[1].sexo='m';
strcpy(paciente[1].escolaridad,"maestria");
strcpy(paciente[1].ocupacion,"Programador");
strcpy(paciente[1].alergias,"perro");
//APNP
strcpy(paciente[1].APNP.alimentacion,"inadecuada");
strcpy(paciente[1].APNP.vacunas,"Esquema incompleto");
strcpy(paciente[1].APNP.banio,"cada 2 dias");
strcpy(paciente[1].APNP.estudios,"maestria");
//APP
strcpy(paciente[1].APP.alcoholismo,"2 cervezas cada 7 dias");
strcpy(paciente[1].APP.enfermedades,"Neg");
strcpy(paciente[1].APP.quirurgicos,"Neg");
strcpy(paciente[1].APP.tabaquismo,"1 al dia");
//AHF
strcpy(paciente[1].AHF.cancer,"Tio");
strcpy(paciente[1].AHF.DM,"neg");
strcpy(paciente[1].AHF.HAS,"madre");
strcpy(paciente[1].AHF.renales,"tia");
//PEPA
strcpy(paciente[1].PEPA,"el paciente inicio hace 3 dias con datos de poliuria polidipsia y polifagia, lo cual le ha generado interes con su saled, por los antecedentes familiares de diabetes se realizo una QS que muestra una glucosa en ayuno de 160 mg/dl");
//EF
paciente[1].signos.altura=1.84;
paciente[1].signos.fc=70;
paciente[1].signos.fr=19;
paciente[1].signos.peso=75;
paciente[1].signos.taD=90;
paciente[1].signos.taS=130;
paciente[1].signos.temp=37.2;

strcpy(paciente[1].EF,"paciente consciente orientado en tiempo persona y espacio, glasgow de 14, con adecuada hidratacion");
strcpy(paciente[1].dx,"1.-DIabetes mellitus");
strcpy(paciente[1].tx,"metformina tabs 500 mg tomar 2 cada 12 hrs por 1 semana");


strcpy(paciente[0].nombres,"Felipe");
strcpy(paciente[0].apellidoP,"Tachiquin");
strcpy(paciente[0].apellidoM,"Alvarez");
strcpy(paciente[0].exp,"1111");
paciente[0].folio=1111;
paciente[0].edad=26;
strcpy(paciente[0].fecha,"1 Diciembre 2018");
strcpy(paciente[0].direccion,"abedules #23");
paciente[0].sexo='m';
strcpy(paciente[0].escolaridad,"Licenciatura");
strcpy(paciente[0].ocupacion,"Trabajador");
strcpy(paciente[0].alergias,"negadas");
//APN0
strcpy(paciente[0].APNP.alimentacion,"adecuada");
strcpy(paciente[0].APNP.vacunas,"Esquema completo");
strcpy(paciente[0].APNP.banio,"Diario");
strcpy(paciente[0].APNP.estudios,"Licenciatura");
//APP
strcpy(paciente[0].APP.alcoholismo,"negado");
strcpy(paciente[0].APP.enfermedades,"Diabetes mellitus 2");
strcpy(paciente[0].APP.quirurgicos,"Apendicectomia 12 anios");
strcpy(paciente[0].APP.tabaquismo,"negado");
//AHF
strcpy(paciente[0].AHF.cancer,"neg");
strcpy(paciente[0].AHF.DM,"Abuela");
strcpy(paciente[0].AHF.HAS,"neg");
strcpy(paciente[0].AHF.renales,"neg");
//PEPA
strcpy(paciente[0].PEPA,"el paciente inicio hace 2 dias con evacuaciones diarreicas bristol 5, para lo cual consumio medicamento no especificado autorecetado, sin llegar a sentir mejoria alguna, por lo que acude a consulta");
//EF
paciente[0].signos.altura=1.75;
paciente[0].signos.fc=88;
paciente[0].signos.fr=20;
paciente[0].signos.peso=76;
paciente[0].signos.taD=80;
paciente[0].signos.taS=120;
paciente[0].signos.temp=36.4;

strcpy(paciente[0].EF,"paciente consciente orientado en tiempo persona y espacio, glasgow de 15, con inadecuada hidratacion y coloracion de piel y tegumentos, craneo normocefalo, pupilas isocoricas, normoreflecticas, labios deshidratados, abdomen plano, blando depresible, doloros a la palpacion profunda");
strcpy(paciente[0].dx,"1.-grastroenteriris infecciosa");
strcpy(paciente[0].tx,"Ciprofloxacino tabs 500 mg tomar 1 cada 12 hrs por 5 dias + biomesina compuesta tabs 10/250 mg tomar 1 cada 8 hrs por 3 dias");


strcpy(paciente[2].nombres,"Aldo");
strcpy(paciente[2].apellidoP,"Arellano");
strcpy(paciente[2].apellidoM,"perez");
strcpy(paciente[2].exp,"2222");
paciente[2].folio=1111;
paciente[2].edad=26;
strcpy(paciente[2].fecha,"1 Diciembre 2018");
strcpy(paciente[2].direccion,"abedules #23");
paciente[2].sexo='m';
strcpy(paciente[2].escolaridad,"Licenciatura");
strcpy(paciente[2].ocupacion,"Trabajador");
strcpy(paciente[2].alergias,"negadas");
//APN0
strcpy(paciente[2].APNP.alimentacion,"adecuada");
strcpy(paciente[2].APNP.vacunas,"Esquema completo");
strcpy(paciente[2].APNP.banio,"Diario");
strcpy(paciente[2].APNP.estudios,"Licenciatura");
//APP
strcpy(paciente[2].APP.alcoholismo,"negado");
strcpy(paciente[2].APP.enfermedades,"Diabetes mellitus 2");
strcpy(paciente[2].APP.quirurgicos,"Apendicectomia 12 anios");
strcpy(paciente[2].APP.tabaquismo,"negado");
//AHF
strcpy(paciente[2].AHF.cancer,"neg");
strcpy(paciente[2].AHF.DM,"Abuela");
strcpy(paciente[2].AHF.HAS,"neg");
strcpy(paciente[2].AHF.renales,"neg");
//PEPA
strcpy(paciente[2].PEPA,"el paciente inicio hace 2 dias con evacuaciones diarreicas bristol 5, para lo cual consumio medicamento no especificado autorecetado, sin llegar a sentir mejoria alguna, por lo que acude a consulta");
//EF
paciente[2].signos.altura=1.75;
paciente[2].signos.fc=88;
paciente[2].signos.fr=20;
paciente[2].signos.peso=76;
paciente[2].signos.taD=80;
paciente[2].signos.taS=120;
paciente[2].signos.temp=36.4;

strcpy(paciente[2].EF,"paciente consciente orientado en tiempo persona y espacio, glasgow de 15, con inadecuada hidratacion y coloracion de piel y tegumentos, craneo normocefalo, pupilas isocoricas, normoreflecticas, labios deshidratados, abdomen plano, blando depresible, doloros a la palpacion profunda");
strcpy(paciente[2].dx,"1.-grastroenteriris infecciosa");
strcpy(paciente[2].tx,"Ciprofloxacino tabs 500 mg tomar 1 cada 12 hrs por 5 dias + biomesina compuesta tabs 10/250 mg tomar 1 cada 8 hrs por 3 dias");

}
*/
int busquedaFolio(int nAnteriores, int buscar){
	int i;
	
	for (i=0; i<nAnteriores;i++)
		{	
		if (pacienteN[i].folioN == buscar){
			return i;
		}
	}
	return -1;
}


int busquedaExpediente(int totalExpediente, char buscar[10]){
	int i;
	
	for (i=0; i<totalExpediente;i++)
		{	
		if (strcmp(paciente[i].exp, buscar)==0){
			return i;
		}
	}
	return -1;
}

void gotoxy(int x, int y)
	{
	HANDLE ventana;
	ventana =GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cordenadas;
	cordenadas.X = x;
	cordenadas.Y = y;
	SetConsoleCursorPosition(ventana,cordenadas);
	}


// ----------------------------------------------------------------------------

/////////////////////////Funciones de menu////////////////////////////////////////

int menuNotas(int *nAnteriores,int px){
	int opcionNotas,i, existe;
	
	printf("\nSe encontro lo solicitado\n\n Elija la opcion deseada:\n");
	printf("\n 1.-Notas anteriores del paciente\n 2.-Nueva nota\n 3.-Salir\n\nOpcion:");
	scanf("%i",&opcionNotas);

	switch (opcionNotas){ 
	case 1: 
	
	// falta revisar este espacio
	if(nAnteriores>0){
		
	system("cls");
	gotoxy(2,1);printf("FOLIO");
	gotoxy(25,1);printf("FECHA");
	gotoxy(55,1);printf("DIAGNOSTICO");
	
	
	for (i=0;i<(*nAnteriores);i++){   
	if(px ==  pacienteN[i].registroExp){
		
		gotoxy(2,4+i);printf("%i", pacienteN[i].folioN);
		gotoxy(25,4+i);printf("%s",pacienteN[i].fechaN);
		gotoxy(55,4+i);printf("%s",pacienteN[i].diagnosticoN);
	}
	}
	
	
} else {
	
		printf("No existen notas almacenadas");	
}

	break;

	case 2:
		
		
	system("cls");
	printf("\t\t\t\t\tNota medica");
	gotoxy(1,2); printf("Fecha: ");
	gotoxy(40,2); printf("Expediente: ");
	gotoxy(52,2);printf("%s",paciente[px].exp);
	gotoxy(62,2);printf("Folio: ");
	
	gotoxy(1,3); printf("Nombres: ");
	gotoxy(10,3); printf("%s ",paciente[px].nombres);
	gotoxy(32,3);printf("%s ",paciente[px].apellidoP);
	gotoxy(52,3);printf("%s ",paciente[px].apellidoM);
	gotoxy(65,3);printf("Edad: "); 
	gotoxy(72,3);printf("%i",paciente[px].edad);
	gotoxy(76,3);printf("anios");
	gotoxy(87,3);printf("Alergias: ");
	gotoxy(97,3);printf("%s",paciente[px].alergias);
	
	gotoxy(1,5);printf("Padecimiento actual: ");
	gotoxy(1,9);printf("Principio y evolucion del padecimiento actual: ");
	gotoxy(1,14);printf("Exploracion fisica: ");
	gotoxy(1,19);printf("Diagnostico: ");
	gotoxy(1,23);printf("Tratamiento: ");
	
	
	pacienteN[*nAnteriores].registroExp = px;
	fflush(stdin);
	gotoxy(9,2); gets(pacienteN[*nAnteriores].fechaN); 
	gotoxy(70,2);scanf("%i",&pacienteN[*nAnteriores].folioN);
	fflush(stdin);
	gotoxy(1,6);gets(pacienteN[*nAnteriores].padecimientoN);
	gotoxy(1,10);gets(pacienteN[*nAnteriores].PEPAN);
	gotoxy(1,15);gets(pacienteN[*nAnteriores].EFN);
	gotoxy(1,20);gets(pacienteN[*nAnteriores].diagnosticoN);
	fflush(stdin);
	gotoxy(1,24);gets(pacienteN[*nAnteriores].tratamientoN);
	
	 (*nAnteriores)++;
	break;
	
	case 3://regresar a menu principal
	break;
	
	default:
	printf("\nOpcion no valida");
	break;
}
}

/////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////// BUSQUEDA APELLIDO  ////////////////////////////////////////////////////

	int busquedaNombre(int nAnteriores, char name[30], char lastName[30]){
	int i, j, existe=0;
	char expedienteBusqueda [10];
	j = 8;
	system("cls");
	for (i=0; i<nAnteriores;i++){
		if (strcmp(lastName,paciente[i].apellidoP)==0 && strcmp(name,paciente[i].nombres)==0) {
				gotoxy(2,7); printf("No.Exp");
				gotoxy(2,j);printf(paciente[i].exp);
				gotoxy(13,7);printf("Apellido paterno");
				gotoxy(13,j);printf(paciente[i].apellidoP);
				gotoxy(34,7);printf("Apellido materno");
				gotoxy(34,j);printf(paciente[i].apellidoM);
				gotoxy(54,7);printf("Nombre");
				gotoxy(54,j);printf(paciente[i].nombres);
				existe = 1;
				j++;
				printf("\n");						
			}	
	}
	if(existe==1){
		printf("\n\nPara corroborar el No. Expediente escribalo a continuacion: \nExpediente: ");
		fflush(stdin);
		gets(expedienteBusqueda);
		return busquedaExpediente(nAnteriores, expedienteBusqueda);
	}
	return -1;
}
	
	/////////////////////////////////////////////////////////////////
	


int main (){
	
	
	int edad,opcionPrincipal, opcionBusqueda, opcionReporte,salir=0,i,bandera1=0,ganancias, folio,folioB,totalExpedientes=0,existe;
	int totalD,consulta, inyeccion, presion, consultaP, inyeccionP,presionP, costoT, reporteTotal=0, sumatoria, nAnteriores=0;
	int consultaD,inyeccionD,presionD,regGuardado, subTotal, banderaFolio=0;
	char agregar[2], name[30], lastName[30], expedienteB[5];

	//datosPrueba();
	//totalExpedientes=3;

do{		
	system("cls");
	printf("\t\t\t BIENVENIDO AL EXPEDIENTE MEDICO");
	printf("\n\n Por favor seleccione la opcion deseada");
	printf("\n\n 1.- Ingresar paciente (primera vez)\n 2.- Busqueda \n 3.- Reportes \n 4.- Salir\n\n Opcion: ");

	scanf("%i",&opcionPrincipal);
	
	switch(opcionPrincipal){
		case 1:
			system("cls");
			gotoxy(1,2); printf("Fecha: ");
			gotoxy(45,2); printf("Expediente: ");
			//gotoxy(80,2);printf("No. Folio: ");
			gotoxy(1,3); printf("Nombres: ");
			gotoxy(45,3); printf("Apellido paterno: ");
			gotoxy(85,3); printf("Apellido materno: ");
			gotoxy(1,4); printf("Edad: ");
			gotoxy(12,4); printf("anios");
			gotoxy(26,4); printf("Sexo (m/f): ");
			gotoxy(45,4); printf("Escolaridad: ");
			gotoxy(1,5); printf("Ocupacion: ");
			gotoxy(45,5); printf("Alergias: ");
			gotoxy(1,6); printf("Direccion: ");
			gotoxy(1,8); printf("\t\t\t\tAntecedentes personales no patologicos ");
			gotoxy(1,10); printf("Alimentacion: ");
			gotoxy(1,12); printf("Inmunizaciones: ");
			gotoxy(45,12); printf("Banio: ");
			gotoxy(1,13); printf("Grado maximo de estudios: ");
			gotoxy(1,15); printf("\t\t\t\tAntecedentes personales patologicos ");
			gotoxy(1,17); printf("Enfermedades actuales: ");
			gotoxy(1,18);printf("Tabaquismo: ");
			gotoxy(1,19);printf("Alcoholismo: ");
			gotoxy(1,20);printf("Quirurgicos: ");
			gotoxy(1,22);printf("\t\t\t\tAntecedentes Heredofamiliares ");
			gotoxy(1,24);printf("Diabetes: ");
			gotoxy(45,24);printf("Hipertension: ");
			gotoxy(1,25);printf("Cancer: ");
			gotoxy(45,25);printf("Renales: ");
			gotoxy(1,28);printf("\t\t\t\tPrincipo y Evolucion del Padecimiento Actual");
			gotoxy(1,34);printf("\t\t\t\tExploracion Fisica");
			gotoxy(1,35); printf("Fc: ");
			gotoxy(13,35);printf("Fr: ");
			gotoxy(30,35);printf("Temp: ");
			gotoxy(39,35);printf(" C");
			gotoxy(45,35);printf("TA: ");
			gotoxy(52,35);printf("/");
			gotoxy(63,35);printf("Peso: ");
			gotoxy(77,35);printf("Kg");
			gotoxy(85,35);printf("Altura: ");
			gotoxy(99,35);printf("m");
			gotoxy(1,37);printf("Exploracion:");
			gotoxy(1,43);printf("Diagnostico: ");
			gotoxy(1,47);printf("Tratamiento:");
			
			fflush(stdin);
			gotoxy(9,2); gets(paciente[totalExpedientes].fecha);
			gotoxy(57,2);fflush(stdin); gets(paciente[totalExpedientes].exp);
			//gotoxy(91,2);fflush(stdin);scanf("%i",&paciente[i].folio);
			gotoxy(11,3); fflush(stdin);gets(paciente[totalExpedientes].nombres);
			gotoxy(65,3); gets(paciente[totalExpedientes].apellidoP);
			gotoxy(103,3); gets(paciente[totalExpedientes].apellidoM);
			gotoxy(8,4); fflush(stdin); scanf("%i",&paciente[totalExpedientes].edad);
			gotoxy(39,4);fflush(stdin);scanf("%s",&paciente[totalExpedientes].sexo);
			gotoxy(58,4); fflush(stdin); gets(paciente[totalExpedientes].escolaridad);
			gotoxy(12,5); gets(paciente[totalExpedientes].ocupacion);
			gotoxy(56,5); gets(paciente[totalExpedientes].alergias);
			gotoxy(12,6); gets(paciente[totalExpedientes].direccion);
			//APNP	
			gotoxy(16,10); gets(paciente[totalExpedientes].APNP.alimentacion);
			gotoxy(17,12); gets(paciente[totalExpedientes].APNP.vacunas);
			gotoxy(55,12); gets(paciente[totalExpedientes].APNP.banio);
			gotoxy(29,13); gets(paciente[totalExpedientes].APNP.estudios);
			//APP
			gotoxy(24,17); gets(paciente[totalExpedientes].APP.enfermedades);
			gotoxy(13,18); gets(paciente[totalExpedientes].APP.tabaquismo);
			gotoxy(14,19); gets(paciente[totalExpedientes].APP.alcoholismo);
			gotoxy(14,20); gets(paciente[totalExpedientes].APP.quirurgicos);
			//AHF
			gotoxy(11,24); gets(paciente[totalExpedientes].AHF.DM);
			gotoxy(59,24); gets(paciente[totalExpedientes].AHF.HAS);
			gotoxy(9,25); gets(paciente[totalExpedientes].AHF.cancer);
			gotoxy(55,25);gets(paciente[totalExpedientes].AHF.renales);
			//PEPA
			gotoxy(1,29);
			gets(paciente[totalExpedientes].PEPA);
			//EF
			gotoxy(5,35);scanf("%i",&paciente[totalExpedientes].signos.fc);
			gotoxy(17,35);scanf("%i",&paciente[totalExpedientes].signos.fr);
			gotoxy(36,35);scanf("%f",&paciente[totalExpedientes].signos.temp);
			gotoxy(49,35);scanf("%i",&paciente[totalExpedientes].signos.taS);
			gotoxy(54,35);scanf("%i",&paciente[totalExpedientes].signos.taD);
			gotoxy(70,35);scanf("%f",&paciente[totalExpedientes].signos.peso);
			gotoxy(94,35);scanf("%f",&paciente[totalExpedientes].signos.altura);
			fflush(stdin);
			gotoxy(14,37);gets(paciente[totalExpedientes].EF);
			fflush(stdin);
			gotoxy(14,43);gets(paciente[totalExpedientes].dx);
			fflush(stdin);
			gotoxy(14,47);gets(paciente[totalExpedientes].tx);
			
			
			totalExpedientes++;
			
			printf(" Historia clinica finalizada...\n Se regresara al menu principal");
			
		break;
		
		case 2:
			system("cls");
			printf("\t\t\tBUSCAR PACIENTE");
			printf("\nPor elija la opcion de busqueda:");
			printf("\n\n 1.- Folio \n 2.- No. Expediente\n 3.- Nombre \n 4.- Regresar a menu anterior\n\n Opcion: ");
			scanf("%i",&opcionBusqueda);
			
					switch (opcionBusqueda){
					case 1: /////////////////////////////////////////////////Folio
					if (nAnteriores>0){
					system("cls");
					printf("\t\t\t\tBUSQUEDA POR FOLIO");
					printf("\n\n A continuacion ingrese los datos: ");
					
					printf("\n\n Folio: ");
					scanf("%i",&folioB);
					
					existe=0;
					existe = busquedaFolio(nAnteriores,folioB);
				
					if(existe>-1){
						system("cls");
						int px = pacienteN[existe].registroExp;
						printf(" Folio %i encontrado", pacienteN[existe].folioN);
						gotoxy(1,2); printf("Fecha: ");printf("%s",pacienteN[existe].fechaN);
						gotoxy(85,2); printf("Expediente: ");printf("%s",paciente[px].exp);
						
						
						gotoxy(1,3); printf("Nombres: ");
						gotoxy(12,3); printf("%s ",paciente[px].nombres);
						gotoxy(32,3);printf("%s ",paciente[px].apellidoP);
						gotoxy(47,3);printf("%s ",paciente[px].apellidoM);
						gotoxy(65,3);printf("Edad: "); printf("%i",paciente[px].edad);gotoxy(76,3);printf("anios");
						gotoxy(87,3);printf("Alergias: ");gotoxy(97,3);printf("%s",paciente[px].alergias);
					
						gotoxy(1,5);printf("Padecimiento actual: ");
						gotoxy(1,6);printf("%s",pacienteN[existe].padecimientoN);
						gotoxy(1,10);printf("Principio y evolucion del padecimiento actual: ");
						gotoxy(1,11);printf("%s",pacienteN[existe].PEPAN);
						gotoxy(1,16);printf("Exploracion fisica: ");
						gotoxy(1,17);printf("%s",pacienteN[existe].EFN);
						gotoxy(1,21);printf("Diagnostico: ");
						gotoxy(1,22);printf("%s",pacienteN[existe].diagnosticoN);
						gotoxy(1,25);printf("Tratamiento: ");
						gotoxy(1,26);printf("%s\n",pacienteN[existe].tratamientoN);
						
						system("pause");
						
						menuNotas(&nAnteriores,px);
						
					}else{
					printf("\n\n Folio no encontrado\n\n Se regresara al menu anterior ...\n\n");
					}
					}else{
						printf("\n\n No existe ningun folio almacenado...\n\n");
					}
					
						printf("\n\n");
					system("pause");
						break;
						
						
					
					case 2: //Expediente //////////////////////////////////////
					if(totalExpedientes>0){
						
					system("cls");
					printf("\t\t\tBUSQUEDA POR EXPEDIENTE");
					printf("\n\n A continuacion ingrese los datos: ");
					
					printf("\n\n No. de Expediente: ");
					fflush(stdin);
					gets(expedienteB);
					
					existe=0;
					existe = busquedaExpediente(totalExpedientes,expedienteB);
					if(existe > -1)
					{
						system("cls");	
						gotoxy(2,1); printf("No.Exp");
						gotoxy(20,1);printf("Nombre: ");
						gotoxy(65,1);printf("Diagnostico: ");
						
						
						
						gotoxy(3,i+3);printf("%s",paciente[existe].exp);
						gotoxy(20,i+3);printf("%s",paciente[existe].nombres);
						gotoxy(35,i+3);printf("%s",paciente[existe].apellidoP);
						gotoxy(50,i+3);printf("%s",paciente[existe].apellidoM);
						gotoxy(65,i+3);printf("%s\n\n",paciente[existe].dx);
						
						menuNotas(&nAnteriores,existe);
						
					}else{
							printf("\n Expediente invalido\n");
						}
						}else{
							printf("\n No existe ningun expediente almacenado...");
						}
					printf("\n\n");
						system("pause");
						break;
						
						
						
					case 3: //Nombre /////////////////////////////////
						if(totalExpedientes>0){
						system("cls");
						printf("\n Es necesario que el nombre y apellido sean ingresados exactamente como se almacenaron");
					
						printf("\n Ingrese los siguientes datos: ");
						fflush(stdin);
						printf("\n\n Apellido paterno: ");
						gets(lastName);
						printf(" Nombres: ");
						gets(name);
						
							existe=0;
							existe =busquedaNombre(totalExpedientes, name, lastName);							
						
						if(existe > -1)
					{		
						menuNotas(&nAnteriores,existe);
						
					}else{
							printf("\n Paciente invalido\n");
						}
					}else{
						printf("\n\n No existen datos almacenados de pacientes aun... \n\n");
					}
					
					printf("\n\n");
					system("pause");
					 break;
					
					case 4://regresar menu principal
						break;
						
						
					default:
							printf("\nOpcion no valida");
							break;
						}
			break;
			
				
		case 3:
		system("cls");
		printf("\nPor favor seleccione la opcion deseada\n");
				
		printf("\n 1.- Captura de reporte\n 2.- Impresion de reportes \n 3.- Salir\n\n Opcion:");
		scanf("%i",&opcionReporte);
		
		switch(opcionReporte){
			case 1:
						
				consulta=0;inyeccion=0;presion=0;
				consultaP=50;inyeccionP=25;presionP=25;
					
				i=0;
				
				do{
					
				system("cls");
				gotoxy(1,1);printf("\t\t\t\t\tCAPTURA DE REPORTES");
				gotoxy(6,3);printf("Fecha");
				gotoxy(20,3);printf("Consultas");
				gotoxy(36,3);printf("Costo");
				gotoxy(47,3);printf("Inyecciones");////
				gotoxy(62,3);printf("Costo");
				gotoxy(72,3);printf("Toma de TA");
				gotoxy(87,3);printf("Costo");
				gotoxy(97,3);printf("Ganancia");
				gotoxy(37,4);printf("$50");
				gotoxy(64,4);printf("$25");
				gotoxy(89,4);printf("$25");
				
				if(i>0){
					for(regGuardado = 0; regGuardado < i; regGuardado++){
					gotoxy(4,4+regGuardado);printf("%s",reporte[regGuardado].fecha);
					gotoxy(24,4+regGuardado);printf("%i",reporte[regGuardado].consultas);
					gotoxy(52,4+regGuardado);printf("%i",reporte[regGuardado].inyecciones);
					gotoxy(77,4+regGuardado);printf("%i",reporte[regGuardado].TA);
					
					subTotal = (reporte[regGuardado].consultas * 50) + (reporte[regGuardado].inyecciones * 25) + (reporte[regGuardado].TA * 25);
					
					gotoxy(97,4+regGuardado);printf(" $ %i",subTotal); 
					}
					}
				
					fflush(stdin);
					
					gotoxy(4,4+i);gets(reporte[i].fecha);
					gotoxy(24,4+i);scanf("%i",&reporte[i].consultas);
					gotoxy(52,4+i);scanf("%i",&reporte[i].inyecciones);
					gotoxy(77,4+i);scanf("%i",&reporte[i].TA);
					
					
					consulta += reporte[i].consultas;
					inyeccion += reporte[i].inyecciones;
					presion += reporte[i].TA;
					
					consultaD =reporte[i].consultas*consultaP;
					inyeccionD =reporte[i].inyecciones*inyeccionP;
					presionD =reporte[i].TA*presionP;
					
					totalD = consultaD+inyeccionD+presionD;
					
					gotoxy(97,4+i);printf(" $ %i",totalD); 			
					i++;
					reporteTotal++;
				
				printf("\n\nDesea agregar mas datos?");
				scanf("%s",&agregar);
				
				}while (strcmp(agregar, "si") == 0 || strcmp(agregar, "Si") == 0 || strcmp(agregar, "sI") == 0 || strcmp(agregar, "SI") == 0);
				
				consulta=consulta*consultaP;
				inyeccion=inyeccion*inyeccionP;
				presion=presion*presionP;
				
				costoT= consulta+inyeccion+presion;
				
				
				gotoxy(87,i+7);printf("Total: $ ");
				gotoxy(97,i+7);printf(" $ %i",costoT);
				
		
			printf("\n");
			system("pause");
			break;
			
			
			case 2:
			
				system("cls");
				if(reporteTotal==0){
					printf("\n\n No se ha ingresado ningun reporte\n\n Favor de ingresar datos antes de consultar ...\n\n\n\n\n\n");
				}else{
					
				
				ganancias=0;
				
				gotoxy(1,1);printf("\t\t\t\t\tIMPRESION DE REPORTES");
				gotoxy(2,3);printf("Fecha");
				gotoxy(17,3);printf("Consultas");
				gotoxy(32,3);printf("Total");
				gotoxy(46,3);printf("Inyecciones");
				gotoxy(63,3);printf("Total");
				gotoxy(75,3);printf("Toma de presion");
				gotoxy(96,3);printf("Total");
				gotoxy(107,3);printf("Subtotal");
				
				
				for (i=0;i<reporteTotal;i++){
					consulta=0;
					inyeccion=0;
					presion=0;
		
					gotoxy(3,6+i);printf("%s",reporte[i].fecha);
					
					gotoxy(20,6+i);printf("%i",reporte[i].consultas);
					consulta = reporte[i].consultas*consultaP;
					gotoxy(33,6+i);printf("$%i",consulta);
					
					gotoxy(51,6+i);printf("%i",reporte[i].inyecciones);
					inyeccion=reporte[i].inyecciones*inyeccionP;
					gotoxy(65,6+i);printf("$%i",inyeccion);
					
					gotoxy(82,6+i);printf("%i",reporte[i].TA);
					presion=reporte[i].TA*presionP;
					gotoxy(98,6+i);printf("$%i",presion);
					
					sumatoria=consulta+inyeccion+presion;
					gotoxy(110,6+i);printf("$%i",sumatoria);
					
					ganancias+=sumatoria;
					}
					
				gotoxy(94,9+i);printf("Ganacias:");
				gotoxy(109,9+i);printf("$%i\n\n\n",ganancias);
				}
				system("pause");
					break;
			case 3:
				break;
			
			default:
			printf("Opcion no valida");
			
		
		}
				
		break;
		
		case 4:
			system("cls");
			printf(" Usted ha decidido salir del EMV\n Que tenga un excelente dia ...");
			salir=1;
			break;
			
		default:
			printf("\n\nOpcion no valida\n\n");
			system("pause");
		break;
	}
		
	}while (salir==0);
	
	
	return 0;
	
}


