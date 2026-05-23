% ---------- HECHOS ----------

curso(ia, [logica, programacion]).
curso(bases_de_datos, [programacion]).
curso(redes, [programacion]).
curso(logica, []).

aprobadas(ana, [logica, programacion]).
aprobadas(luis, [programacion]).
aprobadas(maria, [logica, programacion, bases_de_datos]).

% ---------- PERTENENCIA ----------

pertenece(X, [X|_]).
pertenece(X, [_|R]) :- pertenece(X, R).

% ---------- SUBCONJUNTO ----------

subconjunto([], _).
subconjunto([X|R], L) :-
    pertenece(X, L),
    subconjunto(R, L).

% ---------- REGLA PRINCIPAL ----------

puede_ver(Persona, Curso) :-
    curso(Curso, Prerreq),
    aprobadas(Persona, Aprobadas),
    subconjunto(Prerreq, Aprobadas),
    \+ pertenece(Curso, Aprobadas).