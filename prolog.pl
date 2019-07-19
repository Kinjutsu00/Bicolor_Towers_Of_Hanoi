hanoi(1,A,B,_) :-
    %write('Move top disk from '),
    %write(A),
    open('outputpl.txt', append, Handle), 
    write(Handle, A), 
    write(Handle, ','), 
    write(Handle, B), 
    write(Handle, '\n'), 
    close(Handle).   
    %write(' to '),
    %write(','),
    %write(B),
    %nl.
hanoi(N,A,B,C) :-
    N>1,	
    K is N-1,
    hanoi(K,A,C,B),
    hanoi(1,A,B,_),
    hanoi(K,C,B,A).
hanoi_bicolore(S,N,A,B,C) :-
    S>N,
    K is N/2,
    splitta(K,B,A,C).
hanoi_bicolore(S,N,A,B,C) :- 
    N>S,
    K is S+2,
    hanoi(K,B,A,C),
    hanoi_bicolore(K,N,B,A,C).
splitta(1,A,B,_) :-
    hanoi(1,A,B,_).
splitta(N,A,B,C) :- 
    N>1,
    K is N-1,
    hanoi2(K,A,C,B),
    hanoi(1,A,B,_),
    hanoi2(K,C,A,B),
    splitta(K,A,B,C).
hanoi2(1,A,B,_) :-
    hanoi(1,A,B,_),
    hanoi(1,A,B,_).
hanoi2(N,A,B,C) :-
    N>1,
    K is N-1,
    hanoi2(K,A,C,B),
    hanoi(1,A,B,_),
    hanoi(1,A,B,_),
    hanoi2(K,C,B,A).	
