/**
 * @file bCtrl.cpp
 * @author Dlerk
 * @brief bCrtl的实现
 * @version 0.1
 * @date 2022-04-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "bCtrl.h"

bCtrl::bCtrl( char Ssid[] , char Pswd[] )
{
    
    for( int i=0 ; i<sizeof(Ssid) ; i++ ) 
        ssid[i] = Ssid[i] ;

    for( int i=0 ; i<sizeof(Pswd) ; i++ ) 
        pswd[i] = Pswd[i] ;

    Serial.println(" bCtrl is initialized ") ;    

}

bCtrl::~bCtrl()
{
    Serial.printIn( "bCtrl is deleted" ) ;
}
