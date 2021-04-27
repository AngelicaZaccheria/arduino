char chars[] =
{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H',
'I','L','M','N','O','P','Q','R','S','T','U','V','Z'};
String codes[] =
{"00000","00001","00010","00011","00100","00101","00110","00111","01000",
"01001","01010","01011","01100","01101","01110","01111","10000","10001",
"10010","10011","10100","10101","10110","10111","11000","11001","11010",
"11011","11100","11101","11110"};
 
const int laser = 9;
const int IRwrite = 4;
 
const int t = 1000;
 
void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN,OUTPUT);
    pinMode(laser,OUTPUT);
    pinMode(IRwrite,OUTPUT);
 
    //Spegnimento di tutte le sorgenti
    digitalWrite(laser,LOW);
    digitalWrite(IRwrite,LOW);
 
    //Codifica del codice
    String code = "H725";
 
    //Impulso d'avvio
    Serial.println("Impulso IR inviato");
    for(int x = 0;x<5;x++){
        digitalWrite(IRwrite,HIGH);
        delay(40);
        digitalWrite(IRwrite,LOW);
        delay(40);
    }
 
    //Invio segnale
    for(int lettera = 0; lettera < 4; lettera++){
        Serial.print("Invio carattere   ");
        Serial.println(code.charAt(lettera));
 
        for(int nBit = 0; nBit < 5; nBit++){
            Serial.print(nBit+1);
            digitalWrite(laser,codice(code.charAt(lettera),nBit));
            Serial.println(""); delay(t);
        }
    }
 
    digitalWrite(laser,LOW);
}
 
void loop() {
    digitalWrite(LED_BUILTIN,HIGH);
    delay(400);
    digitalWrite(LED_BUILTIN,LOW);
    delay(400);
}
 
int codice(char val,int index){
    for( int y = 0; y < sizeof(chars); y++ ){
        if( val == chars[y] ){
            Serial.print("° bit Inviato:   ");
            Serial.print(codes[y].charAt(index));
            if((codes[y].charAt(index)) == '0'){
                return 0;
            }
        else{return 255;}
        }
    }
}
