%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Finite Atutomaton                               %%
%% Adrian-Leonard Radu                             %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

m(q0, a, q1).
m(q0, b, q2).
m(q0, c, q0).
m(q1, c, q0).
m(q1, a, q1).
m(q2, b, q2).

final(q1).
final(q2).

fsm(C_State, []):- final(C_State).
fsm(C_State, [H|T]):- m(C_State, H, N_State),
                      fsm(N_State, T).

accept(S):- fsm(q0, S).
