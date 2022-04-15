#include <SR04.h>

SR04* uls = new SR04(2,3) ;

void setup()
{
    Serial.begin(9600) ;    //初始化串口比特率
}

void loop()
{
    float distance = uls->getDistance() ;

    //打印距离至控制台
    Serial.print( "Distance is : " ) ;
    Serial.print( distance ) ;
    Serial.print( " cm" ) ;
    Serial.println() ;

    delete uls ;
}

