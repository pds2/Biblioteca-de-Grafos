#include <bits/stdc++.h>

class Interface_Grafo_Base {
private:
  // nada
public:
 // metodos virtuais aqui
};

class Interface_Grafo_Dirigido : public Interface_Grafo_Base{
private:
  // nada
public:
  // metodos virtuais
};

class Interface_Grafo_nao_Dirigido : public Interface_Grafo_Base{
private:
  // nada
public:
  // metodos virtuais
};

class Grafo_nao_Dirigido : public Interface_Grafo_nao_Dirigido{
private:
  // dados do grafo
public:
  // metodos
};

class Arvore : public Interface_Grafo_nao_Dirigido{
private:
  // dados do grafo
public:
  // metodos
};

class Grafo_Dirigido : public Interface_Grafo_Dirigido{
private:
  // dados do grafo
public:
  // metodos
};

class DAG : public Interface_Grafo_Dirigido{
private:
  // dados do grafo
public:
  // metodos
};
