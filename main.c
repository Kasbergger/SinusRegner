#include <stdio.h>
#include <stdlib.h>
#define PI 3.1416

/**< Deklaretioner af alle funktionerne */
int Fakultet(int tal);
float Potens(float grundtal, int eksponent);
float GradTilRadian(float tal);
float SinusRegner(float grader);


int main()
{
    int i;
    int heltalInd, heltalUd;
    float talInd, talUd;

    while(1){
        /**< Menu til valg af en funktion */
        printf("Mulige operationer der kan vaelges med deres korresponderende tal:\n");
        printf("1. Fakultet\n");
        printf("2. Potens\n");
        printf("3. Konverter grader til radian\n");
        printf("4. Sinus\n");
        printf("8. Ryd skaerm\n");
        printf("9. Sluk program\n");
        fflush(stdin);
        scanf(" %i", &i);
        printf("\n");

        /**< Switchen der vælger den valgte funktion og udføreden */
        switch(i){
        case 1:
            printf("Indtast det tal der skal bruges: ");
            fflush(stdin);
            scanf("%d", &heltalInd);
            heltalUd = Fakultet(heltalInd);
            printf("Fakulteten af tallet %d er %d\n\n", heltalInd, heltalUd);
            break;
        case 2:
            printf("Indtast grundtallet: ");
            fflush(stdin);
            scanf("%f", &talInd);
            printf("Indtast eksponenten: ");
            fflush(stdin);
            scanf("%d", &heltalInd);
            talUd = Potens(talInd, heltalInd);
            printf("Potensen af %f^%d er %f\n\n", talInd, heltalInd, talUd);
            break;
        case 3:
            printf("Indtast det tal der skal konverteres: ");
            fflush(stdin);
            scanf("%f", &talInd);
            talUd = GradTilRadian(talInd);
            printf("%f grader i radian er %f\n\n", talInd, talUd);
            break;
        case 4:
            printf("Indtast tallet der skal tages sinus af i grader: ");
            fflush(stdin);
            scanf("%f", &talInd);
            talUd = SinusRegner(talInd);
            printf("Sinus af %f er %f i radiantal\n\n", talInd, talUd);
            break;
        case 8:
            system("cls");
            break;
        case 9:
            printf("Forvel!");
            usleep(750000);
            return 0;
            break;
        default:
            printf("Inputtet var ikke valid\nGiv et valid input\n\n");
            break;
        }
    }
    return 0;
}

/************************************************
 *  Beskrivelse: Beregner Fakulteten af et tal  *
 ************************************************
 *  Input: positiv heltal                       *
 *  Output: positiv heltal                      *
 ************************************************/
int Fakultet(int tal)
{
    int talOut = tal;
    for (int i = tal; i >= 1; i--){
        talOut = talOut * i;
    }
    return talOut;
}

/************************************************
 *  Beskrivelse: Beregner potensen af to givne  *
 *  tal, grundtallet er en float og eksponenten *
 *  er en int                                   *
 ************************************************
 *  Input: float grundtal, int eksponent        *
 *  Output: positiv float                       *
 ************************************************/
float Potens(float grundtal, int eksponent)
{
    float talOut = grundtal;
    if (eksponent == 0){
        talOut = 1;
    } else if (eksponent < 0){
        for (int i = -1; i > eksponent; i--){
            talOut = talOut*grundtal;
        }
        talOut=1/talOut;
    } else if(eksponent > 0){
        for (int i = 1; i < eksponent; i++){
            talOut = talOut*grundtal;
        }
    } else {
        talOut = 0;
    }
    return talOut;
}

/************************************************
 *  Beskrivelse: Regner grad om til radian.     *
 *  Bruger også PI som er defineret i starten   *
 *  af programmet                               *
 ************************************************
 *  Input: float                                *
 *  Output: float                               *
 ************************************************/
float GradTilRadian(float tal)
{
    float talOut;
    talOut = tal*PI/180.0;
    return talOut;
}

/************************************************
 *  Beskrivelse: Beregner sinus inputtet som    *
 *  skal være angivet i grader.                 *
 *  Denne beregning udføres ved brug af         *
 *  en løsningsformel:                          *
 *  sin(A) = x - (x^3)/3! + (x^5)/5! - (x^7)/7! *
 *  Hvor x er radianen af A                     *
 *  funktionerne der bruges:                    *
 *  GradTilRadian for at konvertere inputtet    *
 *  til radian.                                 *
 *  Potens til potens regningen                 *
 *  Fakultet til Fakultets regningen            *
 ************************************************
 *  Input: float                                *
 *  Output: float                               *
 ************************************************/
float SinusRegner(float grader)
{
    float talOut;
    float xR;
    float num1, num2, num3;

    xR = GradTilRadian(grader);
    num1 = Potens(xR, 3)/Fakultet(3);
    num2 = Potens(xR, 5)/Fakultet(5);
    num3 = Potens(xR, 7)/Fakultet(7);
    talOut = xR-(num1)+(num2)-(num3);

    return talOut;
}

