#ifndef CONSOL_H
#define CONSOL_H


class consol
{
public:
    consol();
    void inputLumen(int data);
    void inputTemp(int data);
private:
    int light[10];
    int temp[10];
    int it;
    int il;
};

#endif // CONSOL_H
