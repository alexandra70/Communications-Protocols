# Pcom - protocoale de comunicatii


>off_t lseek(int fd, off_t offset, int pos) = Lseek (indicatorul poz curente se poate seta
si in cadurl lui leesek, fara sa citesc pana la aceea pos de ex); DECI FUNCTIA LSEEK
POZITIONEAZA INDICATORUL LA DEPLASAMENTUL OFFSET IN FISIER DUPA CUM URMEAZA :: 
POS == SEEK_SET, ATUNCI POZ SE FACE RELATIV LA INCEPUTUL FISIERULUI;
POS == SEEK_CUR, ATUNCI POZ SE FACE RELATIV LA POZ ACTUALA;
POS == SEEK_END, ATUNCI POZ SE FACE RELATIV LA SF FILE.

>Forwarding : 
>Data plane - se refera la procesarea pachetelor ajunse la router. 
>Control plane se refera la popularea tabelelor de routare.
>O tabela de routare contine info precum: interfata pe care trebuie sa trimit pachetul si adresa ip(4/6) a urmtorului hop.
>Proces de routare: Primesc un pachet, extrag din el adresa Ip-dest(unde trebuie sa ajunga pachetul) si mai apoi verific tabela de routare sa vad dc am o adresa mac care corespunde adresei Ip-dest. Din acest punct dirijez pachetul spre next hop. Procesul se va repeta pana se ajunge la destinatie. 

>
>Header Ethernet
>
>+-----------------+------------+-------------+
>
>|     Bytes 0-5   | Bytes 6-11 | Bytes 12-13 |
>
>+------------------------------+-------------+
>
>| Destination MAC | Source MAC |  EtherType  |
>
>+-----------------+------------+-------------+



>Socketi UDP
Comunicare client-server UNIX::
Pasi urmati pentru a schimba mesaje folosind UDP la nivelul Transport sunt urmatorii:

>Deschide un socket unix in scopul de a permite comunicarea intre procese/statii diferite folosind descriptori de fisiere (file descriptors) cu apelul socket().

>Asociaza o adresa pentru socketul deschis cu apelul bind(). Se foloseste bind(), atunci cand astept conexiuni pe un anumit port.

>Trimite/Receptioneaza date cu apelul recvfrom()/sendto().

>Inchide socket prin close().
