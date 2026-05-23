miembro(X, [X|_]).
miembro(X, [_|R]) :- miembro(X, R).

estudiante(ana, [logica, calculo, programacion]).
estudiante(maria, [logica, fisica]).
estudiante(luis, [deportes, ingles]).

cursa(Estudiante, Materia) :-
    estudiante(Estudiante, Lista),
    miembro(Materia, Lista).