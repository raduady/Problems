% btree/2
% btree(+Value, +Left, +Right)
btree(_, nil, nil).
btree(_, L, R):- tree(L), tree(R).

% bvalue/2
% bvalue(+Tree, -V)
bvalue(btree(X, _, _), X).

% bstree/1
% bstree(+BinaryTree).
bstree(btree(_, nil, nil)).
bstree(btree(X, L, R)):- value(L, Vl), value(R, Vr), X > Vl, X < Vr, bstree(L),
                          bstree(R).

% add_bstree/3
% add_bstree(+NewValue, +OldBST, -NewBST)
add_bstree(X, nil, btree(X, nil, nil)).
add_bstree(X, btree(V, L, R), btree(V, NL, R)):- X < V, !, add_bstree(X, L, NL).
add_bstree(X, btree(V, L, R), btree(V, L, NR)):- add_bstree(X, R, NR).

% write_spaces/1
% write_spaces(+NumSpaces)
write_spaces(0).
write_spaces(X):- write(' '), Y is X - 1, write_spaces(Y), !.

% write_preorder_sp/2
% write_preorder_sp(+NumSpaces, +BinaryTree).
write_preorder_sp(Sp, nil):- write_spaces(Sp), write('.'), nl, !.
write_preorder_sp(Sp, btree(V, L, R)):- write_spaces(Sp), write(V), nl,
                                        Nsp is Sp + 1,
                                        write_preorder_sp(Nsp, L), !,
                                        write_preorder_sp(Nsp, R), !.

% write_preorder/2
% write_preorder(+BinaryTree)
write_preorder(B):- write_preorder_sp(0, B).
