#include "header.h"

void createList(List &L){ // Make A List
    first(L) = NULL;
    last(L) = NULL;
}

adr alocate(infotype x){ // Allocate info to an element
    adr P = new ElmList;
    info(P).state = x.state;
    info(P).value = x.value;
    next(P) = NULL;
    return P;
}

void inLa(List &L, adr P){ // Append element to the end of Element List
    if (first(L) == NULL && last(L) == NULL){
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        last(L) = P;
    }
}

void clearList(List &L){  // Flush the list
    if (first(L) == NULL && last(L) == NULL){
        cout<<"List is empty!\n";
    } else {
        adr P = first(L);
        while (P != NULL){
            if (next(first(L)) == NULL){
                delete P;
                first(L) = NULL;
                last(L) = NULL;
                P = NULL;
            } else {
                first(L) = next(P);
                delete P;
                P = NULL;
                P = first(L);
            }
        }
    }
}

void showList(List L){ // Show entire element on list
    if (first(L) == NULL && last(L) == NULL){
        cout<<"List is Empty!\n";
    } else {
        adr P = first(L);
        cout<<"================================\n";
        while (P != NULL){
            cout<<"State: "<<info(P).state<<endl;
            cout<<"Value: "<<info(P).value<<endl;
            cout<<"================================\n";
            P = next(P);
        }
    }
}

void mfEmo(List &L, int x){ // Input member function emotion to List
    infotype z;
    adr P;
    // Start Low
    if (x >= 0 && x <= 10){ // straight
        z.state = "eL";
        z.value = 1;
        P = alocate(z);
        inLa(L,P);
    } else if (x > 10 && x <= 25){ // down
        z.state = "eL";
        z.value = (25.0 - x)/(25.0 - 10.0);
        if (z.value != 0){
            P = alocate(z);
            inLa(L,P);
        }
    } else {}// End Low

    // Start Medium
    if (x >= 10 && x <= 25){ // up
        z.state = "eM";
        z.value = (x - 10.0)/(25.0 - 10.0);
        if (z.value != 0){
            P = alocate(z);
            inLa(L,P);
        }
    } else if (x > 25 && x < 70){ // straight
        z.state = "eM";
        z.value = 1;
        if (z.value != 0){
            P = alocate(z);
            inLa(L,P);
        }
    } else if (x >= 70 && x <= 80){ // down
        z.state = "eM";
        z.value = (80.0 - x)/(80.0 - 70.0);
        if (z.value != 0){
            P = alocate(z);
            inLa(L,P);
        }
    } else {}// End Average

    // Start High
    if (x >= 70 && x <= 80){ // up
        z.state = "eH";
        z.value = (x - 70.0)/(80.0 - 70.0);
        if (z.value != 0){
            P = alocate(z);
            inLa(L,P);
        }
    } else if (x > 70 && x <= 100){ // straight
        z.state = "eH";
        z.value = 1;
        if (z.value != 0){
            P = alocate(z);
            inLa(L,P);
        }
    } else {}// End High
}

void mfPro(List &L, int x){ // Input member function provocation to List
    infotype z;
    adr P;
    // Start Low
    if (x >= 0 && x <= 10){ // straight
        z.state = "pL";
        z.value = 1;
        P = alocate(z);
        inLa(L,P);
    } else if (x > 10 && x <= 25){ // down
        z.state = "pL";
        z.value = (25.0 - x)/(25.0 - 10.0);
        if (z.value != 0){
            P = alocate(z);
            inLa(L,P);
        }
    } else {}// End Low

    // Start Medium
    if (x >= 10 && x <= 25){ // up
        z.state = "pM";
        z.value = (x - 10.0)/(25.0 - 10.0);
        if (z.value != 0){
            P = alocate(z);
            inLa(L,P);
        }
    } else if (x > 25 && x < 70){ // straight
        z.state = "pM";
        z.value = 1;
        if (z.value != 0){
            P = alocate(z);
            inLa(L,P);
        }
    } else if (x >= 70 && x <= 80){ // down
        z.state = "pM";
        z.value = (80.0 - x)/(80.0 - 70.0);
        if (z.value != 0){
            P = alocate(z);
            inLa(L,P);
        }
    } else {}// End Average

    // Start High
    if (x >= 70 && x <= 80){ // up
        z.state = "pH";
        z.value = (x - 70.0)/(80.0 - 70.0);
        if (z.value != 0){
            P = alocate(z);
            inLa(L,P);
        }
    } else if (x > 70 && x <= 100){ // straight
        z.state = "pH";
        z.value = 1;
        if (z.value != 0){
            P = alocate(z);
            inLa(L,P);
        }
    } else {}// End High
}

int countList(List L){ // count list size
    int x = 0;
    if (first(L) == NULL){
        return x;
    } else {
        adr P = first(L);
        while (P != NULL){
            x++;
            P = next(P);
        }
        return x;
    }
}

void infMember(List L){
    int i,j,c = countList(L);
    char fr[3][3] = {// fuzzy rule
    {'N','N','Y'},
    {'N','N','Y'},
    {'N','Y','Y'}
    };

    if (c == 2){ // if list size equal 2
        infotype x,y;
        adr P = first(L);
        x.state = info(P).state;
        x.value = info(P).value;
        P = next(P);
        y.state = info(P).state;
        y.value = info(P).value;

        if (x.state == "eL"){ // mapping emotion
            i = 0;
        } else if (x.state == "eM"){
            i = 1;
        } else if (x.state == "eH"){
            i = 2;
        } else {
            cout<<"Error Inference Ex01\n";
            exit(1);
        }

        if (y.state == "pL"){ // mapping provocation
            j = 0;
        } else if (y.state == "pM"){
            j = 1;
        } else if (y.state == "pH"){
            j = 2;
        } else {
            cout<<"Error Inference Px01\n";
            exit(1);
        }
        string s;
        if (fr[i][j] == 'N'){
            s = "No";
        } else {
            s = "Yes";
        }
        cout<<"Hoax: "<< s <<endl;
        cout<<"Degree of Truth (0-1): 1\n";
    } // end if (c == 2)
    else if (c == 3){
        infotype x,y,z;
        char hs1,hs2;
        double hv1,hv2;
        adr P = first(L);
        x.state = info(P).state;
        x.value = info(P).value;
        P = next(P);
        y.state = info(P).state;
        y.value = info(P).value;
        P = next(P);
        z.state = info(P).state;
        z.value = info(P).value;

        if (y.state == "eL" || y.state == "eM" || y.state == "eH"){ // if second entry of list is emotion
            // hs1 and hv1 == x to z
            if (x.state == "eL"){ // mapping emotion
                i = 0;
            } else if (x.state == "eM"){
                i = 1;
            } else if (x.state == "eH"){
                i = 2;
            } else {
                cout<<"Error Inference Ex01\n";
                exit(1);
            }

            if (z.state == "pL"){ // mapping provocation
                j = 0;
            } else if (z.state == "pM"){
                j = 1;
            } else if (z.state == "pH"){
                j = 2;
            } else {
                cout<<"Error Inference Px01\n";
                exit(1);
            }

            hs1 = fr[i][j];
            hv1 = x.value; // conjunction hs1 and hv1

            // hs2 and hv2 == y to z
            if (y.state == "eL"){ // mapping emotion
                i = 0;
            } else if (y.state == "eM"){
                i = 1;
            } else if (y.state == "eH"){
                i = 2;
            } else {
                cout<<"Error Inference Ex01\n";
                exit(1);
            }

            if (z.state == "pL"){ // mapping provocation
                j = 0;
            } else if (z.state == "pM"){
                j = 1;
            } else if (z.state == "pH"){
                j = 2;
            } else {
                cout<<"Error Inference Px01\n";
                exit(1);
            }
            hs2 = fr[i][j];
            hv2 = y.value; // conjunction hs2 and hv2

            double MAX;

            if (hs1 == hs2){ // disjunction hs1 and hs2
                if (hv1 >= hv2){
                    MAX = hv1;
                } else {
                    MAX = hv2;
                }

                if (hs1 == 'N'){
                    cout<<"Hoax: No\n";
                    cout<<"Degree of Truth: "<<MAX<<endl;
                } else {
                    cout<<"Hoax: Yes\n";
                    cout<<"Degree of Truth: "<<MAX<<endl;
                }
            } else {
                // Mamdani Model
                if (hv1 > hv2){
                    MAX = (((10.0 + 20.0 + 30.0 + 40.0 + 50.0)*hv1) + ((60.0 + 70.0 + 80.0 + 90.0 + 100.0)*hv2)) / ((5*hv1)+(5*hv2));
                } else {
                    MAX = (((10.0 + 20.0 + 30.0 + 40.0)*hv1) + ((50.0 + 60.0 + 70.0 + 80.0 + 90.0 + 100.0)*hv2)) / ((4*hv1)+(6*hv2));
                }
                cout<<"According to Mamdani Model\n";
                if (MAX >= 50){
                    cout<<"Hoax: Yes\n";
                    cout<<"Degree of Truth (0-100): "<<MAX<<endl;
                } else {
                    cout<<"Hoax: No\n";
                    cout<<"Degree of Truth (0-100): "<<MAX<<endl;
                }
            }
        } // end if (y.state == "eL" || y.state == "eM" || y.state == "eH")
        else if (y.state == "pL" || y.state == "pM" || y.state == "pH"){ // if second entry of list is provocation
            // hs1 and hv1 == x to y
            if (x.state == "eL"){ // mapping emotion
                i = 0;
            } else if (x.state == "eM"){
                i = 1;
            } else if (x.state == "eH"){
                i = 2;
            } else {
                cout<<"Error Inference Ex01\n";
                exit(1);
            }

            if (y.state == "pL"){ // mapping provocation
                j = 0;
            } else if (y.state == "pM"){
                j = 1;
            } else if (y.state == "pH"){
                j = 2;
            } else {
                cout<<"Error Inference Px01\n";
                exit(1);
            }

            hs1 = fr[i][j];
            hv1 = y.value; // conjunction hs1 and hv1

            // hs2 and hv2 == x to z
            if (x.state == "eL"){ // mapping emotion
                i = 0;
            } else if (x.state == "eM"){
                i = 1;
            } else if (x.state == "eH"){
                i = 2;
            } else {
                cout<<"Error Inference Ex01\n";
                exit(1);
            }

            if (z.state == "pL"){ // mapping provocation
                j = 0;
            } else if (z.state == "pM"){
                j = 1;
            } else if (z.state == "pH"){
                j = 2;
            } else {
                cout<<"Error Inference Px01\n";
                exit(1);
            }
            hs2 = fr[i][j];
            hv2 = z.value; // conjunction hs2 and hv2

            double MAX;

            if (hs1 == hs2){ // disjunction hs1 and hs2
                if (hv1 >= hv2){
                    MAX = hv1;
                } else {
                    MAX = hv2;
                }

                if (hs1 == 'N'){
                    cout<<"Hoax: No\n";
                    cout<<"Degree of Truth: "<<MAX<<endl;
                } else {
                    cout<<"Hoax: Yes\n";
                    cout<<"Degree of Truth: "<<MAX<<endl;
                }
            } else {
               
                if (hv1 > hv2){
                    MAX = (((10.0 + 20.0 + 30.0 + 40.0 + 50.0)*hv1) + ((60.0 + 70.0 + 80.0 + 90.0 + 100.0)*hv2)) / ((5*hv1)+(5*hv2));
                } else {
                    MAX = (((10.0 + 20.0 + 30.0 + 40.0)*hv1) + ((50.0 + 60.0 + 70.0 + 80.0 + 90.0 + 100.0)*hv2)) / ((4*hv1)+(6*hv2));
                }
                cout<<"According to Mamdani Model\n";
                if (MAX >= 50){
                    cout<<"Hoax: Yes\n";
                    cout<<"Degree of Truth (0-100): "<<MAX<<endl;
                } else {
                    cout<<"Hoax: No\n";
                    cout<<"Degree of Truth (0-100): "<<MAX<<endl;
                }
            }
        } // end if (y.state == "pL" || y.state == "pM" || y.state == "pH")
    } // end if (c == 3)
    else if (c == 4){
        infotype a,b,c,d;
        char hs1,hs2,hs3,hs4;
        double hv1,hv2,hv3,hv4,m;
        adr P = first(L);
        a.state = info(P).state;
        a.value = info(P).value;
        P = next(P);
        b.state = info(P).state;
        b.value = info(P).value;
        P = next(P);
        c.state = info(P).state;
        c.value = info(P).value;
        P = next(P);
        d.state = info(P).state;
        d.value = info(P).value;

        // hs1 and hv1 == a to c
        if (a.state == "eL"){ // mapping emotion
            i = 0;
        } else if (a.state == "eM"){
            i = 1;
        } else if (a.state == "eH"){
            i = 2;
        } else {
            cout<<"Error Inference Ex01\n";
            exit(1);
        }

        if (c.state == "pL"){ // mapping provocation
            j = 0;
        } else if (c.state == "pM"){
            j = 1;
        } else if (c.state == "pH"){
            j = 2;
        } else {
            cout<<"Error Inference Px01\n";
            exit(1);
        }

        hs1 = fr[i][j];
        if (a.value <= c.value){
            hv1 = a.value;
        } else {
            hv1 = c.value;
        }// conjunction hs1 and hv1

        // hs2 and hv2 == a to d
        if (a.state == "eL"){ // mapping emotion
            i = 0;
        } else if (a.state == "eM"){
            i = 1;
        } else if (a.state == "eH"){
            i = 2;
        } else {
            cout<<"Error Inference Ex01\n";
            exit(1);
        }

        if (d.state == "pL"){ // mapping provocation
            j = 0;
        } else if (d.state == "pM"){
            j = 1;
        } else if (d.state == "pH"){
            j = 2;
        } else {
            cout<<"Error Inference Px01\n";
            exit(1);
        }

        hs2 = fr[i][j];
        if (a.value <= d.value){
            hv2 = a.value;
        } else {
            hv2 = d.value;
        }// conjunction hs2 and hv2

        // hs3 and hv3 == b to c
        if (b.state == "eL"){ // mapping emotion
            i = 0;
        } else if (b.state == "eM"){
            i = 1;
        } else if (b.state == "eH"){
            i = 2;
        } else {
            cout<<"Error Inference Ex01\n";
            exit(1);
        }

        if (c.state == "pL"){ // mapping provocation
            j = 0;
        } else if (c.state == "pM"){
            j = 1;
        } else if (c.state == "pH"){
            j = 2;
        } else {
            cout<<"Error Inference Px01\n";
            exit(1);
        }

        hs3 = fr[i][j];
        if (b.value <= c.value){
            hv3 = b.value;
        } else {
            hv3 = c.value;
        }// conjunction hs3 and hv3

        // hs4 and hv4 == b to d
        if (b.state == "eL"){ // mapping emotion
            i = 0;
        } else if (b.state == "eM"){
            i = 1;
        } else if (b.state == "eH"){
            i = 2;
        } else {
            cout<<"Error Inference Ex01\n";
            exit(1);
        }

        if (d.state == "pL"){ // mapping provocation
            j = 0;
        } else if (d.state == "pM"){
            j = 1;
        } else if (d.state == "pH"){
            j = 2;
        } else {
            cout<<"Error Inference Px01\n";
            exit(1);
        }

        hs4 = fr[i][j];
        if (b.value <= d.value){
            hv4 = b.value;
        } else {
            hv4 = d.value;
        }// conjunction hs4 and hv4

        double maks = 0.0; // value for Degree of Truth
        // Disjunction
        if (hs1 == hs2 && hs1 == hs3 && hs1 == hs4){
            if (hv1 >= hv2 && hv1 >= hv3 && hv1 >= hv4){
                maks = hv1;
            }
            if (hv1 >= hv2 && hv1 >= hv3 && hv1 < hv4){
                maks = hv4;
            }
            if (hv1 >= hv2 && hv1 >= hv4 && hv1 < hv3){
                maks = hv3;
            }
            if (hv1 >= hv3 && hv1 >= hv4 && hv1 < hv2){
                maks = hv2;
            }
            if (hv2 >= hv1 && hv2 >= hv3 && hv2 >= hv4){
                maks = hv2;
            }
            if (hv2 >= hv1 && hv2 >= hv3 && hv2 < hv4){
                maks = hv4;
            }
            if (hv2 >= hv1 && hv2 >= hv4 && hv2 < hv3){
                maks = hv3;
            }
            if (hv2 >= hv3 && hv2 >= hv4 && hv2 < hv1){
                maks = hv1;
            }
            if (hv3 >= hv1 && hv3 >= hv2 && hv3 >= hv4){
                maks = hv3;
            }
            if (hv3 >= hv1 && hv3 >= hv2 && hv3 < hv4){
                maks = hv4;
            }
            if (hv3 >= hv1 && hv3 >= hv4 && hv3 < hv2){
                maks = hv2;
            }
            if (hv3 >= hv2 && hv3 >= hv4 && hv2 < hv1){
                maks = hv1;
            }
            if (hv4 >= hv1 && hv4 >= hv2 && hv4 >= hv3){
                maks = hv4;
            }
            if (hv4 >= hv1 && hv4 >= hv2 && hv4 < hv3){
                maks = hv3;
            }
            if (hv4 >= hv1 && hv4 >= hv3 && hv4 < hv2){
                maks = hv2;
            }
            if (hv4 >= hv2 && hv4 >= hv3 && hv4 < hv1){
                maks = hv1;
            }

            if (hs1 == 'N'){
                cout<<"Hoax: No\n";
                cout<<"Degree of Truth (0-1): "<<maks<<endl;
            } else {
                cout<<"Hoax: Yes\n";
                cout<<"Degree of Truth (0-1): "<<maks<<endl;
            }
        } else if (hs1 == hs2 && hs1 == hs3 && hs1 != hs4){
            if (hv1 >= hv2 && hv1 >= hv3){
                maks = hv1;
            }
            if (hv1 >= hv2 && hv1 < hv3){
                maks = hv3;
            }
            if (hv1 >= hv3 && hv1 < hv2){
                maks = hv2;
            }
            if (hv2 >= hv1 && hv2 >= hv3){
                maks = hv2;
            }
            if (hv2 >= hv1 && hv2 < hv3){
                maks = hv3;
            }
            if (hv2 >= hv3 && hv2 < hv1){
                maks = hv1;
            }
            if (hv3 >= hv1 && hv1 >= hv2){
                maks = hv3;
            }
            if (hv3 >= hv1 && hv3 < hv2){
                maks = hv2;
            }
            if (hv3 >= hv2 && hv3 < hv1){
                maks = hv1;
            }
            // Mamdani Model
            if (maks > hv4){
                m = (((10.0 + 20.0 + 30.0 + 40.0 + 50.0)*maks) + ((60.0 + 70.0 + 80.0 + 90.0 + 100.0)*hv4)) / ((5*maks)+(5*hv4));
            } else {
                m = (((10.0 + 20.0 + 30.0 + 40.0)*maks) + ((50.0 + 60.0 + 70.0 + 80.0 + 90.0 + 100.0)*hv4)) / ((4*maks)+(6*hv4));
            }

            cout<<"According to Mamdani Model.\n";
            if (m <= 50.0){
                cout<<"Hoax: No\n";
                cout<<"Degree of Truth (0-100): "<<m<<endl;
            } else {
                cout<<"Hoax: Yes\n";
                cout<<"Degree of Truth (0-100): "<<m<<endl;
            }
        } else if (hs1 == hs2 && hs3 == hs4){
            double maks2;
            if (hv1 >= hv2){
                maks = hv1;
            } else {
                maks = hv2;
            }

            if (hv3 >= hv4){
                maks2 = hv3;
            } else {
                maks2 = hv4;
            }

            // Mamdani Model
            if (maks > maks2){
                m = (((10.0 + 20.0 + 30.0 + 40.0 + 50.0)*maks) + ((60.0 + 70.0 + 80.0 + 90.0 + 100.0)*maks2)) / ((5*maks)+(5*maks2));
            } else {
                m = (((10.0 + 20.0 + 30.0 + 40.0)*maks) + ((50.0 + 60.0 + 70.0 + 80.0 + 90.0 + 100.0)*maks2)) / ((4*maks)+(6*maks2));
            }

            cout<<"According to Mamdani Model.\n";
            if (m <= 50.0){
                cout<<"Hoax: No\n";
                cout<<"Degree of Truth (0-100): "<<m<<endl;
            } else {
                cout<<"Hoax: Yes\n";
                cout<<"Degree of Truth (0-100): "<<m<<endl;
            }
        } else if (hs1 == hs3 && hs2 == hs4){
            double maks2;
            if (hv1 >= hv3){
                maks = hv1;
            } else {
                maks = hv3;
            }

            if (hv2 >= hv4){
                maks2 = hv2;
            } else {
                maks2 = hv4;
            }

            // Mamdani Model
            if (maks > maks2){
                m = (((10.0 + 20.0 + 30.0 + 40.0 + 50.0)*maks) + ((60.0 + 70.0 + 80.0 + 90.0 + 100.0)*maks2)) / ((5*maks)+(5*maks2));
            } else {
                m = (((10.0 + 20.0 + 30.0 + 40.0)*maks) + ((50.0 + 60.0 + 70.0 + 80.0 + 90.0 + 100.0)*maks2)) / ((4*maks)+(6*maks2));
            }

            cout<<"According to Mamdani Model.\n";
            if (m <= 50.0){
                cout<<"Hoax: No\n";
                cout<<"Degree of Truth (0-100): "<<m<<endl;
            } else {
                cout<<"Hoax: Yes\n";
                cout<<"Degree of Truth (0-100): "<<m<<endl;
            }
        } else if (hs1 == hs4 && hs2 == hs3){
            double maks2;
            if (hv1 >= hv4){
                maks = hv1;
            } else {
                maks = hv4;
            }

            if (hv2 >= hv3){
                maks2 = hv2;
            } else {
                maks2 = hv3;
            }

            // Mamdani Model
            if (maks > maks2){
                m = (((10.0 + 20.0 + 30.0 + 40.0 + 50.0)*maks) + ((60.0 + 70.0 + 80.0 + 90.0 + 100.0)*maks2)) / ((5*maks)+(5*maks2));
            } else {
                m = (((10.0 + 20.0 + 30.0 + 40.0)*maks) + ((50.0 + 60.0 + 70.0 + 80.0 + 90.0 + 100.0)*maks2)) / ((4*maks)+(6*maks2));
            }

            cout<<"According to Mamdani Model.\n";
            if (m <= 50.0){
                cout<<"Hoax: No\n";
                cout<<"Degree of Truth (0-100): "<<m<<endl;
            } else {
                cout<<"Hoax: Yes\n";
                cout<<"Degree of Truth (0-100): "<<m<<endl;
            }
        } else if (hs1 == hs2 && hs1 == hs4 && hs1 != hs3){
            if (hv1 >= hv2 && hv1 >= hv4){
                maks = hv1;
            }
            if (hv1 >= hv2 && hv1 < hv4){
                maks = hv4;
            }
            if (hv1 >= hv4 && hv1 < hv2){
                maks = hv2;
            }

            if (hv2 >= hv1 && hv2 >= hv4){
                maks = hv2;
            }
            if (hv2 >= hv1 && hv2 < hv4){
                maks = hv4;
            }
            if (hv2 >= hv4 && hv2 < hv1){
                maks = hv1;
            }

            if (hv4 >= hv1 && hv1 >= hv2){
                maks = hv4;
            }
            if (hv4 >= hv1 && hv4 < hv2){
                maks = hv2;
            }
            if (hv4 >= hv2 && hv4 < hv1){
                maks = hv1;
            }

            // Mamdani Model
            if (maks > hv3){
                m = (((10.0 + 20.0 + 30.0 + 40.0 + 50.0)*maks) + ((60.0 + 70.0 + 80.0 + 90.0 + 100.0)*hv3)) / ((5*maks)+(5*hv3));
            } else {
                m = (((10.0 + 20.0 + 30.0 + 40.0)*maks) + ((50.0 + 60.0 + 70.0 + 80.0 + 90.0 + 100.0)*hv3)) / ((4*maks)+(6*hv3));
            }

            cout<<"According to Mamdani Model.\n";
            if (m <= 50.0){
                cout<<"Hoax: No\n";
                cout<<"Degree of Truth (0-100): "<<m<<endl;
            } else {
                cout<<"Hoax: Yes\n";
                cout<<"Degree of Truth (0-100): "<<m<<endl;
            }
        } else if (hs1 == hs3 && hs1 == hs4 && hs1 != hs2){
            if (hv1 >= hv3 && hv1 >= hv4){
                maks = hv1;
            }
            if (hv1 >= hv3 && hv1 < hv4){
                maks = hv4;
            }
            if (hv1 >= hv4 && hv1 < hv3){
                maks = hv3;
            }

            if (hv3 >= hv1 && hv3 >= hv4){
                maks = hv3;
            }
            if (hv3 >= hv1 && hv3 < hv4){
                maks = hv4;
            }
            if (hv3 >= hv4 && hv3 < hv1){
                maks = hv1;
            }

            if (hv4 >= hv1 && hv4 >= hv3){
                maks = hv4;
            }
            if (hv4 >= hv1 && hv4 < hv3){
                maks = hv3;
            }
            if (hv4 >= hv3 && hv4 < hv1){
                maks = hv1;
            }

            // Mamdani Model
            if (maks > hv2){
                m = (((10.0 + 20.0 + 30.0 + 40.0 + 50.0)*maks) + ((60.0 + 70.0 + 80.0 + 90.0 + 100.0)*hv2)) / ((5*maks)+(5*hv2));
            } else {
                m = (((10.0 + 20.0 + 30.0 + 40.0)*maks) + ((50.0 + 60.0 + 70.0 + 80.0 + 90.0 + 100.0)*hv2)) / ((4*maks)+(6*hv2));
            }

            cout<<"According to Mamdani Model.\n";
            if (m <= 50.0){
                cout<<"Hoax: No\n";
                cout<<"Degree of Truth (0-100): "<<m<<endl;
            } else {
                cout<<"Hoax: Yes\n";
                cout<<"Degree of Truth (0-100): "<<m<<endl;
            }
        } else if (hs2 == hs3 && hs2 == hs4 && hs2 != hs1){
            if (hv2 >= hv3 && hv2 >= hv4){
                maks = hv2;
            }
            if (hv2 >= hv3 && hv2 < hv4){
                maks = hv4;
            }
            if (hv2 >= hv4 && hv2 < hv3){
                maks = hv3;
            }

            if (hv3 >= hv2 && hv3 >= hv4){
                maks = hv3;
            }
            if (hv3 >= hv2 && hv3 < hv4){
                maks = hv4;
            }
            if (hv3 >= hv4 && hv3 < hv2){
                maks = hv2;
            }

            if (hv4 >= hv2 && hv4 >= hv3){
                maks = hv4;
            }
            if (hv4 >= hv2 && hv4 < hv3){
                maks = hv3;
            }
            if (hv4 >= hv3 && hv4 < hv2){
                maks = hv2;
            }

            // Mamdani Model
            if (maks > hv1){
                m = (((10.0 + 20.0 + 30.0 + 40.0 + 50.0)*maks) + ((60.0 + 70.0 + 80.0 + 90.0 + 100.0)*hv1)) / ((5*maks)+(5*hv1));
            } else {
                m = (((10.0 + 20.0 + 30.0 + 40.0)*maks) + ((50.0 + 60.0 + 70.0 + 80.0 + 90.0 + 100.0)*hv1)) / ((4*maks)+(6*hv1));
            }

            cout<<"According to Mamdani Model.\n";
            if (m <= 50.0){
                cout<<"Hoax: No\n";
                cout<<"Degree of Truth (0-100): "<<m<<endl;
            } else {
                cout<<"Hoax: Yes\n";
                cout<<"Degree of Truth (0-100): "<<m<<endl;
            }
        }
    } // end if (c == 4)
}

