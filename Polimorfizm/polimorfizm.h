#ifndef POLIMORFIZM_H_
#define POLIMORFIZM_H_

class Ksztalt
{
  public:
    virtual void oblicz_pole() = 0;
};

class Kolo:
public Ksztalt
{
  private:
    float m_r;
  public:
    Kolo(float r);
    void oblicz_pole() override;
};

class Kwadrat:
public Ksztalt
{
  private:
    float m_x;
  public:
    Kwadrat(float x);
    void oblicz_pole() override;
};

void obliczenia(Ksztalt * pointer);



#endif
