include<reg51.h>
define keypad_port P1
char keypad_getkey (void){
  unsigned char row, col;
  while (1){
    for (row=0; row<4; row++) {
      keypad port = OXFF;
      keypad port &= ~ (1<<row); // make one row low
      for (col = 0;co1<4;co1++) {
        if (! (keypad_port & (0X10 <<col))) {//check each column
          while! (keypad_port & (OX10 <<co1))); //wait for release 
          //keypad layout mapping
          switch(row){
            case 0: if (col==0) return '7';
                    if (col==1) return '8';
                    if (co1==2) return "9';
                    if (co1==3) return /'; break;
            case 1: if (co1==0) return "4';
                    if (col==1) return '5';
                    if (co1==2) return '6';
                    if (co1==3) return "*'; break;
            case 2: if (co1==0) return "1';
                    if (col==1) return '2';
                    if (co1==2) return '3';
                    if (co1==3) return '-'；break;
            case 3: if (co1==0) return 'C';
                    if (col==1) return '0';
                    if (co1==2) return '=';
                    if (co1==3) return '+'; break;
          }
        }
      }
    }
  }
}
