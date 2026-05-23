concatenar([], L, L).

concatenar([X|L1], L2, [X|L3]) :- 
    concatenar(L1, L2, L3).


utiles(ana, [cuaderno, lapiz, borrador]).
utiles(luis, [regla, colores]).

utiles_juntos(P1, P2, L) :-
    utiles(P1, Lista1),
    utiles(P2, Lista2),
    concatenar(Lista1, Lista2, L).
