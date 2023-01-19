#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

//50 datos
std::string atleta[55][3]={{"Aaron","argentina","oro"	},{	"Barbara"	,"brazil",	"plata"	},{	"Charles"	,"rusia",	"bronce"	},{	"David"	,"japon",	"oro"	},{	"Elizabeth"	,"china",	"plata"	},{	"Frank"	,"eu",	"bronce"	},{	"George"	,"uk",	"oro"	},{	"Heather"	,"argentina",      	"plata"	},{	"Isabella"	,"brazil",	"bronce"	},{	"John"	,"rusia",	"oro"	},{	"Katherine"	,"japon",	"plata"	},{	"Louis"	,"china",	"bronce"	},{	"Michael"	,"eu",	"oro"	},{	"Nicole"	,"uk",	"plata"	},{	"Olivia"	,"argentina",      	"bronce"	},{	"Peter"	,"brazil",	"oro"	},{	"Quinn"	,"rusia",	"plata"	},{	"Robert"	,"japon",	"bronce"	},{	" Susan"	,"china",	"oro"	},{	"Thomas"	,"eu",	"plata"	},{	"Ulrich"	,"uk",	"bronce"	},{	"Victoria"	,"argentina",      	"oro"	},{	"William"	,"brazil",	"plata"	},{	"Xander"	,"rusia",	"bronce"	},{	"Yolanda"	,"japon",	"oro"	},{	"Zachary"	,"china",	"plata"	},{	"Aaron"	,"argentina",      	"bronce"	},{	"Barbara"	,"brazil",	"oro"	},{	"Charles"	,"rusia",	"plata"	},{	"David"	,"japon",	"bronce"	},{	"Elizabeth"	,"china",	"oro"	},{	"Frank"	,"eu",	"plata"	},{	"George"	,"uk",	"bronce"	},{	"Heather"	,"argentina",      	"oro"	},{	"Isabella"	,"brazil",	"plata"	},{	"John"	,"rusia",	"bronce"	},{	"Katherine"	,"japon",	"oro"	},{	"Louis"	,"china",	"plata"	},{	"Michael"	,"eu",	"bronce"	},{	"Nicole"	,"uk",	"oro"	},{	"Olivia"	,"argentina",      	"plata"	},{	"Peter"	,"brazil",	"bronce"	},{	"Quinn"	,"rusia",	"oro"	},{	"Robert"	,"japon",	"plata"	},{	"Susan"	,"china","bronce"},{"Thomas","eu","oro"},{"Ulrich","uk","plata"},{"Victoria","argentina","bronce"},{"William","brazil","oro"},{"Xander","rusia","plata"},{"Yolanda","japon","bronce"},{"Zachary","china","oro"}};

// arbol
struct Node {
    std::string name;
    std::string nacionalidad;
    std::string medalla;
    Node *left;
    Node *right;
};

Node * root = NULL;
Node * Oro = NULL;
Node * Plata = NULL;
Node * Bronce = NULL;

void insertNode(int i) {
    Node *newNode = new Node;
    newNode->name = atleta[i][0];
	newNode->nacionalidad = atleta[i][1];
    newNode->medalla=atleta[i][2];
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL) {
        root = newNode;
    } else {
        Node *current = root;
        Node *parent;
        while (true) {
            parent = current;
            if (atleta[i][0] < current->name) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}
void insertNodeOro(int i) {
    Node *newNode = new Node;
    newNode->name = atleta[i][0];
	newNode->nacionalidad = atleta[i][1];
    newNode->medalla=atleta[i][2];
    newNode->left = NULL;
    newNode->right = NULL;

    if (Oro == NULL) {
        Oro = newNode;
    } else {
        Node *currentOro = Oro;
        Node *parentOro;
        while (true) {
            parentOro = currentOro;
            if (atleta[i][0] < currentOro->name) {
                currentOro = currentOro->left;
                if (currentOro == NULL) {
                    parentOro->left = newNode;
                    return;
                }
            } else {
                currentOro = currentOro->right;
                if (currentOro == NULL) {
                    parentOro->right = newNode;
                    return;
                }
            }
        }
    }
}
void insertNodePlata(int i) {
    Node *newNode = new Node;
    newNode->name = atleta[i][0];
	newNode->nacionalidad = atleta[i][1];
    newNode->medalla=atleta[i][2];
    newNode->left = NULL;
    newNode->right = NULL;

    if (Plata == NULL) {
        Plata = newNode;
    } else {
        Node *currentPlata=Plata;
        Node *parentPlata;
        while (true) {
            parentPlata = currentPlata;
            if (atleta[i][0] < currentPlata->name) {
                currentPlata = currentPlata->left;
                if (currentPlata== NULL) {
                    parentPlata->left = newNode;
                    return;
                }
            } else {
                currentPlata= currentPlata->right;
                if (currentPlata== NULL) {
                    parentPlata->right = newNode;
                    return;
                }
            }
        }
    }
}

//Funcion rrecorrido en profundidad preorden
void preorden(Node *root){
    if(root==NULL){
        return ;
    }else{
        std::cout << root->name << "-";
        preorden(root->left);
        preorden(root->right);
    }
}

//Funcion rrecorrido en profundidad postorden
void postorden(Node *root){
    if(root==NULL){
        return ;
    }else{
        postorden(root->left);
        postorden(root->right);
        std::cout << root->name << "-";
    }
}

void inorden(Node * root){
    if(root==NULL){
        return ;
    }else{
        inorden(root->left);
        std::cout << root->name << "-";
        inorden(root->right);
    }
}
Node* searchNode(Node* root,std::string name) {
    if (root == NULL) {
        return NULL;
    }
    if (root->name == name) {
        return root;
    }
    if (name < root->name) {
        return searchNode(root->left, name);
    }
    return searchNode(root->right, name);
}

int main() {	
	int dato, opcion, contador=0, i=0, j=0, suma=0;
	    std::string nombre;
	    std::string nacionalidad;
	for(i=0;i<50;i++){
    if(atleta[i][2]=="oro"){
    insertNodeOro(i);
    } else if(atleta[i][2]== "plata"){
    insertNodePlata(i);
    } else{
    insertNode(i);
    }
	}
	
	do{
		printf("\n\t \t\t\t Menu\n");
		printf("1.-Buscar un nodo por su nombre y nacionalidad y sumar todos los puntos del equipo\n");
//		printf("1. insertar nodos\n");
		printf("2.-Recorrido en Preorden\n");
		printf("3.-Recorrido en Inorden\n");
		printf("4.-Recorrido en Postorden\n");
		printf("5.-Salir \n");
		printf("\n Elije una opcion:\n");
		scanf("%d",&opcion);
		
		switch(opcion){
			case 1:{
    	std::cout << "Ingresa el nombre: ";
    	std::cin >> nombre;
    	std::cout << "Ingresa la nacionalidad: ";
    	std::cin >> nacionalidad;
//    	std::cout << "Hola " << nombre << "!" << std::endl;

	Node* result = searchNode(root, nombre);
	if (result != NULL) {
   		std::cout << "Nodo encontrado: " << result->name<<" tiene la medalla de:"<<result->medalla << std::endl;
    	std::cout << std::endl;
	} else {
    	std::cout << "Nodo no encontrado en las medallas de Bronce" << std::endl;
    	std::cout << std::endl;
	}				

	Node* resultO = searchNode(Oro, nombre);
	if (resultO != NULL) {
   		std::cout << "Nodo encontrado: " << resultO->name<<" tiene la medalla de:"<<resultO->medalla << std::endl;
	} else {
    	std::cout << "Nodo no encontrado en las medallas de Oro" << std::endl;
    	std::cout << std::endl;
	}				

	Node* resultP = searchNode(Plata, nombre);
	if (resultP != NULL) {
   		std::cout << "Nodo encontrado: " << resultP->name<<"tiene la medalla de:"<<resultP->medalla << std::endl;
    	std::cout << std::endl;
	} else {
    	std::cout << "Nodo no encontrado  en las medallas de Plata" << std::endl;
    	std::cout << std::endl;
	}				
   		std::cout << "Equipo de nacionalidad: " << nacionalidad << std::endl;
    	std::cout << std::endl;

for(int i = 0; i < 50; i++){
    if(atleta[i][1]==nacionalidad){
    	if(atleta[i][2]== "oro"){
    		std::cout<<"nombre: \t "<< atleta[i][0]<< " \t nacionalidad: \t"<< atleta[i][1]<<" \t medalla: \t "<< atleta[i][2]<< std::endl;
        suma = suma + 10;
    } else if(atleta[i][2]== "plata"){
    		std::cout<<"nombre: \t "<< atleta[i][0]<< " \t nacionalidad: \t"<< atleta[i][1]<<" \t medalla: \t "<< atleta[i][2]<< std::endl;
        suma = suma + 5;
    } else{
    		std::cout<<"nombre: \t "<< atleta[i][0]<< " \t nacionalidad: \t"<< atleta[i][1]<<" \t medalla: \t "<< atleta[i][2]<< std::endl;
        suma = suma + 2;
    }
	}
}	

std::cout<<"Suma total de puntos de medallas:"<<suma;


				break;
			}
			case 2:{
				printf("\nDame el arbol que quieres recorrer\n");
			printf("1. Oro\n");
			printf("2. Plata\n");
			printf("3.-Bronce\n");
			scanf("%d",&opcion);
				printf("\n\t \t Recorrer arbol en preorden \n");
				if(opcion==1){
				preorden(Oro);
				}else if(opcion==2){
				preorden(Plata);
				}else if(opcion==3){
				preorden(root);
				}
//				inorden(Oro);
				break;
			}
			case 3:{
				printf("\nDame el arbol que quieres recorrer\n");
			printf("1. Oro\n");
			printf("2. Plata\n");
			printf("3.-Bronce\n");
			scanf("%d",&opcion);
			printf("\n\t \t Recorrer arbol en inorden \n");
				if(opcion==1){
					inorden(Oro);
				}else if(opcion==2){
				inorden(Plata);
				}else if(opcion==3){
				inorden(root);
				}
				break;
			}
			case 4:{
				printf("\nDame el arbol que quieres recorrer\n");
			printf("1. Oro\n");
			printf("2. Plata\n");
			printf("3.-Bronce\n");
			scanf("%d",&opcion);
				printf("\n\t \t Recorrer arbol en postorden \n");
				if(opcion==1){
				postorden(Oro);
				}else if(opcion==2){
				postorden(Plata);
				}else if(opcion==3){
				postorden(root);
				}
//				postorden(arbol);
				break;
			}
			case 5:{
				exit(1);
				break;
			}
		}
	}while(opcion != 5);


    return 0;
}
