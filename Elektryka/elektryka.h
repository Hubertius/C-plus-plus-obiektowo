#ifndef ELEKTRYKA_H_
#define ELEKTRYKA_H_

class Zarowka
{
  public:
    int m_power;
  public:
    Zarowka(int moc = 100);
    void UstawMocZarowki(int moc);
    int OdczytajMocZarowki();
    ~Zarowka() {};
};

class Lampa
{
  private:
    Zarowka one, two;
  public:
  Lampa() :
  one(),
  two() {};
  Lampa(int moc) :
    one(moc),
    two(moc) {};
  Lampa(const Lampa & innaLampa);
  Lampa & operator=(const Lampa & innaLampa);
  void UstawMocLampy(int power);
  void OdczytajMocLampy();
  ~Lampa() {};
};

#endif
