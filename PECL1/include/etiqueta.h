#ifndef ETIQUETA_H
#define ETIQUETA_H


class etiqueta
{
public:
    etiqueta();
    virtual ~etiqueta();
protected:

private:
};

class id
{
    struct Identificador
    {
        char ID[7];
        string latitud

    };
    struct coordenadas
    {
        int lat_max(-3190);
        int lat_min(-3250);
        int lon_max(40310);
        int lon_min(40280);
        int longitud(lon_min + rand() % (lon_max+1 - lon_min));
        int latitud (lat_min + rand() % (lat_max+1 - lat_min));
    };
};
#endif // ETIQUETA_H
