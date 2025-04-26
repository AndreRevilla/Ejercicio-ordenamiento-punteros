#include <iostream>
using namespace std;

bool movimientoValido(int *posicion, int *b, char movimiento){
    if(posicion == b && (movimiento == 'w' || movimiento == 'a')){
        return 0;
    }
    if(posicion == b+1 && movimiento == 'w'){
        return 0;
    }
    if(posicion == b+2 && (movimiento == 'w' || movimiento == 'd')){
        return 0;
    }
    if(posicion == b+3 && movimiento == 'a'){
        return 0;
    }
    if(posicion == b+5 && movimiento == 'd'){
        return 0;
    }
    if(posicion == b+6 && (movimiento == 's' || movimiento == 'a')){
        return 0;
    }
    if(posicion == b+7 && movimiento == 's'){
        return 0;
    }
    if(posicion == b+8 && (movimiento == 's' || movimiento == 'd')){
        return 0;
    }
    return 1;
}

void swap(int *posicion, char movimiento){
    
    int tempo=0;
    
    if(movimiento == 'w'){
        tempo = *posicion;
        *posicion = *(posicion-3);
        *(posicion-3) = tempo;
    }
    
    if(movimiento == 'a'){
        tempo = *posicion;
        *posicion = *(posicion-1);
        *(posicion-1) = tempo;
    }
    
    if(movimiento == 's'){
        tempo = *posicion;
        *posicion = *(posicion+3);
        *(posicion+3) = tempo;
    }
    
    if(movimiento == 'd'){
        tempo = *posicion;
        *posicion = *(posicion+1);
        *(posicion+1) = tempo;
    }
}

int main()
{
    int B[3][3]={{8,7,6},{5,4,3},{2,0,1}};
    char movimiento='w';
    while(true){
        for(int *p=*B; p<*B+9 ; p++){
            cout << *p << " ";
            if ((p - *B + 1) % 3 == 0)
                cout << endl;
        }
        
        for(int *p=*B; p<*B+9 ; p++){
            if(*p == 0){
                cout<<"Que posicion desea moverse?"<<endl;
                cin>>movimiento;
                
                if(movimientoValido(p, *B, movimiento)) {
                    swap(p, movimiento);
                } else {
                    cout << "Movimiento ilegal" << endl;
                }
                break;
            }
        }
    }
    return 0;
}
