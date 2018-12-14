typedef double Type;
struct Pt{
  Type x, y;
  Pt(){};
  Pt(Type _x, Type _y){ x = _x, y = _y; }
  Pt operator +(const Pt &p2){ return Pt(x+p2.x, y+p2.y); }
  Pt operator -(const Pt &p2){ return Pt(x-p2.x, y-p2.y); }
  Pt operator *(const Type &p2){ return Pt(x*p2, y*p2); }
  Type operator *(const Pt &p2){ return x*p2.x + y*p2.y; }
  Type operator ^(const Pt &p2){ return x*p2.y - y*p2.x; }
  Type dis(){ return sqrt(x*x+y*y); }
  void read(){ scanf("%lf %lf", &x, &y); }
};
struct Line{
  Pt s, e;
  Line(){};
  Line(Pt _s, Pt _e){ s = _s, e = _e; }
  void read(){ s.read(), e.read(); }
};

