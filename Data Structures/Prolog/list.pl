%% lastL/2
%% lastL(+List, -Element)
lastL([X], X).
lastL([_|T], X):- lastL(T, X).

%% penL/2
%% penL(+List, -Element)
penL([X, _], X).
penL([_|T], X):- penL(T, X).

%% kth/2
%% kth(+List, +K, -Element)
kth([H|_], 0, H).
kth([_|T], K, X):- NK is K - 1, kth(T, NK, X).

%% lengthL/2
%% lengthL(+List, -Length)
lengthL([], 0).
lengthL([_|T], L):- lengthL(T, NL), L is NL + 1.

%% lengthLA/2
%% lengthLA(+List, -Length)
lengthLA(L, X):- lengthLAcc(L, 0, X).
lengthLAcc([], Acc, Acc).
lengthLAcc([_|T], Acc, L):- NAcc is Acc + 1, lengthLAcc(T, NAcc, L). 

%% appendL/2
%% appendL(+List1, +List2, -Result).
appendL([], L, L).
appendL([H|T], L, [H|R]):- appendL(T, L, R).

%% revL/2
%% revL(+List, -RList).
revL([], []).
revL([H|T], R):- revL(T, X), appendL(X, [H], R).

%% revLA/2
%% revLA(+List, -RList)
revLA(L, R):- revLAcc(L, [], R).
revLAcc([], L, L).
revLAcc([H|T], Acc, L):- revLAcc(T, [H|Acc], L).

%% remove_last/2
%% remove_last(+List, -Result).
remove_last([_], []).
remove_last([H|T], [H|R]):- remove_last(T, R).

%% is_palindrom/1
%% is_palindrom(+List).
is_palindrom(L):- reverse(L, L).

%% flatten/2
%% flatten(+List, -Result)
flatten([], []).
flatten([H|T], R):- !, flatten(H, LH), flatten(T, LT), append(LH, LT, R), !.
flatten(X, [X]).

%% compress/2
%% compress(+List, -Result)
compress([], []).
compress([H, H|T], R):- compress([H|T], R), !.
compress([H|T], [H|R]):- compress(T, R).
