#ifndef OPONA_H
#define OPONA_H

class Opona
{
    protected:
        int m_przebita;
    public:
        Opona(int przebita = 0) { m_przebita = przebita; };
        virtual int Przebicie(int srednica);

};

class OponaBezdetkowa: public Opona
{
    public:
        OponaBezdetkowa(int przebita = 0) : Opona(przebita) {};
        virtual int Przebicie(int srednica) override;

};

#endif