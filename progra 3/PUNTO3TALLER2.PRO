% -----------------------------
% HECHOS: lista de amigos
% -----------------------------

amigos(ana,    [carlos, lucia, pedro]).
amigos(carlos, [ana, pedro, maria]).
amigos(lucia,  [ana, juan]).

% -----------------------------
% PERTENECE A UNA LISTA
% -----------------------------

pertenece(X, [X|_]).
pertenece(X, [_|T]) :-
    pertenece(X, T).

% -----------------------------
% VERIFICAR QUE UNA LISTA NO TENGA REPETIDOS
% -----------------------------

sin_repetidos([]).
sin_repetidos([H|T]) :-
    \+ pertenece(H, T),
    sin_repetidos(T).

% -----------------------------
% INTERSECCION ENTRE LISTAS
% -----------------------------

interseccion([], _, []).
interseccion([H|T], L2, [H|R]) :-
    pertenece(H, L2),
    interseccion(T, L2, R).
interseccion([H|T], L2, R) :-
    \+ pertenece(H, L2),
    interseccion(T, L2, R).

% -----------------------------
% AMIGOS EN COMUN
% -----------------------------

amigos_en_comun(P1, P2, C) :-
    amigos(P1, L1),
    amigos(P2, L2),
    sin_repetidos(L1),
    sin_repetidos(L2),
    interseccion(L1, L2, C).