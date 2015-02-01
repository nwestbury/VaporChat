#include "loginwindow.h"
#include "mainwindow.h"
#include "networking.h"
#include <QApplication>


#include "crypto.h"
#include "stdio.h"

char *pubkey = "-----BEGIN PUBLIC KEY-----\n\
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA5ZFiDNgBpmd0Hsl/4S4I\n\
FcZaRMiRCuUb32t7Pqb0ojf87utQoSt50lVuhVI18Wm+wLrGs4dCWzkW8gjJzRcd\n\
P+Bbo2momLThytTDYYbPtzn2X5TNKiw/lEaIz9ubagWrFpo/JC5ZAR2WGFYPcBPy\n\
DPTG2h/rLINqUvlvfG1KBpGtW84adMImWlgCNSA9ja8wf+wntSriN1awAro4xrjO\n\
ZwsDqTj5xN6E9I9S8gpHQsPh67pD0AQqUlcVyLh+cQxljD09QMF/hZrWCVUzEf/W\n\
zm8JFnAdzBoGKrTmPrRlml8lS5wfqKZokbnIIrqjI7tCjL02BPH/YZLDrAYg8Sk+\n\
9QIDAQAB\n-----END PUBLIC KEY-----\n";
char *privatekey = "-----BEGIN ENCRYPTED PRIVATE KEY-----\n\
MIIFHzBJBgkqhkiG9w0BBQ0wPDAbBgkqhkiG9w0BBQwwDgQIBqEztkx09a8CAggA\n\
MB0GCWCGSAFlAwQBKgQQhgKol8Yllt7DP0XrVbO3RwSCBNAcLHo+gLpsDBk0NBU8\n\
C1r273unqyMZgC7Bs9JkrCOOmhQiFQmY4TyQ5yiB8luGp4fXG/W0EJ1GHKYokGN0\n\
VZnGTTsSzIDqZNCoEsBgWuOByCzzyDTRMKzrmcDl4R6Pd+c5SNSiOEG4gedsiJUs\n\
tRxBwCzk9rxMBUr4C4DZTOMqz5Kn3IqTzrgoRWlHZOxDogLBo9Tcgn7KPqbWXcPU\n\
gZlHWDOxiiYjwdt6JDlLNuH/OGeGJhf/vvx1zrscTklU5UdqzfPpn9PjfHehHa95\n\
qDCImeWX53LOc+TABbMQIZ4Q5lde/UIfR1z/jZl7n+tm04oai1KRD9QloSeoz7Pn\n\
mOu8pBHMxJ6Y7+GgZy/UWOTYBnKifqbwC7p0u+5v57ooZi1G8M465otuQkfp3T7X\n\
SWMskOguna1ecs65+2WnHbXayCgu0OeEYDmP7TPc6jz1kzRDZWNbi+s9QU2oXMCQ\n\
APnlef9JgGZhm/48suMAs/mO1sjMAFRQiNqOyIARIUnSctF47hfsc3n177rLAK/X\n\
jqWIu6lBd5z+xg9IVqWimp8Jd0yaApSz7jcIO+hJKpJ00tcVOaYnkeA+K6vsXqbM\n\
LEdq5pMVXq+qwepc5kDQq6xLN5GuU145PA/nGDOiRq2WLud/BQEHgHke8m0hJ/dv\n\
3i+M+TukscOpKGe2eW+sp597y4wVfI0nun0EINyj3Qr5+Kc+g4x+JLQZUhwS66x8\n\
9JBb5Q189+n+ZQdhZ1zQR9vOBYXhZlZPdG7bmkOOFNcJoeMHjbEBZJEKWyqP+FU0\n\
tB1wSHWk9HvMr4d+GLoZTlF37onAKUYxRGCArixzKahDcbpIxNRpMUf/LcO3VZdK\n\
Qyhw7o0sEEKJKQySd9R0qfapjgl5gJyGKCdx8LU/pJ/NMyomrZcbfIUtgm7w+o+u\n\
LqI7LZJeFalBhnRC0GCjn7OHh3EgElaTHjYkMdMF2rvhpqJgbb2fCSUT2FGzHTjY\n\
1PM/U0l+faeA6stwfHImRZHhfu+aoXXLAZllL6tOIqTGFEJ1Z/lYhyyUbd4iamO9\n\
hMzJk9uS7LojwNBXPsospA8St2CjYqjQ60fOSJ7ybBPUNoOfRs4qH7nL4OjY4XwP\n\
ulEDQ89aY0M5yPT8Gvi5EFIM3mENv2YmMLKENJQKLaxGvWbquGUz/iAOzxAAIPys\n\
0P15sP+fjn0PxFspf1N5rLzewFU1Myjehz2/9KvyssvqKzynNVEyq3vagCKTOJEm\n\
Ur852R0u6Nc5m6QvnuMO6FniPY0GfHKj2iBdTlIakfqk9e9KSLvO15MvPwDsghDw\n\
wWiB1IdnEmDW2oT6r/K9tiPbQrD4PP6wm7QSIeoXg27zYEEynXpXCfIWn+NNLFGr\n\
7QKQZI+f3CmLVSpLLQdhNhhudtL5DzHldkryOdWPhu0aazpz3iwzqU1H0RXUIZj3\n\
ZKUM+pQQxhhECeJ0zgxMWpuwUlLn53m+RHZGmWkLBRGGUCBjK+okNLGcOqJBQ9dT\n\
698dCAGcQNRwa8gLq/uNSP2Uy6+UuAriivDOV0TN37+Lq9uvyfJZGQ3dhYzG1nE6\n\
Q/0ZQdkEqrxUuzNp2CiHDwIysZ/nFFWBf3Tb2BNqenO3uCpTxgs+TskNcLlkJuro\n\
Rme6Xi7iAhlJtZu0bLxUkTCMzw==\n-----END ENCRYPTED PRIVATE KEY-----\n";

extern RSA *rsa;

void nathan_tests() {
    init_crypto();

    //char *pub, *priv;
    //createKeyPair("test", &pub, &priv);

    //FILE *f = fopen("C:\\Users\\Jacob\\Documents\\build-VaporChat-Desktop_Qt_5_4_0_MSVC2013_64bit-Debug\\out.txt", "w");

    //fprintf(f,"TESTESTEST%s\n%s", pub, priv);

    importKeyPair("test", privatekey, pubkey);

    char *str = "Test testes test";
    char *encrypted, *decrypted;
    int cryptedlen, decryptedLen;

    RSAEncrypt(rsa, str, strlen(str)+1, &encrypted, &cryptedlen);
    RSADecrypt(rsa, encrypted, cryptedlen, &decrypted, &decryptedLen);

    free(encrypted);

    QMessageBox msg;
    msg.setText(decrypted);
    msg.exec();

    free(decrypted);

    char *hexout;
    bin2hex("test", 4, &hexout);

    msg.setText(hexout);
    msg.exec();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mainWindow w;
    w.show();

	
    if(strcmp(getenv("USERNAME"),"Jacob") == 0)
        nathan_tests();

    return a.exec();
}
