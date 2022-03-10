# Pcom - protocoale de comunicatii


>off_t lseek(int fd, off_t offset, int pos) = Lseek (indicatorul poz curente se poate seta
si in cadurl lui leesek, fara sa citesc pana la aceea pos de ex); DECI FUNCTIA LSEEK
POZITIONEAZA INDICATORUL LA DEPLASAMENTUL OFFSET IN FISIER DUPA CUM URMEAZA :: 
POS == SEEK_SET, ATUNCI POZ SE FACE RELATIV LA INCEPUTUL FISIERULUI;
POS == SEEK_CUR, ATUNCI POZ SE FACE RELATIV LA POZ ACTUALA;
POS == SEEK_END, ATUNCI POZ SE FACE RELATIV LA SF FILE.

>Socketi UDP
