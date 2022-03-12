# Pcom - protocoale de comunicatii


>off_t lseek(int fd, off_t offset, int pos) = Lseek (indicatorul poz curente se poate seta
si in cadurl lui leesek, fara sa citesc pana la aceea pos de ex); DECI FUNCTIA LSEEK
POZITIONEAZA INDICATORUL LA DEPLASAMENTUL OFFSET IN FISIER DUPA CUM URMEAZA :: 
POS == SEEK_SET, ATUNCI POZ SE FACE RELATIV LA INCEPUTUL FISIERULUI;
POS == SEEK_CUR, ATUNCI POZ SE FACE RELATIV LA POZ ACTUALA;
POS == SEEK_END, ATUNCI POZ SE FACE RELATIV LA SF FILE.

>Socketi UDP
Comunicare client-server UNIX::
Pasi urmati pentru a schimba mesaje folosind UDP la nivelul Transport sunt urmatorii:

>Deschide un socket unix in scopul de a permite comunicarea intre procese/statii diferite folosind descriptori de fisiere (file descriptors) cu apelul socket().

>Asociaza o adresa pentru socketul deschis cu apelul bind(). In general, folosim bind() atunci cand dorim sa asteptam conexiuni pe un anumit port.

>Trimite/Receptioneaza date cu apelul recvfrom()/sendto().

>Inchide socket prin close().
