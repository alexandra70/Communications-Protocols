# Pcom - protocoale de comunicatii


***Notiuni pregatitoare protocoale de comunicatii
Fisiere - ex: sockets - folositi in comunicatia dintre procese pe retea; pot fi utilizati si pentru a comunica intre procesele de pe acelasi calculator gazda;
Pentru a putea actiona asupra unui fisier, este nevoie inainte de toate de o metoda de a identifica in mod unic fisierul. In cazul functiilor discutate, identificarea fisierului se face printr-un asa-numit descriptor de fisier (file descriptor). Acesta este un numar intreg care este asociat fisierului in momentul deschiderii acestuia.
Ce trebuie sa invat sa folosesc:***

 int open(const char *pathname, int oflag, [, mode_t mode]);  
 ssize_t read(int fd, void *buff, size_t nbytes);
 ssize_t write(int fd, void *buff, size_t nbytes);

*****off_t lseek(int fd, off_t offset, int pos) = Lseek (indicatorul poz curente se poate seta
si in cadurl lui leesek, fara sa citesc pana la aceea pos de ex); DECI FUNCTIA LSEEK
POZITIONEAZA INDICATORUL LA DEPLASAMENTUL OFFSET IN FISIER DUPA CUM URMEAZA :: 
POS == SEEK_SET, ATUNCI POZ SE FACE RELATIV LA INCEPUTUL FISIERULUI;
POS == SEEK_CUR, ATUNCI POZ SE FACE RELATIV LA POZ ACTUALA;
POS == SEEK_END, ATUNCI POZ SE FACE RELATIV LA SF FILE.*****

Socketi UDP
