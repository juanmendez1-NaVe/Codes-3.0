% Student exercise profile
:- set_prolog_flag(occurs_check, error).        % disallow cyclic terms
:- set_prolog_stack(global, limit(8 000 000)).   % limit term space (8Mb)
:- set_prolog_stack(local,  limit(2 000 000)).   % limit environment space

% =================================================================
% 1. EL TRIQUI (LÓGICA DEL JUEGO)
% =================================================================

% Representación visual (lo que el usuario ve)
mostrar_tablero([P1, P2, P3, P4, P5, P6, P7, P8, P9]) :-
    nl,
    format(' ~w | ~w | ~w ~n', [P1, P2, P3]),
    write('---+---+---'), nl,
    format(' ~w | ~w | ~w ~n', [P4, P5, P6]),
    write('---+---+---'), nl,
    format(' ~w | ~w | ~w ~n', [P7, P8, P9]),
    nl.

% Motor principal del juego
jugar(Humano, PC, TurnoInicial, Modo) :-
    TableroInicial = ['-','-','-','-','-','-','-','-','-'],
    jugar_ciclo(TableroInicial, TurnoInicial, Humano, PC, Modo).
% Ciclo principal del juego
jugar_ciclo(Tablero, Turno, Humano, PC, Modo) :-
    mostrar_tablero(Tablero),
    (
        ganador(Tablero, 'X') ->
            write('Gano X'), nl
    ;   ganador(Tablero, 'O') ->
            write('Gano O'), nl
    ;   empate(Tablero) ->
            write('Empate.'), nl

    ;   Turno == 'X' ->
            pedir_jugada(Tablero, 'X', NuevoTablero),
            siguiente_turno(Turno, 'X', 'O', NuevoTurno),
            jugar_ciclo(NuevoTablero, NuevoTurno, Humano, PC, Modo)

    ;   Turno == 'O',
        Modo == humano ->
            pedir_jugada(Tablero, 'O', NuevoTablero),
            siguiente_turno(Turno, 'X', 'O', NuevoTurno),
            jugar_ciclo(NuevoTablero, NuevoTurno, Humano, PC, Modo)

    ;   Turno == 'O',
        Modo == pc ->
            jugada_pc(Tablero, 'O', NuevoTablero),
            siguiente_turno(Turno, 'X', 'O', NuevoTurno),
            jugar_ciclo(NuevoTablero, NuevoTurno, Humano, PC, Modo)
    ).

% =================================================================
% 2. REGLAS DEL TABLERO
% =================================================================

% Ganador: filas
ganador([F,F,F,_,_,_,_,_,_], F) :- F \= '-'.
ganador([_,_,_,F,F,F,_,_,_], F) :- F \= '-'.
ganador([_,_,_,_,_,_,F,F,F], F) :- F \= '-'.

% Ganador: columnas
ganador([F,_,_,F,_,_,F,_,_], F) :- F \= '-'.
ganador([_,F,_,_,F,_,_,F,_], F) :- F \= '-'.
ganador([_,_,F,_,_,F,_,_,F], F) :- F \= '-'.

% Ganador: diagonales
ganador([F,_,_,_,F,_,_,_,F], F) :- F \= '-'.
ganador([_,_,F,_,F,_,F,_,_], F) :- F \= '-'.

empate(Tablero) :-
    \+ member('-', Tablero).

siguiente_turno(Turno, Humano, PC, NuevoTurno) :-
    ( Turno == Humano ->
        NuevoTurno = PC
    ;   NuevoTurno = Humano
    ).

% =================================================================
% 3. JUGADAS
% =================================================================

% Jugada del humano: valida hasta que ingrese una casilla correcta
pedir_jugada(Tablero, Ficha, NuevoTablero) :-
    repeat,
        format('~nTu turno (~w). Elige una posicion del 1 al 9: ', [Ficha]),
        read(Pos),
        (   integer(Pos),
            Pos >= 1,
            Pos =< 9,
            casilla_libre(Tablero, Pos) ->
                poner_ficha(Tablero, Pos, Ficha, NuevoTablero),
                !
        ;   write('Movimiento invalido. Intenta de nuevo.'), nl,
            fail
        ).

% Jugada de la PC: toma la primera casilla libre
jugada_pc(Tablero, Ficha, NuevoTablero) :-
    % 1. Intentar ganar
    movimiento_ganador(Tablero, Ficha, Pos), !,
    poner_ficha(Tablero, Pos, Ficha, NuevoTablero),
    format('~nLa PC gana jugando en ~w.~n', [Pos]).

jugada_pc(Tablero, Ficha, NuevoTablero) :-
    % 2. Bloquear al rival
    rival(Ficha, Rival),
    movimiento_ganador(Tablero, Rival, Pos), !,
    poner_ficha(Tablero, Pos, Ficha, NuevoTablero),
    format('~nLa PC bloquea en ~w.~n', [Pos]).

jugada_pc(Tablero, Ficha, NuevoTablero) :-
    % 3. Movimiento normal
    nth1(Pos, Tablero, '-'),
    poner_ficha(Tablero, Pos, Ficha, NuevoTablero),
    format('~nLa PC juega en la posicion ~w.~n', [Pos]).

casilla_libre(Tablero, Pos) :-
    nth1(Pos, Tablero, '-').

poner_ficha([_|Resto], 1, Ficha, [Ficha|Resto]).
poner_ficha([C|Resto], Pos, Ficha, [C|NuevoResto]) :-
    Pos > 1,
    Pos1 is Pos - 1,
    poner_ficha(Resto, Pos1, Ficha, NuevoResto).
% Obtener rival
rival('X', 'O').
rival('O', 'X').

% Encontrar jugada ganadora
movimiento_ganador(Tablero, Ficha, Pos) :-
    nth1(Pos, Tablero, '-'),                % probar casilla libre
    poner_ficha(Tablero, Pos, Ficha, Nuevo),
    ganador(Nuevo, Ficha).                  % si gana, es buena jugada

% =================================================================
% 4. EL MENÚ
% =================================================================

menu(Humano, PC, TurnoInicial, Modo) :-
    write('      BIENVENIDO AL TRIQUI      '), nl,
    write('================================'), nl,

    % Elegir ficha
    repeat,
        write('Elija su ficha (X o O): '),
        read(Ficha0),
        downcase_atom(Ficha0, Ficha),
        (   Ficha == x ->
                Humano = 'X', PC = 'O'
        ;   Ficha == o ->
                Humano = 'O', PC = 'X'
        ;   write('Opcion invalida.'), nl,
            fail
        ),
        !,

    format('~nUsted es: ~w | Jugador dos es: ~w~n', [Humano, PC]),

    % Elegir modo de juego
    repeat,
        write('Modo de juego (1 = vs PC, 2 = vs Humano): '),
        read(Modo0),
        (   Modo0 == 1 ->
                Modo = pc
        ;   Modo0 == 2 ->
                Modo = humano
        ;   write('Opcion invalida.'), nl,
            fail
        ),
        !,

    % Elegir quién inicia
    repeat,
        write('Quien inicia? (x = X, o = O): '),
        read(Ini0),
        downcase_atom(Ini0, Ini),
        (   Ini == x ->
                TurnoInicial = 'X'
        ;   Ini == o ->
                TurnoInicial = 'O'
        ;   write('Opcion invalida.'), nl,
            fail
        ),
        !.

% =================================================================
% 5. EL MAIN (INICIO)
% =================================================================

   inicio :-
    menu(Humano, PC, TurnoInicial, Modo),
    jugar(Humano, PC, TurnoInicial, Modo),
    write('Gracias por jugar!'), nl.